#include <string>
#include <cstdlib>
#include "point4d.h"
#include "Edge.h"
#include "Heap.h"
#include "DisjointSet.h"
#include <vector>

#pragma once;

using namespace std; 

class PolyGraph
{
private:
	Point **vertices;
	EdgeHeap *my_edges;
	int size;
	short dim;
	
public:
	PolyGraph();
	PolyGraph(short, int);
	void print() const;
	vector<Edge *> getMST();
};



