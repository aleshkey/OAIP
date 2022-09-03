#include <iostream>
#include <vector>
#include "twodimensional_array.h"
using namespace std;

int main()
{

	setlocale(LC_ALL, "rus");
	int raws, colums;
	cin >> raws>>colums;
	twodimensional_array arr(raws,colums);
	arr.creation();
	arr.sorting();
	cout << "\n\n";
	arr.Print();
	cout << "какой элемент хотите заменить?\n";
	int x, y, number;
	cin >> x >> y>>number;
	arr.replace(x,y, number); 
	cout << "\n\n";
	arr.Print();
	return 0;
}
