#include "Fibonachy.h"

int fibonachy(int x)
{
	if (x == 1 || x == 2) { return 1; }
	else 
		return fibonachy(x-1)+fibonachy(x-2);
}
