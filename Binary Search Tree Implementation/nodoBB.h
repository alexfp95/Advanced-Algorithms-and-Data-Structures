#pragma once

#include <cstdio>
#include <iostream>

using namespace std;

template<class Clave>
class nodoBB
{
public:
  Clave dato_;
  Clave clave_;
  nodoBB* izdo_;
  nodoBB* dcho_;
  nodoBB (Clave dato, Clave clave, nodoBB* izdo=NULL, nodoBB* dcho=NULL);
};

template<class Clave>
nodoBB<Clave>::nodoBB (Clave dato, Clave clave, nodoBB* izdo, nodoBB* dcho):
dato_(dato),
clave_(clave),
izdo_(izdo),
dcho_(dcho)
{}

