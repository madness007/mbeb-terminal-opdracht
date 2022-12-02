#pragma once

namespace Bank {

  class Account {

    // Methods
    public:
      void create_account(int id);
      void set_balance(double amount, int id);
      void add_balance(double amount, int id);
      void withdraw_balance(double amount, int id);

    public:
      double get_balance(void) const;
      int get_id(void) const; // deze werkt hier nog niet zo goed

    // Attributes (instance variables)
    private:
      double balance = 0;
      int id;

  };

};