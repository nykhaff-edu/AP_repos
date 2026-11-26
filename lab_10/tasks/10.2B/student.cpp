// student.cpp

#include "student.h"

#include <iomanip>
#include <iostream>

using namespace std;

int inputInt(const string& prompt, int minVal, int maxVal) {
  int value;
  while (true) {
    cout << prompt;
    if (cin >> value && value >= minVal && value <= maxVal) {
      return value;
    }
    cout << "Введіть ціле число від " << minVal << " до " << maxVal << "\n";

    cin.clear();
    cin.ignore(10000, '\n');
  }
}

void Create(Student* p, const int N) {
  int ispec;
  for (int i = 0; i < N; i++) {
    cout << "Студент № " << i + 1 << ":\n";

    cin.get();
    cin.sync();

    cout << "\tпрізвище: ";
    getline(cin, p[i].prizv);
    p[i].kurs = inputInt("\tкурс: ", 1, 5);
    ispec = inputInt(
      "  спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, "
      "2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове "
      "навчання): ",
      0, 4);
    p[i].spec = (Speciality)ispec;
    p[i].physics = inputInt("\tфізика: ", 1, 5);
    p[i].math = inputInt("\tматематика: ", 1, 5);

    switch (p[i].spec) {
      case CS:
        p[i].programming = inputInt("\tпрограмування: ", 1, 5);
        break;
      case INF:
        p[i].numerical_meth = inputInt("\tчисельні методи: ", 1, 5);
        break;
      case ME:
      case PI:
      case LT:
        p[i].pedagogy = inputInt("\tпедагогіка: ", 1, 5);
        break;
    }
  }
}

string specName(Speciality spec) {
  switch (spec) {
    case CS:
      return "Комп'ютерні науки";
    case INF:
      return "Інформатика";
    case ME:
      return "Математика та економіка";
    case PI:
      return "Фізика та інформатика";
    case LT:
      return "Трудове навчання";
    default:
      return "-";
  }
}

void Print(Student* p, const int N) {
  cout
    << "====================================================================="
       "=====================================\n";
  cout << "|  №  |   Прізвище   | Курс |      Спеціальність      | Фізика | "
          "Математика | Прогр. | Чис. мет. | Педагогіка |\n";
  cout
    << "---------------------------------------------------------------------"
       "-------------------------------------\n";
  for (int i = 0; i < N; i++) {
    cout << "| " << setw(3) << right << i + 1 << " ";
    cout << "| " << setw(13) << left << p[i].prizv << "| " << setw(4) << right
         << p[i].kurs << " "
         << "| " << setw(23) << left << specName(p[i].spec) << " "
         << "| " << setw(6) << right << p[i].physics << " "
         << "| " << setw(10) << right << p[i].math << " ";

    switch (p[i].spec) {
      case CS:
        cout << "| " << setw(6) << right << p[i].programming << " "
             << "| " << setw(9) << right << "" << " "
             << "| " << setw(10) << right << "" << " |\n";
        break;
      case INF:
        cout << "| " << setw(6) << right << "" << " "
             << "| " << setw(9) << right << p[i].numerical_meth << " "
             << "| " << setw(10) << right << "" << " |\n";
        break;
      case ME:
      case PI:
      case LT:
        cout << "| " << setw(6) << right << "" << " "
             << "| " << setw(9) << right << "" << " "
             << "| " << setw(10) << right << p[i].pedagogy << " |\n";
        break;
    }
  }
  cout
    << "====================================================================="
       "=====================================\n\n";
}

double averageGrade(const Student& s) {
  return (s.physics + s.math + s.pedagogy) / 3.0;
}

void Sort(Student* p, const int N) {
  Student tmp;
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N - i - 1; j++) {
      if ((specName(p[j].spec) > specName(p[j + 1].spec)) ||
          (specName(p[j].spec) == specName(p[j + 1].spec) &&
           averageGrade(p[j]) > averageGrade(p[j + 1])) ||
          (specName(p[j].spec) == specName(p[j + 1].spec) &&
           averageGrade(p[j]) == averageGrade(p[j + 1]) &&
           p[j].prizv > p[j + 1].prizv)) {
        tmp = p[j];
        p[j] = p[j + 1];
        p[j + 1] = tmp;
      }
    }
  }
}

int* IndexSort(Student* p, const int N) {
  int* I = new int[N];
  for (int k = 0; k < N; k++) {
    I[k] = k;
  }

  int i, j, value;
  for (i = 1; i < N; i++) {
    value = I[i];
    for (j = i - 1;
         j >= 0 && ((specName(p[I[j]].spec) > specName(p[value].spec)) ||
                    (specName(p[I[j]].spec) == specName(p[value].spec) &&
                     averageGrade(p[I[j]]) > averageGrade(p[value])) ||
                    (specName(p[I[j]].spec) == specName(p[value].spec) &&
                     averageGrade(p[I[j]]) == averageGrade(p[value]) &&
                     p[I[j]].prizv > p[value].prizv));
         j--) {
      I[j + 1] = I[j];
    }
    I[j + 1] = value;
  }
  return I;
}

void PrintIndexSorted(Student* p, int* I, const int N) {
  cout
    << "====================================================================="
       "=====================================\n";
  cout << "|  №  |   Прізвище   | Курс |      Спеціальність      | Фізика | "
          "Математика | Прогр. | Чис. мет. | Педагогіка |\n";
  cout
    << "---------------------------------------------------------------------"
       "-------------------------------------\n";
  for (int i = 0; i < N; i++) {
    cout << "| " << setw(3) << right << i + 1 << " ";
    cout << "| " << setw(13) << left << p[I[i]].prizv << "| " << setw(4)
         << right << p[I[i]].kurs << " "
         << "| " << setw(23) << left << specName(p[I[i]].spec) << " "
         << "| " << setw(6) << right << p[I[i]].physics << " "
         << "| " << setw(10) << right << p[I[i]].math << " ";

    switch (p[I[i]].spec) {
      case CS:
        cout << "| " << setw(6) << right << p[I[i]].programming << " "
             << "| " << setw(9) << right << "" << " "
             << "| " << setw(10) << right << "" << " |\n";
        break;
      case INF:
        cout << "| " << setw(6) << right << "" << " "
             << "| " << setw(9) << right << p[I[i]].numerical_meth << " "
             << "| " << setw(10) << right << "" << " |\n";
        break;
      case ME:
      case PI:
      case LT:
        cout << "| " << setw(6) << right << "" << " "
             << "| " << setw(9) << right << "" << " "
             << "| " << setw(10) << right << p[I[i]].pedagogy << " |\n";
        break;
    }
  }
  cout
    << "====================================================================="
       "=====================================\n\n";
}

int BinSearch(Student* p, const int N, const string prizv,
              const Speciality spec, const double avg) {
  int L = 0, R = N - 1, m;
  do {
    m = (L + R) / 2;
    if (p[m].prizv == prizv && p[m].spec == spec && averageGrade(p[m]) == avg) {
      return m;
    }
    if ((specName(p[m].spec) < specName(spec)) ||
        (specName(p[m].spec) == specName(spec) && averageGrade(p[m]) < avg) ||
        (specName(p[m].spec) == specName(spec) && averageGrade(p[m]) == avg &&
         p[m].prizv < prizv)) {
      L = m + 1;
    } else {
      R = m - 1;
    }
  } while (L <= R);
  return -1;
}