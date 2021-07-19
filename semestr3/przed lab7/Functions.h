#pragma once
#include <iostream>
#include <cstdlib>
#include <cmath>
typedef double (*DataPtr);
typedef void (*functionPtr)(DataPtr);
DataPtr initializeData(const int s);
void printSeries(DataPtr s, DataPtr e);
void tripple(DataPtr wsk);
void add_one(DataPtr wsk);
void squareroot(DataPtr wsk);
void executeFunction(void (*f)(DataPtr wsk),DataPtr s, DataPtr e);
void clearData(DataPtr dataPtr1);