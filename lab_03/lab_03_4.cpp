// lab_03_4.cpp
// Войтович Богдан
// Лабораторна робота № 3.4
// Розгалуження, задане плоскою фігурою.
// Варіант 3

#include <cmath>
#include <iostream>

using namespace std;

int main() {
    double x;  // вхідна абсциса точки
    double y;  // вхідна ордината точки
    double R;  // вхідний папаметр

    cout << "x = "; cin >> x;
    cout << "y = "; cin >> y;
    cout << "R = "; cin >> R;

    // розгалуження в повній формі
    if ((x >= -R && x <= R && y >= -R && y <= R) &&
        (pow(x + R, 2) + pow(y - R, 2) > pow(R, 2)) &&
        (pow(x - R, 2) + pow(y + R, 2) > pow(R, 2)))
        cout << "yes\n";
    else
        cout << "no\n";

    cin.ignore();
    cin.get();
    return 0;
}