#pragma once
#include "bank.h"

namespace Banking {

  class Bank;

  class Account {

    // Methods
    public:
      Account(double balance, Bank * bank);
      void add_balance(double amount);
      void withdraw_balance(double amount);

    public:
      double get_balance(void) const;

    // Attributes (instance variables)
    public:
      Bank * bank;

    private:
      double balance = 0;

  };

};