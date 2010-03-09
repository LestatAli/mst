#include <string>
#include <cstdlib>
#include "Point4D.h"
#include "Edge.h"
#include "Heap.h"
#include "DisjointSet.h"
#include <vector>

#pragma once

using namespace std; 

class PolyGraph
{
private:
	vector<Node *> my_nodes;
	EdgeHeap *my_edges;
	int size;
	short dim;
	
public:
	PolyGraph();
	PolyGraph(short, int);
	void print() const;
	vector<Edge *> getMST();
};



