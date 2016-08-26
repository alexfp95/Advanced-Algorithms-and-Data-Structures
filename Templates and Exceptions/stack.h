#pragma once

#include "nodo.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

template <class TDATO>
class stack_t
{
private:
  nodo_t<TDATO>* inicio_;
  nodo_t<TDATO>* fin_;
public:
  stack_t(void);
  ~stack_t(void);
  void insertar_empty(nodo_t<TDATO>* nodo);
  void push(nodo_t<TDATO>* nodo);
  nodo_t<TDATO>* pop(void);
  bool empty(void);
  void write (ostream& os);
  bool busqueda(TDATO dato);
};


template <class TDATO>
stack_t<TDATO>::stack_t(void):
inicio_(NULL),
fin_(NULL)
{}

template <class TDATO>
stack_t<TDATO>::~stack_t(void)
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
void stack_t<TDATO>::insertar_empty (nodo_t<TDATO>* nodo)
{
  inicio_ = nodo;
  fin_ = nodo;
}

template <class TDATO>
void stack_t<TDATO>::push (nodo_t<TDATO>* nodo)
{
  if(empty()) 
    insertar_empty(nodo);
  else
  {
    nodo->set_next(inicio_);
    inicio_ = nodo;
  }
}

template <class TDATO>
nodo_t<TDATO>* stack_t<TDATO>::pop (void)
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
bool stack_t<TDATO>::empty(void)
{ 
  if(inicio_ == NULL)
    return true;
  else 
    return false;
}

template <class TDATO>
void stack_t<TDATO>::write (ostream& os)
{
  nodo_t<TDATO>* aux = inicio_;
  while(aux != NULL)
  { 
    aux->write(os);
    aux = aux->get_next();
  }
}

template <class TDATO>
bool stack_t<TDATO>::busqueda (TDATO dato)
{
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