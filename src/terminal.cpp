#include "terminal.h"
#include "terminalServer.h"

namespace Banking {

  Terminal::Terminal(TerminalServer * terminalServer) {
    _server = terminalServer;
  }

  void Terminal::payment(double amount,  Account * account, Account * to_account) {
    // the terminal forwards the payment to the terminal server and prints the result to the terminal screen.
    int payment = _server->payment(amount, account, to_account);
    printf("€ %.2f van %s -> %s \n%s balance is %.2f, %s balance is %.2f\n", amount, account->name.c_str(), to_account->name.c_str(), account->name.c_str(), account->get_balance(), to_account->name.c_str(), to_account->get_balance());
  }
};
