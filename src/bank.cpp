#include "bank.h"
#include "account.h"

namespace Bank {

  void Validation::propose_payment(double amount, int id, int to_id) {
    this->amount = amount;
    this->id = id;
    this->to_id = to_id; 
    
    if (get_isValid()) {
        complete_payment();
    }
  }

  void Validation::complete_payment(void) {
      // geld overzetten van account naar ander account
    // //    Bank::Account sender;
    // //    Bank::Account receiver;
    //    sender.withdraw_balance(amount, id);
    //    receiver.add_balance(amount, to_id);

  }

  bool Validation::get_isValid(void) const {
      double balance = 50.00; //Tijdelijke variabel, die gaan we moeten veranderen naar sender.get_balance()
      if (amount <= balance) {
          return true;
      }
    return false;
  }
};
