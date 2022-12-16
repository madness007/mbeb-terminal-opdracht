#include "terminalServer.h"
#include "mbed.h"
#include "rtos.h"
#include "account.h"

namespace Banking {

  TerminalServer::TerminalServer() : _sem(2) {
      
  }

  int TerminalServer::payment(double amount,  Account * account, Account * to_account) {
    // the terminal server forwards the payment to the bank
    _sem.acquire();
    int payment = account->bank->payment(amount, account, to_account);
    _sem.release();
    return payment;
  }

};
