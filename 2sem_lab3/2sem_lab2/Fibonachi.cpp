#include "Fibonachi.h"
int fibonachi(int n)
{
	if (n == 1 || n == 2) return 1;
	else return fibonachi(n-1)+fibonachi(n-2);
}
