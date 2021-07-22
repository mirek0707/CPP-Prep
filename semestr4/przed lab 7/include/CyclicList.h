#pragma once
#include <iostream>
#include "Node.h"
class CyclicList
{
public:
	CyclicList():_start(nullptr), _end(nullptr), licznik(0) {}
	CyclicList& operator <<(Node *node)
	{
		if (licznik)
		{
			_end->next=node;
			_end=node;
			node->next=_start;
		}
		else
		{
			_start=_end=node->next=node;
		}
		licznik++;
		return *this;
	}
	CyclicList(const CyclicList& l)
	{
		_start=nullptr;
		_end=nullptr;
		licznik=0;
		Node * c=l._start;
		for(int i=0; i<l.licznik; i++)
		{
			*this << c->clone();
			c=c->next;
		}
	}
	int count() const
	{
		return licznik;
	}
	Node* operator()() const
	{
		return _start;
	}
	CyclicList& rotate_back()
	{
		for (int i=0; i < licznik-1; i++)
		{
			_start = _start->next;
			_end = _end->next;
		}
		return *this;
	}
	CyclicList& rotate()
	{
		_start=_start->next;
		_end=_end->next;
		return *this;
	}
	~CyclicList()
	{
		_end->next=nullptr;
		while(_start)
		{
			Node *temp=_start->next;
			delete _start;
			_start=temp;
		}
	}
	friend std::ostream& operator<<(std::ostream&, const CyclicList&);
private:
	Node* _start;
	Node* _end;
	int licznik;
};
std::ostream& operator<<(std::ostream& s, const CyclicList& lista)
{
	Node * c=lista._start;
	for (int i = 0; i < lista.licznik; i++)
	{
		s<<c->toString()<<" ";
		c=c->next;
	}
	return s;
}