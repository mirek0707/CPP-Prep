#pragma once
#include "Ksztalt.h"
using namespace std;
class Kolo : public Ksztalt
{
	public:
		Kolo()=default;
		Kolo(double r)
		{
			_r=r;
		}
		void wypisz() const
		{
			cout<<"Kolo o promieniu: "<<_r<<endl;
		}
		void wypisz(std::ostream& s) const
		{
			cout<<"Kolo o promieniu: "<<_r<<endl;
		}
		double polePow() const
		{
			return M_PI*pow(_r,2);
		}
		//~Kolo()=default;
	private:
		double _r=0;
};