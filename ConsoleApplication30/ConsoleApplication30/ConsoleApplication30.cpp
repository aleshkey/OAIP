
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> cl;
vector<int> q;
int /*cycle_st, cycle_end,*/ path =0;

bool dfs(int start, int finish, vector <vector<int>> g) {
	if (start != finish) {
		cl[start] = 1;
		for (size_t i = 0; i < g[start].size(); ++i) {
			int to = g[start][i];
			if (cl[to] == 0) {
				q[to] = start;
				path++;
				if (dfs(to, finish, g))  return true;
			}
		}
		cl[start] = 2;
		return false;
	}
	else return true;
}


int main()
{
	int n, m, k;
	double a, b;
	cin >> n >> m >> k >> a >> b;
	vector <int> people(k);
	vector <int> C(m);
	vector <int> D(m);
	vector <int> paths;
	vector < vector<int> > g(n);
	//int s;
	
	
	//cout << 1;
	//vector<bool> used(n);
	//cout << 2;
	//vector<int> d(n);
	//vector<int> p(n);
	
	
	for (int i = 0; i < k; i++) {
		cin >> people[i];
	}

	for (int j = 0; j < m; j++) {
		cin >> C[j];
		cin >> D[j];
	}
	for (int i = 0; i < m; i++) {
		int x = C[i] - 1;
		int y = D[i] - 1;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			cout << g[i][j]<<" ";
		}
		cout << endl;
	}*/
	//int time = 0;
	for (int i = 0; i < k; i++) {
		q.assign(n, -1);
		cl.assign(n, 0);
		bool x = dfs(people[i]-1, 0, g);
		/*time += path;
		path = 0;*/
	}
	//cout << path;
	
}

