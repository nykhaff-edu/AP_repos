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

    switch (p[i].spec) {
      case KN:
        cout << "\tоцінка з програмування: ";
        cin >> p[i].prohramuvannya;
        break;
      case INF:
        cout << "\tоцінка з чисельних методів: ";
        cin >> p[i].chyselni_metody;
        break;
      case ME:
      case FI:
      case TN:
        cout << "\tоцінка з педагогіки: ";
        cin >> p[i].pedahohika;
        break;
    }
    cout << "\n";
  }
}

void Print(Student* p, const int N) {
  string specStr[] = {"Комп'ютерні науки", "Інформатика",
                      "Математика та економіка", "Фізика та інформатика",
                      "Трудове навчання"};

  cout << "===================================================================="
          "=========================================================\n";
  cout << "|  №  |   Прізвище    | Курс |      Спеціальність      | Фізика | "
          "Математика | Програмування | Чисельні методи | Педагогіка |\n";
  cout << "--------------------------------------------------------------------"
          "---------------------------------------------------------\n";

  for (int i = 0; i < N; i++) {
    cout << "| " << setw(3) << right << i + 1 << " ";
    cout << "| " << setw(14) << left << p[i].prizv << "| " << setw(4) << right
         << p[i].kurs << " "
         << "| " << setw(24) << left << specStr[p[i].spec] << "| " << setw(6)
         << right << p[i].fizyka << " "
         << "| " << setw(10) << right << p[i].matematyka << " ";

    switch (p[i].spec) {
      case KN:
        cout << "| " << setw(13) << right << p[i].prohramuvannya << " "
             << "| " << setw(16) << ""
             << "| " << setw(10) << "" << " |\n";
        break;
      case INF:
        cout << "| " << setw(14) << ""
             << "| " << setw(15) << right << p[i].chyselni_metody << " "
             << "| " << setw(10) << "" << " |\n";
        break;
      case ME:
      case FI:
      case TN:
        cout << "| " << setw(14) << ""
             << "| " << setw(16) << ""
             << "| " << setw(10) << right << p[i].pedahohika << " |\n";
        break;
    }
  }
  cout << "===================================================================="
          "=========================================================\n\n";
}

int ThirdMark(Student* p, const int i) {
  switch (p[i].spec) {
    case KN:
      return p[i].prohramuvannya;
    case INF:
      return p[i].chyselni_metody;
    default:
      return p[i].pedahohika;
  }
}

void PrintWithoutThrees(Student* p, const int N) {
  cout << "Вчаться без трійок:\n";
  int k = 0;
  for (int i = 0; i < N; i++) {
    if (p[i].fizyka >= 4 && p[i].matematyka >= 4 && ThirdMark(p, i) >= 4) {
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