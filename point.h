// Point Class
// Description:
#pragma once

class Point
{
protected:
	float x;
	float y;
	
public:
	Point();
	Point(float, float);
	virtual float getDistanceTo(Point *);
	virtual void print() const;
};
