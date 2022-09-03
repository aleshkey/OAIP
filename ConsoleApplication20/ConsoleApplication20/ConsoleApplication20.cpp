#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
using namespace std;

void sort(int**& arr, int m, int n) {
	int max=0;
	int* compare = new int[m];
	for (int i = 0; i < m; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++)
		max = 
		compare[i] = sum;
	}
	for (int i = m - 1; i > 0; i--)
		for (int j = i - 1; j >= 0; j--)
			if (compare[i] < compare[j]) {
				swap(compare[i], compare[j]);
				for (int k = 0; k < n; k++)
					swap(arr[i][k], arr[j][k]);
			}
}

void show_matrix(int** mat, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(4) << mat[i][j];
		}
		cout << endl;
	}
}

int main(int argc, char* argv[])
{

	int n = 0, m = 0;

	cout << "Enter the column of the matrix: ";
	cin >> n;
	cout << "Enter the rows of the matrix: ";
	cin >> m;

	int** mat = new int*[m];
	for (int k = 0; k < m; k++) {
		mat[k] = new int[n];
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			mat[i][j] = (rand() % 10) + 1;
		}
	}

	show_matrix(mat, m, n);
	cout << endl;
	sort(mat, m, n);
	show_matrix(mat, m, n);

	for (int g = 0; g < m; g++) {
		delete[] mat[g];
	}

	return 0;
}