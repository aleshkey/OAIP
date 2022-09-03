#include <iostream>
#include "Fibonachi.h"
using namespace std;
int FIB(int n) {
	int now = 1, last = 1;
	for (int i = 2; i < n; i++) {
		int temp;
		temp = now;
		now = last + now;
		last = temp;
	}
	return now;
}
int main()
{
	int n;
	cin >> n;
	cout << fibonachi(n)<<endl<<FIB(n);
	return 0;
}
