#pragma once

#include <cstdio>
#include <iostream>

using namespace std;

template <class TDATO> 
class vector_t 
{
private:
  TDATO* datos_;
  int sz_;
public:
  vector_t(int sz);
  ~vector_t(void);
  TDATO get_dato(int posicion);
  void set_dato(int posicion, TDATO dato);
  int get_sz(void);
  void imprimir(void);
  bool busqueda(TDATO x);
};


template <class TDATO>
vector_t<TDATO>::vector_t(int sz):
datos_(NULL),
sz_(sz){
	try
	{
	  datos_ = new TDATO [sz_];
	}
	catch (bad_alloc& ba)
	{
	  cerr << "Excepcion: Fallo en reserva de mem dinamica" << endl;
	  throw;
	}
}

template <class TDATO> 
vector_t<TDATO>::~vector_t(void){
	if(datos_ != NULL){
		delete [] datos_;
		datos_ = NULL;
	}
}

template <class TDATO>
TDATO vector_t<TDATO>::get_dato(int posicion){
	return datos_[posicion % sz_];
}

template <class TDATO>
void vector_t<TDATO>::set_dato(int posicion, TDATO dato){
	datos_[posicion % sz_] = dato;
}

template <class TDATO> 
int vector_t<TDATO>::get_sz(void){
	return sz_;
}

template <class TDATO>
void vector_t<TDATO>::imprimir(void){
  for(int i=0; i<sz_; i++){
    cout << " " << datos_[i];
  }
}

template <class TDATO> 
bool vector_t<TDATO>::busqueda(TDATO x){
  bool encontrado=false;
  
  for(int i=0; i<sz_; i++){
    if(datos_[i] == x)
      encontrado=true;
  }
  
  return encontrado;
}