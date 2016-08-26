#include "ArbolBB.h"
#include "contador.h"
#include "dni.h"

#include <cstdio>
#include <iostream>

using namespace std;

Contador DNI::Comparaciones;

int main (void)
{
  int bucle=1; int clave; int opcion;
  
  cout << "Algoritmos y Estructuras de Datos Avanzados" << endl;
  cout << "Practica 6. Arbol Binario de Búsqueda. Modo demostracion" << endl << endl;
  
  cout << "Alexis Daniel Fuentes Perez" << endl << endl;
  
  ArbolBB<int> A;
  
  cout << "Arbol vacio" << endl;
  A.write(); cout << endl << endl;
  
  while(bucle)
  {
    cout << "[1] Insertar clave" << endl;
    cout << "[2] Eliminar clave" << endl;
    cout << "[0] Salir" << endl;
    cout << "Inserte una opcion: ";
    cin >> opcion; cout << endl;
    
    switch(opcion)
    {
      case 1:	cout << "Insertar: "; cin >> clave; A.Insertar(clave); A.write(); cout << endl << endl; break;
      case 2:	cout << "Eliminar: "; cin >> clave; A.Eliminar(clave); A.write(); cout << endl << endl; break;
      case 0:	bucle = 0; break;
      default: 	cout << "Opcion invalida" << endl; break;
    }
  }
}
      
    