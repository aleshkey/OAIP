#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int main() {
	int m, nach, k = 1;
	char str[256];
	cout << "Enter string : ";
	cin.getline(str, 256);

	int n = strlen(str);
	vector <int> konec;
	vector <int> kol;
	for (int i = 0; i < n; i++) {
		if (str[i] == str[i + 1]) {
			k = k + 1;
		}
		else {
			konec.push_back(i);
			kol.push_back(k);
			k = 1;
		}
	}
	m = kol.size();
	

	for (int p = 0; p < m; p++) {
		if (kol[p] % 2 == 0) {
			nach = konec[p] + 1 - kol[p];
			for (nach + 1; nach <= konec[p]; nach++) {
				cout << str[nach];
			}
			cout << endl;
		}
	}
	system("pause");
	return 0;
}
