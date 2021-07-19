#include "FVec.h"
FVec::FVec(int pi, int ind) 
{
	_w=new int [abs(pi)+abs(ind)];
	_rozmiar=abs(pi)+abs(ind);
	_pi=pi;
	for(int i=0;i<_rozmiar;i++)
	{
		_w[i]=0;

	}
}
FVec::FVec(int f(const int), int ind)
{
	_w=new int [0+abs(ind)];
	_rozmiar=0+abs(ind);
	_pi=0;
	for(int i=0;i<_rozmiar;i++)
	{
		_w[i]=f(i);

	}
}
FVec::FVec(const FVec& other)
{
    _rozmiar=other._rozmiar;
    _pi=other._pi;
    _w=new int[_rozmiar];
    for(int i=0; i<_rozmiar; i++)
        _w[i]=other._w[i];
}
FVec::FVec (FVec &&other)
{
	_rozmiar = std::__exchange (other._rozmiar, 0);
	_pi = std::__exchange (other._pi, 0);
	_w = std::__exchange (other._w, nullptr);
	delete [] other._w;
}
FVec FVec::create (int rozmiar)
{
	FVec V;
	V._w=new int [rozmiar];
	V._rozmiar=rozmiar;
	for(int i=0;i<rozmiar;i++)
	{
		V._w[i]=0;
	}
	return V;
}
int FVec::rozmiar() const
{
	return _rozmiar;
}
int FVec::pi() const
{
	return _pi;
}
int FVec::w(int i) const
{
	return(*(_w+i));
}
int & FVec::operator[](int i)
{
	return _w[i-_pi];
}
int & FVec::operator[](int i) const
{
	return _w[i-_pi];
}
std::ostream& operator<< (std::ostream& s, const FVec w) 
{
	s<<"idx["<<w.pi()<<","<<w.pi()+w.rozmiar()<<"] ";
	for (int i=0;i<w.rozmiar();i++)
	{
		s<<w.w(i)<<" ";
	}
	return s;
}
FVec FVec::set(int i, int wartosc)
{
	_w[i]=wartosc;
	return *this;
}
int FVec::begin() const
{
	return _pi;
}
int FVec::end() const
{
	return _pi+_rozmiar;
}
FVec::~FVec()
{
	
		delete [] _w;
		_w=nullptr;
	
		
	_rozmiar=0;
	_pi=0;
}
FVec& FVec::operator= (const FVec& other)
{
	if (this != &other)
	{
		
		delete [] _w;
		_pi = other._pi;
		_rozmiar = other._rozmiar;
		_w = new int [_rozmiar];
		for (int i = 0; i < _rozmiar; i++)
		{
			_w[i] = other._w[i];
		}
	}

	return *this;
}