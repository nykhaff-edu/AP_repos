// lab_04_7.cpp
// Войтович Богдан
// Лабораторна робота № 4.7
// Обчислення суми ряду Тейлора за допомогою
// ітераційних циклів та рекурентних співвідношень 
// Варіант 3

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double xp, xk, x, dx, eps, a = 0, R = 0, S = 0;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "        Taylor Series Sum Table for e^(x^2)        " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
         << setw(15) << "exp(x^2)" << " |"
         << setw(15) << "S" << " |"
         << setw(5) << "n" << " |"
         << endl;
    cout << "---------------------------------------------------" << endl;

    x = xp;
    while (x <= xk) {
        n = 0;
        a = 1;
        S = a;
        do {
            n++;
            R = pow(x, 2) / n;
            a *= R;
            S += a;
        } while (abs(a) >= eps);

        cout << "|" << setw(7) << setprecision(2) << x << " |"
             << setw(15) << setprecision(5) << exp(pow(x, 2)) << " |"
             << setw(15) << setprecision(5) << S << " |"
             << setw(5) << n << " |"
             << endl;

        x += dx;
    }
    cout << "---------------------------------------------------" << endl;

    cin.ignore();
    cin.get();
    return 0;
}