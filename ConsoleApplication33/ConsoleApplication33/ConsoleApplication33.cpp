#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int rezult = 0;
	char str[256];
	cout << "Enter string : ";
	cin.getline(str, 256);

	int n = strlen(str);
	vector<int> spaces;
	//getline(cin, str);
	spaces.push_back(-1);
	for (int i = 0; i < n; i++) {
		if (str[i] == ' ') {
			spaces.push_back(i);
		}
	}
	int j, x, kol = spaces.size();
	vector<vector<char>> groups(kol);
	for (j = 0; j < kol; j++) {
		if (j + 1 < kol) {
			for (int i = spaces[j]; i < spaces[j + 1] - 1; i++) {
				groups[j].push_back(str[i + 1]);
				x = i;
			}
		}
		else
			for (int i = x + 3; i <n; i++) {
				groups[j].push_back(str[i]);
			}
	}
	for (int i = 0; i < kol; i++) {
		if (groups[i].size() % 2 != 0) {
			for (int j = 0; j < groups[i].size(); j++) {
				if (groups[i][j] == '1') {
					rezult++;
				}
			}
		}
	}
	cout << rezult;
	return 0;
}

