#pragma once

#include "numero.h"
#include "real.h"

#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

class Complejo : public Numero
{
private:
  Real real_;
  Real im_;
public:
  Complejo (float r=0, float i=0);
  ~Complejo (void);
  virtual ostream& toStream (ostream& sout) const;
  virtual istream& fromStream (istream& sin);
  friend Complejo operator+(const Complejo&, const Complejo&);
  friend Complejo operator-(const Complejo&, const Complejo&);
  friend Complejo operator*(const Complejo&, const Complejo&);
  friend Complejo operator/(const Complejo&, const Complejo&);
  friend bool operator==(const Complejo&, const Complejo&);
  /*friend bool operator<(const Complejo&, const Complejo&);
  friend bool operator>(const Complejo&, const Complejo&);*/
  friend ostream& operator<<(ostream&, const Complejo&);
  friend istream& operator>>(istream&, Complejo&);
};