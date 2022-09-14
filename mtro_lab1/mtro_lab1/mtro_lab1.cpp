#include <iostream>

using namespace std;

int main()
{
	int a, m, sum;
	
	sum = 1;
	cin >> a>>m;

	for (int i = 1; i <= m; i++) {
		sum += a * i;
	}

	cout << sum;

}


/*
	общая формула подсчета времени - 3+m*2
	максимальное время выполнения - 23сек
	кол-во переменных - 4
*/