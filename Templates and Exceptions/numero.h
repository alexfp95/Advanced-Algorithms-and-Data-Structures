#pragma once

#include <cstdio>
#include <iostream>

using namespace std;

class Numero
{
public:
  virtual ostream& toStream (ostream& sout) const = 0;
  virtual istream& fromStream (istream& sin) = 0;
};
