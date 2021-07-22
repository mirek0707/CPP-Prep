#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
template<typename K, typename D>
class Assoc
{
public:
	Assoc(): _M({}) {}
	void insert(const K str, const D l)
	{
		_M.push_back(std::make_pair(str,l));
	}
	D &operator[](const K & str)
	{
		auto it = std::find_if(_M.begin(), _M.end(), [&str](auto& para){return para.first == str;});
	    if(it == _M.end())
	    {
	        insert(str, D());
	        return (_M.back()).second;
	    }
    	else 
    		return (*it).second;
	}
	void print(string s) const
	{
	    for_each(_M.begin(), _M.end(), [&s](const std::pair<K, D> &p){ cout<<"--- " <<s<<" --- klucz: "<<p.first<<" wartosc: "<<p.second<<endl;} );
	}
	const D operator[](const K &str) const
	{
		auto it = std::find_if(_M.begin(), _M.end(), [&str](auto& para){return para.first == str;});
	    if(it == _M.end())
	    {
	        return (_M.back()).second;
	    }
    	else 
    		return (*it).second;
	}
	const bool contains(const K &str) const
	{
		auto it = std::find_if(_M.begin(), _M.end(), [&str](auto& para){return para.first == str;});
		return it!=_M.end();
	}

private:
	std::vector<std::pair<K, D> > _M;
};

const string print(const bool c)
{
    if(c)
        return "Znaleziono";
    else
        return  "Nie znaleziono";
}

template<typename D>
D operator*(const D &w, const int l)
{
    D result = w;
    for(int i = 0; i < l - 1; i++)
    {
        result += w;
    }
    return result;
}

template<typename D>
D operator*(const int factor, const D &value)
{
    return value * factor;
}