#include <iostream>
#include "func.h"
#include "kub.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	int x, kod;
	cout << "Выберите функцию\n1)квадрат\n2)куб\n3)корень\n";
	cin >> kod;
	cout << "выберите элемент\n";
	cin >> x;
	switch(kod) {
		case 1: cout << func(x);
				break;
		case 2: cout << kub(x);
				break;
	}
}
