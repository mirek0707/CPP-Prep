// Proszę napisać funkcje tworzące i wykonujące operacje na tablicach
// zawierających prosty ciąg liczb o zadanym rozmiarze.

// Nalezy obliczyc 
// - pierwiastek (squareroot)
// - powiększenie wartości o 1 (add_one)
// - potrojoną wartość (tripple)
// w sposób zgodny z wynikiem na końcu programu.

// Proszę zadbać o dobre zarządzanie pamięcią.



#include "Functions.h"
#include <iostream>

int main ()
{
	const int size = 5;      // rozmiar ciagu 

	DataPtr dataPtr1 = initializeData(size); // tworzy ciąg liczb od 0 do size-1

	DataPtr ptrStart, ptrEnd;
	ptrStart = dataPtr1;
	ptrEnd = dataPtr1 + size;

	// proszę zadbać o odpowiednie formatowanie wyjścia:
	std::cout << "Before:" << std::endl;
	printSeries(ptrStart, ptrEnd);
	DataPtr ptrStart2 = ptrStart + 1; 
	
	std::cout << "After:" << std::endl;
	tripple(ptrStart2);
	printSeries(ptrStart, ptrEnd);

	executeFunction(add_one, ptrStart, ptrEnd-1);
	printSeries(ptrStart, ptrEnd);

	// przypomnienie: functionPtr jest wskaźnikiem na funkcję:
	// - z odpowiednim typem zwracanym
	// - o odpowiednich parametrach formalnych
	// - wskaźnik tego typu definiujemy poprzez typedef 
	functionPtr funContainer [] = {squareroot, // wylicza pierwiastek 2go stopnia
									add_one,  // powiększa element o 1
	                            	tripple };   // potraja liczbę

	const int nOperations = sizeof(funContainer)/sizeof(functionPtr);

	std::cout << "Results of operations:" << std::endl;
	for (int i = 0; i < nOperations; ++i){
		executeFunction(funContainer[i], ptrStart, ptrEnd); // proszę zadbać o odpowiednie formatowanie wyjścia
		printSeries(ptrStart, ptrEnd);
	}

	clearData(dataPtr1);
}
/* wynik dzialania programu:
Before:
0,  1,  2,  3,  4
After:
0,  3,  2,  3,  4
1,  4,  3,  4,  4
Results of operations:
1,  2,  1.73205,  2,  2
2,  3,  2.73205,  3,  3
6,  9,  8.19615,  9,  9
*/

// po zrobieniu zadania do zastanowienia:
// czym się różnią:
// const double* ptr;
// const DataPtr ptr;