#include "lista.h"
#include "nodo.h"
#include "queue.h"
#include "stack.h"
#include "vector.h"
#include "natural.h"
#include "entero.h"
#include "racional.h"
#include "real.h"
#include "complejo.h"
#include "numero.h"

#include <cstdio>
#include <iostream>

using namespace std;

void fvector (void){
  int bucle=1; int opcion; int bucle_in; int size; int pos=0;
  
  cout << "Introduzca el size del vector: ";
  cin >> size;
  
  vector_t<Numero*> myvector (size);
  
   while(bucle==1){
    cout << "[1] Introducir elemento" << endl;
    cout << "[2] Mostrar vector" << endl;
    cout << "[0] Borrar el vector y salir" << endl;
    cout << "Introduzca su opcion: ";
    cin >> opcion;
    
    cout << endl;
    switch(opcion){
      case 1: bucle_in=1; 
	      while(bucle_in==1){
		cout << "[1] Natural" << endl;
		cout << "[2] Entero" << endl;
		cout << "[3] Racional" << endl;
		cout << "[4] Real" << endl;
		cout << "[5] Complejo" << endl;
		cout << "[0] Cancelar" << endl;
		cout << "Introduzca su opcion: ";
		cin >> opcion;
		
		switch(opcion){
		  case 1: {if(pos < myvector.get_sz())
			  {
			    Numero* N = new Natural();
			    cout << "Introducir el numero a insertar: ";
			    N->fromStream(cin);
			    myvector.set_dato(pos, N);
			    pos++;
			    bucle_in=0;
			  }
			  else cout << "Vector lleno" << endl;
			  break;}
			  
		  case 2: {if(pos < myvector.get_sz())
			  {
			    Numero* N = new Entero();
			    cout << "Introducir el numero a insertar: ";
			    N->fromStream(cin);
			    myvector.set_dato(pos, N);
			    pos++;
			    bucle_in=0;
			  }
			  else cout << "Vector lleno" << endl;
			  break;}
			  
		  case 3: {if(pos < myvector.get_sz())
			  {
			    Numero* N = new Racional();
			    cout << "Introducir el numero a insertar: ";
			    N->fromStream(cin);
			    myvector.set_dato(pos, N);
			    pos++;
			    bucle_in=0;
			  }
			  else cout << "Vector lleno" << endl;
			  break;}
			  
		  case 4: {if(pos < myvector.get_sz())
			  {
			    Numero* N = new Real();
			    cout << "Introducir el numero a insertar: ";
			    N->fromStream(cin);
			    myvector.set_dato(pos, N);
			    pos++;
			    bucle_in=0;
			  }
			  else cout << "Vector lleno" << endl;
			  break;}
			  
		  case 5: {if(pos < myvector.get_sz())
			  {
			    Numero* N = new Complejo();
			    cout << "Introducir el numero a insertar: ";
			    N->fromStream(cin);
			    myvector.set_dato(pos, N);
			    pos++;
			    bucle_in=0;
			  }
			  else cout << "Vector lleno" << endl;
			  break;}
			  
		  case 0: bucle_in=0; break;
		  
		  default: cout << "Opcion invalida" << endl; break;
		}
	      }
	      break;
		
      case 2: if(pos != 0){
		Numero* N;
		for(int i=0; i<pos; i++){
		  N = myvector.get_dato(i);
		  N->toStream(cout) << "   ";
		}
	      } break;
      	      
      case 0: myvector.~vector_t(); bucle=0; break;
      
      default: cout << "Opcion invalida" << endl; break;
    }
    cout << endl;
  }
}

