#include "Node.h"
#include <iostream>

Node::Node()
{
	my_vertex = new Point();
	my_parent = NULL;
	my_children.reserve(1);
	my_rank = 0;
}

Node::Node(Point *vertex, Node *parent)
{
	my_vertex = vertex;
	my_parent = parent;
	my_children.reserve(1);
	my_rank = 0;
}

Node::Node(Point *vertex)
{
	my_vertex = vertex;
	my_parent = NULL;
	my_children.reserve(1);
	my_rank = 0;
}

Point * Node::getVertex() const
{
	return my_vertex;
}

Node * Node::getParent() const
{
	return my_parent;
}

void Node::setParent(Node *new_parent) 
{
	my_parent = new_parent;
}

int Node::getRank() const
{
	return my_rank;
}

void Node::setRank(int new_rank)
{
	my_rank = new_rank;
}

vector<Node *> Node::getChildren() const
{
	return my_children;
}

void Node::addChild(Node *new_child) 
{
	my_children.push_back(new_child);
}

void Node::print() const
{
	std::cout << "Node " << this << " = (Vertex: ";
	my_vertex->print();
	cout << ", Parent: ";
	
	if (my_parent != NULL)
		cout << my_parent;
	else
		cout << "[none]";
	
	cout<<", Children: ";
	
	if (my_children.empty())
		cout<< "[none]";
	
	for (int i = 0; i < my_children.size(); i++)
		cout<< my_children[i] << " ";
	
	cout << ")" <<std::endl;
}