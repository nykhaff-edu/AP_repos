// lab_05_1.cpp
// Войтович Богдан
// Лабораторна робота № 5.1
// Функції, що містять арифметичний вираз
// Варіант 3

#include <cmath>
#include <iostream>

using namespace std;

double k(const double x, const double y);

int main() {
    double p, q;

    cout << "p = ";
    cin >> p;
    cout << "q = ";
    cin >> q;

    double result = (k(1 + pow(p, 2), 1 - pow(q, 2)) - pow(k(1, p * q), 2)) /
        (1 + k(p * q, 1));

    cout << "\nresult = " << result;

    cin.ignore();
    cin.get();
    return 0;
}

double k(const double x, const double y) {
    return sin(x) / (pow(x, 2) + pow(y, 2)) + cos(y) / (1 + fabs(x * y));
}