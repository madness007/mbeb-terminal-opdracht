#pragma once
#include "terminalServer.h"

namespace Bank {

  class Terminal {

    // Methods
    public:
      void payment(double amount, int id, int to_id);
      // set the terminalserver on initialisation
      Terminal(TerminalServer * terminalServer);

    public:

    // Attributes (instance variables)
    private:
      TerminalServer _server;

  };

};
