#include "nodoBB.h"
#include "queue.h"
#include "nodo.h"

#include <cstdio>
#include <iostream>

using namespace std;

template<class Clave>
class ArbolBB
{
private:
  nodoBB<Clave>* raiz_;
public:
  ArbolBB (void);
  ~ArbolBB (void);
  void Podar (nodoBB<Clave>* &nodo);
  // bool EsVacio (nodoBB<Clave>* nodo);
  // bool EsHoja (nodoBB<Clave>* nodo);
  nodoBB<Clave>* Buscar (Clave clave_dada);
  nodoBB<Clave>* BuscarRama (nodoBB<Clave>* nodo, Clave clave_dada);
  void Insertar (Clave clave_dada);
  void InsertarRama (nodoBB<Clave>* &nodo, Clave clave_dada);
  void Eliminar (Clave clave_dada);
  void EliminarRama (nodoBB<Clave>* &nodo, Clave clave_dada);
  void sustituye (nodoBB<Clave>* &eliminado, nodoBB<Clave>* &sust);
  void recorreN (nodoBB<Clave>* raiz);
  void write (void);
  bool empty (void);
};

template<class Clave>
ArbolBB<Clave>::ArbolBB (void):
raiz_(NULL)
{}

template<class Clave>
ArbolBB<Clave>::~ArbolBB (void)
{
  Podar(raiz_);
}

template<class Clave>
void ArbolBB<Clave>::Podar (nodoBB<Clave>* &nodo)
{
  if(nodo == NULL)
    return ;
  
  Podar(nodo->izdo_);
  Podar(nodo->dcho_);
  
  delete nodo;
  nodo = NULL;
}

/*template<class Clave>
bool ArbolBB<Clave>::EsVacio (nodoBB<Clave>* nodo)
{
  return nodo == NULL;
}*/

/*template<class Clave>
bool ArbolBB<Clave>::EsHoja (nodoBB<Clave>* nodo)
{
  return (!nodo->dcho_ && !nodo->izdo_);
}*/

template<class Clave>
nodoBB<Clave>* ArbolBB<Clave>::Buscar (Clave clave_dada)
{
  return BuscarRama(raiz_, clave_dada);
}

template<class Clave>
nodoBB<Clave>* ArbolBB<Clave>::BuscarRama (nodoBB<Clave>* nodo, Clave clave_dada)
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
void ArbolBB<Clave>::Insertar (Clave clave_dada)
{
  InsertarRama(raiz_, clave_dada);
}

template<class Clave>
void ArbolBB<Clave>::InsertarRama(nodoBB<Clave>* &nodo, Clave clave_dada)
{
  if(nodo == NULL)
    nodo = new nodoBB<Clave>(clave_dada, clave_dada);
  
  else if(clave_dada < nodo->clave_)
    InsertarRama(nodo->izdo_, clave_dada);
  
  else
    InsertarRama(nodo->dcho_, clave_dada);
}

template<class Clave>
void ArbolBB<Clave>::Eliminar (Clave clave_dada)
{
  EliminarRama(raiz_, clave_dada);
}

template<class Clave>
void ArbolBB<Clave>::EliminarRama (nodoBB<Clave>* &nodo, Clave clave_dada)
{
  if(nodo == NULL)
    return;
  
  if(clave_dada < nodo->clave_)
    EliminarRama(nodo->izdo_, clave_dada);
  
  else if(clave_dada > nodo->clave_)
    EliminarRama(nodo->dcho_, clave_dada);
  
  else
  {
    nodoBB<Clave>* Eliminado = nodo;
    
    if(nodo->dcho_ == NULL)
      nodo = nodo->izdo_;
    
    else if(nodo->izdo_ == NULL)
      nodo = nodo->dcho_;
    
    else
      sustituye(Eliminado, nodo->izdo_);
    
    delete (Eliminado);
  }
}

template<class Clave>
void ArbolBB<Clave>::sustituye (nodoBB<Clave>* &eliminado, nodoBB<Clave>* &sust)
{
  if(sust->dcho_ != NULL)
    sustituye(eliminado, sust->dcho_);
  
  else
  {
    // eliminado->Info = sust->Info;
    eliminado->clave_ = sust->clave_;
    eliminado = sust;
    sust = sust->izdo_;
  }
}

template<class Clave>
void ArbolBB<Clave>::recorreN (nodoBB<Clave>* raiz)
{
  queue_t<nodoBB<Clave>*> Q;
  int Nivel_actual = 0;
  
  cout << "Nivel " << Nivel_actual << ": ";

  nodo_t<nodoBB<Clave>*>* nodo = new nodo_t<nodoBB<Clave>*>(raiz, Nivel_actual);
  
  Q.push(nodo);
  
  while(!Q.empty())
  {
    nodo = Q.pop();
    nodo_t<nodoBB<Clave>*>* hijo_izq = new nodo_t<nodoBB<Clave>*>(NULL, Nivel_actual);
    nodo_t<nodoBB<Clave>*>* hijo_der = new nodo_t<nodoBB<Clave>*>(NULL, Nivel_actual);
    
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
void ArbolBB<Clave>::write (void)
{
  recorreN(raiz_);
}

template<class Clave>
bool ArbolBB<Clave>::empty (void)
{
  if(raiz_ == NULL)
    return true;
  else
    return false;
}