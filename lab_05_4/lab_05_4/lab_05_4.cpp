// lab_05_4.cpp
// Войтович Богдан
// Лабораторна робота № 5.4
// Обчислення сум та добутків за допомогою рекурсії
// Варіант 3

#include <cmath>
#include <iostream>

using namespace std;

double rec_d_par_d(const int i, double t) {
    t = t + (1.0 / i) + sqrt(1 + pow(sin(i), 2));

    if (i <= 1) {
        return t;
    } else {
        return rec_d_par_d(i - 1, t);
    }
}

double rec_d_par_up(const int i, const int N, double t) {
    t = t + (1.0 / i) + sqrt(1 + pow(sin(i), 2));

    if (i >= N) {
        return t;
    } else {
        return rec_d_par_up(i + 1, N, t);
    }
}

double rec_up_par_d(const int i) {
    if (i < 1) {
        return 0;
    } else {
        return (1.0 / i) + sqrt(1 + pow(sin(i), 2)) + rec_up_par_d(i - 1);
    }
}

double rec_up_par_up(const int i, const int N) {
    if (i > N) {
        return 0;
    } else {
        return (1.0 / i) + sqrt(1 + pow(sin(i), 2)) + rec_up_par_up(i + 1, N);
    }
}

double c_iter(const int i, const int N) {
    double s = 0;
    for (int c = i; c <= N; c++) {
        s += (1.0 / c) + sqrt(1 + pow(sin(c), 2));
    }

    return s;
}

int main() {
    int i = 1, N;

    cout << "N = ";
    cin >> N;

    cout << "\n1. (rec down --) -> " << rec_d_par_d(N, 0);
    cout << "\n2. (rec down ++) -> " << rec_d_par_up(i, N, 0);
    cout << "\n3. (rec up --) -> " << rec_up_par_d(N);
    cout << "\n4. (rec up ++) -> " << rec_up_par_up(i, N);
    cout << "\n5. (iter) -> " << c_iter(i, N);

    cin.ignore();
    cin.get();
    return 0;
}