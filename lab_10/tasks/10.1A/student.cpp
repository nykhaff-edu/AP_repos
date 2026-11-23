// student.cpp

#include "student.h"

#include <iomanip>
#include <iostream>

using namespace std;

void Create(Student* p, const int N) {
  int spec;
  for (int i = 0; i < N; i++) {
    cout << "Студент № " << i + 1 << ":\n";

    cin.get();
    cin.sync();

    cout << "\tпрізвище: ";
    getline(cin, p[i].prizv);
    cout << "\tкурс: ";
    cin >> p[i].kurs;
    cout
      << "\tспеціальність (0 - Комп'ютерні науки, 1 - Інформатика, 2 - "
         "Математика та економіка,\n\t\t3 - Фізика та інформатика, 4 - Трудове "
         "навчання): ";
    cin >> spec;
    p[i].spec = (Spec)spec;

    cout << "\tоцінка з фізики: ";
    cin >> p[i].fizyka;
    cout << "\tоцінка з математики: ";
    cin >> p[i].matematyka;
    cout << "\tоцінка з інформатики: ";
    cin >> p[i].informatyka;
    cout << "\n";
  }
}

void Print(Student* p, const int N) {
  string specStr[] = {"Комп'ютерні науки", "Інформатика",
                      "Математика та економіка", "Фізика та інформатика",
                      "Трудове навчання"};

  cout << "===================================================================="
          "========================\n";
  cout << "|  №  |   Прізвище    | Курс |      Спеціальність      | Фізика | "
          "Математика | Інформатика |\n";
  cout
    << "---------------------------------------------------------------------"
       "-----------------------\n";

  for (int i = 0; i < N; i++) {
    cout << "| " << setw(3) << right << i + 1 << " ";
    cout << "| " << setw(14) << left << p[i].prizv << "| " << setw(4) << right
         << p[i].kurs << " "
         << "| " << setw(24) << left << specStr[p[i].spec] << "| " << setw(6)
         << right << p[i].fizyka << " "
         << "| " << setw(10) << right << p[i].matematyka << " "
         << "| " << setw(11) << right << p[i].informatyka << " |\n";
  }
  cout << "===================================================================="
          "========================\n\n";
}

void PrintWithoutThrees(Student* p, const int N) {
  cout << "Вчаться без трійок:\n";
  int k = 0;
  for (int i = 0; i < N; i++) {
    if (p[i].fizyka >= 4 && p[i].matematyka >= 4 && p[i].informatyka >= 4) {
      k++;
      cout << setw(3) << right << k << " " << p[i].prizv << "\n";
    }
  }
  if (k == 0) cout << "\tТаких студентів немає." << "\n\n";
}

int CountPhysicsFive(Student* p, const int N) {
  int count = 0;
  for (int i = 0; i < N; i++) {
    if (p[i].fizyka == 5) {
      count++;
    }
  }
  return count;
}