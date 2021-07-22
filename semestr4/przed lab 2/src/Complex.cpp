#include "Complex.h"
Complex::Complex(double re, double im)
{
	_im=im;
	_re=re;
}
double Complex::re() const
{
	return _re;
}
double Complex::im() const
{
	return _im;
}
Complex::~Complex()
{
	_im=0;
	_re=0;
}
std::ostream & operator<< (std::ostream& s, const Complex &a)
{
	s<<"("<<a.re()<<" + "<<a.im()<<"*i)";
	return s;
}
Complex Complex::operator+ (Complex a)
{
	Complex t;
	t._re=a._re+_re;
	t._im=a._im+_im;
	return (t);
}
Complex Complex::operator++ (int)
{
	return Complex(_re++,_im++);
}
Complex Complex::operator++ ()
{
	return Complex(++_re,++_im);
}
Complex  &Complex::re() 
{
	return *this;
}
void Complex::operator=(int l)
{
	_re=l;
}