#include <mbed.h>


Thread thr_clock;
// Thread thr_betaalterminal;
// Thread thr_bancontact;
// Thread thr_belfius;
// Thread thr_bank1;

// | Thread | OOP            |
// |--------|----------------|
// | Klok   | Betaalterminal |
// |        | Bancontact     |
// |        | Bank           |

 

void klok() {
    // 24u klok in 5 minuten simuleren:
    // Meeste betalingen tussen 7u en 20u
    // Overzetting geld tussen banken: 20u - 7u
    uint8_t clock = 0;
    while (true)
    {
        if (clock < 24) {
            printf("%d:00\n\r", clock); // Als het klaar is niet meer printen
            ThisThread::sleep_for(1s);
            clock++;
        } else {
            clock = 0;
        }
    }
}

// void betaling() { // in OOP class
// // Hier betaalt de consument, automatisch komt er "Even geduld" na betaling:
// // --- Betaling wordt verstuurd naar Bancontact server
// // --- Wachten op antwoord van Bancontact server
    
// }

// void bancontact_server(){ // in OOP class
// // Bancontact verwerkt de betaling: 
// // --- Stuurt betaalpropositie door naar de bank
// // --- wacht op antwoord van bank: betaling goedgekeurd/afgekeurd
// // --- Stuurt terug naar terminal: Verwerkt/saldo ontoereikend
    
// }

// void kbc(){ // in OOP class
// // Ontvangt betaalpropositie van Bancontact:
// // --- Als account van betaler genoeg geld heeft, betaling accepteren en geld aftrekken
// // --- Stuur naar Bancontact wanneer de betaling is goedgekeurd of afgekeurd.
// // --- Afgetrokken geld van consument doorsturen naar bank van verkoper:
// // --- --- hebben ze dezelfde bank?: instant
// // --- --- Andere bank?: s'nachts doorsturen

// void belfius(){
// // = kbc
// }

int main() {
    // thr_betaalterminal.start(betaling);
    // thr_bancontact.start(bancontact_server);
    thr_clock.start(klok);


    return 0;
}