// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
	double now,sum=0;
	int kod, kol, maxznach, minznach;
	srand(time(0));
	cout << "1) vvodim s klaviaturi" << endl << "2) random ";
	cin >> kod;
	cout << endl << "vvedite kolichestvo elementov"<< endl;
	cin >> kol;
	vector <double> a(kol);
	cout << "vashi elementi ravni: ";
	if (kod == 1) {
		for (int i = 0; i < kol; i++) {
			cin >> a[i];
		}
	
	}
	else {
		for (int i = 0; i < kol; i++) {
			a[i] = rand()%100-50;
			cout << a[i]<<" ";
		}
	}

	for (int i = 0; i < kol; i++) {
		if (a[i] > 0) {
			maxznach = i;
		}
 	}

	for (int i = kol-1; i >=0; i--) {
		if (a[i] > 0) {
			minznach = i;
		}
	}
	minznach += 1;
	for (minznach; minznach < maxznach; minznach++) {
		sum = sum + a[minznach];
	}
	cout << endl << sum;

		return 0;
}
