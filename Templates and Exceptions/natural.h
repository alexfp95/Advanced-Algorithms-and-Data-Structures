#pragma once

#include "numero.h"

#include <cstdio>
#include <iostream>

using namespace std;

class Natural : public Numero
{
private:
  unsigned int numero_;
public:
  Natural (unsigned int x = 0);
  ~Natural (void);
  unsigned int get_numero (void) const;
  void set_numero (unsigned int dato);
  virtual ostream& toStream (ostream& sout) const;
  virtual istream& fromStream (istream& sin);
  friend Natural operator+(const Natural&, const Natural&);
  friend Natural operator-(const Natural&, const Natural&);
  friend Natural operator*(const Natural&, const Natural&);
  friend Natural operator/(const Natural&, const Natural&);
  friend bool operator==(const Natural&, const Natural&);
  friend bool operator<(const Natural&, const Natural&);
  friend bool operator>(const Natural&, const Natural&);
  friend ostream& operator<<(ostream&, const Natural&);
  friend istream& operator>>(istream&, Natural&);
};