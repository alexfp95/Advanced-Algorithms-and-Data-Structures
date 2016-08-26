#include "racional.h"

Racional::Racional (int x, int y):
numerador_(0),
denominador_(0)
{
  minimizar(x, y);
  numerador_.set_numero(x);
  denominador_.set_numero(y);
}

Racional::~Racional(void){}

void Racional::minimizar (int &numerador, int &denominador)
{
  if(denominador != 1){
    int aux=2;
    while(aux <= denominador){
      if((denominador%aux == 0) && (numerador%aux == 0)){
	denominador = denominador / aux;
	numerador = numerador / aux;
      }
      else
	aux++;
    }
  }
}

Racional operator+(const Racional& n1, const Racional& n2)
{
  return Racional (n1.numerador_.get_numero()*n2.denominador_.get_numero() + n2.numerador_.get_numero()*n1.denominador_.get_numero(), n1.denominador_.get_numero()*n2.denominador_.get_numero());
}

Racional operator-(const Racional& n1, const Racional& n2)
{
  return Racional (n1.numerador_.get_numero()*n2.denominador_.get_numero() - n2.numerador_.get_numero()*n1.denominador_.get_numero(), n1.denominador_.get_numero()*n2.denominador_.get_numero());
}

Racional operator*(const Racional& n1, const Racional& n2)
{
  return Racional (n1.numerador_.get_numero()*n2.numerador_.get_numero(), n1.denominador_.get_numero()*n2.denominador_.get_numero());
}

Racional operator/(const Racional& n1, const Racional& n2)
{
  return Racional (n1.numerador_.get_numero()*n2.denominador_.get_numero(), n1.denominador_.get_numero()*n2.numerador_.get_numero());
}

bool operator==(const Racional& n1, const Racional& n2)
{
  return ((n1.numerador_.get_numero() == n2.numerador_.get_numero()) && (n1.denominador_.get_numero() == n2.denominador_.get_numero()));
}

bool operator<(const Racional& n1, const Racional& n2)
{
  return (((float)n1.numerador_.get_numero()/((float)n1.denominador_.get_numero())) < ((float)n2.numerador_.get_numero()/((float)n2.denominador_.get_numero())));
}

bool operator>(const Racional& n1, const Racional& n2)
{
  return (((float)n1.numerador_.get_numero()/((float)n1.denominador_.get_numero())) > ((float)n2.numerador_.get_numero()/((float)n2.denominador_.get_numero())));
}

ostream& operator<<(ostream& os, const Racional& n1)
{
  os << n1.numerador_.get_numero() << "/" << n1.denominador_.get_numero();
  return os;
}

istream& operator>>(istream& is, Racional& n1)
{
  int dato1, dato2;
  is >> dato1 >> dato2;
  n1.minimizar(dato1, dato2);
  n1.numerador_.set_numero(dato1);
  n1.denominador_.set_numero(dato2);
  return is;
}

ostream& Racional::toStream (ostream& sout) const
{
  sout << numerador_.get_numero() << "/" << denominador_.get_numero();
  return sout;
}

istream& Racional::fromStream (istream& sin)
{
  int dato1, dato2; bool error=true;
  
  while(error==true){
    try
    {
      sin >> dato1 >> dato2;
      if(dato2 == 0)
	throw 1;
      else
	error=false;
    }
    catch (int e)
    {
      cout << "Excepcion: El denominador no puede ser 0" << endl;
      cout << "Introduzca el racional de nuevo: ";
    }
  }
  minimizar(dato1, dato2);
  numerador_.set_numero(dato1);
  denominador_.set_numero(dato2);
  return sin;
}