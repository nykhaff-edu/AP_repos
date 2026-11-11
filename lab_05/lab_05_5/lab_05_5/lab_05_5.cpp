// lab_05_5.cpp
// Войтович Богдан
// Лабораторна робота № 5.5
// Рекурсивні функції
// Варіант 3

#include <iostream>
#include <iomanip>

using namespace std;

int C(const int n, const int k, int l, int& d) {
    if (l > d) {
        d = l;
    }

    cout << "\n" << setw(9) << "Level: " << l << setw(6) << " C(" << n << ", " << k << ")";

    if (k == 0 || k == n) {
        return 1;
    } else {
        return C(n - 1, k - 1, l + 1, d) + C(n - 1, k, l + 1, d);
    }
}

int main() {
    int n, k, r, d = 0;

    cout << "n = ";
    cin >> n;
    cout << "k = ";
    cin >> k;

    r = C(n, k, 1, d);
    cout << "\n\nC(" << n << ", " << k << ") = " << r;
    cout << "\nDepth: " << d;

	cin.ignore();
	cin.get();
	return 0;
}
