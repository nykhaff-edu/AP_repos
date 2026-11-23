// student.h

#pragma once
#include <string>

enum Spec { KN, INF, ME, FI, TN };

struct Student {
  std::string prizv;
  unsigned kurs;
  Spec spec;
  int fizyka;
  int matematyka;
  union {
    int prohramuvannya;
    int chyselni_metody;
    int pedahohika;
  };
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
int ThirdMark(Student* p, const int i);
void PrintWithoutThrees(Student* p, const int N);
int CountPhysicsFive(Student* p, const int N);