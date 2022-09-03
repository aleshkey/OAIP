#include <stdlib.h>
#include <iostream>
#include "menu.h"
void output(float* a, int m, int n) {
	int i, j;
	if (m == 0 || n == 0) {
		printf("Не введен массив\n");
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%.2f ", *(a + i * m + j));
		printf("\n");
	}
	menu(a, m, n);
}