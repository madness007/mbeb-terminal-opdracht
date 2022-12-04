#include "terminalServer.h"
#include "mbed.h"
#include "rtos.h"

namespace Bank {

  TerminalServer::TerminalServer() {
    this->_sem = rtos::Semaphore(2);
  }

};
