#include <stdio.h>
#include <iostream>
int func(int x) {
	int rezult=0;
	if (x == 2 || x==1 || x==0) {
		rezult =1;
	}
	else rezult = func(x-2)+func(x-1);
	//std::cout << rezult<< " ";
	return rezult;
}