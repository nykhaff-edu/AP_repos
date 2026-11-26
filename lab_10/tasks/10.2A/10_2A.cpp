// 10_2A.cpp
// Войтович Богдан
// Лабораторна робота № 10.2
// Впорядкування та бінарний пошук в
// масиві структур
// Варіант 3

#include <windows.h>

#include <iostream>
#include <string>

#include "student.h"

using namespace std;

int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  int N = inputInt("N = ", 1, 1000);
  Student* p = new Student[N];

  int menuItem;
  bool isCreated = false;
  bool isSorted = false;

  do {
    cout << "\n\nВиберіть дію:\n\n";
    cout << " [1] - введення даних з клавіатури\n";
    cout << " [2] - вивід даних на екран\n";
    cout << " [3] - фізичне впорядкування даних\n";
    cout << " [4] - індексне впорядкування та вивід даних\n";
    cout << " [5] - бінарний пошук студента\n\n";
    cout << " [0] - вихід та завершення роботи програми\n\n";
    menuItem = inputInt("Введіть значення: ", 0, 5);
    cout << "\n";

    switch (menuItem) {
      case 1:
        Create(p, N);
        isCreated = true;
        isSorted = false;
        break;
      case 2:
        if (!isCreated) {
          cout << "Спочатку введіть дані\n";
        } else {
          Print(p, N);
        }
        break;
      case 3:
        if (!isCreated) {
          cout << "Спочатку введіть дані\n";
        } else {
          Sort(p, N);
          isSorted = true;
          cout << "Масив фізично впорядковано\n";
        }
        break;
      case 4:
        if (!isCreated) {
          cout << "Спочатку введіть дані\n";
        } else {
          int* I = IndexSort(p, N);
          PrintIndexSorted(p, I, N);
          delete[] I;
        }
        break;
      case 5: {
        if (!isCreated) {
          cout << "Спочатку введіть дані\n";
          break;
        }
        if (!isSorted) {
          cout << "Для бінарного пошуку масив має бути фізично впорядкованим\n";
          break;
        }
        cout << "Введіть ключі пошуку:\n";
        int ispec = inputInt(
          "  спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, "
          "2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове "
          "навчання): ",
          0, 4);
        Speciality spec = (Speciality)ispec;

        double avg;
        while (true) {
          cout << "\tсередній бал: ";
          if (cin >> avg && avg >= 1.0 && avg <= 5.0) {
            break;
          }
          cout << "Введіть коректний середній бал (від 1.0 до 5.0)\n";
          cin.clear();
          cin.ignore(10000, '\n');
        }

        string prizv;
        cin.get();
        cin.sync();
        cout << "\tпрізвище: ";
        getline(cin, prizv);
        cout << endl;

        int found = BinSearch(p, N, prizv, spec, avg);
        if (found != -1) {
          cout << "Знайдено студента в позиції " << found + 1 << "\n";
        } else {
          cout << "Шуканого студента не знайдено\n";
        }
        break;
      }
      case 0:
        break;
    }
  } while (menuItem != 0);

  delete[] p;
  return 0;
}