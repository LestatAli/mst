#include "Node.h"
#include <iostream>

#pragma once

class Edge
{
private:
	Node *u; 
	Node *v;
	float my_weight;
	
public:
	Edge();
	Edge(Node *, Node *, float);
	Edge(Node *, Node *);
	float getWeight() const;
	Node * getOriginNode() const;
	Node * getEndNode() const;
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