#pragma once
#include "account.h"
#include <string>

namespace Banking {

  class Account;

  class Bank {

    // Methods
    public:
      Bank(std::string bankname);
      int payment(double amount, Account * account, Account * to_account);

    private:
      int get_isValid(void) const;

    // Attributes (instance variables)
    private:
      double amount = 0;
      int id;
      int to_id;
      std::string _bankname;
      

  };

};
