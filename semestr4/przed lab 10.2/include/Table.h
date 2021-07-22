#pragma once

#include"Data.h"
using namespace std;
class Table
{
public:
	void operator+= (const Data& data) 
	{
    	_dni.push_back(data);
	}
	void print() const 
	{
	    for (auto& day:_dni) 
	    {
	        day.print();
	    }
	}
	Table& sort(int k)
	{
		if(k>(int)_dni.size()-1)
		{
	      std::cout<<"Indeks "<<k<<" nieprawidlowy!\n";
	      return *this;
	    }
		std::sort(_dni.begin(), _dni.end(), [k](Data d1, Data d2){ return d1[k]<d2[k]; });
		return *this;
	}
	Table& sortBy(std::function<bool(const Data& d1, const Data& d2)> sorter) 
	{
	    std::sort(_dni.begin(), _dni.end(), sorter);
	    return *this;
	}	
private:
    vector<Data> _dni; 
};