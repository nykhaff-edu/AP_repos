// 8_1it.cpp
// Войтович Богдан
// Лабораторна робота № 8.1
// Пошук та заміна символів у літерному рядку
// Варіант 3

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

using namespace std;

int findThirdSymbol(const char* str, const char smbl) {
  int count = 0;

  for (int i = 0; !(str[i] == '\0'); i++) {
    if (str[i] == smbl) {
      count++;
    }
    if (count == 3) {
      return i;
    }
  }

  return -1;
}

char* change(const char* str, const char smbl) {
  char* res = new char[strlen(str) * 2 + 1];
  char* p = res;

  for (int i = 0; !(str[i] == '\0'); i++) {
    if (str[i] == smbl) {
      *p++ = '*';
      *p++ = '*';
    } else {
      *p++ = str[i];
    }
  }
  *p = '\0';

  return res;
}

#ifndef TEST_MODE
int main() {
  char str[101];

  cout << "Enter string: ";
  cin.getline(str, 100);

  cout << "Third comma index: " << findThirdSymbol(str, ',') << "\n";

  char* result = change(str, ',');
  cout << "Modified string: " << result << "\n";

  delete[] result;

  return 0;
}
#endif