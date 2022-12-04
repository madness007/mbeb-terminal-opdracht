#include "terminalServer.h"
#include "mbed.h"
#include "rtos.h"

namespace Banking {

  TerminalServer::TerminalServer() : _sem(2) {

  }

};
