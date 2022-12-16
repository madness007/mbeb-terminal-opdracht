#include "mbed.h"
#include "rtos.h"
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include "bank.h"
#include "account.h"
#include "terminal.h"
#include "terminalServer.h"

rtos::Thread thr_terminal1;
rtos::Thread thr_terminal2;
rtos::Thread thr_terminal3;
rtos::Thread thr_terminal4;
rtos::Thread thr_terminal5;
rtos::Thread thr_terminal6;
rtos::Thread thr_terminal7;
rtos::Thread thr_terminal8;
rtos::Thread thr_terminal9;
rtos::Thread thr_kbc;
rtos::Thread thr_belfius;
rtos::Thread thr_klok;

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
Banking::Account mark("Mark Coucke", 100000000, &kbc);
Banking::Account jeanine("Jeanine", 10000, &kbc);

Banking::Account willy("Willy Naessens", 100000000, &belfius);
Banking::Account john("John", 785, &belfius);
Banking::Account jacky("Jacky", 500, &belfius);
Banking::Account charles("Charles", 1000000, &belfius);
Banking::Account piet("Piet", 15000, &belfius);

Banking::Account casino("Casino", 100000, &kbc);
Banking::Account bakker("Bakkerij Bollaert", 100000, &kbc);
Banking::Account bordeel("Night-Rider", 10000, &kbc);
Banking::Account pizzahut("Pizza-Hut", 100000, &belfius);
Banking::Account frietkot("Frida Kroket", 10000, &kbc);
Banking::Account waterbeer("De Waterbeer", 100000, &kbc);
Banking::Account prowifi("Arno Schoutteten", 10000, &belfius);

//terminal 1
void casino_terminal() {
  // terminal.payment(amount, from, to)
  ThisThread::sleep_for(chrono::seconds(rand()%5));
  terminal1.payment(rand() % 100 + 50, &jan, &casino);
  ThisThread::sleep_for(chrono::seconds(rand()%5));
  terminal1.payment(rand() % 200 + 50, &jef, &casino);
  ThisThread::sleep_for(chrono::seconds(rand()%5));
  terminal1.payment(rand() % 200 + 50, &jef, &casino);
  

}

void bakker_terminal() {
  ThisThread::sleep_for(chrono::seconds(rand()%5));
  terminal2.payment(rand() % 9 + 1.99, &jeanine, &bakker);
  ThisThread::sleep_for(chrono::seconds(rand()%5));
  terminal2.payment(rand() % 9 + 1.99, &mark, &bakker);
  ThisThread::sleep_for(chrono::seconds(rand()%5));
  terminal2.payment(rand() % 9 + 1.99, &charles, &bakker);
}

void bordeel_terminal() {
  ThisThread::sleep_for(chrono::seconds(rand()%5));
  terminal3.payment(rand() % 200 + 600, &willy, &bordeel);
  ThisThread::sleep_for(chrono::seconds(rand()%5));
  terminal3.payment(rand() % 200 + 800, &mark, &bordeel);
  ThisThread::sleep_for(chrono::seconds(rand()%5));
  terminal3.payment(rand() % 200 + 100, &piet, &bordeel);
  ThisThread::sleep_for(chrono::seconds(rand()%5));
  terminal3.payment(1300, &bordeel, &jeanine);
  ThisThread::sleep_for(chrono::seconds(rand()%5));

}

void pizzahut_terminal() {
  terminal4.payment(rand() % 10 + 8.99, &jan, &pizzahut);
  ThisThread::sleep_for(chrono::seconds(rand()%5));
  terminal4.payment(rand() % 10 + 8.99, &jef, &pizzahut);
  ThisThread::sleep_for(chrono::seconds(rand()%5));
  terminal4.payment(rand() % 10 + 8.99, &jacky, &pizzahut);
  ThisThread::sleep_for(chrono::seconds(rand()%5));
  terminal4.payment(rand() % 10 + 8.99, &jeanine, &pizzahut);
  ThisThread::sleep_for(chrono::seconds(rand()%5));
  terminal4.payment(rand() % 10 + 8.99, &charles, &pizzahut);
  ThisThread::sleep_for(chrono::seconds(rand()%5));
  terminal4.payment(500, &pizzahut, &jos);

}

void vis_terminal() {
    terminal5.payment(rand() % 10 + 8.99, &piet, &jef);
    ThisThread::sleep_for(chrono::seconds(rand()%5));
    terminal5.payment(rand() % 10 + 8.99, &jan, &jef);
    ThisThread::sleep_for(chrono::seconds(rand()%5));
    terminal5.payment(rand() % 10 + 8.99, &mark, &jef);
    ThisThread::sleep_for(chrono::seconds(rand()%5));
    

}


void vlees_terminal() {
    terminal6.payment(rand() % 10 + 8.99, &piet, &charles);
    ThisThread::sleep_for(chrono::seconds(rand()%5));
    terminal6.payment(rand() % 10 + 8.99, &jan, &charles);
    ThisThread::sleep_for(chrono::seconds(rand()%5));
    terminal6.payment(rand() % 10 + 8.99, &mark, &charles);
    ThisThread::sleep_for(chrono::seconds(rand()%5));
    

}

void frietkot_terminal() {
    terminal7.payment(rand() % 10 + 8.99, &charles, &frietkot);
    ThisThread::sleep_for(chrono::seconds(rand()%5));
    terminal7.payment(rand() % 10 + 8.99, &jef, &frietkot);
    ThisThread::sleep_for(chrono::seconds(rand()%5));
    terminal7.payment(rand() % 10 + 8.99, &willy, &frietkot);
    ThisThread::sleep_for(chrono::seconds(rand()%5));

}

void waterbeer_terminal() {
    terminal8.payment(rand() % 100 + 400, &mark , &waterbeer);
    ThisThread::sleep_for(chrono::seconds(rand()%10));
    terminal8.payment(rand() % 100 + 400, &willy, &waterbeer);
    ThisThread::sleep_for(chrono::seconds(rand()%10));

}

void prowifi_terminal() {
    terminal9.payment(rand() % 50 + 175, &jeanine, &prowifi);
    ThisThread::sleep_for(chrono::seconds(rand()%10));
    terminal9.payment(rand() % 50 + 175, &frietkot, &prowifi);
    ThisThread::sleep_for(chrono::seconds(rand()%10));
    

}

void klok() {
    // 24u klok in 5 minuten simuleren:
    // Meeste betalingen tussen 7u en 20u
    // Overzetting geld tussen banken: 20u - 7u
    uint8_t clock = 0;
    while (true)
    {
      switch (clock) {
      case 22:
      printf("het is 22 uur");
        thr_kbc.start(kbc.handle_payments);
        thr_belfius.start(belfius.handle_payments);
        break;
      }
      ThisThread::sleep_for(1s);
      printf("%d:00\n\r", clock);
      clock++;
      clock = clock %24;
    }
}

int main(void) {

    // thr_terminal1.start(casino_terminal);
    // thr_terminal2.start(bordeel_terminal);
    // thr_terminal3.start(pizzahut_terminal);
    // thr_terminal4.start(bakker_terminal);
    // thr_terminal5.start(vis_terminal);
    // thr_terminal6.start(vlees_terminal);
    // thr_terminal7.start(frietkot_terminal);
    // thr_terminal8.start(waterbeer_terminal);
    // thr_terminal9.start(prowifi_terminal);
    thr_klok.start(klok);
    

    return 0;
}