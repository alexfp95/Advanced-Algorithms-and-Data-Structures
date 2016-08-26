#include "contador.h"

#include <cstdio>
#include <iostream>
#include <cstdlib>

class DNI
{
private:
  int numero_;
public:
  DNI (void);
  ~DNI (void);
  bool operator==(const DNI& n1);
  int get (void);
  static Contador Comparaciones;
};