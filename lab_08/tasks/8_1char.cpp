// 8_1char.cpp
// Войтович Богдан
// Лабораторна робота № 8.1
// Пошук та заміна символів у літерному рядку
// Варіант 3

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

using namespace std;

int findThirdSymbol(const char* str, const int smbl) {
  int count = 0, pos = 0;
  const char* t;

  while (count < 3 && (t = strchr(str + pos, smbl))) {
    pos = t - str + 1;

    count++;
  }

  return pos - 1;
}

char* change(const char* str, const char smbl, char* res) {
  res[0] = '\0';

  const char* pos = str;
  const char* t;

  while (t = strchr(pos, smbl)) {
    strncat(res, pos, t - pos);
    strcat(res, "**");

    pos = t + 1;
  }

  strcat(res, pos);

  return res;
}

#ifndef TEST_MODE
int main() {
  char str[101];

  cout << "Enter string: ";
  cin.getline(str, 100);

  cout << "Third comma index: " << findThirdSymbol(str, ',') << "\n";

  char* result = new char[strlen(str) * 2 + 1];
  change(str, ',', result);
  cout << "Modified string: " << result << "\n";

  delete[] result;

  return 0;
}
#endif