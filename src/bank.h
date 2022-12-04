#pragma once
#include "mbed.h"
#include "rtos.h"
#include "account.h"
#include <string>

namespace Banking {

  class Account;

  class Bank {

    // Methods
    public:
      Bank(std::string bankname);
      int payment(double amount, Account * account, Account * to_account);

    private:
      int get_isValid(double amount, Account * account);

    // Attributes (instance variables)
    private:
      std::string _bankname;
      rtos::Semaphore _sem;
      

  };

};
