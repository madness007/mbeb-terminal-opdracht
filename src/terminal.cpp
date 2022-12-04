#include "terminal.h"
#include "terminalServer.h"

namespace Banking {

  Terminal::Terminal(TerminalServer * terminalServer) {
    _server = terminalServer;
  }

  void Terminal::payment(double amount,  Account * account, Account * to_account) {
    _server->payment(amount, account, to_account);
  }
};
