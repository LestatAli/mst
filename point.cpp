// Implementation of Point class

#include <iostream>
#include <cstdlib>
#include "Point.h"
#include "QuickMath.h"

using namespace std;

Point::Point(float x, float y)
{
	this->x = x;
	this->y = y;
}

Point::Point()
{
	x = myrand();
	y = myrand();
}


float Point::getDistanceTo(Point *B)
{
	float distance = 0;
	distance += square(this->x - B->x);
	distance += square(this->y - B->y);
	return sqrt(distance);
}

void Point::print() const
{
	cout<< "(" << x <<", " << y << ")";
}	