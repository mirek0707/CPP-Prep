#pragma once
#include<iostream>
#include<string>
using namespace std;
class Pomieszczenie
{
public:
	Pomieszczenie(const string n):_n(n){ cout<<"Tworze pomieszcznie: "<<_n<<endl; }
	void zetrzyj_kurze() const
	{
		cout<<"Scieram kurze w pomieszczeniu: "<<_n<<endl;
	}
	void umyj_podloge() const
	{
		cout<<"Myje podloge w pomieszczeniu: "<<_n<<endl;
	}
	void odkurz() const
	{
		cout<<"Odkurzam pomieszczenie: "<<_n<<endl;
	}
	template <typename T>
	void wstaw(T l) const
	{
		cout<<"Wstawiam "<<l<<" do pomieszczenia: "<<_n<<endl;
	}
	string getName() const
	{
    	return _n;
    }
private:
	string _n;
};