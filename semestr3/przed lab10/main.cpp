// Nazwa pliku wykonywalnego: Rational

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klase Rational reprezentujacą liczby wymierne (licznik/mianownik).
// Dodatkowo, proszę zaimplementować metody, funkcje działające na liczbach typu Rational.
// Metody te mogą być zaimplementowane w ramach klasy Fun;

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod).

// Makefile (lub CMakelLists.txt) dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Rational. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Kody zrodlowe musza znajdowac sie w katalogu (preoop) do ktorego nikt oprocz
// wlasciciela nie ma praw dostepu.

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy wgrac
// do UPEL

#include <iostream>
#include <cmath>
#include "Rational.h"

int main() {

  Rational Raz(1, 2);
  Raz.Print();

  const Rational Dwa(2, 3);
  Dwa.Print();
  

  const Rational Trzy = Fun::Add(Dwa,Dwa);
  Trzy.Print();

  Rational Wynik1 = Fun::Multiply(Raz, Dwa);
  Wynik1.Print();


  Rational Wynik2 = Fun::Add(Raz, 5);
  Wynik2.Print();

  Rational Wynik3 = Fun::Divide(10, Dwa);
  Wynik3.Print();

  float Wynik4 = std::sqrt(Wynik3);
  std::cout<< Wynik4 << std::endl;

  Fun::Average(Raz);
  Fun::Average(Dwa);
  std::cout << "Average: " << float(Fun::Average()) <<std::endl;
  


  return 0;
}
/** Wynik dzialania programu:
1/2
2/3
4/3
2/6
11/2
30/2
3.87298
Average: 0.583333
*/