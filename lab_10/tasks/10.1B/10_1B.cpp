// 10_1B.cpp
// Войтович Богдан
// Лабораторна робота № 10.1
// Послідовний пошук в масиві структур
// Варіант 3

#include <Windows.h>

#include <iostream>

#include "student.h"

using namespace std;

int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  int N;
  cout << "N = ";
  cin >> N;

  Student* p = new Student[N];

  Create(p, N);
  Print(p, N);

  PrintWithoutThrees(p, N);

  int count = CountPhysicsFive(p, N);
  cout << "Кількість студентів, які отримали з фізики \"5\": " << count << "\n";

  delete[] p;
  return 0;
}
