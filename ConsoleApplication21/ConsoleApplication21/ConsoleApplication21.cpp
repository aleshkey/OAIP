#include <vector>
#include <iostream>
using namespace std;
int main()
{
	int n, m,p, kol = 0;
	cout << "vvedite N i M ";
	cin >> n >> m;
	vector <int> maximal;
	vector <int> nomer;
	int **a = new int*[n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int maxznach;
	for (int i = 0; i < n; i++) {
		maxznach = a[i][0];
		for (int j = 0; j < n; j++) {
			if (a[i][j] > maxznach) {
				maxznach = a[i][j];
			}
		}
		nomer.push_back(i);
		maximal.push_back(maxznach);
	}
	for (int j = 0; j < n; j++) {
			int num_max = j; //номер минимального элемента
			for (int i = j; i < n; i++) { //ищем только в еще не упорядоченной части
				if (maximal[i] > maximal[num_max]) {
					num_max = i;
				}
			}
			int temp;
			temp = maximal[j];
			maximal[j] = maximal[num_max];
			maximal[num_max] = temp;
			temp = nomer[j];
			nomer[j] = nomer[num_max];
			nomer[num_max] = temp;


	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		p = nomer[i];
		for (int j=0; j < m; j++) {
			cout << a[p][j]<<" ";
		}
		cout << endl;
	}

	return 0;
}

