#include "complejo.h"

Complejo::Complejo (float r, float i):
real_(r),
im_(i)
{}

Complejo::~Complejo (void){}

Complejo operator+(const Complejo& n1, const Complejo& n2)
{
  return Complejo (n1.real_.get_numero() + n2.real_.get_numero(), n1.im_.get_numero() + n2.im_.get_numero());
}

Complejo operator-(const Complejo& n1, const Complejo& n2)
{
  return Complejo (n1.real_.get_numero() - n2.real_.get_numero(), n1.im_.get_numero() - n2.im_.get_numero());
}

Complejo operator*(const Complejo& n1, const Complejo& n2)
{
  return Complejo (n1.real_.get_numero()*n2.real_.get_numero() - n1.im_.get_numero()*n2.im_.get_numero(), n1.real_.get_numero()*n2.im_.get_numero() + n1.im_.get_numero()*n2.real_.get_numero());
}

Complejo operator/(const Complejo& n1, const Complejo& n2)
{
  return Complejo ((n1.real_.get_numero()*n2.real_.get_numero()+n1.im_.get_numero()*n2.im_.get_numero()) / (pow(n2.real_.get_numero(),2)+pow(n2.im_.get_numero(),2)), (n1.im_.get_numero()*n2.real_.get_numero()-n1.real_.get_numero()*n2.im_.get_numero()) / (pow(n2.real_.get_numero(),2)+pow(n2.im_.get_numero(),2)));
}

bool operator==(const Complejo& n1, const Complejo& n2)
{
  return ((n1.real_.get_numero() == n2.real_.get_numero()) && (n1.im_.get_numero() == n2.im_.get_numero()));
}
/*
bool operator<(const Complejo& n1, const Complejo& n2)
{
  return ((sqrt(pow(n1.real_.get_numero(),2)+pow(n1.im_.get_numero(),2))) < (sqrt(pow(n2.real_.get_numero(),2)+pow(n2.im_.get_numero(),2))));
}

bool operator>(const Complejo& n1, const Complejo& n2)
{
  return ((sqrt(pow(n1.real_.get_numero(),2)+pow(n1.im_.get_numero(),2))) > (sqrt(pow(n2.real_.get_numero(),2)+pow(n2.im_.get_numero(),2))));
}
*/
ostream& operator<<(ostream& os, const Complejo& n1)
{
  os << n1.real_.get_numero() << " + " << n1.im_.get_numero() << "i";
  return os;
}

istream& operator>>(istream& is, Complejo& n1)
{
  float dato1, dato2;
  is >> dato1 >> dato2;
  n1.real_.set_numero(dato1);
  n1.im_.set_numero(dato2);
  return is;
}

ostream& Complejo::toStream (ostream& sout) const
{
  sout << real_.get_numero() << " + " << im_.get_numero() << "i";
  return sout;
}

istream& Complejo::fromStream (istream& sin)
{
  float dato1, dato2;
  sin >> dato1 >> dato2;
  real_.set_numero(dato1);
  im_.set_numero(dato2);
  return sin;
}