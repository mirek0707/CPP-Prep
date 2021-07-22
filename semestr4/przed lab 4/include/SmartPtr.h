#pragma once
#include<iostream>
#include<cstring>
#include"TestClass.h"
using namespace std;
class SmartPtr
{
public:
	SmartPtr()=default;
	SmartPtr(TestClass *T);
	SmartPtr(SmartPtr && P);
	typedef TestClass ptrType;
	TestClass* get();
	TestClass *operator->() const;
	TestClass &operator*() const;
	SmartPtr &operator=(SmartPtr && P);
	operator bool() const;
	TestClass * release();
	void operator!=(SmartPtr) {}
	~SmartPtr();
private:
	TestClass * _wsk=nullptr;	
};
