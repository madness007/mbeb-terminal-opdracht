#include "bank.h"
#include "account.h"
#include <string>

namespace Banking {
  
  Bank::Bank(std::string bankname) : _sem(2)  {
    this->_bankname = bankname;
  }

  int Bank::payment(double amount,  Account * account, Account * to_account) {
    _sem.acquire();   
    if (get_isValid(amount, account) == 0) {
        account->withdraw_balance(amount);
        to_account->add_balance(amount); // TODO bank kiezen eerst
        _sem.release();
        return 0; //goedgekeurd
    }
    _sem.release();
    return 1; //niet goedgekeurd
  }

  int Bank::get_isValid(double amount, Account * account) {
      if (amount <= account->get_balance()) {
          return 0;
      }
    return 1;
  }
};
