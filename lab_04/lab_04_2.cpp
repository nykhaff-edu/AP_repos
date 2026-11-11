// lab_04_2.cpp
// Войтович Богдан
// Лабораторна робота № 4.2
// Табуляція функції, заданої формулою: функція однієї змінної
// Варіант 3

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    double x, xp, xk, dx, A, B, y;

    cout << "xp = ";
    cin >> xp;

    cout << "xk = ";
    cin >> xk;

    cout << "dx = ";
    cin >> dx;

    cout << fixed;
    cout << "---------------------------\n";
    cout << "|" << setw(7) << "x" << " |" << setw(10) << "y" << " |\n";
    cout << "---------------------------\n";
    
    x = xp;
    while (x <= xk) {
        A = 2 / x + fabs(x);
        if (x < 0)
            B = 1 + 4 * pow(x, 2);
        else
            if (x >= 0 && x <= 2)
                B = pow(exp(x) + fabs(x), 2);
            else
                B = 5 * sin(pow(x, 2) + 1);

        y = A + B;
        cout << "|" << setw(7) << setprecision(2) << x
        << " |" << setw(10) << setprecision(3) << y
        << " |\n";
        
        x += dx;
    }
    cout << "---------------------------\n";

    cin.ignore();
    cin.get();
    return 0;
}