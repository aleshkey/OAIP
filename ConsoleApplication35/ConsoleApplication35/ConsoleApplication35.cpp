#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <cstdlib>
using namespace std;
int main()
{
	double now, proiz = 1;
	int kod, kol;
	srand(time(NULL));
	cout << "1) vvodim s klaviaturi" << endl << "2) random \n";
	cin >> kod;
	cout << endl << "vvedite kolichestvo elementov" << endl;
	cin >> kol;
	vector <double> a(kol);
	vector <int> nulls;
	cout << "vashi elementi ravni: ";
	if (kod == 1) {
		for (int i = 0; i < kol; i++) {
			cin >> a[i];
		}

	}
	else {
		for (int i = 0; i < kol; i++) {
			a[i] = rand() % 20 - 10;
			cout << a[i] << " ";
		}
	}
	for (int i = 0; i < kol; i++) {
		if (a[i] == 0) {
			nulls.push_back(i);
		}
	}
	cout << "\n";
	if (nulls.size() > 2) {
		for (int i = nulls[0] + 1; i < nulls[1]; i++) {
			proiz *= a[i];
		}
		cout << proiz;
	}
	else { cout << "incorrect input";}
		
	
}
