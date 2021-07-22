#pragma once
#include<iostream>
#include "Vector3d.h"
using namespace std;
class Matrix3d
{
public:
	Matrix3d();
	Matrix3d(const Vector3d& v1, const Vector3d& v2, const Vector3d& v3);
	friend std::ostream & operator<< (std::ostream &s, const Matrix3d &m);
	Vector3d & operator[](int i);
	Vector3d operator*(Vector3d &v) const;
	//~Matrix3d();
private:
	Vector3d _m[3];
	
};
std::ostream & operator<< (std::ostream &s, const Matrix3d &m);
