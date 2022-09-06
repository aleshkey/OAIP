#include <iostream>
#include <cmath>
#include<stdlib.h>
#include "Vector.h"

using namespace std;

int main()
{
	double start[3] = { 0,0,3 };
	double finish[3] = { 0,0,4 };
	Vector vec {start, finish};
  	cout << vec.getLength();
	return 0;
}
