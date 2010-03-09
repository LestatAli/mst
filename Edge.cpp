#include "Edge.h"

using namespace std;

Edge::Edge()
{
	u = new Node();
	v = new Node();
	my_weight = u->getVertex()->getDistanceTo(v->getVertex());
}

Edge::Edge(Node *u, Node *v, float weight)
{
	this->u = u;
	this->v = v;
	my_weight = weight;
}

Edge::Edge(Node *u, Node *v)
{
	this->u = u;
	this->v = v;
	my_weight = u->getVertex()->getDistanceTo(v->getVertex());
}


float Edge::getWeight() const
{
	return my_weight;
}

Node * Edge::getOriginNode() const
{
	return u;
}

Node * Edge::getEndNode() const
{
	return v;
}

void Edge::print() const
{
	cout << "Edge: [u = " << u;
	//u->print();
	cout<< ", v = " << v;
	//v->print();
	cout<< ", weight = " << my_weight << "]" <<endl;
}