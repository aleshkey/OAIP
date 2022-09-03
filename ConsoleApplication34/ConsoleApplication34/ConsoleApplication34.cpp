#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int n;

vector<char> cl;
vector<int> p;
vector<vector<int> > g, gr;
vector < vector < int>> a(6);
vector < vector < int>> zxc(5);
vector<int> used, top, color;
int cycle_st, cycle_end;

/*void transponirovanie() {

}*/
void asdasdsadsa(vector<vector<int>>zxc) {
	 for (int i = 0; i < zxc.size(); i++){
	 for (int j = 0; j < zxc.size(); j++){
	 cout << zxc[i][j];
	 }
	 }
}

int main() {
	int x, nach, obhvat = 1;
	vector<int> k;
	vector<int> b;
	ifstream fin; fin.open("input.txt");
	if (fin.is_open()) {
		while (!fin.eof()) {
			fin >> x;
			k.push_back(x);
		}
	}
	x = k.size();
	int q = 0;
	n = round(sqrt(x));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i].push_back(k[q]);
			q++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	//cout << 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			zxc[i].push_back(a[j][i]);
		}
	}
}