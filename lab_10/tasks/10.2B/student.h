// student.h

#pragma once
#include <string>

enum Speciality { CS, INF, ME, PI, LT };

struct Student {
  std::string prizv;
  int kurs;
  Speciality spec;
  int physics;
  int math;
  union {
    int programming;
    int numerical_meth;
    int pedagogy;
  };
};

int inputInt(const std::string& prompt, int minVal, int maxVal);
void Create(Student* p, const int N);
std::string specName(Speciality spec);
void Print(Student* p, const int N);
double averageGrade(const Student& s);
void Sort(Student* p, const int N);
int* IndexSort(Student* p, const int N);
void PrintIndexSorted(Student* p, int* I, const int N);
int BinSearch(Student* p, const int N, const std::string prizv,
              const Speciality spec, const double avg);