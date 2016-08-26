#include "nodoAVL.h"
#include "queue.h"
#include "nodo.h"

#include <cstdio>
#include <iostream>

using namespace std;

template<class Clave>
class ArbolAVL
{
private:
  nodoAVL<Clave>* raiz_;
public:
  ArbolAVL (void);
  ~ArbolAVL (void);
  nodoAVL<Clave>* Buscar (Clave clave_dada);
  nodoAVL<Clave>* BuscarRama (nodoAVL<Clave>* nodo, Clave clave_dada);
  void rotacion_II (nodoAVL<Clave>* &nodo);
  void rotacion_DD (nodoAVL<Clave>* &nodo);
  void rotacion_ID (nodoAVL<Clave>* &nodo);
  void rotacion_DI (nodoAVL<Clave>* &nodo);
  void Insertar (Clave ClaveDada);
  void inserta_bal (nodoAVL<Clave>* &nodo, nodoAVL<Clave>* nuevo, bool& crece);
  void insert_re_balancea_izda (nodoAVL<Clave>* &nodo, bool& crece);
  void insert_re_balancea_dcha (nodoAVL<Clave>* &nodo, bool& crece);
  void Eliminar (Clave clave_dada);
  void elimina_rama (nodoAVL<Clave>* &nodo, Clave ClaveDada, bool& decrece);
  void sustituye (nodoAVL<Clave>* &eliminado, nodoAVL<Clave>* &sust, bool &decrece);
  void eliminar_re_balancea_izda (nodoAVL<Clave>* &nodo, bool& decrece);
  void eliminar_re_balancea_dcha (nodoAVL<Clave>* &nodo, bool& decrece);
  void recorreN (nodoAVL<Clave>* raiz);
  void write (void);
};

template<class Clave>
ArbolAVL<Clave>::ArbolAVL (void):
raiz_(NULL)
{}

template<class Clave>
ArbolAVL<Clave>::~ArbolAVL (void)
{}

template<class Clave>
nodoAVL<Clave>* ArbolAVL<Clave>::Buscar (Clave clave_dada)
{
  return BuscarRama(raiz_, clave_dada);
}

template<class Clave>
nodoAVL<Clave>* ArbolAVL<Clave>::BuscarRama (nodoAVL<Clave>* nodo, Clave clave_dada)
{
  if(nodo == NULL)
    return NULL;
  
  if(clave_dada == nodo->clave_)
    return nodo;
  
  if(clave_dada < nodo->clave_)
    return BuscarRama(nodo->izdo_, clave_dada);
  
  else
    return BuscarRama(nodo->dcho_, clave_dada);
}

template<class Clave>
void ArbolAVL<Clave>::rotacion_II (nodoAVL<Clave>* &nodo)
{
  nodoAVL<Clave>* nodo1 = nodo->izdo_;
  nodo->izdo_ = nodo1->dcho_;
  nodo1->dcho_ = nodo;
  
  if(nodo1->bal_ == 1)
  {
    nodo->bal_ = 0;
    nodo1->bal_ = 0;
  }
  
  else
  {
    nodo->bal_ = 1;
    nodo1->bal_ = -1;
  }
  
  nodo = nodo1;
}

template<class Clave>
void ArbolAVL<Clave>::rotacion_DD (nodoAVL<Clave>* &nodo)
{
  nodoAVL<Clave>* nodo1 = nodo->dcho_;
  nodo->dcho_ = nodo1->izdo_;
  nodo1->izdo_ = nodo;
  
  if(nodo1->bal_ == -1)
  {
    nodo->bal_ = 0;
    nodo1->bal_ = 0;
  }
  
  else
  {
    nodo->bal_ = -1;
    nodo1->bal_ = 1;
  }
  
  nodo = nodo1;
}

template<class Clave>
void ArbolAVL<Clave>::rotacion_ID (nodoAVL<Clave>* &nodo)
{
  nodoAVL<Clave>* nodo1 = nodo->izdo_;
  nodoAVL<Clave>* nodo2 = nodo1->dcho_;
  
  nodo->izdo_ = nodo2->dcho_;
  nodo2->dcho_ = nodo;
  nodo1->dcho_ = nodo2->izdo_;
  nodo2->izdo_ = nodo1;
  
  if(nodo2->bal_ == -1)
    nodo1->bal_ = 1;
  else
    nodo1->bal_ = 0;
  
  if(nodo2->bal_ == 1)
    nodo->bal_ = -1;
  else
    nodo->bal_ = 0;
  
  nodo2->bal_ = 0;
  
  nodo = nodo2;
}

