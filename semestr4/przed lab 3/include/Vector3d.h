#pragma once
#include<iostream>
using namespace std;
class Vector3d
{
	public:
		//Vector3d();
		Vector3d(double a=0, double b=0, double c=0);
		//Vector3d(Vector3d &v);
		friend std::ostream & operator<< (std::ostream &s, const Vector3d &v);
		double w(int i) const;
		double operator*(const Vector3d v);
		double & operator[](int i);
		friend Vector3d operator*(double a, Vector3d &v);
		Vector3d operator*(double a);
		//~Vector3d();
	private:
		double _w[3];
};
std::ostream & operator<< (std::ostream &s, const Vector3d &v);
Vector3d operator*(double a, Vector3d &v);