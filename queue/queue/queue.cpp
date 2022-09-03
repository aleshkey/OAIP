#include <iostream>
#include <queue>
using namespace std;
int main()
{
	int n;
	queue<int> q;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		q.push(temp);
	}
	swap(q.front(), q.back());
	for (int i = 0; i < n; i++) {
		cout << q.front()<< " ";
		q.pop();
	}
	return 0;
}

