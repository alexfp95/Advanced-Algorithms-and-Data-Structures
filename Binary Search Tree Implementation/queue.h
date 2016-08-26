#pragma once

#include "nodo.h"

#include <cstdio>
#include <iostream>

using namespace std;

template <class TDATO>
class queue_t
{
private:
  nodo_t<TDATO>* inicio_;
  nodo_t<TDATO>* fin_;
public:
  queue_t(void);
  ~queue_t(void);
  void insertar_empty(nodo_t<TDATO>* nodo);
  void push(nodo_t<TDATO>* nodo);
  nodo_t<TDATO>* pop(void);
  bool empty(void);
  void write (ostream& os);
  bool busqueda(TDATO dato);
  void insertar_inicio (nodo_t<TDATO>* nodo);
};

template <class TDATO>
queue_t<TDATO>::queue_t(void):
inicio_(NULL),
fin_(NULL)
{}

template <class TDATO>
queue_t<TDATO>::~queue_t(void)
{
  nodo_t<TDATO>* aux = inicio_;
  while(inicio_ != NULL)
  {
    inicio_ = inicio_->get_next();
    delete aux;
    aux = inicio_;
  }
}

template <class TDATO>
void queue_t<TDATO>::insertar_empty (nodo_t<TDATO>* nodo)
{
  inicio_ = nodo;
  fin_ = nodo;
}

template <class TDATO>
void queue_t<TDATO>::push (nodo_t<TDATO>* nodo)
{
  if(empty()) 
    insertar_empty(nodo);
  else
  {
    fin_->set_next(nodo);
    fin_ = nodo;
  }
}

template <class TDATO>
nodo_t<TDATO>* queue_t<TDATO>::pop(void)
{ 
  if(inicio_ == fin_)
  { 
    nodo_t<TDATO>* aux = inicio_;
    inicio_ = NULL; 
    fin_ = NULL; 
    return aux;
  }
  else
  {
    nodo_t<TDATO>* aux = inicio_;
    inicio_ = inicio_->get_next();
    return aux;
  }
}

template <class TDATO>
bool queue_t<TDATO>::empty(void){ 
  if(inicio_ == NULL)
    return true;
  else 
    return false;
}

template <class TDATO>
void queue_t<TDATO>::write (ostream& os){
  nodo_t<TDATO>* aux = inicio_;
  while(aux != NULL)
  { 
    aux->write(os);
    aux = aux->get_next();
  }
}

template <class TDATO>
bool queue_t<TDATO>::busqueda (TDATO dato){
  bool encontrado=false;
  
  nodo_t<TDATO>* aux = inicio_;
  
  while((encontrado==false) && (aux != NULL)){
    if(aux->get_dato() == dato)
      encontrado=true;
    else
      aux = aux->get_next();
  }
  
  return encontrado;
}

template <class TDATO>
void queue_t<TDATO>::insertar_inicio (nodo_t<TDATO>* nodo){
	if(empty()) 
		insertar_empty(nodo);
	else{
		nodo->set_next(inicio_);
		inicio_->set_prev(nodo);
		inicio_ = nodo;
	}
}