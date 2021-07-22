#pragma once
#include<iostream>
#include<cstring>
using namespace std;
class TestClass
{
public:
	TestClass()=default;
	TestClass(const char *t);
	const char * info() const;
	void setName(const char * t);
	~TestClass();
private:
	char* _text=nullptr;
	
};
