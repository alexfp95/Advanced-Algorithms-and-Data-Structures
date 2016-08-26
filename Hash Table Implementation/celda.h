#include <cstdio>
#include <iostream>

using namespace std;

template<class Clave>
class Celda
{
private:
  Clave* nBloques_;
  int size_;
  int pos_;
public:
  Celda (int nBloques);
  ~Celda (void);
  bool buscar (const Clave& X);
  bool insertar (const Clave& X);
  bool llena (void) const;
};

template<class Clave>
Celda<Clave>::Celda (int nBloques):
nBloques_(NULL),
size_(nBloques),
pos_(0)
{
  nBloques_ = new Clave [size_];
}

template<class Clave>
Celda<Clave>::~Celda (void)
{
  if(nBloques_ != NULL)
  {
    delete [] nBloques_;
    nBloques_ = NULL;
  }
}

template<class Clave>
bool Celda<Clave>::buscar (const Clave& X)
{
  bool encontrado = false;
  
  for(int i=0; i<size_; i++)
  {
    if(nBloques_[i] == X)
      encontrado = true;
  }
  
  return encontrado;
}

template<class Clave>
bool Celda<Clave>::insertar (const Clave& X)
{
  if(!llena())
  {
    nBloques_[pos_] = X;
    pos_++;
    return true;
  }
  else
    return false;
}

template<class Clave>
bool Celda<Clave>::llena (void) const
{
  if(pos_ == size_)
    return true;
  else
    return false;
}