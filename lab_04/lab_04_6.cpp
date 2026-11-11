// lab_04_6.cpp
// Войтович Богдан
// Лабораторна робота № 4.6
// Вкладені цикли
// Варіант 3

#include <cmath>
#include <iostream>

using namespace std;

int main() {
    double S, P;
    int i, k;

    // 1) while(…) {… while(…) {…} …}
    S = 0;
    i = 1;
    while (i <= 15) {
        P = 1;
        k = 1;
        while (k <= i) {
            P *= sqrt(k);
            k++;
        }
        S += (sin(10 * i) + cos(10 * i)) / P;
        i++;
    }
    cout << "\n1) " << S;

    // 2) do{… do{…} while(…) …} while(…)
    S = 0;
    i = 1;
    do {
        P = 1;
        k = 1;
        do {
            P *= sqrt(k);
            k++;
        } while (k <= i);
        S += (sin(10 * i) + cos(10 * i)) / P;
        i++;
    } while (i <= 15);
    cout << "\n2) " << S;

    // 3) for(…; …; n++) {… for(…; …; k++) {…} …}
    S = 0;
    for (i = 1; i <= 15; i++) {
        P = 1;
        for (k = 1; k <= i; k++) {
            P *= sqrt(k);
        }
        S += (sin(10 * i) + cos(10 * i)) / P;
    }
    cout << "\n3) " << S;

    // 4) for(…; …; n--) {… for(…; …; k--) {…} …}
    S = 0;
    for (i = 15; i >= 1; i--) {
        P = 1;
        for (k = i; k >= 1; k--) {
            P *= sqrt(k);
        }
        S += (sin(10 * i) + cos(10 * i)) / P;
    }
    cout << "\n4) " << S;

    cin.get();
    return 0;
}