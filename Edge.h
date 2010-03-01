#include "point.h"
#include <iostream>

#pragma once;

class Edge
{
private:
	Point *u; 
	Point *v;
	float my_weight;
	
public:
	Edge();
	Edge(Point *, Point *, float);
	Edge(Point *, Point *);
	float getWeight() const;
	Point * getOriginVertex() const;
	Point * getEndVertex() const;
	void print() const;
	bool operator > (Edge);
};

class EdgeComparator
{
public:
	bool operator()(Edge *e1, Edge *e2)
	{
		return (e1->getWeight() > e2->getWeight());
	}
};