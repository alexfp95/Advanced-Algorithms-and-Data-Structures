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
  int N, P;
  
  ordenacion<DNI> Or;
  
  cout << "Algoritmos y Estructuras de Datos Avanzadas" << endl;
  cout << "Practica 5. Ordenacion. Modo estadisticas." << endl << endl;
  
  cout << "Alexis Daniel Fuentes Perez" << endl << endl;
  
  cout << "Introducir el tamaño de la secuencia a ordenar: "; cin >> N; 
  cout << endl;
  
  cout << "Introducir el numero de pruebas: "; cin >> P; 
  cout << endl;
  
  cout << "Numero de Comparaciones" << endl << endl;
  
  DNI::Comparaciones.reset();
  srand(16);
    
  for(int i=0; i<P; i++)
  {
    DNI* banco = new DNI [N];
    for(int i=0; i<N; i++)
    {
      DNI A;
      banco[i] = A;
      A.~DNI();
    }
    
    DNI::Comparaciones.start();
    Or.insercion(banco, N);
    DNI::Comparaciones.stop();
  
    delete [] banco;
  }
  
  cout << "Algoritmo: Insercion" << endl << DNI:: Comparaciones << endl;
  
  DNI::Comparaciones.reset();
  srand(16);
    
  for(int i=0; i<P; i++)
  {
    DNI* banco = new DNI [N];
    for(int i=0; i<N; i++)
    {
      DNI A;
      banco[i] = A;
      A.~DNI();
    }
    
    DNI::Comparaciones.start();
    Or.seleccion(banco, N);
    DNI::Comparaciones.stop();
  
    delete [] banco;
  }
  
  cout << "Algoritmo: Seleccion" << endl << DNI:: Comparaciones << endl;
  
  DNI::Comparaciones.reset();
  srand(16);
    
  for(int i=0; i<P; i++)
  {
    DNI* banco = new DNI [N];
    for(int i=0; i<N; i++)
    {
      DNI A;
      banco[i] = A;
      A.~DNI();
    }
    
    DNI::Comparaciones.start();
    Or.shellsort(banco, N);
    DNI::Comparaciones.stop();
  
    delete [] banco;
  }
  
  cout << "Algoritmo: ShellSort" << endl << DNI:: Comparaciones << endl;
  
  DNI::Comparaciones.reset();
  srand(16);
    
  for(int i=0; i<P; i++)
  {
    DNI* banco = new DNI [N];
    for(int i=0; i<N; i++)
    {
      DNI A;
      banco[i] = A;
      A.~DNI();
    }
    
    DNI::Comparaciones.start();
    Or.quicksort(banco, N);
    DNI::Comparaciones.stop();
  
    delete [] banco;
  }
  
  cout << "Algoritmo: QuickSort" << endl << DNI:: Comparaciones << endl;
  
  DNI::Comparaciones.reset();
  srand(16);
    
  for(int i=0; i<P; i++)
  {
    DNI* banco = new DNI [N];
    for(int i=0; i<N; i++)
    {
      DNI A;
      banco[i] = A;
      A.~DNI();
    }
    
    DNI::Comparaciones.start();
    Or.mergesort(banco, N);
    DNI::Comparaciones.stop();
  
    delete [] banco;
  }
  
  cout << "Algoritmo: MergeSort" << endl << DNI:: Comparaciones << endl;
  
}