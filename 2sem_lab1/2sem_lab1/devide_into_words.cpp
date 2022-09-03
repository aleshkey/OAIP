#include "devide_into_words.h"
#include <vector>
#include <string>
using namespace std;
vector<string> Devide_into_words(std::string str) {
	vector<int> spaces;
	spaces.push_back(-1);
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			spaces.push_back(i);
		}
	}
	int j, x=-2, kol = spaces.size();
	vector<string> words(kol);
	for (j = 0; j < kol; j++) {
		if (j + 1 < kol) {
			for (int i = spaces[j] + 1; i < spaces[j + 1]; i++) {
				words[j].push_back(str[i]);
				x = i;
			}
		}
		else
			if (spaces.size()!=1) {
				for (int i = x + 2; i < str.length(); i++) {
					words[j].push_back(str[i]);
				}
			}
	}
	return words;
}