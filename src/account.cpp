#include "account.h"
#include "bank.h"
#include <string>

namespace Banking {

  Account::Account(std::string name, double balance, Bank * bank) {
    this->name = name;
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