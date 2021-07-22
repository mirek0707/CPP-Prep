#pragma once
#include "PojazdLadowy.h"
class Samochod : virtual public PojazdLadowy
{
public:
	Samochod()=default;	
	Samochod(PredkoscMaksymalna m)
	{
		_pm=m;
	}
	virtual std::string typ() const override 
	{
		return "Samochod";
	}
	std::string predkoscMaksymalna() const 
	{ 
		return std::to_string(_pm.predkoscMaksymalna()).append("km/h"); 
	}
	~Samochod() override =default;
private:
	PredkoscMaksymalna _pm;
};