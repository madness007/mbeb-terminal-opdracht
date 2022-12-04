#pragma once
#include <string>

namespace Banking {

  class Bank {

    // Methods
    public:
      Bank(std::string bankname);
      void propose_payment(double amount, int id, int to_id);
      void complete_payment(void);

    public:
      bool get_isValid(void) const;

    // Attributes (instance variables)
    private:
      double amount = 0;
      int id;
      int to_id;
      std::string _bankname;

  };

};
