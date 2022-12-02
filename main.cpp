#include "mbed.h"
#include "rtos.h"
#include <chrono>

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

    return 0;
}