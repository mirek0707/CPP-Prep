#pragma once
#include "Ksztalt.h"
using namespace std;
class Kwadrat : public Ksztalt
{
	public:
		Kwadrat()=default;
		Kwadrat(double a)
		{
			_a=a;
		}
		void wypisz() const
		{
			cout<<"Kwadrat o boku: "<<_a<<endl;
		}
		void wypisz(std::ostream& s) const
		{
			s<<"Kwadrat o boku: "<<_a<<endl;
		}
		double polePow() const
		{
			return pow(_a,2);
		}
		//~Kwadrat()=default;
	private:
		double _a=0;
};