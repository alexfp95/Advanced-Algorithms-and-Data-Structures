#include "ArbolAVL.h"
#include "contador.h"
#include "dni.h"

#include <cstdio>
#include <iostream>

using namespace std;

Contador DNI::Comparaciones;

int main (void)
{
  int N, P;
  int error=1;
  
  cout << "Algoritmos y Estructuras de Datos Avanzadas" << endl;
  cout << "Practica 7. Arboles AVL. Modo estadisticas." << endl << endl;
  
  cout << "Alexis Daniel Fuentes Perez" << endl << endl;
  
  cout << "Introducir el tamaño del arbol: "; cin >> N; 
  cout << endl;
  
  while(error)
  {
    cout << "Introducir el numero de pruebas: "; cin >> P; 
    cout << endl;
    
    if(P > N)
      cout << "Error. El numero de pruebas debe ser menor o igual al tamaño del arbol." << endl;
    else
      error=0;
  }
  
  ArbolAVL<DNI> Ar;
    
  DNI* banco = new DNI [N+P];
  for(int i=0; i<N+P; i++)
  {
    DNI A;
    banco[i] = A;
    A.~DNI();
  }
  
  for(int i=0; i<N; i++)
    Ar.Insertar(banco[i]);
    
  cout << "Numero de Comparaciones" << endl << endl;
  
  DNI::Comparaciones.reset();
  
  for(int i=0; i<P; i++)
  {
    DNI::Comparaciones.start();
    Ar.Buscar(banco[i]);
    DNI::Comparaciones.stop();
  }
    
  cout << "Busqueda de P valores de clave ya introducidas" << endl << DNI::Comparaciones << endl << endl;
  
  DNI::Comparaciones.reset();
    
  DNI::Comparaciones.start();
  for(int i=N; i<N+P; i++)
  {
    DNI::Comparaciones.start();
    Ar.Buscar(banco[i]);
    DNI::Comparaciones.stop();
  }
  
  cout << "Busqueda de P valores de clave NO introducidas" << endl << DNI::Comparaciones << endl;
  
}
      
    