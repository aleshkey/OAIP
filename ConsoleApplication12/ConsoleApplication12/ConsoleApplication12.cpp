// ConsoleApplication12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <cmath>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	string x;
	cout << "Choose month ";
	getline (cin, x);
	if (x == "January" || x == "March" || x == "May" || x == "July" || x == "August" || x == "October"|| x == "December") {
		cout << "31 \n";
	}
	if (x == "February") {
		cout << "28 or 29 \n";
	}
	if (x == "April" || x == "June" || x == "September" || x == "November") {
		cout << "30 \n";
	}

	return 0;
}

