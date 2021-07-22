#pragma once
#include "Animals.h"
using namespace std;
class Meadow
{
public:
	Meadow(){};
	void add(unique_ptr<Animal> nz)
	{
		_Z.push_back(std::move(nz));
	}
	void print(string s) const
	{
		cout<<"=== "<<s<<" ==="<<endl;
		for_each(_Z.begin(), _Z.end(), [](const unique_ptr<Animal> &A){ A->print(); cout<<endl; });
	}
	void countNames() 
	{
		map<string, int> M;
		for_each(_Z.begin(), _Z.end(), [&M](const unique_ptr<Animal> &A){ M[A->name()]++; });
		for_each(M.begin(), M.end(), [](pair<const string, int> &p){ cout<<p.first<<": "<<p.second<<endl; });
	}
	vector<Sheep*> getSheepHerd()
	{
		vector<Sheep*> T;
		for_each(_Z.begin(), _Z.end(), [&T](const unique_ptr<Animal> &A){ Sheep *t=dynamic_cast<Sheep*>(A.get()); if(t){T.push_back(t);} });
		return T;
	}
	~Meadow(){};
private:
	vector<unique_ptr<Animal>> _Z;	
};