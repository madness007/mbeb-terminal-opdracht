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

Banking::Account jan("Jan", 1000, &kbc);
Banking::Account jef("Jef", 1500, &kbc);
Banking::Account jos("Jos", 50, &kbc);
Banking::Account mark("Mark", 100000000, &kbc);
Banking::Account jeanine("Jeanine", 10000, &kbc);

Banking::Account willy("Willy", 100000000, &belfius);
Banking::Account john("John", 785, &belfius);
Banking::Account jacky("Jacky", -500, &belfius);
Banking::Account charles("Charles", 1000000, &belfius);
Banking::Account piet("Piet", 15000, &belfius);

Banking::Account casino("Casino", 100000, &kbc);

//terminal 1
void casino_terminal() {
  printf("%s balance is %.2f\n", jan.name.c_str(), jan.get_balance());
  printf("%s balance is %.2f\n", casino.name.c_str(), casino.get_balance());
  terminal1.payment(100, &jan, &casino);
  printf("%s balance is %.2f\n", jan.name.c_str(), jan.get_balance());
  printf("%s balance is %.2f\n", casino.name.c_str(), casino.get_balance());

    
}

int main(void) {
    casino_terminal();
    // Banking::Account jan(50, &kbc);
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
    // Banking::Account jan(50, &kbc);
    // jan.add_balance(20);
    // jan.add_balance(50);
    // printf("jan balance is %.2f\n", jan.get_balance());
    // jan.withdraw_balance(3.99);
    // printf("jan balance is %.2f\n", jan.get_balance());
    



    return 0;
}