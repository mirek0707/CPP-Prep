#pragma once
#include<iostream>
using namespace std;
#include "PredkoscMaksymalna.h"
class Pojazd
{
public:
	Pojazd()=default;
	virtual ~Pojazd()=default;
	virtual std::string typ() const=0;
};
std::ostream& operator<<(std::ostream& s, const Pojazd& p) 
{
	s << p.typ();
	return s;
}