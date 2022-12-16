#include "mbed.h"
#include "rtos.h"
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include "bank.h"
#include "account.h"
#include "terminal.h"
#include "terminalServer.h"

#define FLAG_WATERBEER    (1UL << 0)
#define FLAG_BAKKER    (1UL << 1)
#define FLAG_VIS    (1UL << 2)
#define FLAG_VLEES    (1UL << 3)
#define FLAG_PIZZAHUT    (1UL << 4)
#define FLAG_FRIETKOT    (1UL << 5)
#define FLAG_PROWIFI    (1UL << 6)
#define FLAG_CASINO    (1UL << 7)
#define FLAG_BORDEEL    (1UL << 8)

EventFlags      event_flags;

rtos::Thread thr_terminal1;
rtos::Thread thr_terminal2;
rtos::Thread thr_terminal3;
rtos::Thread thr_terminal4;
rtos::Thread thr_terminal5;
rtos::Thread thr_terminal6;
rtos::Thread thr_terminal7;
rtos::Thread thr_terminal8;
rtos::Thread thr_terminal9;
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
  while (true) {
    event_flags.wait_all(FLAG_CASINO);
    // terminal.payment(amount, from, to)
    ThisThread::sleep_for(chrono::seconds(rand()%5));
    terminal1.payment(rand() % 100 + 50, &jan, &casino);
    ThisThread::sleep_for(chrono::seconds(rand()%5));
    terminal1.payment(rand() % 200 + 50, &jef, &casino);
    ThisThread::sleep_for(chrono::seconds(rand()%5));
    terminal1.payment(rand() % 200 + 50, &jef, &casino);
  }
  

}

void bakker_terminal() {
  while (true) {
    event_flags.wait_all(FLAG_BAKKER);
    ThisThread::sleep_for(chrono::seconds(rand()%5));
    terminal2.payment(rand() % 9 + 1.99, &jeanine, &bakker);
    ThisThread::sleep_for(chrono::seconds(rand()%5));
    terminal2.payment(rand() % 9 + 1.99, &mark, &bakker);
    ThisThread::sleep_for(chrono::seconds(rand()%5));
    terminal2.payment(rand() % 9 + 1.99, &charles, &bakker);
  }
}

void bordeel_terminal() {
  while (true) {
  event_flags.wait_all(FLAG_BORDEEL);
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


}

void pizzahut_terminal() {
  while (true) {
  event_flags.wait_all(FLAG_PIZZAHUT);
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
}

void vis_terminal() {
  while (true) {
    event_flags.wait_all(FLAG_VIS);
    terminal5.payment(rand() % 10 + 8.99, &piet, &jef);
    ThisThread::sleep_for(chrono::seconds(rand()%5));
    terminal5.payment(rand() % 10 + 8.99, &jan, &jef);
    ThisThread::sleep_for(chrono::seconds(rand()%5));
    terminal5.payment(rand() % 10 + 8.99, &mark, &jef);
    ThisThread::sleep_for(chrono::seconds(rand()%5));
  }
}

void vlees_terminal() {
  while (true) {
    event_flags.wait_all(FLAG_VLEES);
    terminal6.payment(rand() % 10 + 8.99, &piet, &charles);
    ThisThread::sleep_for(chrono::seconds(rand()%5));
    terminal6.payment(rand() % 10 + 8.99, &jan, &charles);
    ThisThread::sleep_for(chrono::seconds(rand()%5));
    terminal6.payment(rand() % 10 + 8.99, &mark, &charles);
    ThisThread::sleep_for(chrono::seconds(rand()%5));
  }
}

void frietkot_terminal() {
  while (true) {
    event_flags.wait_all(FLAG_FRIETKOT);
    terminal7.payment(rand() % 10 + 8.99, &charles, &frietkot);
    ThisThread::sleep_for(chrono::seconds(rand()%5));
    terminal7.payment(rand() % 10 + 8.99, &jef, &frietkot);
    ThisThread::sleep_for(chrono::seconds(rand()%5));
    terminal7.payment(rand() % 10 + 8.99, &willy, &frietkot);
    ThisThread::sleep_for(chrono::seconds(rand()%5));
  }
}

void waterbeer_terminal() {
  while (true) {
    event_flags.wait_all(FLAG_WATERBEER);
    terminal8.payment(rand() % 100 + 400, &mark , &waterbeer);
    ThisThread::sleep_for(chrono::seconds(rand()%10));
    terminal8.payment(rand() % 100 + 400, &willy, &waterbeer);
    ThisThread::sleep_for(chrono::seconds(rand()%10));
  }

}

void prowifi_terminal() {
  while (true) {
    event_flags.wait_all(FLAG_PROWIFI);
    terminal9.payment(rand() % 50 + 175, &jeanine, &prowifi);
    ThisThread::sleep_for(chrono::seconds(rand()%10));
    terminal9.payment(rand() % 50 + 175, &frietkot, &prowifi);
    ThisThread::sleep_for(chrono::seconds(rand()%10));
  }
}

void klok() {
    // 24u klok in 5 minuten simuleren:
    // Meeste betalingen tussen 7u en 20u
    // Overzetting geld tussen banken: 20u - 7u
    uint8_t clock = 23;
    while (true)
    {
      printf("%d:00\n\r", clock);
      if (clock == 22) {
        printf("het is 22 uur\r\n");
        kbc.handle_payments();
        belfius.handle_payments();
      }
      switch (clock) {
        case 4:
          event_flags.set(FLAG_WATERBEER);
          event_flags.set(FLAG_BAKKER);
        break;
        case 6:
          event_flags.set(FLAG_VIS);
          event_flags.set(FLAG_VLEES);
        break;
        case 17:
          event_flags.set(FLAG_FRIETKOT);
          event_flags.set(FLAG_PIZZAHUT);
        break;
        case 19:
          event_flags.set(FLAG_PROWIFI);
        break;
        case 20:
          event_flags.set(FLAG_CASINO);
          event_flags.set(FLAG_BORDEEL);
        break;
      }

      ThisThread::sleep_for(chrono::milliseconds(12500)); // 1 uur duurt 12.5s
      clock++;
      clock = clock %24;
    }
}

int main(void) {
    thr_klok.start(klok);
    thr_terminal4.start(bakker_terminal);
    thr_terminal8.start(waterbeer_terminal);
    thr_terminal5.start(vis_terminal);
    thr_terminal6.start(vlees_terminal);
    thr_terminal3.start(pizzahut_terminal);
    thr_terminal7.start(frietkot_terminal);
    thr_terminal9.start(prowifi_terminal);
    thr_terminal1.start(casino_terminal);
    thr_terminal2.start(bordeel_terminal);
    
    return 0;
}