#pragma once
#include "bank.h"

namespace Banking {

  class Account {

    // Methods
    public:
      Account(double balance, Bank * bank);
      void add_balance(double amount, int id);
      void withdraw_balance(double amount, int id);

    public:
      double get_balance(void) const;

    // Attributes (instance variables)
    private:
      double balance = 0;
      Bank * _bank;

  };

};