void flista (void){
  int bucle=1; int opcion; int bucle_in;
  
  lista_t<Numero*> mylist;
  
  while(bucle==1){
    cout << "[1] Introducir numero" << endl;
    cout << "[2] Sacar numero por el inicio" << endl;
    cout << "[3] Sacar numero por el final" << endl;
    cout << "[4] Mostrar la lista" << endl;
    cout << "[5] Estado de la lista" << endl;
    cout << "[0] Borrar la lista y salir" << endl;
    cout << "Introduzca su opcion: ";
    cin >> opcion;
    
    cout << endl;
    switch(opcion){
      case 1: bucle_in=1; 
	      while(bucle_in==1){
		cout << "[1] Natural" << endl;
		cout << "[2] Entero" << endl;
		cout << "[3] Racional" << endl;
		cout << "[4] Real" << endl;
		cout << "[5] Complejo" << endl;
		cout << "[0] Cancelar" << endl;
		cout << "Introduzca su opcion: ";
		cin >> opcion;
		
		switch(opcion){
		  case 1: {
			  try
			  {
			    Numero* N = new Natural();
			    cout << "Introducir el numero a insertar: ";
			    N->fromStream(cin);
			    nodo_t<Numero*>* aux = new nodo_t<Numero*>(N);
			    mylist.insertar_final(aux);
			    bucle_in=0;
			  }
			  catch (bad_alloc& ba)
			  {
			    cerr << "Excepcion: Fallo en reserva de mem dinamica" << endl;
			    throw;
			  }
			  break;}
			  
		  case 2: {
			  try
			  {
			    Numero* N = new Entero();
			    cout << "Introducir el numero a insertar: ";
			    N->fromStream(cin);
			    nodo_t<Numero*>* aux = new nodo_t<Numero*>(N);
			    mylist.insertar_final(aux);
			    bucle_in=0;
			  }
			  catch (bad_alloc& ba)
			  {
			    cerr << "Excepcion: Fallo en reserva de mem dinamica" << endl;
			    throw;
			  }
			  break;}
			  
		  case 3: {
			  try
			  {
			  Numero* N = new Racional();
			  cout << "Introducir el numero a insertar (numerador denominador): ";
			  N->fromStream(cin);
			  nodo_t<Numero*>* aux = new nodo_t<Numero*>(N);
			  mylist.insertar_final(aux);
			  bucle_in=0;
			  }
			  catch (bad_alloc& ba)
			  {
			    cerr << "Excepcion: Fallo en reserva de mem dinamica" << endl;
			    throw;
			  }
			  break;}
			  
		  case 4: {
			  try
			  {
			    Numero* N = new Real();
			    cout << "Introducir el numero a insertar: ";
			    N->fromStream(cin);
			    nodo_t<Numero*>* aux = new nodo_t<Numero*>(N);
			    mylist.insertar_final(aux);
			    bucle_in=0;
			  }
			  catch (bad_alloc& ba)
			  {
			    cerr << "Excepcion: Fallo en reserva de mem dinamica" << endl;
			    throw;
			  }
			  break;}
			  
		  case 5: {
			  try
			  {
			    Numero* N = new Complejo();
			    cout << "Introducir el numero a insertar (parte_real parte_imaginaria): ";
			    N->fromStream(cin);
			    nodo_t<Numero*>* aux = new nodo_t<Numero*>(N);
			    mylist.insertar_final(aux);
			    bucle_in=0;
			  }
			  catch (bad_alloc& ba)
			  {
			    cerr << "Excepcion: Fallo en reserva de mem dinamica" << endl;
			    throw;
			  }
			  break;}
			  
		  case 0: bucle_in=0; break;
		  
		  default: cout << "Opcion invalida" << endl; break;
		}
	      }
	      break;
		
      case 2: {if(!mylist.empty()){
		nodo_t<Numero*>* aux = mylist.extraer_inicio();
		Numero* N = aux->get_dato();
		N->toStream(cout); cout << " ha sido extraido" << endl;
	       }
	       else
		 cout << "La lista esta vacia" << endl;
	       break;}
	       
      case 3: {if(!mylist.empty()){
		nodo_t<Numero*>* aux = mylist.extraer_final();
		Numero* N = aux->get_dato();
		N->toStream(cout); cout << " ha sido extraido" << endl;
	       }
	       else
		 cout << "La lista esta vacia" << endl;
	       break;}
	       
      case 4: if(!mylist.empty()){
		nodo_t<Numero*>* aux = mylist.extraer_inicio();
		mylist.insertar_inicio(aux);
		Numero* N;
		while(aux != NULL){
		  N = aux->get_dato();
		  N->toStream(cout) << "   ";
		  aux = aux->get_next();
		}
		cout << endl;
	      }
	      else
		cout << "La lista esta vacia" << endl;
	      break;
      
      case 5: if(mylist.empty())
		cout << "La lista esta vacia" << endl;
	      else
		cout << "La lista no esta vacia" << endl;
	      break;
	      	      
      case 0: mylist.~lista_t(); bucle=0; break;
      
      default: cout << "Opcion invalida" << endl; break;
    }
    cout << endl;
  }
}

