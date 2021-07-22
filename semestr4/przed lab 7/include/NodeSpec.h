#pragma once
#include "Node.h"
using namespace std;
class NodeInt : public Node
{
public:
	NodeInt(int n):Node(), war(n){}
	int valInt()
	{
		return war;
	}
	string toString() const override
	{
		return to_string(war);
	}
	NodeInt * clone() override
	{
		return new NodeInt(war);
	}
	~NodeInt()=default;
private:
	int war;
	
};

class NodeFloat : public Node
{
public:
	NodeFloat(float n):Node(), war(n){}
	float valFloat()
	{
		return war;
	}
	string toString() const override
	{
		return to_string(war);
	}
	NodeFloat * clone()  override
	{
		return new NodeFloat(war);
	}
	~NodeFloat()=default;
private:
	float war;
	
};

class NodeString : public Node
{
public:
	NodeString(string n):Node(), war(n){}
	string &valString()
	{
		return war;
	}
	std::string toString() const override
	{
		return war;
	}
	NodeString * clone() override
	{
		return new NodeString(war);
	}
	~NodeString()=default;
private:
	string war;
	
};