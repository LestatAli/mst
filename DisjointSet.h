#include "Node.h"
#include <cstring>
#include <cstdlib>
#include <iostream>

#pragma once

using namespace std;

class DisjointSet
{
private:
	Node* my_root;
	
public:
	DisjointSet();
	DisjointSet(Node *);
	Node * getRoot() const;
	bool isMember(Node *);
	void print() const;

private:
	void printHelper(Node *) const;
};

