#pragma once
#include <iostream>
class Vector
{
private:
	double start[3];
	double finish[3];
public:
	Vector();
	Vector(double start[3], double finish[3]);
	double* getStart();
	void setStart(double start[3]);
	double* getFinish();
	void setFinish(double finish[3]);
	
	double getLength();
};

