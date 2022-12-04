#include "mbed.h"
#include "rtos.h"
#include <chrono>
#include "bank.h"
#include "account.h"
#include "terminal.h"
#include "terminalServer.h"

rtos::Thread thr_terminalServer1;
rtos::Thread thr_terminalServer2;
rtos::Thread thr_terminalServer3;
rtos::Thread thr_belfius;
rtos::Thread thr_kbc;

Banking::Bank kbc("kbc");
Banking::Bank belfius("belfius");

Banking::TerminalServer terminalServer2;
Banking::TerminalServer terminalServer3;
Banking::TerminalServer terminalServer1;

Banking::Terminal terminal1(&terminalServer1);
Banking::Terminal terminal2(&terminalServer1);
Banking::Terminal terminal3(&terminalServer1);
Banking::Terminal terminal4(&terminalServer2);
Banking::Terminal terminal5(&terminalServer2);
Banking::Terminal terminal6(&terminalServer2);
Banking::Terminal terminal7(&terminalServer3);
Banking::Terminal terminal8(&terminalServer3);
Banking::Terminal terminal9(&terminalServer3);

//terminal 1
// void casino() {
//     sleep random 1 5min
//     jan 1000euro
// }

int main(void) {

    // Banking::Bank kbc; // Betalingsvalidatie testen (mag dan gebruikt worden in een andere class als dit af is)
    // kbc.propose_payment(39.99, 1234, 4555);
    // if (kbc.get_isValid()) {
    //     printf("Betaling goedgekeurd.\n\r");
    // } else {
    //     printf("Saldo ontoereikend.\n");
    // }

    // kbc.propose_payment(89.99, 1234, 4555);
    // if (kbc.get_isValid()) {
    //     printf("Betaling goedgekeurd.\n\r");
    // } else {
    //     printf("Saldo ontoereikend.\n");
    // }

    // testen van account class
    Banking::Account jan(50, &kbc);
    jan.add_balance(20, 1);
    jan.add_balance(50, 1);
    printf("jan balance is %.2f\n", jan.get_balance());
    jan.withdraw_balance(3.99, 1);
    printf("jan balance is %.2f\n", jan.get_balance());
    



    return 0;
}