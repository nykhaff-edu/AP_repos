// lab_04_4.cpp
// Войтович Богдан
// Лабораторна робота № 4.4
// Табуляція функції, заданої графіком
// Варіант 3

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double x, xp, xk, dx, R, y;

    double pi = acos(-1.0);

    cout << "R = "; cin >> R;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;

    cout << fixed;
    cout << "\n  Function Values Table\n";
    cout << "---------------------------\n";
    cout << "|" << setw(7) << "x" << " |" << setw(10) << "y" << " |\n";
    cout << "---------------------------\n";

    x = xp;
    while (x <= xk) {
        if (x <= -7 - R || (x > -7 + R && x <= -4))
            y = R;
        else 
            if (x > -7 - R && x <= -7 + R)
                y = R - sqrt(pow(R, 2) - pow((x + 7), 2));
            else
                if (x > -4 && x <= 0)
                    y = (-R * x) / 4;
                else
                    if (x > 0 && x <= pi)
                        y = sin(x);
                    else
                        y = x - pi;

        cout << "|" << setw(7) << setprecision(2) << x
            << " |" << setw(10) << setprecision(3) << y
            << " |\n";

        x += dx;
    }

    cin.ignore();
    cin.get();
    return 0;
}