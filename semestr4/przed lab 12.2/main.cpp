// Nazwa pliku wykonywalnego: Lokaj

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// UWAGA!
// Przy rozwiazaniu zadania nie wolno korzystac z instrukcji
// warunkowych np. if.

// Prosze napisac klase Pomieszczenie reprezentujaca pomieszczenie,
// ktore mozna sprzatac oraz wstawic cos do niego. Metoda Wstaw ma
// tylko wypisywac tekst na ekran i nie robic nic wiecej. Prosze
// napisac rowniez funkcje Lokaj, ktora wykonuje jedna z czynnosci.

// Pliku Main.cpp, nie wolno modyfikowac.

// Komentarz w kodzie mowia jakie wyjscie powinna generowac dana
// linia.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy
// wgrac do UPEL.


#include"Pomieszczenie.h"
#include"Lokaj.h"


int main ()
{

  Pomieszczenie kuchnia ("kuchnia"); // Tworze pomieszcznie: kuchnia
  kuchnia.zetrzyj_kurze();       // Scieram kurze w pomieszczeniu: kuchnia
  kuchnia.umyj_podloge();      // Myje podloge w pomieszczeniu: kuchnia
  kuchnia.odkurz();        // Odkurzam pomieszczenie: kuchnia

  std::cout<<std::endl;
  
  Pomieszczenie pokoj ("pokoj"); // Tworze pomieszcznie: pokoj
  pokoj.wstaw((char) 113.5);   // Wstawiam q do pomieszczenia: pokoj
  pokoj.wstaw((int) 113.5);  // Wstawiam 113 do pomieszczenia: pokoj
  pokoj.wstaw((float) 113.5);  // Wstawiam 113.5 do pomieszczenia: pokoj
  pokoj.wstaw((double) 113.5);   // Wstawiam 113.5 do pomieszczenia: pokoj
  pokoj.wstaw((unsigned int) 113.5); // Wstawiam 113 do pomieszczenia: pokoj

  std::cout<<std::endl;
  
  Pomieszczenie lazienka ("lazienka"); // Tworze pomieszcznie: lazienka
  lazienka.zetrzyj_kurze();        // Scieram kurze w pomieszczeniu: lazienka
  lazienka.umyj_podloge();         // Myje podloge w pomieszczeniu: lazienka
  lazienka.odkurz();           // Odkurzam pomieszczenie: lazienka

  std::cout<<std::endl;
  
  const Pomieszczenie zamknietaLazienka ("lazienka"); // Tworze pomieszcznie: lazienka
  
  std::cout<<std::endl;
  
  Lokaj<&Pomieszczenie::zetrzyj_kurze>(kuchnia); // Scieram kurze w pomieszczeniu: kuchnia
  Lokaj<&Pomieszczenie::zetrzyj_kurze>(lazienka); // Scieram kurze w pomieszczeniu: lazienka
  Lokaj<&Pomieszczenie::zetrzyj_kurze>(zamknietaLazienka); // Pomieszczenie lazienka jest zamknięte.
  Lokaj<&Pomieszczenie::zetrzyj_kurze>(pokoj);       // Scieram kurze w pomieszczeniu: pokoj

  std::cout<<std::endl;
  
  Lokaj<&Pomieszczenie::umyj_podloge>(pokoj); // Myje podloge w pomieszczeniu: pokoj
  Lokaj<&Pomieszczenie::umyj_podloge>(kuchnia); // Myje podloge w pomieszczeniu: kuchnia
  Lokaj<&Pomieszczenie::umyj_podloge>(lazienka); // Myje podloge w pomieszczeniu: lazienka
  Lokaj<&Pomieszczenie::umyj_podloge>(zamknietaLazienka); // Pomieszczenie lazienka jest zamknięte.

  std::cout<<std::endl;
    
  Lokaj<&Pomieszczenie::odkurz>(lazienka); // Odkurzam pomieszczenie: lazienka
  Lokaj<&Pomieszczenie::odkurz>(kuchnia);  // Odkurzam pomieszczenie: kuchnia
  Lokaj<&Pomieszczenie::odkurz>(pokoj);    // Odkurzam pomieszczenie: pokoj

  std::cout<<std::endl;

  Lokaj<NULL>(pokoj);   // Nic nie robie.
  Lokaj<NULL>(kuchnia);   // Nic nie robie.
  Lokaj<NULL>(lazienka);  // Nic nie robie.
  
  return 0;
}
/*
Tworze pomieszcznie: kuchnia
Scieram kurze w pomieszczeniu: kuchnia
Myje podloge w pomieszczeniu: kuchnia
Odkurzam pomieszczenie: kuchnia
Tworze pomieszcznie: pokoj
Wstawiam q do pomieszczenia: pokoj
Wstawiam 113 do pomieszczenia: pokoj
Wstawiam 113.5 do pomieszczenia: pokoj
Wstawiam 113.5 do pomieszczenia: pokoj
Wstawiam 113 do pomieszczenia: pokoj
Tworze pomieszcznie: lazienka
Scieram kurze w pomieszczeniu: lazienka
Myje podloge w pomieszczeniu: lazienka
Odkurzam pomieszczenie: lazienka
Tworze pomieszcznie: lazienka
Scieram kurze w pomieszczeniu: kuchnia
Scieram kurze w pomieszczeniu: lazienka
Pomieszczenie lazienka jest zamknięte.
Scieram kurze w pomieszczeniu: pokoj
Myje podloge w pomieszczeniu: pokoj
Myje podloge w pomieszczeniu: kuchnia
Myje podloge w pomieszczeniu: lazienka
Pomieszczenie lazienka jest zamknięte.
Odkurzam pomieszczenie: lazienka
Odkurzam pomieszczenie: kuchnia
Odkurzam pomieszczenie: pokoj
Nic nie robie.
Nic nie robie.
Nic nie robie.
*/