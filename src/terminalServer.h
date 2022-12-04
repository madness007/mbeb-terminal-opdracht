#pragma once
#include "mbed.h"
#include "rtos.h"
#include "account.h"

namespace Banking {

  class TerminalServer {

    // Methods
    public:
      TerminalServer();
      int payment(double amount,  Account * account, Account * to_account);

    public:
      bool get_isValid(void) const;

    // Attributes (instance variables)
    private:
      rtos::Semaphore _sem;

  };

};
