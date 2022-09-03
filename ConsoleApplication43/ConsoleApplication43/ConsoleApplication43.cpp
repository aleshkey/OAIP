#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	char str[256];
	cin.getline(str, 256);
	vector<char> rezult;
	int kol=0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] <= '9' && str[i] >= '0' && kol<=1) {
			rezult.push_back(str[i]);
		}
		else
			if ((str[i] == '.' || str[i] == ',') && (rezult.size() != 0 && kol==0)) {
				rezult.push_back(str[i]);
				kol++;
			}
			else if ((str[i] == '.' || str[i] == ','||(str[i] >= 'A' && str[i]<='z')) && rezult.size()!=0) {
				kol++;
			}
	}
	cout << endl;
	for (int i = 0; i < rezult.size(); i++) {
		cout << rezult[i];
	}
	return 0;
}

