#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
	vector <int> a;
	vector <int> b;
	int kolel,x,kolsd;
	cout << "vvedite kolichestvo\n";
	cin >> kolel;
	for (int i = 0; i < kolel; i++) {
		cin >> x;
		a.push_back(x);
	}
	cout << "kol-vo sdvigov ravno\n";
	cin >> kolsd;
	for (int i = kolel-kolsd; i < kolel; i++) {
		b.push_back(a[i]);
	}
	for (int i = 0; i < kolel-kolsd; i++) {
		b.push_back(a[i]);
	}
	for (int i = 0; i < kolel; i++) {
		cout << b[i] << " ";
	}

	return 0;
}