template<class Clave>
void ArbolAVL<Clave>::rotacion_DI (nodoAVL<Clave>* &nodo)
{
  nodoAVL<Clave>* nodo1 = nodo->dcho_;
  nodoAVL<Clave>* nodo2 = nodo1->izdo_;
  
  nodo->dcho_ = nodo2->izdo_;
  nodo2->izdo_ = nodo;
  nodo1->izdo_ = nodo2->dcho_;
  nodo2->dcho_ = nodo1;
  
  if(nodo2->bal_ == 1)
    nodo1->bal_ = -1;
  else
    nodo1->bal_ = 0;
  
  if(nodo2->bal_ == -1)
    nodo->bal_ = 1;
  else
    nodo->bal_ = 0;
  
  nodo2->bal_ = 0;
  
  nodo = nodo2;
}

template<class Clave>
void ArbolAVL<Clave>::Insertar (Clave ClaveDada)
{
  nodoAVL<Clave>* nuevo =  new nodoAVL<Clave>(ClaveDada, 0);
  
  bool crece = false;
  
  inserta_bal(raiz_, nuevo, crece);
}

template<class Clave>
void ArbolAVL<Clave>::inserta_bal (nodoAVL<Clave>* &nodo, nodoAVL<Clave>* nuevo, bool& crece)
{
  if(nodo == NULL)
  {
    nodo = nuevo;
    crece = true;
  }
  
  else if (nuevo->clave_ < nodo->clave_)
  {
    inserta_bal(nodo->izdo_, nuevo, crece);
    if(crece)
      insert_re_balancea_izda(nodo, crece);
  }
  
  else if(nuevo->clave_ > nodo->clave_)
  {
    inserta_bal(nodo->dcho_, nuevo, crece);
    if(crece)
      insert_re_balancea_dcha(nodo, crece);
  }
}

template<class Clave>
void ArbolAVL<Clave>::insert_re_balancea_izda (nodoAVL<Clave>* &nodo, bool& crece)
{
  switch(nodo->bal_)
  {
    case -1:  nodo->bal_ = 0;
	      crece = false;
	      break;
	      
    case 0:   nodo->bal_ = 1;
	      break;
	      
    case 1:   nodoAVL<Clave>* nodo1 = nodo->izdo_;
	      if(nodo1->bal_ == 1)
		rotacion_II(nodo);
	      else
		rotacion_ID(nodo);
	      crece = false;
  }
}

template<class Clave>
void ArbolAVL<Clave>::insert_re_balancea_dcha (nodoAVL<Clave>* &nodo, bool& crece)
{
  switch(nodo->bal_)
  {
    case 1:   nodo->bal_ = 0;
	      crece = false;
	      break;
	      
    case 0:   nodo->bal_ = -1;
	      break;
	      
    case -1:  nodoAVL<Clave>* nodo1 = nodo->dcho_;
	      if(nodo1->bal_ == -1)
		rotacion_DD(nodo);
	      else
		rotacion_DI(nodo);
	      crece = false;
  }
}

template<class Clave>
void ArbolAVL<Clave>::Eliminar (Clave clave_dada)
{
  bool decrece = false;
  elimina_rama (raiz_, clave_dada, decrece);
}

