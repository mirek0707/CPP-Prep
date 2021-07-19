#include "Rational.h"
Rational::Rational(int l, int m)
{
	_licznik=l;
	_mianownik=m;
}
void Rational::Print() const
{
	cout<<_licznik<<"/"<<_mianownik<<endl;
}