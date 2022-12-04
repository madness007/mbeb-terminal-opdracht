#pragma once
#include "terminalServer.h"

namespace Banking {

  class Terminal {

    // Methods
    public:
      // set the terminalserver on initialisation
      Terminal(TerminalServer * terminalServer);

      void payment(double amount, int id, int to_id);

    public:

    // Attributes (instance variables)
    private:
      TerminalServer * _server;

  };

};
