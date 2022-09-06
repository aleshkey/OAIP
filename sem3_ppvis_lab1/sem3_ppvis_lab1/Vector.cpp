#include "Vector.h"
#include "cmath"

Vector::Vector()
{
}

Vector::Vector(double start[3], double finish[3])
{
	this->start[0] = start[0];
	this->start[1] = start[1];
	this->start[2] = start[2];
	this->finish[0] = finish[0];
	this->finish[1] = finish[1];
	this->finish[2] = finish[2];
}


double * Vector::getStart()
{
	return start;
}

void Vector::setStart(double start[3])
{
	this->start[0] = start[0];
	this->start[1] = start[1];
	this->start[2] = start[2];
}

double * Vector::getFinish()
{
	return finish;
}

void Vector::setFinish(double finish[3])
{
	this->finish[0] = finish[0];

	this->finish[1] = finish[1];

	this->finish[2] = finish[2];
}

double Vector::getLength()
{
	double res =  sqrt(pow((finish[0]+start[0]), 2) + pow((finish[1] + start[1]), 2) + pow((finish[3] + start[3]), 2));
	return res;
}


