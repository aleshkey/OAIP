#include <fstream>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

void dfs(int v, vector<int> used, vector<vector<int>> g, vector<int> p, bool cycle) {
	used[v] = 1;
	for (size_t i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if (used[to] == 0) {
			p[to] = v;
			dfs(to, used, g, p, cycle);
		}
		else if (used[to] == 1)
			cycle = true;
	}
	used[v] = 2;
}

int main()
{
	bool  cycle;
	vector<int> p;
	vector<int> used;
	vector<int> ans;
	vector<vector<int>> g;
	int x;
	vector <int> k;
	ifstream fin; fin.open("input.txt");
	if (fin.is_open()) {
		while (!fin.eof()) {
			fin >> x;
			k.push_back(x);
		}
	}
	else cout << "file is not open\n";
	int n = round (sqrt(k.size()));
	int **a = new int*[n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
	}
	
	int p = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = k[p];
			p++;
		}
	}
	cout << 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1) {
				g[i].push_back(j);
			}
			cout << 2;
		}
	}
	cout << 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < sizeof(g[i]); j++) {
			cout.width(2);
			cout << g[i][j]<<"\t ";
		}
		cout << endl<<endl;
	}
	x = 0;
	int y = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j< n; j++) {
			if (g[i][j] == 1) {
				
			}
		}
	}
	cout << 1;
	for (int l = 0; l < n; ++l) {
		if (!used[l]) dfs(l, used, g, p, cycle);
		if (cycle) {
			cout << cycle;
		}
	}
	cout << 0;
	


	for (int i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
	fin.close();
	return 0;
}
