// Nazwa pliku wykonywalnego: Lista

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// UWAGA
// Do rozwiazania zadanie nie wolno wykorzystywac nic z biblioteki
// standardowej oprocz cout i endl

// Prosze napisac szablon listy (ktory dzialal jak lista) w ktorej
// bedzie mozna przechowywal wskazniki na obiekty tego samego typu i
// ktory bedzie dalo sie wykorzystac dla dowolnego typu wskaznikow.

// UWAGA
// Prosze zwrocic uwage na zarzadzanie pamiecia.

// Pliku Main.cpp nie wolno modyfikowac.

// Komentarze w kodzie informuja jaki tekst na ekranie wypisuje dana
// linia kodu.

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


#include<iostream>

#include"list"
#include"list"

int main ()
{

  std::cout<<"===== PRIMES =====\n"; // ===== PRIMES =====
  agh::list<int*> integers;
  integers.push_back(new int (1));
  integers.push_back(new int (2));
  integers.push_back(new int (3));
  integers.push_back(new int (5));
  integers.push_back(new int (7));
  integers.push_back(new int (11));

  std::cout<<"--- Print list ---\n"; // --- Print list ---
  integers.print();   // 1, 2, 3, 5, 7, 11

  std::cout<<"--- Loop print ---\n"; // --- Loop print ---
  const agh::list<int*>::iterator integersEnd = integers.end();
  for (agh::list<int*>::iterator integersIter = integers.begin(); integersIter != integersEnd; ++integersIter)
    std::cout<<**integersIter<<"\n";


  std::cout<<"\n===== STRINGS =====\n"; // ===== STRINGS =====
  agh::list<std::string*> strings;
  strings.push_back(new std::string ("guitar"));
  strings.push_back(new std::string ("violin"));
  strings.push_back(new std::string ("harp"));
  strings.push_back(new std::string ("cello"));
  strings.push_back(new std::string ("piano"));
  strings.push_back(new std::string ("lyre"));

  std::cout<<"--- Print list ---\n"; // --- Print list ---
  strings.print();    // guitar, violin, harp, cello, piano, lyre

  std::cout<<"--- Loop print ---\n"; // --- Loop print ---
  const agh::list<std::string*>::iterator stringsEnd = strings.end();
  agh::list<std::string*>::iterator stringsIter = strings.begin();
  do {
    std::cout<<**stringsIter<<"\n";
  } while (++stringsIter != stringsEnd);


  std::cout<<"\n===== UNORDERED =====\n"; // ===== UNORDERED =====
  agh::list<int*> integersDifferent;
  integersDifferent.push_back(new int (3));
  integersDifferent.push_back(new int (2));
  integersDifferent.push_back(new int (1));
  integersDifferent.push_back(new int (11));
  integersDifferent.push_back(new int (5));
  integersDifferent.push_back(new int (7));

  std::cout<<"Print list\n";  // Print list
  integersDifferent.print();  // 3, 2, 1, 11, 5, 7
  
  return 0;
}
/*
===== PRIMES =====
--- Print list ---
1, 2, 3, 5, 7, 11
--- Loop print ---
1
2
3
5
7
11
===== STRINGS =====
--- Print list ---
guitar, violin, harp, cello, piano, lyre
--- Loop print ---
guitar
violin
harp
cello
piano
lyre
===== UNORDERED =====
Print list
3, 2, 1, 11, 5, 7
*/