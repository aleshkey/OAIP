#include <Windows.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;
int main()
{
	float x;
	HDC hDC = GetDC(GetConsoleWindow());
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hDC, Pen);
	MoveToEx(hDC, 10, 170, NULL);
	LineTo(hDC, 420, 170);
	MoveToEx(hDC, 200, 50, NULL);
	LineTo(hDC, 200, 240);
	MoveToEx(hDC, 200, 50, NULL);
	LineTo(hDC, 195, 70);
	MoveToEx(hDC, 200, 50, NULL);
	LineTo(hDC, 205, 70);
	MoveToEx(hDC, 420, 170, NULL);
	LineTo(hDC, 400, 175);
	MoveToEx(hDC, 420, 170, NULL);
	LineTo(hDC, 400, 165);
	for (x = -9.0; x <= 9.5; x += 0.0001) 
	{
		MoveToEx(hDC, 20 * x + 200, -20 * (exp(x) / (x*x*x) - pow(sin(x), 3) - 2) + 170, NULL);
		LineTo(hDC, 20 * x + 200, -20 * (exp(x) / (x*x*x) - pow(sin(x), 3) - 2) + 170);
	}
	_getch();
	return 0;
}