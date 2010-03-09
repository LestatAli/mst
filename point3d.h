// Point3D Class
// Description:

#include "Point.h"
#include "QuickMath.h"
#include <iostream>
#include <cstdlib>

class Point3D : public Point
{
protected:
	float z;
	
public:
	Point3D();
	Point3D(float, float, float);
	float getDistanceTo(Point3D *);
	void print() const;
};



