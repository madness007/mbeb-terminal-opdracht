#pragma once
#include "terminalServer.h"
#include "account.h"

namespace Banking {

  class Terminal {

    // Methods
    public:
      // set the terminalserver on initialisation
      Terminal(TerminalServer * terminalServer);

      void payment(double amount,  Account * account, Account * to_account);

    public:

    // Attributes (instance variables)
    private:
      TerminalServer * _server;

  };

};
