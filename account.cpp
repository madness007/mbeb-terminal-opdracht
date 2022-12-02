#include "account.h"

namespace Bank {

  void Account::create_account(int id) {
    this->id = id;
  }

  void Account::set_balance(double amount, int id) {
      this->balance = amount;
  }

  void Account::add_balance(double amount, int id) {
      this->balance += amount; 
  }

  void Account::withdraw_balance(double amount, int id) {
    this->balance -= amount;
  }

  double Account::get_balance(void) const {
    return balance;
  }

};