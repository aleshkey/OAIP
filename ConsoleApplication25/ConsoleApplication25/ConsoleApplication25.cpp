#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
vector<int> cl;
vector<int> p;
int cycle_size=0;
vector<int> sizes;
vector<int> buffer;
int min = INT_MAX;
int cycle_st, cycle_end;

int minimum(vector<int> a) {
	int minzn = INT_MAX;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] < minzn) {
			minzn = a[i];
		}
	}
	return minzn;
}

int maximum(vector<int> a){
	if (a.size() > 0) {
		int maxzn = INT_MIN;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] > maxzn) {
				maxzn = a[i];
			}
		}
		return maxzn;
	}
	else return INT_MAX;
}

bool dfs(int v, vector <vector<int>> g) {
		
		cl[v] = 1;
		int q = 0;
		cycle_size = 0;
		for (int i = 0; i < g[v].size(); ++i) {
			int to = g[v][i];
			if (cl[to] == 0) {
				p[to] = v;
				if (dfs(to, g)) { cycle_size++; 
				}
			}
			else if (cl[to] == 1) {
				cycle_end = v;
				cycle_st = to;
				//int n = g.size();
				cycle_size++;
			}
			if (cycle_size > 0) {
				q++;
			}
			buffer.push_back(cycle_size);
		}
		if (q == 0) {
				return false;
			}
			else return true;
		cl[v] = 2;
		
}

int main() {
	int x, nach, obhvat =1;
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
	int q = 0;
	int n = round(sqrt(x));
	vector<int> b(n);
	vector<vector<int>> a(n);
	vector<vector<int>> g(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i].push_back(k[q]);
			q++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1) {
				g[i].push_back(j);
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		
		p.assign(n, -1);
		cl.assign(n, 0);
		cycle_st = -1;
		if (dfs(i, g)) {
			sizes.push_back(maximum(buffer));
			cycle.clear();
			p.clear();
			buffer.clear();
		}
		
	}
		if (cycle_st == -1)
			puts("Acyclic");
		else {
				cout << "\nmin cycle = " << minimum(sizes);
			}
			
}
