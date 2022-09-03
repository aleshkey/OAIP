#include <iostream>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>	
using namespace std;
int from = 0, n = 0, k = 0, num_of_units = 0, num_of_edges = 0;
vector<vector<int> > p;
vector<int> color;
vector<int> sizes;
struct edge {
	int b;
	int e;
};

void dfs(vector<vector<int> >ed, int v) {
	n++;
	static int to; // to - номер вершины, в которую собираемся пойти
	color[v] = 1;
	for (int i = 0; i < num_of_edges; i++)
	{
		if (ed[i][0] == v)
		{
			to = ed[i][1];
			if (color[to] == 0)
			{
				p[n][0] = ed[i][0]; p[n][1] = ed[i][1]; //
				from = v;
				dfs(ed, to);
				if (n < p.size()) {
					while (p[n][1] != v && n > 0)       //!!!!!
						n--;
					n++;
				}
				else {
					n = 0;
				}
			}
			else if (color[to] == 1)
			{
				k = n;
				sizes.push_back(n);

			}
		}
	}
	if (v == 0) color[v] = 2;
	else
		if (color[from] == 1)
			color[v] = 0;
		else color[v] = 2;
}

int main()
{
	ifstream in("input.txt");
	vector<string> stringnode;
	vector<vector<edge> > result;
	vector<vector<string> > mi;
	string s, tmp_;
	edge ed;
	int obhvat = INT_MAX;
	string::iterator itr;
	while (getline(in, s)) // запись массива в стринг из файла
	{
		for (itr = s.begin(); itr != s.end(); itr++) {
			if (*itr != ' ') {
				tmp_.push_back(*itr);
			}
			if (*itr == ' ' || itr == s.end() - 1) {
				stringnode.push_back(tmp_);
				tmp_.clear();
			}
		}
		mi.push_back(stringnode);
		stringnode.clear();
	}
	vector<string> vect = mi[0];
	int siz = vect.size();
	vect.clear();
	vector<vector<int> > graf;
	vector<int> temp;
	for (int i = 0; i < siz; i++) {
		for (int j = 0; j < mi.size(); j++) {
			temp.push_back(atoi(mi[j][i].c_str()));
		}
		graf.push_back(temp);
		temp.clear();
	}//запись стринга в число в столбцы
	int prov = 0;
	siz = mi.size();
	num_of_edges = graf.size();
	num_of_units = siz;
	vector<vector<int> > tem;
	for (int i = 0; i < num_of_edges; i++) {
		vector<int>sos_i_pie_sos;
		sos_i_pie_sos.push_back(0);
		sos_i_pie_sos.push_back(0);
		tem.push_back(sos_i_pie_sos);
	}
	for (int i = 0; i < graf.size(); i++) {
		for (int j = 0; j < siz; j++) {
			if (graf[i][j] == 1) {
				tem[i][0] = j;
			}
			if (graf[i][j] == -1) {
				tem[i][1] = j;
			}
		}
	}
	for (int i = 0; i < num_of_units; i++)
		color.push_back(0);
	for (int i = 0; i < num_of_edges; i++) {
		vector<int>sos_i_pie_sos;
		sos_i_pie_sos.push_back(0);
		sos_i_pie_sos.push_back(0);
		p.push_back(sos_i_pie_sos);
	}
	for (int i = 0; i < num_of_units; i++)
		if (color[i] == 0)
			dfs(tem, i);
	for (int i = 0; i < sizes.size(); i++) {
		if (obhvat >= sizes[i]) {
			obhvat = sizes[i];
		}
	}
	cout << obhvat;
}