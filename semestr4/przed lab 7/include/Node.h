#pragma once
#include<iostream>
#include <string>
using namespace std;
class Node
{
public:
	Node * next;
	Node():next(nullptr){}
	virtual Node * clone() =0;
	virtual std::string toString() const = 0;
	virtual ~Node()=default;
};