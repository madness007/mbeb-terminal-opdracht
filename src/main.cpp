#include "mbed.h"
#include "rtos.h"
#include <chrono>
#include "bank.h"
#include "account.h"

rtos::Thread thr_bancontact1;
rtos::Thread thr_bancontact2;
rtos::Thread thr_bancontact3;
rtos::Thread thr_belfius;
rtos::Thread thr_kbc;


int main(void) {

    Bank::Validation kbc; // Betalingsvalidatie testen (mag dan gebruikt worden in een andere class als dit af is)
    kbc.propose_payment(39.99, 1234, 4555);
    if (kbc.get_isValid()) {
        printf("Betaling goedgekeurd.\n\r");
    } else {
        printf("Saldo ontoereikend.\n");
    }

    kbc.propose_payment(89.99, 1234, 4555);
    if (kbc.get_isValid()) {
        printf("Betaling goedgekeurd.\n\r");
    } else {
        printf("Saldo ontoereikend.\n");
    }

    // testen van account class
    Bank::Account jan;
    jan.create_account(5555);
    jan.add_balance(50, 5555);
    printf("jan balance is %.2f\n", jan.get_balance());
    jan.withdraw_balance(3.99, 5555);
    printf("jan balance is %.2f\n", jan.get_balance());
    



    return 0;
}