
#include <vector>
#include <iostream>
#include <queue>
#include <fstream>
using namespace std;
int main()
{
	
	int x, nach, obhvat = 1;
	vector<int> k;
	vector<int> cycle;
	ifstream fin; fin.open("input.txt");
	if (fin.is_open()) {
		while (!fin.eof()) {
			fin >> x;
			k.push_back(x);
		}
	}
	x = k.size();
	int w = 0;
	int n = round(sqrt(x));
	vector<int> b(n);
	vector<vector<int>> a(n);
	vector<vector<int>> g(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i].push_back(k[w]);
			w++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1) {
				g[i].push_back(j);
			}
		}
	} // число вершин
	//cout << 1;
	int to;
		int s=0;
		queue<int> q;
		q.push(s);
		vector<bool> used(n);
		vector<int> d(n), p(n);
		used[s] = true;
		p[s] = -1;
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (size_t i = 0; i < g[v].size(); ++i) {
				to = g[v][i];
				if (!used[to]) {
					used[to] = true;
					q.push(to);
					d[to] = d[v] + 1;
					p[to] = v;
				}
				else {
					cycle.push_back(d[to]);
				}
			}
		}
	for (int i = 0; i < cycle.size(); i++) {
		cout << cycle[i] << " ";
	}
}