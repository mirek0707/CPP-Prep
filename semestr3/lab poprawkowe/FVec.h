#pragma once
#include<iostream>
#include<cmath>
using namespace std;
class FVec
{
public:
	
	FVec(int pi, int ind);
	FVec(int f(const int), int ind);
	FVec(const FVec& other);
	FVec (FVec &&other);

	static FVec create (int rozmiar);
	int & operator[](int i);
	int & operator[](int i) const;
	friend std::ostream& operator<< (std::ostream& s, const FVec w);
	int rozmiar() const;
	int w(int i) const;
	int pi() const;
	int begin() const;
	int end() const;

	FVec set(int i, int wartosc);
	~FVec();
	FVec& operator= (const FVec& other);
private:
	int *_w=nullptr;
	int _rozmiar=0;
	int _pi=0;
	FVec()=default;
	
};
std::ostream& operator<< (std::ostream& s, const FVec w);

