#include "Edge.h"
#include <cstdlib>
#include <vector>

#pragma once

using namespace std;

class EdgeHeap
{
private:
	vector<Edge *> my_list;
	
public:
	EdgeHeap();
	EdgeHeap(vector<Edge *> &some_list);
	int getParent(int i);
	int getRight(int i);
	int getLeft(int i);
	bool exists(int x);
	Edge *extractMin();
	void print() const;
	int getSize() const;
private:
	void minHeapify(int);
	void buildHeap();
};