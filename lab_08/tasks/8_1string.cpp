// 8_1string.cpp
// Войтович Богдан
// Лабораторна робота № 8.1
// Пошук та заміна символів у літерному рядку
// Варіант 3

#include <iostream>
#include <string>

using namespace std;

int findThirdSymbol(const string& str, const char smbl) {
  int count = 0;
  size_t pos = 0;

  while (count < 3 && !((pos = str.find(smbl, pos)) == -1)) {
    pos++;
    count++;
  }

  return (int)pos - 1;
}

string change(const string& str, const char smbl) {
  string res = str;
  size_t pos = 0;

  while (!((pos = res.find(smbl, pos)) == -1)) {
    res.replace(pos, 1, "**");
    pos += 2;
  }

  return res;
}

#ifndef TEST_MODE
int main() {
  string str;

  cout << "Enter string: ";
  getline(cin, str);

  cout << "Third comma index: " << findThirdSymbol(str, ',') << "\n";

  string result = change(str, ',');
  cout << "Modified string: " << result << "\n";

  return 0;
}
#endif