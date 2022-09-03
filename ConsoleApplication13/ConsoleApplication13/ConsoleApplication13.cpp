// ConsoleApplication13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
	int n, m, kol = 0;
	double;
	cout << "vvedite N i M ";
	cin >> n >> m;
	int **a = new int*[n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	auto x = a[0];
	a[0] = a[n-1];
	a[n-1] = x;
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j]<< " ";
		}
		cout << endl;
	}


	return 0;
}

