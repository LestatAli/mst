#include <cstdlib>
#include <vector>
#include "point.h"

#pragma once

using namespace std;

class Node 
{
private:
	Point *my_vertex;
	Node *my_parent;
	vector<Node *> my_children;
	
public:
	Node();
	//Node(Point *, Node *, Point *);
	Node(Point *, Node *);
	Node(Point *);
	~Node();
	Point * getVertex() const;
	Node * getParent() const;
	vector<Node *> getChildren() const;
	void setParent(Node *);
	void addChild(Node *);
	void print() const;
};
