#include "tabla.h"
#include "dni.h"

#include <cstdio>
#include <iostream>

using namespace std;

Contador DNI::Comparaciones;

int main (void)
{
  int nCeldas, nBloques;
  int dispersion, exploracion;
  float factor;
  int nPruebas, N;
  char m_factor='S';
  
  cout << "Algoritmos y Estructuras de Datos Avanzadas" << endl;
  cout << "Implementación de Tabla Hash" << endl << endl;
  
  cout << "Alexis Daniel Fuentes Perez" << endl << endl;
  
  cout << "Insertar numero de celdas: ";
  cin >> nCeldas;
  cout << "Insertar numero de bloques: ";
  cin >> nBloques;
  
  cout << endl;
  
  cout << "Elegir funcion de dispersion: " << endl;
  cout << "[1] Modulo" << endl;
  cout << "[2] Suma" << endl;
  cout << "[3] Pseudo-aleatoria" << endl;
  cout << "Eleccion: ";
  cin >> dispersion;
  
  cout << endl;
  
  cout << "Elegir funcion de exploracion: " << endl;
  cout << "[1] Lineal" << endl;
  cout << "[2] Cuadratica" << endl;
  cout << "[3] Dispersion doble" << endl;
  cout << "[4] Re-dispersion" << endl;
  cout << "Eleccion: ";
  cin >> exploracion;
  
  cout << endl;
    
  cout << "Insertar numero de pruebas: ";
  cin >> nPruebas;
  
  while(m_factor == 'S')
  {
    cout << "Insertar factor de carga (valor entre 0 y 1): ";
    cin >> factor;
    
    cout << endl;
    
    Tabla<DNI> Hash(nCeldas, nBloques, dispersion, exploracion);
      
    N = factor*nCeldas*nBloques;
    
    DNI* banco = new DNI [2*N];
    for(int i=0; i<2*N; i++)
    {
      DNI A;
      banco[i] = A;
      A.~DNI();
    }
        
    for(int i=0; i<N; i++)
      Hash.insertar(banco[i], nPruebas);
       
    cout << "Celdas\tBloques\tCarga\tPruebas\tExploracion\t" << endl;
    cout << nCeldas << "\t" << nBloques << "\t" << factor << "\t" << nPruebas << "\t";
    if(exploracion == 1)
      cout << "Lineal\t";
    if(exploracion == 2)
      cout << "Cuadratica\t";
    if(exploracion == 3)
      cout << "Dispersion Doble\t";
    if(exploracion == 4)
      cout << "Re-dispersion\t";
    cout << endl << endl;
    
    cout << "Numero de Comparaciones" << endl << endl;
    
    DNI::Comparaciones.reset();
    for(int i=0; i<nPruebas; i++)
    {
      DNI::Comparaciones.start();
      Hash.buscar(banco[rand() % N], nPruebas);
      DNI::Comparaciones.stop();
    }
    cout << "Busquedas" << endl << DNI::Comparaciones << endl;
    
    DNI::Comparaciones.reset();
    for(int i=0; i<nPruebas; i++)
    {
      DNI::Comparaciones.start();
      Hash.insertar(banco[rand() % 2*N + N], nPruebas);
      DNI::Comparaciones.stop();
    }
    cout << "Insercion" << endl << DNI::Comparaciones << endl << endl;
    
    cout << "Cambiar factor de carga (S/N): ";
    cin >> m_factor;
    
    if(m_factor == 'S')
    {
      Hash.~Tabla();
      delete [] banco;
      banco = NULL;
    }
  }
}