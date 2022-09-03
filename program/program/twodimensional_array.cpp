#include "twodimensional_array.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool twodimensional_array::row_comparison(vector<int> arr1, vector<int> arr2)
{
	if (arr1.size() == arr2.size()) {
		for (int i = 0; i < arr1.size(); i++) {
			if (arr1[i] != arr2[i]) {
				return false;
			}
		}
		return true;
	}
	else return false;
}

twodimensional_array::twodimensional_array(int rows, int colums)
{
		this->rows = rows;
		this->colums = colums;
}

twodimensional_array::~twodimensional_array()
{
	arr.clear();
}

vector<vector<int>> twodimensional_array::GetArray()
{
	return arr;
}

void twodimensional_array::creation()
{
	for (int i = 0; i < rows; i++) {
		vector <int> buffer;
		for (int j = 0; j < colums; j++) {
			int x;
			cin >> x;
			buffer.push_back(x);
		}
		arr.push_back(buffer);
	}
}

void twodimensional_array::sorting()
{
	vector<int> buffer(rows*colums);
	int count = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colums; j++) {
			buffer[count] = arr[i][j];
			count++;
		}
	}
	sort(buffer.begin(), buffer.end());
	count = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colums; j++) {
			arr[i][j] = buffer[count];
			count++;
		}
	}
}

void twodimensional_array::print()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colums; j++) {
			int buffer = arr[i][j];
			cout << buffer << "\t";
		}
		cout << endl<<endl;
	}
}

void twodimensional_array::replace(int valueROW, int valueCOLUM, int number)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colums; j++) {
			if (i == valueROW && j == valueCOLUM) {
				arr[i][j] = number;
			}
		}
	}
	//sorting();
}

void twodimensional_array::addrow()
{
	vector<int> arr1;
	cout << "enter new row\n";
	for (int i = 0; i < colums; i++) {
		int buffer;
		cin >> buffer;
		arr1.push_back(buffer);
	}
	arr.push_back(arr1);
	rows++;
}

void twodimensional_array::search(int number)
{ 
	vector <pair<int, int>> cordinates;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colums; j++) {
			if (arr[i][j] == number) {
				cordinates.emplace_back(i, j);
			}
		}
	}
	if (cordinates.size() == 0) {
		cout << "таких элементов нет\n";
	}
	else {
		for (int i = 0; i < cordinates.size(); i++) {
			cout << "кординаты этого элемента: строка - " << cordinates[i].first << " столбец - "<< cordinates[i].second<<endl;
		}
	}
}

void twodimensional_array::Union(twodimensional_array arr2)
{
	vector<vector<int>> arr1 = arr2.GetArray();
	if (arr[0].size() == arr1[0].size()) {
		int count = 0;
		for (int i = 0; i < arr1.size(); i++) {
			for (int j = 0; j < arr.size(); j++) {
				if (row_comparison(arr1[i], arr[j])) {
					count++;
				}
			}
			if (count == 0) {
				arr.push_back(arr1[i]);
				rows++;
			}
			count = 0;
		}
		cout << "\nобъединение\n";
		print();
	}
	else cout << "\nу массивов разное количество столбцов, объединение невозможно\n";
	arr1.clear();
}

void twodimensional_array::intersection(twodimensional_array arr2)
{
	vector<vector<int>> arr1 = arr2.GetArray();
	if (arr[0].size() == arr1[0].size()) {
		int count = 0;
		int i = 0;
		while (i < arr.size()) {
			for (int j = 0; j < arr1.size(); j++) {
				if (row_comparison(arr1[j], arr[i])) {
					count++;
				}
			}
			if (count == 0) {
				arr.erase(arr.begin() + i);
				rows--;
			}
			else i++;
			count = 0;
		}
		cout << "\nпересечение\n";
		print();
	}
	else cout << "\nу массивов разное количество столбцов, пересечение невозможно\n";
	arr1.clear();
}

void twodimensional_array::SetRows(int rows)
{
	this->rows = rows;
}

void twodimensional_array::SetColums(int colums)
{
	this->colums = colums;
}

void twodimensional_array::SetArray(vector<vector<int>> arr1)
{
	arr = arr1;
	rows = arr1.size();
	colums = arr1[0].size();
}

