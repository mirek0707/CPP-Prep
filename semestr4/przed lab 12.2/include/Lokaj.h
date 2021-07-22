#pragma once
#include<iostream>
#include "Pomieszczenie.h"
using namespace std;

template <void (Pomieszczenie::*f)() const> 
void Lokaj(Pomieszczenie &p)
{
    (p.*f)();
}

template <void (Pomieszczenie::*f)() const> 
void Lokaj(const Pomieszczenie &p)
{
   cout<<"Pomieszczenie "<< p.getName() <<" jest zamknięte." <<std::endl;
}

template <int N>
void Lokaj(const Pomieszczenie& p)
{
    std::cout<<"Nic nie robie." <<std::endl;
}