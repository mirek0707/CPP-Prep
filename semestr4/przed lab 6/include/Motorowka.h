#pragma once
#include "Pojazd.h"
class Motorowka : virtual public Pojazd
{
public:
	Motorowka()=default;	
	Motorowka(PredkoscMaksymalna m)
	{
		_pm=m;
	}
	virtual std::string typ() const override 
	{
		return "Motorowka";
	}
	std::string predkoscMaksymalna() const 
	{ 
		return std::to_string(_pm.predkoscMaksymalna()).append("km/h"); 
	}
	~Motorowka() override = default;
private:
	PredkoscMaksymalna _pm;
};