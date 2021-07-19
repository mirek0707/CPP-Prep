#pragma once
#include<iostream>
#include "Fraction.h"
using namespace std;
class FractionArray
{
public:
	FractionArray(int _size);
	~FractionArray();
	Fraction& operator [](unsigned i);
    const Fraction& operator [](unsigned i ) const;
    friend std::ostream& operator<< (std::ostream& strm, const FractionArray &_tab);
private:
	Fraction *T;
	int _s;
};