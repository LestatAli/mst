#include <iostream>
#include "quickmath.h"

#pragma once;

using namespace std;

class SimpleGraph
{
private:
	float **edge_weights;
	int size;
	
public:
	SimpleGraph();
	SimpleGraph(int);
	void print() const;
	void getMST(); 
};