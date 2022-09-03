#include <iostream>
using namespace std;
#include "Header.h"
int main()
{
	char kod = 'y';
	while (kod != 'n') {
		int x;
		cin >> x;
		cout << func(x);
		char buffer;
		system("pause");
		system("cls");
		cout << endl<<"hochesh povtorit?\n";
		cin >> buffer;
		kod = buffer;
		system("cls");
	}
	return 0;
}

