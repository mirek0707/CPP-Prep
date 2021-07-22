#pragma once
#include<iostream>
#include<cmath>
using namespace std;
class Ksztalt
{
	public:
		static void wypisz(const Ksztalt& k)
		{
			k.wypisz();
		}
		static void wypisz(const Ksztalt* k)
		{
			k->wypisz();
		}
		virtual void wypisz(std::ostream& s) const=0;
		virtual void wypisz() const=0;
		virtual double polePow() const=0;
		virtual ~Ksztalt()=default;

};