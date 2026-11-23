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
  int informatyka;
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
void PrintWithoutThrees(Student* p, const int N);
int CountPhysicsFive(Student* p, const int N);