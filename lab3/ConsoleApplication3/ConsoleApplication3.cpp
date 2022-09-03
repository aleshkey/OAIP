#include <iostream>
//#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
int fact(int n) {
	if (n == 0) {
		return 1;
	}
	else return (n * fact(n-1));
}
int main()
{
	int kol,n;
	double a, b, h, sum=0;
	cout << "vvedite a, b ,h, n ";
	cin >> a >> b >> h>>n;
	kol = (b - a) / h;
	
	vector <double> x;
	for (int i = 0; i < kol; i++) {
		x.push_back( a + h * i );
	}
	
	vector <double> sx;
	
	for (int i = 0; i < kol; i++) {
		sum = 0;
		for (int k = 0; k <= n; k++) {
			sum =sum + pow(-1, k) * pow(x[i], 2 * k) / fact(2 * k);
		}
		sx.push_back(sum);
	}
	
	vector <double> yx;

	for (int i = 0; i < kol; i++) {
		yx.push_back(cos(x[i]));
	}
	
	vector <double> modul;

	for (int i = 0; i < kol; i++) {
		modul.push_back(abs(yx[i] - sx[i]));
	}
	for (int i = 0; i < kol; i++) {
		cout.width(8);
		cout << yx[i] << "\t " << sx[i] << "\t "<< modul[i] << "\t " << endl;
	}

	return 0;
}
