#pragma once
#include<iostream>
using namespace std;
class Fraction
{
public:
	Fraction();
	Fraction(int l, int m);
	Fraction(const Fraction & f);
	int gl() const;
	int gm() const;
	operator double() const;
	Fraction operator * (const Fraction &f);
	Fraction operator + (const Fraction &f) const;
	friend Fraction operator * (int l, const Fraction &f);
	friend std::ostream& operator<< (std::ostream& strm, const Fraction &f);
	void simplify();
private:
	int _licznik;
	int _mianownik;
};

