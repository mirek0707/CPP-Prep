#pragma once
#include "Ksztalt.h"
using namespace std;
class Trojkat : public Ksztalt
{
	public:
		Trojkat()=default;
		Trojkat(double a, double b, double c)
		{
			_a=a;
			_b=b;
			_c=c;
		}
		void wypisz() const
		{
			cout<<"Trojkat o bokach: "<<_a<<" "<<_b<<" "<<_c<<endl;
		}
		void wypisz(std::ostream& s) const
		{
			s<<"Trojkat o bokach: "<<_a<<" "<<_b<<" "<<_c<<endl;
		}
		double polePow() const
		{
			double p=(_a+_b+_c)/2;
			return sqrt(p*(p-_a)*(p-_b)*(p-_c));
		}
		//~Trojkat()=default;
	private:
		double _a=0;
		double _b=0;
		double _c=0;
};