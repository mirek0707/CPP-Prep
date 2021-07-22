#pragma once
#include"Animal.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include <utility>
#include <map>
using namespace std;

class Sheep : public Animal
{
public:
	explicit Sheep(const string& n) : Animal(n) {}
	~Sheep()
	{
		if(_strzyz)
		{
			cout<<"- Owca "<<name()<<" ostrzyzona wraca do zagrody";
		}
		else
		{
			cout<<"- Owca "<<name()<<" nieostrzyzona wraca do zagrody";
		}
		cout<<endl;
	}
	void print() const override
	{
		cout<<"- Owca "<<name();
		if(_strzyz)
		{
			cout<<" ostrzyzona";
		}
		else
		{
			cout<<" nieostrzyzona";
		}
		//cout<<endl;
	}
	void shear()
	{
		_strzyz=true;
	}

private:
	bool _strzyz=false;
};

class Cow : public Animal
{
public:
	explicit Cow(const string& n) : Animal(n) {}
	~Cow()
	{
		cout<<"- Krowa "<<name()<<" wraca do obory";
		cout<<endl;
	}
	void print() const override
	{
		cout<<"- Krowa "<<name();
	}
};

class Horse : public Animal
{
public:
	explicit Horse(const string& n) : Animal(n) {}
	~Horse()
	{
		cout<<"- Kon "<<name()<<" wraca do stajni";
		cout<<endl;
	}
	void print() const override
	{
		cout<<"- Kon "<<name();
	}
};