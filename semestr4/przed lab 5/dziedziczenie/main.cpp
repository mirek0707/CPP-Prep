/*
 Celem zadania jest napisanie kilku klas zwiazanych relacja
 dziedziczenia. Klasy te opisuja elementarne ksztalty. Kazdy ksztalt
 posiada jakies polimorficzne metody i konieczna infrastrukture.
 
 Kompilwac z opcjami -Wall -g do pliku stest
 UWAGA: Przed rozpoczeciem pisania prosze przeczytac zadanie do konca.
 UWAGA: W tym zadaniu: PI to 3.1415. Wzor na pole trojkata: sqrt( x(x-a)(x-b)(x-c) ) 
 gdzie "x" to polowa obwodu trojkata.
*/

#include <iostream>
#include "Kwadrat.h"
#include "Kolo.h"
#include "Trojkat.h"

int main() {
  Kwadrat k(4);
  Trojkat t(3,2,4);
  const Kolo    ko(3);

  Ksztalt::wypisz(k); // Kwadrat o boku: 4
  Ksztalt::wypisz(t); // Trojkat o bokach: 3 2 4
  Ksztalt::wypisz(ko);// Kolo o promieniu: 3

  Ksztalt* b = new Kwadrat(7);
  Ksztalt::wypisz(*b);
  delete b;
  b = new Kolo(7);
  Ksztalt::wypisz(*b);
  delete b;

  const Ksztalt* wszystkie[] = { &k, &k, &ko, &t, &ko };
  const int rozmiar = sizeof(wszystkie)/sizeof(Ksztalt*);
  double pole_calkowite = 0.0;
  for ( int idx = 0; idx < rozmiar; ++idx ) {
    const Ksztalt* k = wszystkie[idx];
    k->wypisz(std::cout);
    double pole = k->polePow();
    std::cout << " - pole = " << pole << std::endl;
  
    pole_calkowite += pole;
  }
  std::cout << "Calkowite pole = " << pole_calkowite << std::endl;
  
}

/* wynik
Kwadrat o boku: 4
Trojkat o bokach: 3 2 4
Kolo o promieniu: 3
Kwadrat o boku: 7
Kolo o promieniu: 7
Kwadrat o boku: 4
 - pole = 16
Kwadrat o boku: 4
 - pole = 16
Kolo o promieniu: 3
 - pole = 28.2735
Trojkat o bokach: 3 2 4
 - pole = 2.90474
Kolo o promieniu: 3
 - pole = 28.2735
Calkowite pole = 91.4517
*/