#include "bank.h"
#include "account.h"
#include <string>

namespace Banking {

  Bank::Bank(std::string bankname) : _sem(2), _vector(1)  {
    this->bankname = bankname;
    _vector.clear();
  }

  int Bank::payment(double amount,  Account * account, Account * to_account) {
    _sem.acquire();   
    if (get_isValid(amount, account) == 0) {
        payment_transfer(amount, account, to_account);
        return 0; //goedgekeurd
    }
    _sem.release();
    return 1; //niet goedgekeurd
  }

  void Bank::payment_transfer(double amount,  Account * account, Account * to_account) {
    account->withdraw_balance(amount);
    if (this->bankname == to_account->bank->bankname) {
      to_account->add_balance(amount);
    }
    else {
      to_account->append_credit(amount);
      to_account->bank->_vector.push_back(to_account);
    }
  }

  int Bank::get_isValid(double amount, Account * account) {
      if (amount <= account->get_balance()) {
          return 0;
      }
    return 1;
  }

  void Bank::handle_payments() {
    while (!_vector.empty()) {
      Account * account = _vector.back();
      _sem.acquire();   
      account->add_balance(account->get_credit());
      account->clear_credit();
      _vector.pop_back();
      _sem.release();
    }
  }

};
