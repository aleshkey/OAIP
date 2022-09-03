// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <string> 
using namespace std;
int main()
{
	string str;
	double a, b, z, x, p, fx,y;
	cout << "vvedite a i b "<< endl;
	cin >> a >> b;
	cout << "vvedite z" << endl;
	cin >> z;
	cout << "chemu ravno F(x):" << endl << "1) F(x)=2*x" << endl << "2) F(x)=x*x" << endl << "3) F(x)=x/3"<<endl;
	cin >> p;
	
	if (z < 1) {
		x = z * z*z + 0.2;
	}

	else {x = z + log10(z); }
	
	if (p == 1) {
		fx = 2 * x;
		str = "*2";
	}

	if (p == 2) {
		fx = x * x;
		str = "^2";
	}

	if (p == 3) {
		fx = x/3;
		str = "/3";
	}

	y = 2 * a*cos(x*x)*cos(x*x)*cos(x*x) + sin(x*x*x)*sin(x*x*x) - b * fx;
	cout << "y = "<< a<<"*cos^3("<<x<<"^2) + sin^2 ("<<x<<"^3) - "<< b<< "*"<<x<< str<<endl;
	cout << "Otvet: " << y;

	return 0;
}


