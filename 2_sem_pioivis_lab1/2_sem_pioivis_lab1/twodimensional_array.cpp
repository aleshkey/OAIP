#include <iostream>
#include "twodimensional_array.h"
using namespace std;

twodimensional_array::twodimensional_array(int raws, int colums) {
	this->raws = raws;
	this->colums = colums;
	for (int count = 0; count < this->raws; count++)
		arr[count] = new int[this->colums];
}

twodimensional_array::~twodimensional_array() {
	for (int count = 0; count < raws; count++)
		delete (arr[count]);
}

void twodimensional_array::creation()
{
	for (int i = 0; i < raws; i++) {
		for (int j = 0; j < colums; j++) {
			cin >> arr[i][j];
		}
	}
}

void twodimensional_array::sorting()
{
	int  *buffer = new int[raws*colums];
	int count = 0, n = raws*colums;
	for (int i = 0; i < raws; i++) {
		for (int j = 0; j < colums; j++) {
			buffer[count] = arr[i][j];
			count++;
		}
	}
	for (int j = 0; j < n; j++) { 
		int num_min = j; 
		for (int i = j; i < n; i++) {
			if (buffer[i] < buffer[num_min]) {
				num_min = i;
			}
		}
		int temp;
		temp = buffer[j];
		buffer[j] = buffer[num_min];
		buffer[num_min] = temp;
	}
	count = 0;
	for (int i = 0; i < raws; i++) {
		for (int j = 0; j < colums; j++) {
			arr[i][j] = buffer[count];
			count++;
		}
	}
}

void twodimensional_array::Print()
{
	for (int i = 0; i < raws; i++) {
		for (int j = 0; j < colums; j++) {
			int buffer = arr[i][j];
			cout << buffer << "\t";
		}
		cout << endl;
	}
}

void twodimensional_array::replace(int x, int y, int a)
{
	for (int i = 0; i < raws; i++) {
		for (int j = 0; j < colums; j++) {
			if (i == x && j == y) {
				arr[i][j] = a;
			}
		}
	}
	sorting();
}

