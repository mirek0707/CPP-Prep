#pragma once
class Sum
{
public:
	Sum(double s) : _suma(s){}
	void operator() (double i) 
	{
    	_suma += i;
	}
	double value() const
	{
		return _suma;
	}
private:
	double _suma=0.0;
};
