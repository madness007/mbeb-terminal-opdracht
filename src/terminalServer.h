#pragma once
#include "mbed.h"
#include "rtos.h"

namespace Bank {

  class TerminalServer {

    // Methods
    public:
      TerminalServer();

    public:
      bool get_isValid(void) const;

    // Attributes (instance variables)
    private:
        //semaphore needs to be initialised in constructoor
        // this semaphore is for the max of 2 connections.
        rtos::Semaphore _sem;

  };

};
