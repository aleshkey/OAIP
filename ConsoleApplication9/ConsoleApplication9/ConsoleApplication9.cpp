// ConsoleApplication9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <cmath>
#include <iostream>
int fact(int d) {
	int res = 1;
	for (int i = 1; i <= d; i++) {
		res = res * i;
	}
	return res;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b, h, n, x, y, sum = 0, a1, a2, a3;

	cin » a » b » h » n;
	for (x = a; x <= b; x += h) {
		y = ((pow(x, 2.0)) / 4.0 + x / 2.0 + 1)*exp(x / 2.0);
		for (int k = 0; k <= n; k++) {
			a1 = (pow(k, 2.0) + 1) * (pow(x / 2.0, k));
			a2 = fact(k);
			a3 = a1 / a2;
			sum += a3;

		}
		cout « "При x= " « x « " Значение функции: " « y « " Значение суммы: " « sum « "\n";
	};

};