#include <iostream>
#include <cmath>
#include <conio.h>
#include <vector>
using namespace std;

bool Check(vector<double> arr, double x, double eps) {
	int count=0;
	for (int i = 0; i < arr.size(); i++) {
		if (abs(arr[i] - x) < eps) count++;
	}
	if (count == 0) return true;
	return false;
}

double func(double x) {
	return (exp(x) / (x*x*x) - pow(sin(x), 3) - 2);
}

double MetodVagsteina(double x0, double x1, double eps, int k) {
	double y0, y1, x2, de;
	y0 = func(x0);	   y1 = func(x1);
	do {
		if (k < 100000) {
			x2 = x1 - y1 * (x1 - x0) / (y1 - y0);
			de = fabs(x1 - x2);
			x0 = x1; 	x1 = x2; 	y0 = y1; 	y1 = func(x2);
			k++;
		}
		else throw;
	} while (de > eps);
	return x2;
}

int main()
{
	vector <double> rez;
	double a = 4, b = 7, eps = 0.000000000000001, temp, h=0.1;
	for (double i = a; i < b; i+=h) {
		double temp;
		try {
			if (func(i)*func(i + h) <= 0) {
				temp = MetodVagsteina(i, i + h, eps, 0);
				if (Check(rez, temp, eps) && temp >= a && temp <= b) {
					rez.push_back(temp);
				}
			}
		}
		catch (const std::exception& ex){}
	}
	for (int i = 0; i < rez.size(); i++) {
		cout << rez[i] <<"\t"<<func(rez[i])<< endl;
	}
	return 0;
}