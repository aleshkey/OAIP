#include <iostream>
#include <vector>
using namespace std;
bool magic(vector<vector<double>> matrix, int por) {
	double sum=0,kol=0;
	for (int i = 0; i < por; i++) {
		sum += matrix[i][0];
	}
	for (int i = 0; i < por; i++) {
		double sum1=0, sum2=0;
		for (int j = 0; j < por; j++) {
			sum1 += matrix[i][j];
			sum2 += matrix[j][i];
		}
		if (sum1 != sum && sum2 != sum) {
			kol++;
		}
	}
	if (kol == 0) return true;
	else return false;
}
int main()
{
	int por;
	cout << "vvedite poriadok matrici\n";
	cin >> por;
	vector <vector <double>> matrix(por);
	for (int i = 0; i < por; i++) {
		for (int j = 0; j < por; j++) {
			double buffer;
			cin >>buffer;
			matrix[i].push_back(buffer);
		}
	}
	if (magic(matrix, por)) {
		cout << "magicheskiy kvadrat";
	}
	else cout << "net";
	return 0;
}
