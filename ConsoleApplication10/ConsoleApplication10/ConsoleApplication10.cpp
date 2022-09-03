// ConsoleApplication10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iomanip>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int fact(int n) {

	if (n == 0) {
		return 1;
	}
	return (n * fact(n - 1));
}
int main()
{
	
	double a, b, n, h, sum, kol;
	cout << "vvedite a, b, h, n ";
	cin >> a >> b >> h >> n;
	kol = (b - a) / h;
	vector <double> sx;
	vector <double> x;
	for (int i = 0; i < kol; i++) {
		x.push_back(a + h * i);
	}

	

	for (int i = 0; i < kol; i++) {
		sum = 0;
		for (int k = 0; k <= n; k++) {
			sum = sum +((k*k+1)/fact (k))* (pow (x[i]/2, k));
		}
		sx.push_back(sum);
	}
	vector <double> yx;
	for (int i = 0; i < kol; i++) {
		yx.push_back(((pow(x[i], 2)) / 4 + x[i] / 2 + 1)*exp(x[i] / 2));
	}
	for (int i = 0; i < kol; i++) {
		cout << sx[i] << "\t" << yx[i] << "\n";
	}


	return 0;
}

