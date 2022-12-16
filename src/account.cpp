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

  void Account::append_credit(double amount) {
    this->credit_to_add += amount;
  }

  double Account::get_balance(void) {
    return balance;
  }

  double Account::get_credit(void) {
    return credit_to_add;
  }

  void Account::clear_credit(void) {
    credit_to_add = 0;
  }

};