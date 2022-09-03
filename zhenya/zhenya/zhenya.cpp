#include <iostream>
#include <string>
#include "Lib.h"
using namespace std;
int main()
{
	Lib<string> a;
	a.SetCount("5");
	a.Show();
	return 0;
}
