#include <stdlib.h>
#include <iostream>
#include "menu.h"
void nek() {
	printf("������� ������\n");
	float* a;
	int n, m, i, j;
	printf("������� ���������� ����� �������\n");
	scanf_s("%i", &m);
	printf("������� ���������� �������� �������\n");
	scanf_s("%i", &n);
	a = (float*)malloc(n * m * sizeof(float));
	printf("������� �������� �������\n");
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf_s("%f", (a + i * n + j));
		}
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%.2f ", *(a + i * m + j));
		printf("\n");
	}
	menu(a, m, n);
}
