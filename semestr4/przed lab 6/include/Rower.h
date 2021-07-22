#pragma once
#include "PojazdLadowy.h"
class Rower : public PojazdLadowy
{
public:
	Rower()=default;	
	Rower(PredkoscMaksymalna m)
	{
		_pm=m;
	}
	virtual std::string typ() const override 
	{
		return "Rower";
	}
	~Rower() override =default;
private:
	PredkoscMaksymalna _pm;
};