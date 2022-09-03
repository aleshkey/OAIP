#include <iostream>
#include <vector>
#include <string>
using namespace std;
int minimum(vector<char> arr1, vector<char> arr2, int N) {
	int i=0;
	if (arr1.size() != 0 && arr2.size() != 0) {
		if (arr1[N] < arr2[N]) {
			i = 1;
		}
		else {
			if (arr1[N] == arr2[N] && N + 1 < arr1.size() && N + 1 < arr2.size()) {
				N++;
				i = minimum(arr1, arr2, N);
			}
		}
	}
	return i;
}
int main()
{
	string str;
	vector<int> spaces;
	getline(cin, str);
	spaces.push_back(-1);
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			spaces.push_back(i);
		}
	}
	int j,x, kol = spaces.size();
	vector<vector<char>> words(kol);
	for (j = 0; j < kol; j++) {
		if (j+1 < kol) {
			for (int i = spaces[j]+1; i < spaces[j + 1]; i++) {
				words[j].push_back(str[i]);
				x = i;
			}
		}
		else 
			for (int i = x+2; i < str.length(); i++) {
				words[j].push_back(str[i]);
			}
	}

	//сортировка------------------------------------------------------------------------
	
	for (int p = 0; p < kol; p++) {
		int num_min = p;
		for (int i = p; i < kol; i++) {
			/*if (words[i] < words[num_min]) {
				num_min = i;
			}*/
			if (words[i].size() != 0 && words[num_min].size() != 0) {
				j = 0;
				int x = minimum(words[i], words[num_min], j);
				if (x == 1) {
					num_min = i;
				}
			}
		}
		swap(words[p], words[num_min]);
	}

	//-----------------------------------------------------------------------------
	for (int i = 0; i < words.size(); i++) {
		for (j = 0; j < words[i].size(); j++) {
			cout << words[i][j];
		}
		cout<<endl;
	}
	return 0;
}

