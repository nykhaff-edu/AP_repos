// 9_2.cpp
// Войтович Богдан
// Лабораторна робота № 9.2
// Директиви препроцесора
// Варіант 3

#include "macros.h"
#include <iostream>

using namespace std;

#define Z 5

int main() {
  double x, y, w;

  cout << "x = ";
  cin >> x;
  cout << "y = ";
  cin >> y;

#if Z > 1 && Z < 3
  w = MAX(ABS(x) + ABS(y) + ABS(Z), CUBE(x));
#elif Z > 3
  w = MIN(2 * x + y, SQR(2 * y - Z));
#else
#error "Z is out of interval"
#endif

  PRINT(w);
  return 0;
}
