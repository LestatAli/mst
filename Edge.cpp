#include "Edge.h"

using namespace std;

Edge::Edge()
{
	u = new Point();
	v = new Point();
	my_weight = u->getDistanceTo(v);
}

Edge::Edge(Point *u, Point *v, float weight)
{
	this->u = u;
	this->v = v;
	my_weight = weight;
}

Edge::Edge(Point *u, Point *v)
{
	this->u = u;
	this->v = v;
	my_weight = u->getDistanceTo(v);
}


float Edge::getWeight() const
{
	return my_weight;
}

Point * Edge::getOriginVertex() const
{
	return u;
}

Point * Edge::getEndVertex() const
{
	return v;
}

bool Edge::operator > (Edge e2)
{
	return (my_weight > e2.getWeight());
}

void Edge::print() const
{
	cout << "Edge: [u = ";
	u->print();
	cout<< ", v = ";
	v->print();
	cout<< ", weight = " << my_weight << "]" <<endl;
}