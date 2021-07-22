#pragma once
#include <iostream>
class Complex
{
	public:
		Complex()=default;
		Complex(double re, double im);
		double re() const;
		double im() const;
		friend std::ostream& operator<< (std::ostream& s, const Complex & a);
		Complex operator+ (Complex a);
		Complex operator++ (int);
		Complex operator++ ();
		Complex  &re();
		void operator=(int l);
		~Complex();
	private:
		double _re=0;
		double _im=0;
};
std::ostream& operator<< (std::ostream& s, const Complex &a);
