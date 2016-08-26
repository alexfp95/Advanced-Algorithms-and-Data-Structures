#include <cstdio>
#include <iostream>
#include <cmath>

#define DEBUG

using namespace std;

template<class Clave>
class ordenacion
{
public:
  void insercion (Clave* secuencia, int size);
  void seleccion (Clave* secuencia, int size);
  void shellsort (Clave* secuencia, int size);
  void Msort (Clave* secuencia, int ini, int fin, int size);
  void Mezcla (Clave* secuencia, int ini, int cen, int fin, int size);
  void mergesort (Clave* secuencia, int size);
  void Qsort (Clave* secuencia, int ini, int fin, int size);
  void quicksort (Clave* secuencia, int size);
};


template<class Clave>
void ordenacion<Clave>::insercion (Clave* secuencia, int size)
{
  Clave X;
  int j;
  
  for(int i=1; i<size; i++)
  {
#ifdef DEBUG
    cout << "i = " << i << endl << endl;
#endif
    X = secuencia[i];
    j= i-1;
#ifdef DEBUG
    cout << X << " < " << secuencia[j] << " ?" << endl << endl;
#endif 
    while((X < secuencia[j]) && (j>=0))
    {
      secuencia[j+1] = secuencia[j];
      secuencia[j] = X;
      j--;
#ifdef DEBUG
      write(secuencia, 0, size);
      cout << endl;
      if(j>=0)
	cout << X << " < " << secuencia[j] << " ?" << endl << endl;
#endif
    }
  }
}

template<class Clave>
void ordenacion<Clave>::seleccion (Clave* secuencia, int size)
{
  Clave X;
  int min;
  
  for(int i=0; i<size-1; i++)
  {
#ifdef DEBUG
    cout << "i = " << i << endl << endl;
#endif
    min = i;
    for(int j=i+1; j<size; j++)
    {
#ifdef DEBUG
      cout << secuencia[j] << " < " << secuencia[min] << " ?" << endl << endl;
#endif       
      if(secuencia[j] < secuencia[min])
	min = j;
    }
    X = secuencia[min];
    secuencia[min] = secuencia[i];
    secuencia[i] = X;
    
#ifdef DEBUG
    write(secuencia, 0, size);
    cout << endl;
#endif
  }
}

template<class Clave>
void ordenacion<Clave>::shellsort (Clave* secuencia, int size)
{
  Clave X;
  int delta, j; double alfa;

  cout << "Introducir alfa (valor entre 0-1): "; cin >> alfa; cout << endl;
  
  delta = size * alfa;
  
  while(delta > 1)
  {
#ifdef DEBUG
    cout << "Mientras Delta > 1. (Delta = " << delta << ")" << endl << endl;
#endif
    delta = delta * alfa;
    for(int i=delta; i<size; i++)
    {
#ifdef DEBUG
    cout << "i = " << i << endl << endl;
#endif
      X = secuencia[i];
      j=i;
#ifdef DEBUG
      cout << X << " < " << secuencia[j-delta] << " ?" << endl << endl;
#endif  
      while((j >= delta) && (X < secuencia[j-delta]))
      {
	secuencia[j] = secuencia[j-delta];
	j = j - delta;
#ifdef DEBUG
	write(secuencia, 0, size);
	cout << endl;
	if(j >= delta)
	  cout << X << " < " << secuencia[j-delta] << " ?" << endl << endl;
#endif  
      }
      secuencia[j] = X;
      
#ifdef DEBUG
      write(secuencia, 0, size);
      cout << endl;
#endif
    }
  }   
}

template<class Clave>
void ordenacion<Clave>::Msort (Clave* secuencia, int ini, int fin, int size)
{
  if (ini < fin)
  {
    int cen = (ini + fin)/2;
    Msort (secuencia, ini, cen, size);
    Msort (secuencia, cen+1, fin, size);
    Mezcla (secuencia, ini, cen, fin, size);
  }
}

template<class Clave>
void ordenacion<Clave>::Mezcla (Clave* secuencia, int ini, int cen, int fin, int size)
{
  int i = ini; int j = cen+1; int k = ini;
  
  Clave* aux = new Clave [fin+1];
  
  while((i<=cen) && (j <= fin))
  {
#ifdef DEBUG
    cout << secuencia[i] << " < " << secuencia[j] << " ?" << endl << endl;
#endif  
    if(secuencia[i] < secuencia[j])
    {
      aux[k] = secuencia[i];
      i++;
    }
    else
    {
      aux[k] = secuencia[j];
      j++;
    }
    k++;
  }
  
  if(i > cen)
  {
    while(j <= fin)
    {
      aux[k] = secuencia[j];
      j++; k++;
    }
  }
  else
  {
    while(i <= cen)
    {
      aux[k] = secuencia[i];
      i++; k++;
    }
  }
  
  for(int k=ini; k<= fin; k++)
    secuencia[k] = aux[k];
#ifdef DEBUG
  write(secuencia, ini, fin+1);
  cout << endl;
#endif
}


template<class Clave>
void ordenacion<Clave>::mergesort (Clave* secuencia, int size)
{
  Msort(secuencia, 0, size-1, size);
}

template<class Clave>
void ordenacion<Clave>::Qsort (Clave* secuencia, int ini, int fin, int size)
{
  Clave X;
  int i = ini; int f = fin;
  Clave p = secuencia[(i+f)/2];
#ifdef DEBUG
  cout << "Pivote: " << p << endl << endl;
#endif
  while(i <= f)
  {
#ifdef DEBUG
    cout << secuencia[i] << " < " << p << " ?" << endl << endl;
#endif
    while(secuencia[i] < p){ i++;
#ifdef DEBUG
      cout << secuencia[i] << " < " << p << " ?" << endl << endl;
#endif
    }
#ifdef DEBUG
    cout << secuencia[f] << " > " << p << " ?" << endl << endl;
#endif
    while(secuencia[f] > p){ f--;
#ifdef DEBUG
      cout << secuencia[f] << " > " << p << " ?" << endl << endl;
#endif
    }
    if(i <= f)
    {
      X = secuencia[i];
      secuencia[i] = secuencia[f];
      secuencia[f] = X;
      i++; f--;
#ifdef DEBUG
      write(secuencia, 0, size);
      cout << endl;
#endif
    }
  }
  
  if(ini < f) Qsort(secuencia, ini, f, size);
  if(i < fin) Qsort(secuencia, i, fin, size);
}

template<class Clave>
void ordenacion<Clave>::quicksort (Clave* secuencia, int size)
{
  Qsort(secuencia, 0, size-1, size);
}