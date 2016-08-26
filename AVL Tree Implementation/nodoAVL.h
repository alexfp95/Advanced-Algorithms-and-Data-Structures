#include <cstdio>
#include <iostream>

using namespace std;

template<class Clave>
class nodoAVL
{
public:
  Clave clave_;
  int bal_;
  nodoAVL<Clave>* izdo_;
  nodoAVL<Clave>* dcho_;
  nodoAVL(Clave clave, nodoAVL<Clave>* izdo=NULL, nodoAVL<Clave>* dcho=NULL);
};

template<class Clave>
nodoAVL<Clave>::nodoAVL (Clave clave, nodoAVL<Clave>* izdo, nodoAVL<Clave>* dcho):
clave_(clave),
bal_(0),
izdo_(izdo),
dcho_(dcho)
{}
