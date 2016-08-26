#include "dni.h"
#include "contador.h"
#include "ordenacion.h"

#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

Contador DNI::Comparaciones;

template<class Clave>
void write (Clave* secuencia, int ini, int fin)
{
  for(int i=ini; i<fin; i++)
    cout << secuencia[i].get() << " ";
  cout << endl;
}

int main (void)
{
  int N, opcion; int bucle = 1;
  
  ordenacion<DNI> Or;
  
  cout << "Algoritmos y Estructuras de Datos Avanzadas" << endl;
  cout << "Practica 5. Ordenacion. Modo demostracion." << endl << endl;
  
  cout << "Alexis Daniel Fuentes Perez" << endl << endl;
  
  cout << "Introducir el tamaño de la secuencia a ordenar: "; cin >> N; 
  cout << endl;
  
  while(bucle)
  {
    cout << "Introducir el algoritmo a ejecutar: " << endl;
    cout << "[1] Insercion." << endl;
    cout << "[2] Seleccion." << endl;
    cout << "[3] ShellSort." << endl;
    cout << "[4] QuickSort." << endl;
    cout << "[5] MergeSort." << endl;
    cout << "[0] Salir." << endl;
    cout << "Opcion: "; cin >> opcion; cout << endl;
    
    srand(16);
    DNI* banco = new DNI [N];
    for(int i=0; i<N; i++)
    {
      DNI A;
      banco[i] = A;
      A.~DNI();
    }
    
    cout << "Secuencia inicial: " << endl;
    write(banco, 0, N); 
    cout << endl;
    
    switch(opcion)
    {
      case 1: Or.insercion(banco, N); delete [] banco; break;
      case 2: Or.seleccion(banco, N); delete [] banco; break;
      case 3: Or.shellsort(banco, N); delete [] banco; break;
      case 4: Or.quicksort(banco, N); delete [] banco; break;
      case 5: Or.mergesort(banco, N); delete [] banco; break;
      case 0: bucle=0; break;
      default: cout << "Opción incorrecta. Opcion: "; cin >> opcion; break;
    }
  }
}