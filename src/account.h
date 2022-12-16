#pragma once
#include "bank.h"
#include <string>

namespace Banking {

  class Bank;

  class Account {

    // Methods
    public:
      Account(std::string name, double balance, Bank * bank);
      void add_balance(double amount);
      void withdraw_balance(double amount);
      void append_credit(double amount);
      void clear_credit(void);

    public:
      double get_balance(void);
      double get_credit(void);

    // Attributes (instance variables)
    public:
      Bank * bank;
      std::string name;

    private:
      double balance = 0;
      double credit_to_add = 0;

  };

};