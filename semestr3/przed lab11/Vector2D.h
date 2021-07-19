#pragma once
#include<iostream>
#include<cmath>
using namespace std;

class Vector2D
{
public:
	Vector2D();
	Vector2D(const Vector2D& w2);
	Vector2D(Vector2D&& w2);
	~Vector2D();
	static int count;
	static Vector2D fromCarthesian(float x, float y);
	static Vector2D fromPolar(float r, float fi);
	void print(const char * s) const;
	double dot(const Vector2D& w) const;
	Vector2D add(const Vector2D& w1) const;
private:
	float _x;
	float _y;
};