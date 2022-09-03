// Создать программу, которая выполняет действия из задания 1 и задания 2. По запросу с клавиатуры, программа выполняет следующие действия: 
//1)    Ввести новый массив (динамический); 
//3)    Вывод массива; 
//5)    Выход. 

#include <stdio.h> 
#include <locale.h> 
#include <stdlib.h> 
#include <locale.h> 
#include"menu.h" 

/*void nek();
void output(float*, int, int);
void menu(float*, int, int);
void zad1(void);*/

int main() {
	menu(0, 0, 0);
	setlocale(LC_ALL, "Russian");
}

/*void menu(float* a, int m, int n) {
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
	case 2:
		//zad1();
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

void nek() {
	printf("Введите массив\n");
	float* a;
	int n, m, i, j;
	printf("Введите количество строк массива\n");
	scanf_s("%i", &m);
	printf("Введите количество столбцов массива\n");
	scanf_s("%i", &n);
	a = (float*)malloc(n * m * sizeof(float));
	printf("Введите элементы массива\n");
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
}*/