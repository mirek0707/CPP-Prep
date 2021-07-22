#pragma once
#include "Algo.h"

class Suma : public Algo 
{
public:
	Argumenty wykonaj(const Argumenty& arg) const 
	{
		Argumenty a(1);
		a(0,0.0);
		for (int i=0;i<arg.rozmiar();i++)
			a(0,a[0]+(arg[i]));
		return a;
	}
	Suma* sklonuj() const
	{
		return new Suma;
	}

};