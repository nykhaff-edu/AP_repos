// lab_04_5.cpp
// Войтович Богдан
// Лабораторна робота № 4.5
// «Попадання» у плоску фігуру
// Варіант 3

#include <time.h>

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    double x, y, R;

    cout << "R = ";
    cin >> R;

    srand((unsigned) time(NULL));

    for (int i = 0; i < 10; i++) {
        cout << "x = ";
        cin >> x;
        cout << "y = ";
        cin >> y;

        if ((x >= -R && x <= R && y >= -R && y <= R) &&
            (pow(x + R, 2) + pow(y - R, 2) > pow(R, 2)) &&
            (pow(x - R, 2) + pow(y + R, 2) > pow(R, 2)))
            cout << "yes\n";
        else
            cout << "no\n";
    }

    cout << "\n" << fixed;

    for (int i = 0; i < 10; i++) {
        x = 4. * R * rand() / RAND_MAX - 2. * R;
        y = 4. * R * rand() / RAND_MAX - 2. * R;

        if ((x >= -R && x <= R && y >= -R && y <= R) &&
            (pow(x + R, 2) + pow(y - R, 2) > pow(R, 2)) &&
            (pow(x - R, 2) + pow(y + R, 2) > pow(R, 2)))
            cout << setw(8) << setprecision(4) << x << " "
                 << setw(8) << setprecision(4) << y << " " << "yes" << endl;
        else
            cout << setw(8) << setprecision(4) << x << " "
                 << setw(8) << setprecision(4) << y << " " << "no" << endl;
    }

    cin.ignore();
    cin.get();
    return 0;
}