#include <stdlib.h>
#include <iostream>
#include "nek.h"
#include "output.h"
void menu(float* a, int m, int n) {
	setlocale(LC_ALL, "Russian");
	printf("\n");
	printf("Выберите действие:\n");
	printf("1.Ввод массива\n");
	printf("3.Вывод массива\n");
	printf("5.Выход\n");
	int c;
	scanf_s("%d", &c);
	switch (c) {
	case 1:
		nek();
		break;   
	case 3:
		output(a, m, n);
		break;
	case 5:
		break;
	default:
		printf("Ошибка\n");
	}
}