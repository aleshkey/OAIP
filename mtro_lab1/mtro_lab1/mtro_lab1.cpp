#include <iostream>

using namespace std;

int main()
{
	int a, m, sum=1;

	cin >> a>>m;

	for (int i = 1; i <= m; i++) {
		sum += a * i;
	}

	cout << sum;

}


/*
	максимальное время выполнения - 14сек
	кол-во переменных - 4
*/