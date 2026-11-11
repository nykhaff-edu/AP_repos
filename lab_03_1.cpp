// Lab_03_1.cpp
// Войтович Богдан
// Лабораторна робота № 3.1
// Розгалуження, задане формулою: функція однієї змінної.
// Варіант 3

#include <cmath>
#include <iostream>

using namespace std;

int main() {
    double x;  // Вхідний параметр
    double y;  // Результат
    double A;  // Проміжний результат - функціонально стала частина виразу
    double B;  // Проміжний результат - функціонально змінна частина виразу

    cout << "x = "; cin >> x;

    A = 2 / x + fabs(x);

    // спосіб 1: розгалуження в скороченій формі
    if (x < 0) 
        B = 1 + 4 * pow(x, 2);
    if (x >= 0 && x <= 2) 
        B = pow((exp(x) + fabs(x)), 2);
    if (x > 2) 
        B = 5 * sin(pow(x, 2) + 1);

    y = A + B;
    cout << "\n1) y = " << y;

    // спосіб 2: розгалуження в повній формі
    if (x < 0) 
        B = 1 + 4 * pow(x, 2);
    else
        if (x >= 0 && x <= 2) 
            B = pow((exp(x) + fabs(x)), 2);
        else
            B = 5 * sin(pow(x, 2) + 1);

    y = A + B;
    cout << "\n2) y = " << y;

    cin.ignore();
    cin.get();
    return 0;
}