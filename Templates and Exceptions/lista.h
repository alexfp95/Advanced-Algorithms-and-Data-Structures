#pragma once

#include "nodo.h"

#include <cstdio>
#include <iostream>

using namespace std;

template <class TDATO>
class lista_t{
private:
	nodo_t<TDATO>* inicio_;
	nodo_t<TDATO>* fin_;
public:
	lista_t (void);
	~lista_t (void);
	bool empty (void);
	void write (ostream& os);
	void insertar_empty (nodo_t<TDATO>* nodo);
	void insertar_inicio (nodo_t<TDATO>* nodo);
	void insertar_final (nodo_t<TDATO>* nodo);
	nodo_t<TDATO>* extraer_inicio (void);
	nodo_t<TDATO>* extraer_final (void);
	nodo_t<TDATO>* get_inicio (void);
	bool busqueda (TDATO dato);
};


template <class TDATO>
lista_t<TDATO>::lista_t (void):
	inicio_(NULL),
	fin_(NULL){}

template <class TDATO>
lista_t<TDATO>::~lista_t (void){ 
	nodo_t<TDATO>* aux = inicio_;
	while(inicio_ != NULL){
		inicio_ = inicio_->get_next();
		delete aux;
		aux = inicio_;
	}
}

template <class TDATO>
bool lista_t<TDATO>::empty (void){
	if(inicio_ == NULL) return true;
	else return false;
}

template <class TDATO>
void lista_t<TDATO>::write (ostream& os){
	nodo_t<TDATO>* aux = inicio_;
	while(aux != NULL){ 
		aux->write(os);
		aux = aux->get_next();
	}
}

template <class TDATO>
void lista_t<TDATO>::insertar_empty (nodo_t<TDATO>* nodo){
	inicio_ = nodo;
	fin_ = nodo;
}

template <class TDATO>
void lista_t<TDATO>::insertar_inicio (nodo_t<TDATO>* nodo){
	if(empty()) 
		insertar_empty(nodo);
	else{
		nodo->set_next(inicio_);
		inicio_->set_prev(nodo);
		inicio_ = nodo;
	}
}

template <class TDATO>
void lista_t<TDATO>::insertar_final  (nodo_t<TDATO>* nodo){
	if(empty())
		insertar_empty(nodo);
	else{
		fin_->set_next(nodo);
		nodo->set_prev(fin_);
		fin_ = nodo;
	}
}

template <class TDATO>
nodo_t<TDATO>* lista_t<TDATO>::extraer_inicio (void){
	if(inicio_ == fin_){ 
		nodo_t<TDATO>* aux = inicio_;
		inicio_ = NULL; 
		fin_ = NULL; 
		return aux;
	}
	else{
		nodo_t<TDATO>* aux = inicio_;
		inicio_ = inicio_->get_next();
		return aux;
	}
}

template <class TDATO>
nodo_t<TDATO>* lista_t<TDATO>::extraer_final (void){
	if(inicio_ == fin_){ 
		nodo_t<TDATO>* aux = fin_;
		inicio_ = NULL; 
		fin_ = NULL; 
		return aux;
	}
	else{
		nodo_t<TDATO>* aux = fin_;		
		fin_ = fin_->get_prev();
		fin_->set_next(NULL);
		return aux;
	}
}

template <class TDATO>
nodo_t<TDATO>* lista_t<TDATO>::get_inicio(){
	return inicio_->get_next();
}

template <class TDATO>
bool lista_t<TDATO>::busqueda (TDATO dato){
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