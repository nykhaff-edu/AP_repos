// lab_05_3.cpp
// Войтович Богдан
// Лабораторна робота № 5.3
// Функції, що містять розгалуження та цикли з рекурентними співвідношеннями
// Варіант 3

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double h(const double x);

int main() {
	double q, qp, qk, r;
	int n;

	cout << "qp = "; cin >> qp;
	cout << "qk = "; cin >> qk;
	cout << "n = "; cin >> n;

	cout << fixed;
	cout << "     Table of r(q) values" << endl;
	cout << "------------------------------" << endl;
	cout << "|" << setw(10) << "q" << " |"
		 << setw(15) << "r" << " |" << endl;
	cout << "------------------------------" << endl;

	double dq = (qk - qp) / n;

	q = qp;
	while (q <= qk) {
		r = h(q + 1) + h(pow(q, 2) + 1) + pow(h(pow(q, 2)), 2);
		cout << "|" << setw(10) << q << " |"
			 << setw(15) << r << " |" << endl;
		q += dq;
	}
	cout << "------------------------------" << endl;

	cin.ignore();
	cin.get();
	return 0;
}

double h(const double x) {
	if (fabs(x) >= 1) {
		return (cos(x) + 1) / (pow(cos(x), 2) + 1);
	}
	else {
		double s = 0, a = 1;
		int i = 0;

		s = a;
		do {
			i++;
			double R = pow(x, 2) / ((2 * i - 1) * 2 * i);
			a *= R;
			s += a;
		} while (i < 6);

		return 1 / cos(x) * s;
	}
}