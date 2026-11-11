// Lab_02.cpp
// Войтович Богдан
// Лабораторна робота № 2.
// Лінійні програми.
// Варіант 3

#include <cmath>
#include <iostream>

using namespace std;

int main() {
    double a;   // Вхідний параметер
    double z1;  // Результат обчислення 1-го виразу
    double z2;  // Результат обчислення 2-го виразу

    cout << "a = ";
    cin >> a; // введення значення a

    z1 = (sin(2 * a) + sin(5 * a) - sin(3 * a)) /
         (cos(a) + 1 - 2 * pow(sin(2 * a), 2));
    z2 = 2 * sin(a);

    cout << "\n";
    cout << "z1 = " << z1 << "\n";
    cout << "z2 = " << z2 << "\n";

    return 0;
}