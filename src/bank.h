#pragma once
#include "mbed.h"
#include "rtos.h"
#include "account.h"
#include <string>
#include <vector>

namespace Banking {

  class Account;

  class Bank {

    // Methods
    public:
      Bank(std::string bankname);
      int payment(double amount, Account * account, Account * to_account);
      void payment_transfer(double amount,  Account * account, Account * to_account);
      void handle_payments(void);

    private:
      int get_isValid(double amount, Account * account);

    // Attributes (instance variables)
    public:
      std::string bankname;
      vector<Account *> _vector;
    private:
      rtos::Semaphore _sem;

      

  };

};
