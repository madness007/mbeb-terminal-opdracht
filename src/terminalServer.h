#pragma once
#include "mbed.h"
#include "rtos.h"
#include "account.h"

namespace Banking {

  class TerminalServer {

    // Methods
    public:
      TerminalServer();
      void payment(double amount,  Account * account, Account * to_account);

    public:
      bool get_isValid(void) const;

    // Attributes (instance variables)
    private:
        //semaphore needs to be initialised in constructoor
        // this semaphore is for the max of 2 connections.
        rtos::Semaphore _sem;

  };

};