template<class Clave>
void ArbolAVL<Clave>::elimina_rama (nodoAVL<Clave>* &nodo, Clave ClaveDada, bool& decrece)
{
  if (nodo == NULL)
    return;
  
  if(ClaveDada < nodo->clave_)
  {
    elimina_rama(nodo->izdo_, ClaveDada, decrece);
    if(decrece)
      eliminar_re_balancea_izda(nodo, decrece);
  }
  
  else if (ClaveDada > nodo->clave_)
  {
    elimina_rama(nodo->dcho_, ClaveDada, decrece);
    if(decrece)
      eliminar_re_balancea_dcha(nodo, decrece);
  }
  
  else
  {
    nodoAVL<Clave>* Eliminado = nodo;
    
    if(nodo->izdo_ == NULL)
    {
      nodo = nodo->dcho_;
      decrece = true;
    }
    
    else if(nodo->dcho_ == NULL)
    {
      nodo = nodo->izdo_;
      decrece = true;
    }
    
    else
    {
      sustituye(Eliminado, nodo->izdo_, decrece);
      if(decrece)
	eliminar_re_balancea_izda(nodo, decrece);
    }
    
    delete Eliminado;
  }
}

template<class Clave>
void ArbolAVL<Clave>::sustituye (nodoAVL<Clave>* &eliminado, nodoAVL<Clave>* &sust, bool &decrece)
{
  if (sust->dcho_ != NULL)
  {
    sustituye(eliminado, sust->dcho_, decrece);
    if (decrece)
      eliminar_re_balancea_dcha(sust, decrece);
  }
  
  else
  {
    eliminado->clave_ = sust->clave_;
    eliminado = sust;
    sust = sust->izdo_;
    decrece = true;
  }
}

template<class Clave>
void ArbolAVL<Clave>::eliminar_re_balancea_izda (nodoAVL<Clave>* &nodo, bool& decrece)
{
  switch (nodo->bal_)
  {
    case -1:  {nodoAVL<Clave>* nodo1 = nodo->dcho_;
	      if (nodo1->bal_ > 0)
		rotacion_DI(nodo);
	      else
	      {
		if (nodo1->bal_ == 0)
		  decrece = false;
		rotacion_DD(nodo);
	      }
	      break;}
	      
    case 0:   nodo->bal_ = -1;
	      decrece = false;
	      break;
	      
    case 1:   nodo->bal_ = 0;
  }
}

template<class Clave>
void ArbolAVL<Clave>::eliminar_re_balancea_dcha (nodoAVL<Clave>* &nodo, bool& decrece)
{
  switch (nodo->bal_) 
  {
    case 1:   {nodoAVL<Clave>* nodo1 = nodo->izdo_;
	      if (nodo1->bal_ < 0)
		rotacion_ID(nodo);
	      else {
		if (nodo1->bal_ == 0)
		  decrece = false;
		rotacion_II(nodo);
	      }
	      break;}
	      
    case 0:   nodo->bal_ = 1;
	      decrece = false;
	      break;
	      
    case -1:  nodo->bal_ = 0;
  }
}

template<class Clave>
void ArbolAVL<Clave>::recorreN (nodoAVL<Clave>* raiz)
{
  queue_t<nodoAVL<Clave>*> Q;
  int Nivel_actual = 0;
  
  cout << "Nivel " << Nivel_actual << ": ";

  nodo_t<nodoAVL<Clave>*>* nodo = new nodo_t<nodoAVL<Clave>*>(raiz, Nivel_actual);
  
  Q.push(nodo);
  
  while(!Q.empty())
  {
    nodo = Q.pop();
    nodo_t<nodoAVL<Clave>*>* hijo_izq = new nodo_t<nodoAVL<Clave>*>(NULL, Nivel_actual);
    nodo_t<nodoAVL<Clave>*>* hijo_der = new nodo_t<nodoAVL<Clave>*>(NULL, Nivel_actual);
    
    if(nodo->get_nivel() > Nivel_actual)
    {
      Nivel_actual = nodo->get_nivel();
      cout << endl << "Nivel " << Nivel_actual << ": ";
    }
    
    if(nodo->get_dato() != NULL)
    {
      cout << "[" << nodo->get_dato()->clave_ << "] ";
      
      hijo_izq->set_dato(nodo->get_dato()->izdo_); hijo_izq->set_nivel(nodo->get_nivel()+1);
      Q.push(hijo_izq);

      hijo_der->set_dato(nodo->get_dato()->dcho_); hijo_der->set_nivel(nodo->get_nivel()+1);
      Q.push(hijo_der);
    }
    
    else
    {
      cout << "[.] ";
    }
  }
}

template<class Clave>
void ArbolAVL<Clave>::write (void)
{
  recorreN(raiz_);
}