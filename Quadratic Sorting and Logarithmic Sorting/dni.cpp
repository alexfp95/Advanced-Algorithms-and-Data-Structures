#include "dni.h"

DNI::DNI (void)
{
  numero_ = rand() % 50000000 + 30000000;
}

DNI::~DNI (void)
{}

bool DNI::operator==(const DNI& n1)
{
  ++Comparaciones;
  return (numero_ == n1.numero_);
}

bool DNI::operator<(const DNI& n1)
{
  ++Comparaciones;
  return (numero_ < n1.numero_);
}

bool DNI::operator>(const DNI& n1)
{
  ++Comparaciones;
  return (numero_ > n1.numero_);
}

bool DNI::operator<(const int n1)
{
  ++Comparaciones;
  return (numero_ < n1);
}

bool DNI::operator>(const int n1)
{
  ++Comparaciones;
  return (numero_ > n1);
}

bool DNI::operator=(const DNI& n1)
{
  numero_ = n1.numero_;
}

ostream& operator<<(ostream& os, const DNI& n1)
{
  os << n1.numero_;
}

int DNI::get (void)
{
  return numero_;
}