#include "Vector2D.h"
int Vector2D::count=0;
Vector2D::Vector2D()
{
	_x=0.0;
	_y=0.0;
	count++;
}
Vector2D::Vector2D(const Vector2D& w2)
{
	w2.print("copying: ");
	_x=w2._x;
	_y=w2._y;
	count++;
}
Vector2D::Vector2D(Vector2D&& w2): _x(std::move(w2._x)), _y(std::move(w2._y))
{
	print("moving");
    count++;
}
Vector2D Vector2D::fromCarthesian(float x, float y)
{
	Vector2D w;
	w._x=x;
	w._y=y;
	return w;
}
Vector2D Vector2D::fromPolar(float r, float fi)
{
	Vector2D w;
	w._x=r*cos((fi*2*M_PI)/360);
	w._y=r*sin((fi*2*M_PI)/360);
	return w;
}
void Vector2D::print(const char * s) const 
{
	cout<<s<<"("<<_x<<", "<<_y<<")"<<endl;
}
double Vector2D::dot(const Vector2D& w) const
{
	return (_x*w._x+_y*w._y);
}
Vector2D Vector2D::add(const Vector2D& w1) const
{
	Vector2D w;
	w._x=_x+w1._x;
	w._y=_y+w1._y;
	return w;
}
Vector2D::~Vector2D()
{
	count=0;
}