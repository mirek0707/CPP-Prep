#pragma once
#include "Pojazd.h"
class Amfibia : virtual public Samochod, virtual public Motorowka
{
public:
	Amfibia()=default;	
	Amfibia(PredkoscMaksymalna l, PredkoscMaksymalna w):Samochod(l), Motorowka(w){}
	virtual std::string typ() const override 
	{
		return "Amfibia";
	}
	std::string predkoscMaksymalna_Lad()
	{
		return Samochod::predkoscMaksymalna();
	}
	std::string predkoscMaksymalna_Woda()
	{
		return Motorowka::predkoscMaksymalna();
	}
	~Amfibia() override = default;
};