#include "account.h"
#include "bank.h"

namespace Banking {

  Account::Account(double balance, Bank * bank) {
    this->balance = balance;
    this->bank = bank;
  }

  void Account::add_balance(double amount) {
      this->balance += amount; 
  }

  void Account::withdraw_balance(double amount) {
    this->balance -= amount;
  }

  double Account::get_balance(void) const {
    return balance;
  }

};