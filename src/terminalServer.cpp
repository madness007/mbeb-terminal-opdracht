#include "terminalServer.h"
#include "mbed.h"
#include "rtos.h"
#include "account.h"

namespace Banking {

  TerminalServer::TerminalServer() : _sem(2) {
      
  }

  void TerminalServer::payment(double amount,  Account * account, Account * to_account) {
    _sem.acquire();
    account->bank->payment(amount, account, to_account);
    _sem.release();
  }

};
