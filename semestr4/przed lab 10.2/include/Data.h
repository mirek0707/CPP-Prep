#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <functional>
#include "Sum.h"
using namespace std;
class Data
{
public:
    Data(string n, vector<double> V) : _n(n), _V(V){}
    void print() const
    {
        cout<<_n<<": ";
        for_each(_V.begin(), _V.end(), [](double n){cout<<setw(6)<<n;});
        cout<<endl;
    }
    double operator[] (int index) const 
    {
        return _V[index];
    }
    friend Sum sumData(const Data &d);
private:
    string _n;
    vector<double> _V;
};
Sum sumData(const Data &d)
{
    return Sum(std::accumulate(std::begin(d._V), std::end(d._V), 0.0));
}