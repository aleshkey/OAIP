#include <iostream>
#include <vector>
using namespace std;
int time(vector<int> k, int p) {
	int sum=0;
	for (int i = 0; i < p+1; i++) {
		sum += k[i];
	}
	return sum;
}

int main(){
	int n, m;
	cin >> n>> m;
	vector<int> t;
	vector<int> a(m);
	vector<int> s(m);
	vector<int> T(m);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		t.push_back(x);
	}
	for (int j = 0; j < m; j++) {
		cin >> a[j];
		cin >> s[j];
		cin >> T[j];
	}
	for (int i = 0; i < m; i++) {
		//cout << 2 << " ";
		for (int j = 0; j < t.size(); j++) {
			//cout << 3 << " ";
			if (a[i] > 0) {
				int x = time(t, j), y = s[i];
				//cout << 4 << " ";
				if (time(t, j) > s[i]) {
					t[j + a[i]] += T[i];
					goto tryAgain;
				}
			}
			else {
				t.push_back(T[j]); 
				goto tryAgain;
			}
		}
	tryAgain:;
	}
	for (int i = 0; i < t.size(); i++) {
		cout << t[i]<<" ";
	}
	cout <<endl<<  time(t, (n-2));
	return 0;
}