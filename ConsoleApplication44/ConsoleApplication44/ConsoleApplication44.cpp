#include <iostream>
#include <cmath>
using namespace std;
double Sx(double x, int k) {
	double sum = 0, step=0;
	for (int i = 1; i < k; i++) {
		step = 4 * i - 1;
		sum = sum + pow(x, step)/(4*i-1);
	}
	return sum;
}
double Yx(double x) {
	double rez = log((x + 1) / (1 - x)) / 4 - atan(x) / 2;
	return rez;
}
int main()
{
	double a, b;
	int k;
	cin >> a >> b >> k;
	double e = 0.00001;
	for (double x = a; x < b; x = x + e) {
		cout.width(10);
		cout << Sx (x, k)<<"\t "<<Yx(x)<<endl;
	}
	return 0;
}

