// ConsoleApplication5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
	int n, m, kol=0;
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

	vector <double> sum(m);
	
	for (int j = 0; j < m; j++) {
		sum[j] = 0;
		for (int i = 0; i < n; i++) {
			sum[j] = sum[j] + a[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] > (sum[j] - a[i][j])) {
				kol = kol + 1;
			}
		}
	}
	cout <<"otvet: "<< kol<<endl;
	cout << endl;

	cout << a << endl<<endl;

	for (int i = 0; i < n; i++) {
		cout << a[i]<<endl;
	}

	cout << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << &a[i][j] << "\t";
		}
		cout<<endl;
	}

	for (int i = 0; i < n; i++) {
			delete[] a[i];
	}
	delete[] a;//освобождение памяти
	system("pause");
	return 0;
}
