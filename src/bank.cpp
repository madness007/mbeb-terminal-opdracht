#include "bank.h"
#include "account.h"
#include <string>

namespace Banking {
  
  Bank::Bank(std::string bankname) {
    this->_bankname = bankname;
  }

  int Bank::payment(double amount,  Account * account, Account * to_account) {
    this->amount = amount;
; 
    
    if (get_isValid() == 0) {
        return 0; //goedgekeurd
    }
    return 1; //niet goedgekeurd
  }

  int Bank::get_isValid(void) const {
      double balance = 50.00; //Tijdelijke variabel, die gaan we moeten veranderen naar sender.get_balance()
      if (amount <= balance) {
          return 0;
      }
    return 1;
  }
};
