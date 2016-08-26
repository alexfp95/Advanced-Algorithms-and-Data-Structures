#include <iostream>
#include <cstdio>

using namespace std;

class Contador
{
private:
  int Cuenta_;
  int Min_;
  int Max_;
  int Acumulado_;
  int Pruebas_;
public:
  Contador (void);
  void reset (void);
  void start (void);
  int stop (void);
  const Contador& operator++();
  friend ostream& operator<<(ostream& sout, const Contador& cont);
};