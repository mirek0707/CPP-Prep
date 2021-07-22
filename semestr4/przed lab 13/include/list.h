#pragma once
#include<iostream>
using namespace std;
namespace agh
{
	template<typename T>
	class node
	{
	public:
		node(T w) : _w(w), _next(nullptr){}
		void add(node<T>*n)  
		{ 
			_next = n; 
		} 
		node<T>* next() 
		{ 
			return _next; 
		}
		T w() const 
		{
			return _w; 
		}

		bool operator!= (const node<T>& n)
		{
			if (*(_w) ==*(n.w()))
			{
				cout<<*(_w)<<endl;
			}
			return*(_w)!= *(n.w()); 
		}

		node<T> operator++ ()
		{
			this->_w = this->_next->_w; 
			this->_next = this->_next->_next; 
			return *this;
		}

		T operator* () 
		{ 
			return this->_w; 
		}
		~node(){}
	private:
		T _w;
		node<T>* _next;
	};
	template<typename T>
	class list
	{
	public:
		list(): _head(nullptr){}
		void push_back(T w)
		{
			node<T>* Node=new node<T>(w);
			if (_head)
			{
				node<T>* temp =_head;
				while(temp->next()!=nullptr)
					temp=temp->next();
				temp->add(Node);
			}
			else
			{
				_head=Node;
			}
		}
		void print() const
		{
			node<T>*temp=_head;
			while(temp->next() != nullptr) 
			{
				cout << *(temp->w()) << ", ";
				temp = temp->next();
			}
			cout << *(temp->w()) << std::endl;
		}
		node<T> end()
		{
			node<T>* temp =_head;
			while(temp->next()!=nullptr)
				temp=temp->next();
			return *(temp);
		}
		node<T> begin() 
		{ 
			return*(_head); 
		}
		typedef node<T> iterator;
		~list()
		{
			node<T>*temp=_head;
			node<T>*tempn=_head->next();
			while(temp->next()!=nullptr)
			{
				delete temp->w();

				delete temp;
				temp=tempn;
				tempn=tempn->next();
			}
			delete temp->w();
			delete temp;
			delete tempn;

		}
	private:
		node<T>* _head;
	};
}