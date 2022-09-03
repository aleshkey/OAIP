

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
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
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < m - 1; j++) {
				if (a[i][j] > a[i][j + 1] && a[i][j] < a[i][j - 1]) {
					kol++;
				}
			}
		}
		cout << kol;
}