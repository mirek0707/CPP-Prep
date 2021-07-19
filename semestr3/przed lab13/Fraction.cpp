#include "Fraction.h"
Fraction::Fraction(int l, int m)
{
	_licznik=l;
	_mianownik=m;
}

Fraction::Fraction()
{
    _licznik=1;
    _mianownik=1;
}
Fraction::Fraction(const Fraction & f)
{
	_licznik=f.gl();
	_mianownik=f.gm();
}
int Fraction::gl() const
{
	return _licznik;
}
int Fraction::gm() const
{
	return _mianownik;
}
Fraction::operator double() const
{
    return static_cast<double>(_licznik)/static_cast<double>(_mianownik);
}
void Fraction::simplify()
{
	if (_licznik<=_mianownik)
	{
		for (int i=_licznik;i>1;i--)
		{
			if (_licznik%i==0 && _mianownik%i==0)
			{
				_licznik=_licznik/i;
				_mianownik=_mianownik/i;
			}
		}
	}
	else
	{
		for (int i=_mianownik;i>1;i--)
		{
			if (_licznik%i==0&&_mianownik%i==0)
			{
				_licznik=_licznik/i;
				_mianownik=_mianownik/i;
			}
		}
	}
}
Fraction Fraction::operator * (const Fraction &f)
{
	return Fraction(f.gl()*_licznik,f.gm()*_mianownik);
}
Fraction Fraction::operator + (const Fraction &f) const
{
	return Fraction(f.gl()*_mianownik+f.gm()*_licznik,_mianownik*f.gm());
}
Fraction operator * (int l, const Fraction &f)
{
	return Fraction(l*f.gl(),f.gm());
}


std::ostream& operator<< (std::ostream& strm, const Fraction &f)
{
    return (strm << f.gl() << "/" << f.gm() );
}
