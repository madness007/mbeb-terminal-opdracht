#include "mbed.h"
#include "rtos.h"
#include <chrono>
#include "bank.h"
#include "account.h"

rtos::Thread thread1;
rtos::Thread thread2;
rtos::Thread thread3;
rtos::Thread thread4;

rtos::Semaphore _sem(3);
int counter = 0;

void client_work(void) {
    printf("client is working on server\n");
    counter++;
    printf("active clients: %d \n", counter);
    ThisThread::sleep_for(chrono::seconds(rand()%5));
    counter--;
}

void connect(void) {
    _sem.acquire();
    client_work();
    _sem.release();
}

void client() {
    while (true) {
        connect();
        ThisThread::sleep_for(chrono::seconds(rand()%5));
    }
}


int main(void) {
    thread1.start(client);
    thread2.start(client);
    thread3.start(client);
    thread4.start(client);

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