void fcola (void){
  int bucle=1; int opcion; int bucle_in;
  
  queue_t<Numero*> myqueue;
  
  while(bucle==1){
    cout << "[1] Hacer PUSH" << endl;
    cout << "[2] Hacer POP" << endl;
    cout << "[3] Mostrar la cola" << endl;
    cout << "[4] Estado de la cola" << endl;
    cout << "[0] Borrar la cola y salir" << endl;
    cout << "Introduzca su opcion: ";
    cin >> opcion;
    
    cout << endl;
    switch(opcion){
      case 1: bucle_in=1; 
	      while(bucle_in==1){
		cout << "[1] Natural" << endl;
		cout << "[2] Entero" << endl;
		cout << "[3] Racional" << endl;
		cout << "[4] Real" << endl;
		cout << "[5] Complejo" << endl;
		cout << "[0] Cancelar" << endl;
		cout << "Introduzca su opcion: ";
		cin >> opcion;
		
		switch(opcion){
		  case 1: {
			  try
			  {
			    Numero* N = new Natural();
			    cout << "Introducir el numero a insertar: ";
			    N->fromStream(cin);
			    nodo_t<Numero*>* aux = new nodo_t<Numero*>(N);
			    myqueue.push(aux);
			    bucle_in=0;
			  }
			  catch (bad_alloc& ba)
			  {
			    cerr << "Excepcion: Fallo en reserva de mem dinamica" << endl;
			    throw;
			  }
			  break;}
			  
		  case 2: {
			  try
			  {
			    Numero* N = new Entero();
			    cout << "Introducir el numero a insertar: ";
			    N->fromStream(cin);
			    nodo_t<Numero*>* aux = new nodo_t<Numero*>(N);
			    myqueue.push(aux);
			    bucle_in=0;
			  }
			  catch (bad_alloc& ba)
			  {
			    cerr << "Excepcion: Fallo en reserva de mem dinamica" << endl;
			    throw;
			  }
			  break;}
			  
		  case 3: {
			  try
			  {
			    Numero* N = new Racional();
			    cout << "Introducir el numero a insertar (numerador denominador): ";
			    N->fromStream(cin);
			    nodo_t<Numero*>* aux = new nodo_t<Numero*>(N);
			    myqueue.push(aux);
			    bucle_in=0;
			  }
			  catch (bad_alloc& ba)
			  {
			    cerr << "Excepcion: Fallo en reserva de mem dinamica" << endl;
			    throw;
			  }
			  break;}
			  
		  case 4: {
			  try
			  {
			    Numero* N = new Real();
			    cout << "Introducir el numero a insertar: ";
			    N->fromStream(cin);
			    nodo_t<Numero*>* aux = new nodo_t<Numero*>(N);
			    myqueue.push(aux);
			    bucle_in=0;
			  }
			  catch (bad_alloc& ba)
			  {
			    cerr << "Excepcion: Fallo en reserva de mem dinamica" << endl;
			    throw;
			  }
			  break;}
			  
		  case 5: {
			  try
			  {
			    Numero* N = new Complejo();
			    cout << "Introducir el numero a insertar (parte_real parte_imaginaria): ";
			    N->fromStream(cin);
			    nodo_t<Numero*>* aux = new nodo_t<Numero*>(N);
			    myqueue.push(aux);
			    bucle_in=0;
			  }
			  catch (bad_alloc& ba)
			  {
			    cerr << "Excepcion: Fallo en reserva de mem dinamica" << endl;
			    throw;
			  }
			  break;}
			  
		  case 0: bucle_in=0; break;
		  
		  default: cout << "Opcion invalida" << endl; break;
		}
	      }
	      break;
		
      case 2: {if(!myqueue.empty()){
		nodo_t<Numero*>* aux = myqueue.pop();
		Numero* N = aux->get_dato();
		N->toStream(cout); cout << " ha sido extraido" << endl;
	       }
	       else
		 cout << "La cola esta vacia" << endl;
	       break;}
      	      
      case 3: if(!myqueue.empty()){
		nodo_t<Numero*>* aux = myqueue.pop();
		myqueue.insertar_inicio(aux);
		Numero* N;
		while(aux != NULL){
		  N = aux->get_dato();
		  N->toStream(cout) << "   ";
		  aux = aux->get_next();
		}
		cout << endl;
	      }
	      else
		cout << "La cola esta vacia" << endl;
	      break;
	
      case 4: if(myqueue.empty())
		cout << "La cola esta vacia" << endl;
	      else
		cout << "La cola no esta vacia" << endl;
	      break;
	      	      
      case 0: myqueue.~queue_t(); bucle=0; break;
      
      default: cout << "Opcion invalida" << endl; break;
    }
    cout << endl;
  }
}

