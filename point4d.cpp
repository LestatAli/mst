// Implementation of Point4D class

#include "Point4D.h"

using namespace std;

Point4D::Point4D(float x, float y, float z, float w) : Point3D(x, y, z)
{
	this->w = w;
}

Point4D::Point4D()
{
	w = myrand();
}


float Point4D::getDistanceTo(Point4D *B)
{
	float distance = 0;
	distance += square(this->x - B->x);
	distance += square(this->y - B->y);
	distance += square(this->y - B->z);
	distance += square(this->w - B->w);
	return sqrt(distance);
}

void Point4D::print() const
{
	cout<< "(" << x <<", " << y <<", " << z << ", " << w << ")";
}	