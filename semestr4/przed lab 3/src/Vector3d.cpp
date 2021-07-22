#include "Vector3d.h"
// Vector::Vector3d()
// {
// 	_w=new double[3];
// }
Vector3d::Vector3d(double a, double b, double c)
{

	_w[0]=a;
	_w[1]=b;
	_w[2]=c;
}
std::ostream & operator<< (std::ostream &s, const Vector3d &v)
{
	s<<"[ ";
	for (int i=0;i<3;i++)
	{
		s<<v.w(i)<<" ";
	}
	s<<"]";
	return s;
}
double Vector3d::w(int i) const
{
	return _w[i];
}
double Vector3d::operator*(Vector3d v)
{
	double suma=0;
	for(int i=0;i<3;i++)
	{
		suma+=_w[i]*v._w[i];
	}
	return suma;
}
double & Vector3d::operator[](int i)
{
	return _w[i];
}
Vector3d operator*(double a, Vector3d& v)
{
	Vector3d t(0,0,0);
	t._w[0]=v._w[0]*a;
	t._w[1]=v._w[1]*a;
	t._w[2]=v._w[2]*a;
	return t;

}
Vector3d Vector3d::operator*(double a)
{
	Vector3d t(0,0,0);
	t._w[0]=_w[0]*a;
	t._w[1]=_w[1]*a;
	t._w[2]=_w[2]*a;
	return t;
}
// Vector3d::Vector3d(Vector3d &v)
// {
// 	_w=new double[3];
// 	for (int i=0;i<3;i++)
// 	{
// 		_w[i]=v._w[i];
// 	}
// }
// Vector3d::~Vector3d()
// {
// 	if (_w!=NULL)
// 		delete [] _w;
// }