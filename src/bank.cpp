#include "bank.h"
#include "account.h"
#include <string>

namespace Banking {

  Bank::Bank(std::string bankname) : _sem(2), _vector(1)  {
    this->bankname = bankname;
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
      to_account->add_balance(amount); // TODO bank kiezen eerst
    }
    else {
      struct Message {
        double amount = amount;
        Account * account = account;
        Account * to_account = to_account;
      };
      
    }
  }

  int Bank::get_isValid(double amount, Account * account) {
      if (amount <= account->get_balance()) {
          return 0;
      }
    return 1;
  }
};
