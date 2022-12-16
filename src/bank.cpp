#include "bank.h"
#include "account.h"
#include <string>

namespace Banking {

  Bank::Bank(std::string bankname) : _sem(2), _vector(1)  {
    // Bank constructor, set the bankname and initialise semaphore and vector.
    this->bankname = bankname;
    _vector.clear();
  }

  int Bank::payment(double amount,  Account * account, Account * to_account) {
    // aquire the semaphore and process the payment.
    // first check if the payment is valid.
    // if the payment is valid, transfer the money
    _sem.acquire();   
    if (get_isValid(amount, account) == 0) {
        payment_transfer(amount, account, to_account);
        return 0; //goedgekeurd
    }
    _sem.release();
    return 1; //niet goedgekeurd
  }

  void Bank::payment_transfer(double amount,  Account * account, Account * to_account) {
    // first withdraw the amount.
    // then add the balance to the TO account if its the same bank.
    // otherwise append the credit to the to account and give the account to the destination bank.
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
    // this checks if the balance is valid
      if (amount <= account->get_balance()) {
          return 0;
      }
    return 1;
  }

  void Bank::handle_payments() {
    // this method runs at night.
    // it pops an account from the vector. and processes the payment.
    // this verctor holds all the accounts that needs payment processing.
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
