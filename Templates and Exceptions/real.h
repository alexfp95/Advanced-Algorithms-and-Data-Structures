#pragma once

#include "numero.h"

#include <cstdio>
#include <iostream>

using namespace std;

class Real : public Numero
{
private:
  float numero_;
public:
  Real (float x = 0);
  ~Real (void);
  float get_numero (void) const;
  void set_numero (float dato);
  virtual ostream& toStream (ostream& sout) const;
  virtual istream& fromStream (istream& sin);
  friend Real operator+(const Real&, const Real&);
  friend Real operator-(const Real&, const Real&);
  friend Real operator*(const Real&, const Real&);
  friend Real operator/(const Real&, const Real&);
  friend bool operator==(const Real&, const Real&);
  friend bool operator<(const Real&, const Real&);
  friend bool operator>(const Real&, const Real&);
  friend ostream& operator<<(ostream&, const Real&);
  friend istream& operator>>(istream&, Real&);
};