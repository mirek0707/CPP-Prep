#pragma once
#include<iostream>
using namespace std;
class PredkoscMaksymalna
{
public:
	PredkoscMaksymalna()=default;
	PredkoscMaksymalna(int p)
	{
		_predkosc=p;
	}
	int predkoscMaksymalna() const
	{
		return _predkosc;
	}
private:
	int _predkosc;
};
std::ostream& operator<< (std::ostream &s, const PredkoscMaksymalna& p)
{
	s<<p.predkoscMaksymalna()<<"km/h";
	return s;
}