#include "contador.h"

Contador::Contador(void):
Cuenta_(0),
Min_(0),
Max_(0),
Acumulado_(0),
Pruebas_(0)
{}

void Contador::reset (void)
{
  Cuenta_ = 0;
  Min_ = 0;
  Max_ = 0;
  Acumulado_ = 0;
  Pruebas_ = 0;
}

void Contador::start (void)
{
  Cuenta_ = 0;
}

int Contador::stop (void)
{
  if(Min_ == 0)
    Min_ = Cuenta_;
  
  else
  {
    if(Min_ > Cuenta_)
      Min_ = Cuenta_;
  }
  
  if(Max_ < Cuenta_)
    Max_ = Cuenta_;
  
  Acumulado_ += Cuenta_;
  
  Pruebas_++;
}

const Contador& Contador::operator++()
{
  Cuenta_++;
}

ostream& operator<<(ostream& sout, const Contador& cont)
{
  sout << "Minimo\tMedio\tMaximo" << endl;
  sout << cont.Min_ << "\t" << cont.Acumulado_/cont.Pruebas_ << "\t" << cont.Max_ << endl;
}
  