#include "FractionArray.h"

FractionArray :: FractionArray(int size)
{
    _s=size;   
    T=new Fraction[size];
}
Fraction& FractionArray :: operator[](unsigned i)
{
    return T[i];
}

const Fraction& FractionArray :: operator[](unsigned i) const
{
    return T[i];
}
std::ostream& operator<< (std::ostream& strm, const FractionArray &_tab)
{
    strm << "[ ";
    for(int i=0;i<_tab._s;i++)
    {
        strm << _tab.T[i] << " ";
    }
    strm << "]";
    return strm;
}
FractionArray :: ~FractionArray()
{
    delete[] T;
}