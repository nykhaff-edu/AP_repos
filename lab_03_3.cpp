// lab_03_3.cpp
// Войтович Богдан
// Лабораторна робота № 3.3
// Розгалуження, задане графіком функції.
// Варіант 3

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x; // вхідний аргумент
    double R; // вхідний параметр
    double y; // результат обчислення виразу

    double pi = acos(-1.0);

    cout << "R = "; cin >> R;
    cout << "x = "; cin >> x;

    // розгалуження в повній формі
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

    cout << "\ny = " << y;
    cin.ignore();
    cin.get();
    return 0;
}