#include "bank.h"
#include "account.h"
#include <string>

namespace Banking {
  
  Bank::Bank(std::string bankname) {
    this->_bankname = bankname;
  }

  void Bank::propose_payment(double amount, int id, int to_id) {
    this->amount = amount;
    this->id = id;
    this->to_id = to_id; 
    
    if (get_isValid()) {
        complete_payment();
    }
  }

  void Bank::complete_payment(void) {
      // geld overzetten van account naar ander account
    // //    Bank::Account sender;
    // //    Bank::Account receiver;
    //    sender.withdraw_balance(amount, id);
    //    receiver.add_balance(amount, to_id);

  }

  bool Bank::get_isValid(void) const {
      double balance = 50.00; //Tijdelijke variabel, die gaan we moeten veranderen naar sender.get_balance()
      if (amount <= balance) {
          return true;
      }
    return false;
  }
};
