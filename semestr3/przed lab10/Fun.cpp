#include "Fun.h"
int Fun::i = 0;
float Fun::suma = 0;
Rational Fun::Add(const Rational A, const Rational B)
{
	if (A._mianownik==B._mianownik)
	{
		Rational temp(A._licznik+B._licznik, A._mianownik);
		return temp;
	}
	else
	{
		Rational temp(A._licznik*B._mianownik+B._licznik*A._mianownik, A._mianownik*B._mianownik);
		return temp;
	}
}
Rational Fun::Add(const Rational A, int n)
{
	
	Rational temp(A._licznik+n*A._mianownik, A._mianownik);
	return temp;
}
Rational Fun::Multiply(const Rational A, const Rational B)
{
	Rational temp(A._licznik*B._licznik, A._mianownik*B._mianownik);
	return temp;
}
Rational Fun::Divide(int n, const Rational A)
{
	Rational temp(A._mianownik*10,A._licznik);
	return temp;
}
void Fun::Average(Rational r) 
{
	suma += (float)r._licznik / (float)r._mianownik;
	i++;
}

Rational Fun::Average() 
{
	Rational temp(suma,i);
	return temp;
}