// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// !!! UWAGA !!! 
// Przy wykonaniu tego zadania nie wolno korzystac z std::vector

// UWAGA!!!
// Nie wolno uzywac jawnego rzutowania. Uzycie jawnego rzutownia
// bedzie traktowane jak blad kompilacji, czyli 0 punktow.

// UWAGA!!!
// W tym zadaniu nie wolno uzywac mutable. Uzycie tego slowa
// kluczowego oznacza 0 punktow za zadanie.

// UWAGA!!!
// Uzycie const_cast z obiektem const powoduje niezdefiniowane
// dzialanie programu, dlatego w takiej sytuacji nie wolno uzyc
// const_cast.

// Prosze napisac klase Student reprezentujaca informacje o studencie
// i klase StudentsList reprezentujaca liste/tablice
// studentow. Tablice lub listy powinny dostosowywać swój rozmiar do
// ilości elementów w nich zawartych.

// Prosze zwrocic uwage na dobre zarzadzanie pamiecia, zwlaszcza na
// zwolnienie pamieci na koniec programu.

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow. Można użyć wcześniejszego CMakeLists.txt

// Kody zrodlowe musza znajdowac sie w katalogu do ktorego nikt oprocz
// wlasciciela nie ma praw dostepu.

// Rozwiazanie (czyli dodane pliki, CMakeLists.txt i Main.cpp)
// nalezy wgrac do UPEL w formie archiwum, spakowany folder projektu do Lab09.tar.gz

#include<iostream>
#include"Student.h"
#include"StudentsList.h"

int main ()
{
  StudentsList computerScienceList ("Computer science");
  computerScienceList.PrintInfo();
  

  Student* archer = new Student ("Sterling", "Archer");
  archer->Print();
  std::cout << std::endl;

  computerScienceList.AddStudent(archer);
  computerScienceList.AddStudent(new Student("Rick", "Sanchez"));

  const Student* spiegel = new Student ("Spike", "Spiegel");
  computerScienceList.AddStudent(spiegel);

  computerScienceList.PrintList();
  
  return 0;
}
/**
brachwal@vbox:[cmake-build-debug]$ ./studentLists
[StudentsList]: Computer science
Student ID: 1, Name: Sterling, Surname: Archer
[StudentsList]: Computer science
Student ID: 1, Name: Sterling, Surname: Archer
Student ID: 2, Name: Rick, Surname: Sanchez
Student ID: 3, Name: Spike, Surname: Spiegel
*/