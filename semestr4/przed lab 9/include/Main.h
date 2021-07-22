#pragma once
#include<iostream>
#include<cmath>
using namespace std;
class Point
{
public:
	Point()=default;
	Point(double x, double y) : _x(x), _y(y){}
	~Point()=default;
	void setX(double x)
	{
		_x=x;
	}
	void setY(double y)
	{
		_y=y;
	}
	double X() const
	{
		return _x;
	}
	double Y() const
	{
		return _y;
	}
	friend std::ostream& operator<< (std::ostream & s, const Point& p)
	{
		s<<"("<<p._x<<", "<<p._y<<")";
		return s;
	}
private:
	double _x=0.0;
	double _y=0.0;
};
class ClosedShape
{
public:
	virtual double area() const=0;
};
class Transformable
{
public:
	virtual void shift(double x, double y)=0;
};
class Drawable
{
public:
	virtual void draw() const=0;
};

class Circle : public ClosedShape, public Transformable, public Drawable
{
public:
	Circle(Point p, int r): _p(p), _r(r){}
	double area() const override
	{
		return M_PI*pow(_r,2); 
	}
	void shift(double x, double y) override
	{
		_p.setX(_p.X()+x);
		_p.setY(_p.Y()+y);
	}
	void draw() const override
	{
		cout<<"++ Rysuje kolo o srodku ("<<_p.X()<<", "<<_p.Y()<<") i promieniu 3"<<endl;
	}
private:
	Point _p;
	int _r;
};
class Rectangle : public ClosedShape, public Transformable, public Drawable
{
public:
	Rectangle(Point p1, Point p2): _p1(p1), _p2(p2){}
	double area() const override
	{
		return abs(_p1.X()-_p2.X())*abs(_p1.Y()-_p2.Y());
	}
	void shift(double x, double y) override
	{
		_p1.setX(_p1.X()+x);
		_p1.setY(_p1.Y()+y);
		_p2.setX(_p2.X()+x);
		_p2.setY(_p2.Y()+y);

	}
	void draw() const override
	{
		cout<<"++ Rysuje prostokat o rogach w ("<<_p1.X()<<", "<<_p1.Y()<<") i ("<<_p2.X()<<", "<<_p2.Y()<<")"<<endl;
	}
private:
	Point _p1;
	Point _p2;
};

class Line : public Transformable, public Drawable
{
public:
	Line(Point p1, Point p2): _p1(p1), _p2(p2){}
	void shift(double x, double y) override
	{
		_p1.setX(_p1.X()+x);
		_p1.setY(_p1.Y()+y);
		_p2.setX(_p2.X()+x);
		_p2.setY(_p2.Y()+y);

	}
	void draw() const override
	{
		cout<<"++ Rysuje linie od ("<<_p1.X()<<", "<<_p1.Y()<<") do ("<<_p2.X()<<", "<<_p2.Y()<<")"<<endl;
	}
private:
	Point _p1;
	Point _p2;
};

void draw(Drawable *d)
{
	d->draw();
}