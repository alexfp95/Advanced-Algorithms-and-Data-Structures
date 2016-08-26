#include "celda.h"

#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>

template<class Clave>
class Tabla
{
private:
  Celda<Clave>** nCeldas_;
  int size_;
  int hcode_;
  int gcode_;
  int h (Clave& X);
  int g (Clave& X, int intento);
public:
  Tabla (int nCeldas, int nBloques, int h_code, int g_code);
  ~Tabla (void);
  bool buscar (Clave& X, int pruebas);
  bool insertar (Clave& X, int pruebas);
};

template<class Clave>
Tabla<Clave>::Tabla (int nCeldas, int nBloques, int hcode, int gcode):
nCeldas_(NULL),
size_(nCeldas),
hcode_(hcode),
gcode_(gcode)
{
  nCeldas_ = new Celda<Clave>* [nCeldas];
  
  for(int i=0; i<nCeldas; i++)
    nCeldas_[i] = new Celda<Clave> (nBloques);
}

template<class Clave>
Tabla<Clave>::~Tabla (void)
{
  if(nCeldas_ != NULL)
  {
    for(int i=0; i<size_; i++)
      delete nCeldas_[i];
    
    delete [] nCeldas_;
    nCeldas_ = NULL;
  }
}

template<class Clave>
int Tabla<Clave>::h (Clave& X) 
{
  if(hcode_ == 1)
  {
    int aux = X.get();
    return aux % size_;
  }
  
  if(hcode_ == 2)
  {
    int suma = 0;
    int z = X.get();
    int aux;
    
    while(z > 0)
    {
      aux = z % 10;
      suma = suma + aux;
      z = z / 10;
    }
    
    return (suma % size_);
  }
  
  if(hcode_ == 3)
  {
    srand(X.get());
    return rand() % size_;
  }
}

template<class Clave>
int Tabla<Clave>::g (Clave& X, int intento)
{
  
  if(gcode_ == 1)
  {
    return intento;
  }
  
  if(gcode_ == 2)
  {
    return intento*intento;
  }
  
  if(gcode_ == 3)
  {
    srand(X.get());
    return (rand() % size_)*intento;
  }
  
  if(gcode_ == 4)
  {
    srand(X.get());
    for(int i=1; i < intento; i++)
      rand();
    return rand() % size_;
  }
}

template<class Clave>
bool Tabla<Clave>::buscar (Clave& X, int pruebas)
{
  int pos = h(X);
  int intento = 1;
  
  if(nCeldas_[pos]->buscar(X))
    return true;
  
  else
  {
    while(intento < pruebas)
    {
      pos = (h(X)+g(X, intento)) % size_;
      if(nCeldas_[pos]->buscar(X))
	return true;
      else
	intento++;
    }
    return false;
  }
}

template<class Clave>
bool Tabla<Clave>::insertar (Clave& X, int pruebas)
{
  int pos = h(X);
  int intento = 1;
  
  if(!buscar(X, pruebas))
  {
    if(nCeldas_[pos]->insertar(X))
      return true;
    
    else
    {
      while(intento < pruebas)
      {
	pos = (h(X)+g(X, intento)) % size_;
	if(nCeldas_[pos]->insertar(X))
	  return true;
	else
	  intento++;
      }
      return false;
    }
  }
}
