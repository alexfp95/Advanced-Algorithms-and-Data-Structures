#pragma once

#include "numero.h"

#include <cstdio>
#include <iostream>

using namespace std;

class Entero : public Numero
{
private:
  int numero_;
public:
  Entero (int x = 0);
  ~Entero (void);
  int get_numero (void) const;
  void set_numero (int dato);
  virtual ostream& toStream (ostream& sout) const;
  virtual istream& fromStream (istream& sin);
  friend Entero operator+(const Entero&, const Entero&);
  friend Entero operator-(const Entero&, const Entero&);
  friend Entero operator*(const Entero&, const Entero&);
  friend Entero operator/(const Entero&, const Entero&);
  friend bool operator==(const Entero&, const Entero&);
  friend bool operator<(const Entero&, const Entero&);
  friend bool operator>(const Entero&, const Entero&);
  friend ostream& operator<<(ostream&, const Entero&);
  friend istream& operator>>(istream&, Entero&);
};