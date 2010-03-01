#include <vector>
#include "DisjointSet.h"

#pragma once

class DisjointSetCollection
{
private:
	vector<DisjointSet *> my_sets;

public:
	DisjointSetCollection();
	void makeSet(Node *a_root);
	int find(Node *some_node);
	void link(int set_x_addr, int set_y_addr);
	void unite(Node *node_x, Node *node_y);
	void print() const;
};

