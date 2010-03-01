#include <iostream>
#include <ctime>
#include "QuickMath.h"
#include "PolyGraph.h"
#include "SimpleGraph.h"
#include "DisjointSetCollection.h"
#include "Heap.h"
#include <iomanip>

using namespace std;

void testPoints();
void testSets();
void testSetCollection();

int main (int argc, char * const argv[]) 
{
	cout<<"Seeding random number generator..." <<endl;
	srand(clock());
	
	//testPoints();
	//testSets();
	//testSetCollection();
	
	// Tests for graphs
	cout<<"Running Graph tests..." <<endl;
	PolyGraph pG(3, 5);
	cout<<"Graph created. Printing edge heap... " <<endl;
	pG.print();
	
	cout<<"Running Kruskal's algorithm... " <<endl;
	vector<Edge *> tree = pG.getMST();
	
	cout<<"Printing MST as an edge list... " <<endl;
	for (int i = 0; i < tree.size(); i++)
	{
		cout<<"Edge " << i <<": ";
		tree[i]->print();
	}
}
	
void testSetCollection()
{
	DisjointSetCollection *coll = new DisjointSetCollection();
	
	coll->makeSet(new Node(new Point()));
	coll->makeSet(new Node(new Point()));
	
	coll->print();
	
	// To do: test the rest of the operations
}

void testPoints()
{
	// Tests for points
	cout<<"Running Point tests..." <<endl;
	Point *vertices[3];
	
	vertices[0] = new Point4D();
	vertices[1] = new Point3D();
	vertices[2] = new Point();
	
	cout<<"Created three vertices. Printing.." <<endl;
	vertices[0]->print();
	cout<<endl;
	vertices[1]->print();
	cout<<endl;
	vertices[2]->print();
	cout<<endl;
	
	cout<<"Distance = " << vertices[0]->getDistanceTo(vertices[1]) << endl;
}

void testSets()
{
	// Tests for disjoint sets
	cout<< "Testing Nodes... "<<endl;
	Node *n1 = new Node(new Point(3, 4));
	Node *n2 = new Node(new Point(4, 13));
	Node *n3 = new Node(new Point(2.4, 32.4), n1);
	Node *n4 = new Node (new Point(13.4, 3.121));
	
	n1->addChild(n2);
	n1->addChild(n3);
	n2->setParent(n1);
	
	n1->print();
	n2->print();
	n3->print();
	n4->print();
	
	cout<< "Testing Disjoin Sets... "<<endl;
	DisjointSet *s1 = new DisjointSet(n1);
	s1->print();
	if (s1->isMember(n3))
		cout<< "Node is a member of S1" <<endl;
	else
		cout<< "Node not found in S1" <<endl;
	
}	
