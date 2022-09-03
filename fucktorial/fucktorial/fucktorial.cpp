#include <iostream>
using namespace std;
int rek(int n) {
	if (n == 0) return 1;
	else return n * rek(n - 1);
}
int func(int n) {
	int rez=1;
	for(int i=1;i<=n; i++){
		rez = rez * i;
	}
	return rez;
}
int main()
{
	int n;
	cin >> n;
	cout << rek(n)<<endl;
	cout << func(n) << endl;
	return 0;
}
