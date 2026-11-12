// 8_1rec.cpp
// Войтович Богдан
// Лабораторна робота № 8.1
// Пошук та заміна символів у літерному рядку
// Варіант 3

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

using namespace std;

int findThirdSymbol(const char* str, const char smbl, int i = 0,
                    int count = 0) {
  if (str[i] == '\0') {
    return -1;
  }

  if (str[i] == smbl) {
    count++;
    if (count == 3) {
      return i;
    }
  }

  return findThirdSymbol(str, smbl, i + 1, count);
}

char* change(const char* str, const char smbl, char* res, int i = 0,
             int j = 0) {
  if (str[i] == '\0') {
    res[j] = '\0';

    return res;
  }

  if (str[i] == smbl) {
    res[j] = '*';
    res[j + 1] = '*';

    return change(str, smbl, res, i + 1, j + 2);
  } else {
    res[j] = str[i];

    return change(str, smbl, res, i + 1, j + 1);
  }
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