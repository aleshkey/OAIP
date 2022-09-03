#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, m, kp2;
	kp2 = 0;
	cin >> n >> m;
	int a[100][100];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = 0;
		}
	}
	for (int raz = 0; raz < n / 2 + n % 2; raz++) {
		if (kp2 != n - 1 - kp2) {
			for (int j = kp2; j < m - kp2; j++) {
				a[kp2][j] = 2 * kp2*(m + n - 2 - 2 * (kp2 - 1)) + j - kp2 + 1; // верхний
				a[n - 1 - kp2][j] = n + 2 * m - kp2 - 2 - j + 2 * kp2*(m + n - 4 - 2 * (kp2 - 1)); // нижний
			}
		}
		else for (int j = kp2; j < m - kp2; j++) {
			a[kp2][j] = 2 * kp2*(m + n - 2 - 2 * (kp2 - 1)) + j - kp2 + 1; // ТОЛЬКО верхний
		}
		kp2++;
	}
	kp2 = 0;
	for (int raz = 0; raz < m / 2 + m % 2; raz++) {
		for (int i = kp2 + 1; i < n - kp2; i++) {
			a[i][kp2] = 2 * (m - kp2)*(kp2 + 1) + 2 * kp2*(n - kp2 - 1) + n - 2 * (kp2 + 1) + n - kp2 - i - 1; // дадалевый
			a[i][m - 1 - kp2] = 2 * kp2*(m + n - 2 - 2 * (kp2 - 1)) + m - 3 * kp2 + i; // дадаправый
		}
		kp2++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] < 10) {
				cout.width(5);
				cout << "\t" << a[i][j];
			}
			else if (a[i][j] < 100) {
				cout.width(5);
				cout << "\t" << a[i][j];
			}
			else if (a[i][j] < 1000) {
				cout.width(5);
				cout << "\t" << a[i][j];
			}
			else {
				cout.width(5);
				cout << "\t"<<a[i][j];
			}
		}
		cout << endl;
	}
	return 0;
}