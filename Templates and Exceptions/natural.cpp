#include "natural.h"

Natural::Natural (unsigned int x)
{
  numero_ = x;
}

Natural::~Natural(void){}

unsigned int Natural::get_numero (void) const
{
  return numero_;
}

void Natural::set_numero (unsigned int dato)
{
  numero_ = dato;
}

Natural operator+(const Natural& n1, const Natural& n2)
{
  return Natural (n1.numero_ + n2.numero_);
}

Natural operator-(const Natural& n1, const Natural& n2)
{
  if(n1>n2)
    return Natural (n1.numero_ - n2.numero_);
  else{
    cout << "Error. El primer numero es menor que el segundo." << endl;
    return Natural (0);
  }
}

Natural operator*(const Natural& n1, const Natural& n2)
{
  return Natural (n1.numero_ * n2.numero_);
}

Natural operator/(const Natural& n1, const Natural& n2)
{
  try
  {
    if(n2.numero_ == 0)
      throw 0;
  }
  catch (int e)
  {
    cout << "Excepcion: Division por 0" << endl;
    throw;
  }
  return Natural (n1.numero_ / n2.numero_);
}

bool operator==(const Natural& n1, const Natural& n2)
{
  return (n1.numero_ == n2.numero_);
}

bool operator<(const Natural& n1, const Natural& n2)
{
  return (n1.numero_ < n2.numero_);
}

bool operator>(const Natural& n1, const Natural& n2)
{
  return (n1.numero_ > n2.numero_);
}

ostream& operator<<(ostream& os, const Natural& n1)
{
  os << n1.numero_;
  return os;
}

istream& operator>>(istream& is, Natural& n1)
{ 
  int dato; bool error=true;
  
  try
  {
    while(error == true){
      is >> dato;
      if(dato < 0)
	throw 1;
      else{
	error=false;
	n1.set_numero(dato);
      }
    }
  }
  catch(int e)
  {
    cout << "El numero debe ser natural" << endl;
  }
  
  return is;
}

ostream& Natural::toStream (ostream& sout) const
{
  sout << numero_;
  return sout;
}

istream& Natural::fromStream (istream& sin)
{
  bool error=true; int dato;
  
  while(error == true){
    sin >> dato;
    try
    {
      if(dato < 0)
	throw 1;
      else{
	numero_ = dato;
	error = false;
      }
    }
    catch (int e)
    {
      cout << "Excepcion: El numero debe ser natural" << endl;
      cout << "Introduzca el natural de nuevo: " << endl;
    }
  }
  
  return sin;
}