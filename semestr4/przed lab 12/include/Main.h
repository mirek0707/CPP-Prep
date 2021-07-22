#pragma once
#include<iostream>
using namespace std;
template<typename T>
class UniquePointer
{
public:
	UniquePointer(T* w) : _war(w){}
	UniquePointer(UniquePointer & p)
	{
		_war = p._war;
		p._war = nullptr;
	}
	~UniquePointer()
	{
		if (_war)
			delete _war;
	}
	T& operator*() const 
	{
		return *_war;
	}
	UniquePointer & operator=(UniquePointer & p)
	{
		if(&p == this)
			return *this;
		if(_war)
			delete _war;
		_war = p._war;
		p._war = nullptr;
		return *this;
	}
	operator T*()
	{
		return &*_war;
	}
	friend std::ostream & operator<<(std::ostream &s, const UniquePointer<T> & p)
	{
		s<<"[pointing to "<<&*p<<"]";
		return s;
	}
private:
	T* _war;
};