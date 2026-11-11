// lab_04_3.cpp
// Войтович Богдан
// Лабораторна робота № 4.3
// Табуляція функції, заданої формулою: функція з параметрами
// Варіант 3

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    double x, xp, xk, dx, a, b, c, F;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;

    cout << fixed;
    cout << "---------------------------\n";
    cout << "|" << setw(7) << "x" << " |" << setw(10) << "F" << " |\n";
    cout << "---------------------------\n";

    x = xp;
    while (x <= xk) {
        if (a < 0 && c != 0) 
            F = a * pow(x, 2) + b * x + c;
        else 
            if (a > 0 && c == 0) 
                F = -a/(x-b);
            else
                F = a * (x + c);   
        
        cout << "|" << setw(7) << setprecision(2) << x
            << " |" << setw(10) << setprecision(3) << F
            << " |\n";

        x += dx;
    }
}