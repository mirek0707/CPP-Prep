#pragma once
#include <cmath>
#include "Algo.h"

class Pierwiastek : public Algo 
{
	public:
		Argumenty wykonaj(const Argumenty& arg) const 
		{
			Argumenty a(arg.rozmiar());
			for (int i=0;i<arg.rozmiar();i++)
				a(i,sqrt(arg[i]));
			return a;
		}
		Pierwiastek* sklonuj() const
		{
			return new Pierwiastek;
		}	
};