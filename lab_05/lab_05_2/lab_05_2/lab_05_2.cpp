// lab_05_2.cpp
// Войтович Богдан
// Лабораторна робота № 5.2
// Обчислення суми ряду Тейлора за допомогою функцій
// Варіант 3

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double S(const double x, const double eps, int& n, double s);
double A(const double x, const int n, double a);

int main() {
	double xp, xk, dx, x, eps, s = 0;
	int n = 0;

	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;

	cout << fixed;
	cout << "   Taylor Series Sum Table for e^(x^2)   " << endl;
	cout << "-----------------------------------------" << endl;
	cout << "|" << setw(7) << "x" << " |"
		<< setw(10) << "exp(x^2)" << " |"
		<< setw(10) << "S" << " |"
		<< setw(5) << "n" << " |"
		<< endl;
	cout << "-----------------------------------------" << endl;

	x = xp;
	while (x <= xk) {
		s = S(x, eps, n, s);

		cout << "|" << setw(7) << setprecision(2) << x << " |"
			<< setw(10) << setprecision(5) << exp(pow(x, 2)) << " |"
			<< setw(10) << setprecision(5) << s << " |"
			<< setw(5) << n << " |"
			<< endl;

		x += dx;
	}
	cout << "-----------------------------------------" << endl;

	cin.ignore();
	cin.get();
	return 0;
}

double S(const double x, const double eps, int& n, double s) {
	n = 0; 
	double a = 1; 
	s = a;
	do {
		n++;
		a = A(x, n, a);
		s += a;
	} while (abs(a) >= eps);
	return s;
}

double A(const double x, const int n, double a) {
	double R = pow(x, 2) / n;
	a *= R;
	return a;
}