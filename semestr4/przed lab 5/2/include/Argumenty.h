#pragma once
#include <iostream>

class Argumenty 
{
public:
	Argumenty(int i);
	Argumenty& operator()(int indeks, double wartosc);
	void print (const char * t, std::ostream& str = std::cout) const;
	double rozmiar() const;
	double operator[](int indeks) const;
	~Argumenty();
private:
	int _i;
	double * _w;
};