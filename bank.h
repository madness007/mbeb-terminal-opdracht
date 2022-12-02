#pragma once

namespace Bank {

  class Validation {

    // Methods
    public:
      void propose_payment(double amount, int id, int to_id);
      void complete_payment(void);

    public:
      bool get_isValid(void) const;

    // Attributes (instance variables)
    private:
      double amount = 0;
      int id;
      int to_id;

  };

};
