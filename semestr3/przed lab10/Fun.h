#pragma once
#include<iostream>
#include "Rational.h"
using namespace std;
class Rational;
class Fun
{
public:
	
	static Rational Add(const Rational A, const Rational B);
	static Rational Multiply(const Rational A, const Rational B);
	static Rational Add(const Rational A, int n);
	static Rational Divide(int n, const Rational A);
	static void Average(Rational r);
	static Rational Average();
private:
	static float suma;
	static int i;
};