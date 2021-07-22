#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <numeric>
using namespace std;

bool NotInt(double i)
{
	return (int)i!=i;
}

struct badScores
{
    bool operator()(double ocena)
    {
        if(ocena<3) 
        	return true;
        return false;
    }
};

class Person
{
public:
	Person(const string n, vector<double> V): _nazwa(n), _oceny(V){}
	void print() const
	{
		cout<<_nazwa<<": "<<setw(6);
		for(auto const &e: _oceny)
		{
			cout<<e<< std::setw(6);
		}
		cout<<endl;
	}
	double getSum() const
	{
		return accumulate(_oceny.begin(), _oceny.end(), 0.0);
	}
	double dlugosc() const
	{
		return _oceny.size();
	}
	auto notIntScores() const
	{
		vector<double>::const_iterator tmp = std::find_if(_oceny.begin(), _oceny.end(), NotInt);
		return tmp;
	}
	int countGoodScores() const
	{
		return _oceny.size() - count_if(_oceny.begin(), _oceny.end(), badScores());
	}
	string nazwa() const
	{
		return _nazwa;
	}
	vector<double> oceny() const
	{
		return _oceny;
	}
	void addScore(double n)
    {
        _oceny.push_back(n);
    }
    double operator[](int i)
    {
        return _oceny[i];
    }
    void removeScore(double n)
    {
        auto a=find(_oceny.begin(), _oceny.end(), n);
        if (a!=_oceny.end())
        {
        	_oceny.erase(a);
        }
    }
private:
	string _nazwa;
    vector<double> _oceny;
};
double averageScore(const Person &student)
{
	return student.getSum()/student.dlugosc();
}