void fpila (void){
  int bucle=1; int opcion; int bucle_in;
  
  stack_t<Numero*> mystack;
  
  while(bucle==1){
    cout << "[1] Hacer PUSH" << endl;
    cout << "[2] Hacer POP" << endl;
    cout << "[3] Mostrar la pila" << endl;
    cout << "[4] Estado de la pila" << endl;
    cout << "[0] Borrar la pila y salir" << endl;
    cout << "Introduzca su opcion: ";
    cin >> opcion;
    
    cout << endl;
    switch(opcion){
      case 1: bucle_in=1; 
	      while(bucle_in==1){
		cout << "[1] Natural" << endl;
		cout << "[2] Entero" << endl;
		cout << "[3] Racional" << endl;
		cout << "[4] Real" << endl;
		cout << "[5] Complejo" << endl;
		cout << "[0] Cancelar" << endl;
		cout << "Introduzca su opcion: ";
		cin >> opcion;
		
		switch(opcion){
		  case 1: {
			  try
			  {
			    Numero* N = new Natural();
			    cout << "Introducir el numero a insertar: ";
			    N->fromStream(cin);
			    nodo_t<Numero*>* aux = new nodo_t<Numero*>(N);
			    mystack.push(aux);
			    bucle_in=0;
			  }
			  catch (bad_alloc& ba)
			  {
			    cerr << "Excepcion: Fallo en reserva de mem dinamica" << endl;
			    throw;
			  }
			  break;}
			  
		  case 2: {
			  try
			  {
			    Numero* N = new Entero();
			    cout << "Introducir el numero a insertar: ";
			    N->fromStream(cin);
			    nodo_t<Numero*>* aux = new nodo_t<Numero*>(N);
			    mystack.push(aux);
			    bucle_in=0;
			  }
			  catch (bad_alloc& ba)
			  {
			    cerr << "Excepcion: Fallo en reserva de mem dinamica" << endl;
			    throw;
			  }
			  break;}
			  
		  case 3: {
			  try
			  {
			    Numero* N = new Racional();
			    cout << "Introducir el numero a insertar (numerador denominador): ";
			    N->fromStream(cin);
			    nodo_t<Numero*>* aux = new nodo_t<Numero*>(N);
			    mystack.push(aux);
			    bucle_in=0;
			  }
			  catch (bad_alloc& ba)
			  {
			    cerr << "Excepcion: Fallo en reserva de mem dinamica" << endl;
			    throw;
			  }
			  break;}
			  
		  case 4: {
			  try{
			    Numero* N = new Real();
			    cout << "Introducir el numero a insertar: ";
			    N->fromStream(cin);
			    nodo_t<Numero*>* aux = new nodo_t<Numero*>(N);
			    mystack.push(aux);
			    bucle_in=0;
			  }
			  catch (bad_alloc& ba)
			  {
			    cerr << "Excepcion: Fallo en reserva de mem dinamica" << endl;
			    throw;
			  }
			  break;}
			  
		  case 5: {
			  try
			  {
			    Numero* N = new Complejo();
			    cout << "Introducir el numero a insertar (parte_real parte_imaginaria): ";
			    N->fromStream(cin);
			    nodo_t<Numero*>* aux = new nodo_t<Numero*>(N);
			    mystack.push(aux);
			    bucle_in=0;
			  }
			  catch (bad_alloc& ba)
			  {
			    cerr << "Excepcion: Fallo en reserva de mem dinamica" << endl;
			    throw;
			  }
			  break;}
			  
		  case 0: bucle_in=0; break;
		  
		  default: cout << "Opcion invalida" << endl; break;
		}
	      }
	      break;
		
      case 2: {if(!mystack.empty()){
		nodo_t<Numero*>* aux = mystack.pop();
		Numero* N = aux->get_dato();
		N->toStream(cout); cout << " ha sido extraido" << endl;
	       }
	       else
		 cout << "La pila esta vacia" << endl;
	       break;}
      	      
      case 3: if(!mystack.empty()){
		nodo_t<Numero*>* aux = mystack.pop();
		mystack.push(aux);
		Numero* N;
		while(aux != NULL){
		  N = aux->get_dato();
		  N->toStream(cout) << "   ";
		  aux = aux->get_next();
		}
		cout << endl;
	      }
	      else
		cout << "La pila esta vacia" << endl;
	      break;
	
      case 4: if(mystack.empty())
		cout << "La pila esta vacia" << endl;
	      else
		cout << "La pila no esta vacia" << endl;
	      break;
	      	      
      case 0: mystack.~stack_t(); bucle=0; break;
      
      default: cout << "Opcion invalida" << endl; break;
    }
    cout << endl;
  }
}

int main (void) {
  int opcion; int bucle=1;
  
  cout << "Algoritmos y Estructura de Datos Avanzados. Practica 3" << endl;
  cout << "Alexis Daniel Fuentes Pérez" << endl;
    
  while(bucle==1){
    cout << endl;
    cout << "[1] Vector" << endl;
    cout << "[2] Lista enlazada" << endl;
    cout << "[3] Pila" << endl;
    cout << "[4] Cola" << endl;
    cout << "[0] Salir" << endl;
    cout << "Introduzca su opcion: ";
    cin >> opcion;
    cout << endl;
    
    switch(opcion){
      case 1: fvector(); break;
      case 2: flista(); break;
      case 3: fpila(); break;
      case 4: fcola(); break;
      case 0: bucle=0; break;
      default: cout << "Ha introducido una opcion invalida" << endl;
    }
  }
}