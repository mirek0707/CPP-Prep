#include "Functions.h"
#include <iostream>
using namespace std;
DataPtr initializeData(const int s)
{
	DataPtr wsk=new double[s];
	for (int i=0;i<s;i++)
	{
		wsk[i]=i;
	} 
	return wsk;
}
void printSeries(DataPtr s, DataPtr e)
{
	DataPtr t=s;
	while (t!=e)
	{
		if ((t+1)!=e)	
			cout<<*t<<", ";
		else
			cout<<*t<<endl;
		t=t+1;
	}
}
void tripple(DataPtr wsk)
{
	(*wsk)=(*wsk)*3;
}
void add_one(DataPtr wsk)
{
	*wsk=*wsk+1;
}
void squareroot(DataPtr wsk)
{
	*wsk=sqrt(*wsk); 
}
void executeFunction(void (*f)(DataPtr wsk),DataPtr s, DataPtr e)
{
	DataPtr wsk=s;
	while (wsk!=e)
	{
		f(wsk);
		wsk+=1;
	}
}
void clearData(DataPtr dataPtr1)
{
	delete dataPtr1;
}
