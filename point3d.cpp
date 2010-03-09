// Implementation of Point3D class

#include "Point3D.h"

using namespace std;

Point3D::Point3D(float x, float y, float z) : Point(x, y)
{
	this->z = z;
}

Point3D::Point3D()
{
	z = myrand();
}


float Point3D::getDistanceTo(Point3D *B)
{
	float distance = 0;
	distance += square(this->x - B->x);
	distance += square(this->y - B->y);
	distance += square(this->y - B->z);
	return sqrt(distance);
}

void Point3D::print() const
{
	cout<< "(" << x <<", " << y <<", " << z << ")";
}	