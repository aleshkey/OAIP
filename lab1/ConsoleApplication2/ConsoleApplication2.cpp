

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	
	double x, y, z, modul, step, ch1, ch2;
	cout << "vvedite x, y, z ";
	cin >> x >> y>>z ;
	modul = abs(cos(x) - cos(y));
	step = 1 + 2 * sin(y)*sin(y);
	ch1 = pow(modul, step);
	ch2 = 1 + z + z * z / 2 + z * z*z / 3 + z * z*z*z / 4;
	cout << ch1*ch2<<endl;
	system("pause");
	return 0;
}
