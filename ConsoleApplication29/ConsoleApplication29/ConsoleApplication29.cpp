#include <random>
#include <iostream>


using namespace std;

int main()
{

	//srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	system("color b");

	int n1 = 0, m1 = 0, ch = 0, m = 0;
	int N, M, counter = 0;
	cout << "Введите N,M:" << endl;
	cin >> N >> M;

	vector <vector<int>> mtrx(M);
	cout << "Способ задания матрицы:" << endl << "1-Заполнение случайными числами" << endl << "2-Заполнение вручную" << endl;
	cin >> ch;
	if (ch == 1) {

		for (int m = 0; m < M; m++)
		{
			int buffer;
			for (int n = 0; n < N; n++)
			{
				buffer = rand() % 90 + 10;
				mtrx[m].push_back(buffer);
				cout << mtrx[m][n] << " ";
			}

			cout << "\n";
		}
	}
	else if (ch == 2) {

		for (int m = 0; m < M; m++)
		{
			int buffer;
			for (int n = 0; n < N; n++)
			{
				cin >> buffer;
				mtrx[m].push_back(buffer);
			}

		}
		cout << endl;
	}
	for (int n = 0; n < N; n++) {
		for (int m = 1; m < M - 1; m++) {
			if (mtrx[n][m] < mtrx[n][m + 1]) {
				if (mtrx[n][m] > mtrx[n][m - 1]) {
					counter += 1;
				}

			}
		}
	};
	cout << "Количество элементов: " << counter << endl;


}