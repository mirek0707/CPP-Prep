/*
  Celm zadania jest napisanie wektora. 
  Troche specjalne jest w tym wektorze to, ze jest on adresowany indeksami
  w dowolnym zakesie liczb calkowitcyh. Np. od 5 do 10, od -200, -100, itp.
  Wektor ma operator [] aby umozliwic semantyke podobna do zwyklych tablic z C.
  Nalezy rowniez przeladowac operator << sluzacy do wypisywania wektora.
  
  UWAGA: Nie trzeba obslugiwac zlego uzycia tego wektora
  UWAGA: Aby obliczyc indeks w rzeczywistej tablicy (to jest od 0) 
         wystarczy odejmowac od przkazanago indeksu wartosc begin()!!! 
  UWAGA: Operatory, tak jak i metody, moga miec dwa warianty const i "nie-const".
  UWAGA: Moze byc potrzebne napisanie dodatkowych metod pomocniczych.

  Ostateczny program powinien byc przyjazny dla programisty (miec
  czytelny i dobrze napisany kod, a takze dokumentacje).
   
  Pliku main.cpp nie wolno modyfikowac (oczywiście w trakcie pracy można sobie
  komentować fragmenty).

  CMakeLists.txt dolaczony do rozwiazania powinien tworzyc plik wykonywalny
  o nazwie CPPLab.
  Program nalezy kompilowac z flagami -Wall -g.
  Prosze zadbac o dobre zarzadzanie pamiecia.

  Przy wykonaniu zadania nie wolno korzystać z internetu, notatek,
  ani żadnych innych materiałów (w tym własnych wcześniej
  przygotowanych plików)

  Rozwiązanie (archiwum zip) należy przesłać na UPeL do godziny 9:30
  (po 9:30 nie bedzie mozliwosci doslania rozwiazania).
 */
#include <iostream>
#include "FVec.h"

int gen(const int n){

  return n+2;
}

int main() {

  std::cout << "Wektor 5 elementowy indeksowany od 0 do 4" << std::endl;
  FVec a = FVec::create(5);
  a[0] =7;
  a[1] =6;
  a.set(2,5).set(3,-1);  
  std::cout << "Wektor a:" <<  a << std::endl;
  FVec& aref = a;
  std::cout << "aref[2]: " << aref[2] << std::endl;
  
  std::cout << "Wektor o indeksach -2, -1, 0, 1" << std::endl;
  FVec b(-2, 2); 
  for ( int i = b.begin(); i < b.end(); ++i ){
    b[i] = i;
  }  
  b[-1] = -4;
  b[-2] = -44;
  std::cout << "Wektor b:" << b << std::endl; 

  const FVec c = b;
  b = a; 
  std::cout << "Wektor c:" << c << std::endl; 
  std::cout << "Wektor b:" << b << std::endl; 

  const FVec d(-10, 0);
  std::cout << "Wektor d:" << d << std::endl; 

  const FVec e = std::move(b);
  std::cout << "Wektor e:" << e << std::endl; 

  const FVec f();

  const FVec g = FVec(gen,3);
  std::cout << "Wektor g:" << g << std::endl; 
  //Odkomentowanie ponizszych lini powinno wyrzucic blad kompilacji. Brak spelnienia
  //tego wymagania oznacza -1 pkt. za kazda linie.*/
  //FVec a1(5);
  //FVec a2;

}
/* output:
 
Wektor 5 elementowy indeksowany od 0 do 4
Wektor a:idx[0,5] 7 6 5 -1 0
aref[2]: 5
Wektor o indeksach -2, -1, 0, 1
Wektor b:idx[-2,2] -44 -4 0 1
Wektor c:idx[-2,2] -44 -4 0 1
Wektor b:idx[0,5] 7 6 5 -1 0
Wektor d:idx[-10,0] 0 0 0 0 0 0 0 0 0 0
Wektor e:idx[0,5] 7 6 5 -1 0
Wektor g:idx[0,3] 2 3 4

 */
