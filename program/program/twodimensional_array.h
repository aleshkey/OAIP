#pragma once
#include <vector>
using namespace std;
class twodimensional_array
{
private:
	int rows;
	int colums;
	vector <std::vector<int>> arr;
	bool row_comparison(vector <int> arr1, vector <int> arr2);
	vector<vector<int>> GetArray();
public:
	twodimensional_array(int raws=0, int colums=0);
	~twodimensional_array();
	void creation();
	void sorting();
	void print();
	void replace(int valueROW, int valueCOLUM, int number);
	void addrow();
	void search(int number);
	void Union(twodimensional_array arr1);
	void intersection(twodimensional_array arr1);
	void SetRows(int rows);
	void SetColums(int colums);
	void SetArray(vector<vector<int>> arr1);
};
