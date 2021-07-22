#include "Matrix3d.h"
Matrix3d::Matrix3d()
{
	
}
Matrix3d::Matrix3d(const Vector3d& v1, const Vector3d& v2, const Vector3d& v3)
{

	_m[0]=v1;
	_m[1]=v2;
	_m[2]=v3;
}
std::ostream & operator<< (std::ostream &s, const Matrix3d &m)
{
	for (int i=0;i<3;i++)
	{
		s<<m._m[i]<<endl;
	}
	return s;
}
Vector3d & Matrix3d::operator[](int i) 
{
	return _m[i];
}
Vector3d Matrix3d::operator*(Vector3d &v) const
{
	Vector3d t(_m[0]*v, _m[1]*v, _m[2]*v);
	return t;
}
// Matrix3d::~Matrix3d()
// {
	
// 	delete [] _m;

// }