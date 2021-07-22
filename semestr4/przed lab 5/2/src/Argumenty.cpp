#include "Argumenty.h"
#include <iostream>
using namespace std;
Argumenty::Argumenty(int i)
{
	_w=new double[i];
	for (int j=0;j<i;j++)
	{
		_w[i]=0.0;
	}
	_i=i;
}
Argumenty& Argumenty::operator()(int indeks, double wartosc)
{
	_w[indeks]=wartosc;
	return *this;
}
void Argumenty::print (const char * t, std::ostream& str) const
{
	str<<t<<" ";
	for (int i=0;i<_i;i++)
	{
		str<<_w[i]<<" ";
	}
	str<<endl;
}
double Argumenty::rozmiar() const
{
	return _i;
}
double Argumenty::operator[](int indeks) const
{
	return _w[indeks];
}
Argumenty::~Argumenty()
{
	delete [] _w;
}