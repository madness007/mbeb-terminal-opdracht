#include "terminalServer.h"
#include "mbed.h"
#include "rtos.h"
#include "account.h"

namespace Banking {

  TerminalServer::TerminalServer() : _sem(2) {
      
  }

  void payment(double amount,  Account * account, Account * to_account) {
      account->bank->payment(amount, account, to_account);
  }

};
