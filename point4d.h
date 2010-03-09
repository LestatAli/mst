// Point4D Class
// Description: 4 dimensional point

#include "Point3D.h"
#include "QuickMath.h"
#include <iostream>
#include <cstdlib>

class Point4D : public Point3D
{
protected:
	float w;
	
public:
	Point4D();
	Point4D(float, float, float, float);
	float getDistanceTo(Point4D *);
	void print() const;
};



