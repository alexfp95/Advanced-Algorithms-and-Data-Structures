#include "real.h"

Real::Real (float x)
{
  numero_ = x;
}

Real::~Real (void){}

float Real::get_numero (void) const
{
  return numero_;
}

void Real::set_numero (float dato)
{
  numero_ = dato;
}

Real operator+(const Real& n1, const Real& n2)
{
  return Real (n1.numero_ + n2.numero_);
}

Real operator-(const Real& n1, const Real& n2)
{
  return Real (n1.numero_ - n2.numero_);
}

Real operator*(const Real& n1, const Real& n2)
{
  return Real (n1.numero_ * n2.numero_);
}

Real operator/(const Real& n1, const Real& n2)
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
  return Real (n1.numero_ / n2.numero_);
}

bool operator==(const Real& n1, const Real& n2)
{
  return (n1.numero_ == n2.numero_);
}

bool operator<(const Real& n1, const Real& n2)
{
  return (n1.numero_ < n2.numero_);
}

bool operator>(const Real& n1, const Real& n2)
{
  return (n1.numero_ > n2.numero_);
}

ostream& operator<<(ostream& os, const Real& n1)
{
  os << n1.numero_;
  return os;
}

istream& operator>>(istream& is, Real& n1)
{
  is >> n1.numero_;
  return is;
}

ostream& Real::toStream (ostream& sout) const
{
  sout << numero_;
  return sout;
}

istream& Real::fromStream (istream& sin)
{
  sin >> numero_;
  return sin;
}