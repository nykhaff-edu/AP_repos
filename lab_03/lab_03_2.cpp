// lab_03_2.cpp
// Войтович Богдан
// Лабораторна робота № 3.2
// Розгалуження, задане формулою: функція з параметрами.
// Варіант 3

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x;  // вхідний параметр
    double a;  // вхідний параметр
    double b;  // вхідний параметр
    double c;  // вхідний параметр
    double F;  // результат

    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;
    cout << "x = "; cin >> x;

    // спосіб 1: розгалуження в скороченій формі
    if (a < 0 && c != 0)
        F = a * pow(x, 2) + b * x + c;
    if (a > 0 && c == 0)
        F = (-a) / (x - b);
    if (!(a < 0 && c != 0) && !(a > 0 && c == 0))
        F = a * (x + c);

    cout << "\n1) F = " << F;

    // спосіб 2: розгалуження в повній формі
    if (a < 0 && c != 0)
        F = a * pow(x, 2) + b * x + c;
    else 
        if (a > 0 && c == 0)
            F = (-a) / (x - b);
        else
             F = a * (x + c);

    cout << "\n2) F = " << F;
    
    cin.ignore();
    cin.get();
    return 0;
}