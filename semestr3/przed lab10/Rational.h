#pragma once
#include<iostream>
#include "Fun.h"
using namespace std;
class Fun;
class Rational
{
public:
	friend class Fun;
	Rational(int l, int m);
	void Print() const;
	operator float() const 
	{
		return (float)_licznik / (float)_mianownik;
	}
private:
	int _licznik;
	int _mianownik;
	
};