// Nazwa pliku wykonywalnego: SmartPointer

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze zaimplementować szablon UniquePointer, ktory bedzie przechowywal adres
// obiektu. Moze istniec tylko jeden obiekt przechowujacy ten sam
// adres. Gdy obiekt typu UniqeuPointer jest niszczony, niszczony
// powinien byc rowniez obiekt na ktory wskazuje.

// UWAGA
// W zadaniu bardzo wazne jest zarzadzanie pamiecia.

// Pliku Main.cpp, nie wolno modyfikowac.

// Komentarz w kodzie mowia jakie wyjscie powinna generowac dana
// linia.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Fraction. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy
// wgrac do UPEL.

#include"Main.h"
#include<iostream>

void AddToInt (int* val){ *val += 2; }

int main ()
{
  using namespace std;

  std::cout<<"===== INTEGER =====\n";
  UniquePointer<int> dynamicInt1 = new int (4);
  std::cout<<"pointer: "<<dynamicInt1<<"\n";    // pointer: [pointing to <adres>]
  std::cout<<"  value: "<<*dynamicInt1<<"\n";   //   value: 4
  
  {
    
    std::cout<<"\n---- entering new scope ---- \n";
    UniquePointer<int> dynamicInt2 = dynamicInt1;
    std::cout<<"pointer: "<<dynamicInt1<<"\n";  // pointer: [pointing to 0]   
    std::cout<<"pointer: "<<dynamicInt2<<"\n";  // pointer: [pointing to <adres>]
    std::cout<<"  value: "<<*dynamicInt2<<"\n"; //   value: 4
    
    UniquePointer<int> dynamicInt3 = new int (6);
    cout<<"pointer: "<<dynamicInt3<<"\n";   //  pointer: [pointing to <adres>]
    cout<<"  value: "<<*dynamicInt3<<"\n";  //    value: 6
    AddToInt (dynamicInt3);
    cout<<"Add two: "<<*dynamicInt3<<"\n";  // Add two: 8
    
    dynamicInt3 = dynamicInt2 = dynamicInt2;
    cout<<"EQUAL: "<<"\n";                            //  EQUAL:
    cout<<"pointer: "<<dynamicInt1<<"\n";             //  pointer: [pointing to 0]
    cout<<"pointer: "<<dynamicInt2<<"\n";             //  pointer: [pointing to 0]
    cout<<"pointer: "<<dynamicInt3<<"\n";             //  pointer: [pointing to <adres>]
    cout<<"  value: "<<*dynamicInt3<<"\n";            //    value: 4
    std::cout<<" ---- end of scope ---- \n\n";
    
  }

  std::cout<<"===== FLOAT =====\n";
  UniquePointer<float> dynamicFloat = new float (3.5);
  std::cout<<"pointer: "<<dynamicFloat<<"\n";    // pointer: [pointing to <adres>]
  std::cout<<"  value: "<<*dynamicFloat<<"\n";   //   value: 3.5
  
  return 0;
}


/*
===== INTEGER =====
pointer: [pointing to <adres>]
  value: 4
---- entering new scope ---- 
pointer: [pointing to 0]
pointer: [pointing to <adres>0]
  value: 4
pointer: [pointing to <adres>]
  value: 6
Add two: 8
EQUAL: 
pointer: [pointing to 0]
pointer: [pointing to 0]
pointer: [pointing to <adres>]
  value: 4
 ---- end of scope ---- 
===== FLOAT =====
pointer: [pointing to <adres>]
  value: 3.5
 */