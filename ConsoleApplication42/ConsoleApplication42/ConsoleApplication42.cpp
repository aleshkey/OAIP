#include <iostream>
#include <vector>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int n, m;
	cout << "Введите количество строк\n";
	cin >> n;
	cout << "Введите количество столбцов\n";
	cin >> m;
	vector<vector<int>> matrix(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int buffer;
			cin >> buffer;
			matrix[i].push_back(buffer);
		}
	}
	for (int j = 0; j < n; j++) { //j – начиная с какого номера ищем наименьший
		int num_min = j; //номер минимального элемента
		for (int i = j; i < n; i++) { //ищем только в еще не упорядоченной части
			if (matrix[i][0] < matrix[num_min][0]) {
				num_min = i;
			}
		}
		//обмен значений элементов a[j] и a[num_min]
		swap(matrix[j], matrix[num_min]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j]<<" ";
		}
		cout << endl;
	}
	return 0;
}
