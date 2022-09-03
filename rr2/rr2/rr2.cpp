#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

void dfs(int v,  vector<vector<int>> g, vector<bool> used, vector<int> p, bool cycle) {
	used.push_back (1);
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if (used[to] == 0) {
			p[to] = v;
			dfs(to, g, used, p, cycle);
		}
		else if (used[to] == 1)
			cycle = true;
	}
	used[v] = 2;
}

int main()
{
	vector<bool> used;
	vector<int> p;
	bool cycle;
	int x;
	vector<int> k;
	ifstream fin; fin.open("input.txt");
	if (fin.is_open()) {
		while (!fin.eof()) {
			fin >> x;
			k.push_back(x);
		}
	}
	else cout << "file is not open\n";
	x = k.size();
	int n = round(sqrt(x));
	vector<vector<int>> g(n);
	int q = 0;
	vector<vector<int>> a(n);
	//cout << 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i].push_back(k[q]);
			q++;
		}
	}
	//cout << 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1) {
				g[i].push_back(j);
			}
		}
	}
	cout << 3;
	for (int i = 0; i < n; i++) {
		cout << i << ") ";
		for (int j = 0; j < g[i].size(); j++) {
			cout << g[i][j]<<" ";
		} 
		cout << endl;
	}
	cout << endl;
	for (int l = 0; l < n; l++) {
		if (!used[l]) dfs(l, a, used, p, cycle);
		if (cycle) {
			cout << cycle;
		}
	}
	cout << 0;
	
	return 0;
}
