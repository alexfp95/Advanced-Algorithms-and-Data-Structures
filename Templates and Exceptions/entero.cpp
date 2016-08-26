#include "entero.h"

Entero::Entero (int x)
{
  numero_ = x;
}

Entero::~Entero (void) {}

int Entero::get_numero (void) const
{
  return numero_;
}

void Entero::set_numero (int dato)
{
  numero_ = dato;
}

Entero operator+(const Entero& n1, const Entero& n2)
{
  return Entero (n1.numero_ + n2.numero_);
}

Entero operator-(const Entero& n1, const Entero& n2)
{
  return Entero (n1.numero_ - n2.numero_);
}

Entero operator*(const Entero& n1, const Entero& n2)
{
  return Entero (n1.numero_ * n2.numero_);
}

Entero operator/(const Entero& n1, const Entero& n2)
{
  try
  {
    if(n2.numero_ == 0)
      throw 0;
  }
  catch  (int e)
  {
    cout << "Excepcion: Division por 0" << endl;
    throw;
  }  
  return Entero (n1.numero_ / n2.numero_);
}

bool operator==(const Entero& n1, const Entero& n2)
{
  return (n1.numero_ == n2.numero_);
}

bool operator<(const Entero& n1, const Entero& n2)
{
  return (n1.numero_ < n2.numero_);
}

bool operator>(const Entero& n1, const Entero& n2)
{
  return (n1.numero_ > n2.numero_);
}

ostream& operator<<(ostream& os, const Entero& n1)
{
  os << n1.numero_;
  return os;
}

istream& operator>>(istream& is, Entero& n1)
{
  is >> n1.numero_;
  return is;
}

ostream& Entero::toStream (ostream& sout) const
{
  sout << numero_;
  return sout;
}

istream& Entero::fromStream (istream& sin)
{
  sin >> numero_;
  return sin;
}