#pragma once
#include <iostream>
using namespace std;
class twodimensional_array
{
private:
	int raws, colums;
	int **arr = new int*[raws];

public:
	twodimensional_array(int raws, int colums);
	~twodimensional_array();
	void creation();
	void sorting();
	void Print();
	void replace(int x, int y, int a);
};

