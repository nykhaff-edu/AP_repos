// 9_1.cpp
// Войтович Богдан
// Лабораторна робота № 9.1
// Простори імен
// Варіант 3

#include <math.h>

#include <iomanip>
#include <iostream>

#include "sum.h"
#include "var.h"

using namespace std;

using namespace nsSum;
using namespace nsVar;

int main() {
  cout << "xp = ";
  cin >> xp;
  cout << "xk = ";
  cin >> xk;
  cout << "dx = ";
  cin >> dx;
  cout << "eps = ";
  cin >> eps;

  cout << fixed;
  cout << "        Taylor Series Sum Table for e^(x^2)        " << endl;
  cout << "---------------------------------------------------" << endl;
  cout << "|" << setw(7) << "x" << " |" << setw(15) << "exp(x^2)" << " |"
       << setw(15) << "S" << " |" << setw(5) << "n" << " |" << endl;
  cout << "---------------------------------------------------" << endl;

  x = xp;
  while (x <= xk) {
    sum();

    cout << "|" << setw(7) << setprecision(2) << x << " |" << setw(15)
         << setprecision(5) << exp(pow(x, 2)) << " |" << setw(15)
         << setprecision(5) << S << " |" << setw(5) << n << " |" << endl;

    x += dx;
  }
  cout << "---------------------------------------------------" << endl;

  cin.ignore();
  cin.get();
  return 0;
}
