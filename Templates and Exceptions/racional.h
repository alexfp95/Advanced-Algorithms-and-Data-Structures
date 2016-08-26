#pragma once

#include "numero.h"
#include "entero.h"
#include "natural.h"

#include <cstdio>
#include <iostream>

using namespace std;

class Racional : public Numero
{
private:
  Entero numerador_;
  Entero denominador_;
public:
  Racional (int x = 0, int y = 0);
  ~Racional (void);
  void minimizar (int &numerador, int &denominador);
  virtual ostream& toStream (ostream& sout) const;
  virtual istream& fromStream (istream& sin);
  friend Racional operator+(const Racional&, const Racional&);
  friend Racional operator-(const Racional&, const Racional&);
  friend Racional operator*(const Racional&, const Racional&);
  friend Racional operator/(const Racional&, const Racional&);
  friend bool operator==(const Racional&, const Racional&);
  friend bool operator<(const Racional&, const Racional&);
  friend bool operator>(const Racional&, const Racional&);
  friend ostream& operator<<(ostream&, const Racional&);
  friend istream& operator>>(istream&, Racional&);
};