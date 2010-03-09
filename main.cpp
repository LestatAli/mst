#include <iostream>
#include <sys/time.h>
#include "QuickMath.h"
#include "PolyGraph.h"
#include "DisjointSetCollection.h"
#include "Heap.h"

using namespace std;

// tests
void testPoints();
void testSets();
void testSetCollection();

int main (int argc, char * const argv[]) 
{
	// interpret command line arguments
	if (argc < 5)
	{
		cout << "Usage: randmst 0 numpoints numtrials dimension" <<endl;
		return 1;
	}
	
	int mode = atoi(argv[1]);
	int num_points = atoi(argv[2]);
	int num_trials = atoi(argv[3]);
	int dimension = atoi(argv[4]);
	
	if (dimension == 1 || dimension > 4)
	{
		cout<<"Dimension " <<dimension <<" is not supported due to lack of interest." <<endl;
		return 2;
	}
	
	if (mode > 0)
	{
		cout<<"Running in timed mode." <<endl;
		if (mode == 2)
			cout<<"Will also be verbose!" <<endl;
	}
	
	// prepare some vars
	float average_weight = 0;
	if (mode > 0)
		cout<<"Seeding random number generator..." <<endl;
	srand(clock());
	
	// begin trials
	for (int trials = 0; trials < num_trials; trials++)
	{
		struct timeval timeval1;
		struct timeval timeval2;
		
		if (mode > 0)
		{
			gettimeofday(&timeval1, NULL);
			cout<<"Generating graph with d = " <<dimension <<" and n = " << num_points << "..." <<endl;
		}
		
		// make graph
		PolyGraph pG(dimension, num_points);
		
		if (mode > 0)
		{
			gettimeofday(&timeval2, NULL);
			
			if (timeval2.tv_sec - timeval1.tv_sec == 0)
				cout<< "Graph created in " << timeval2.tv_usec - timeval1.tv_usec <<" microseconds." <<endl;
			else
				cout<< "Graph created in "<< timeval2.tv_sec - timeval1.tv_sec << " seconds and "<< timeval2.tv_usec <<" microseconds." <<endl;		
		}
		
		if (mode == 2)
		{
			cout<<"Printing graph... "<<endl;
			pG.print();
		}
		
		if (mode > 0)
		{
			gettimeofday(&timeval1, NULL);
			cout<<"Running Kruskal's algorithm... " <<endl;
		}
		
		// run kruskal's
		vector<Edge *> tree = pG.getMST();
		float tree_weight = 0;
		for (int i = 0; i < tree.size(); i++)
			tree_weight += tree[i]->getWeight();
		
		// update average
		average_weight += tree_weight;		
		
		if (mode > 0)
		{
			gettimeofday(&timeval2, NULL);
			if (timeval2.tv_sec - timeval1.tv_sec == 0)
				cout<< "Algorithm finished in " << timeval2.tv_usec - timeval1.tv_usec <<" microseconds." <<endl;
			else
				cout<< "Algorithm finished in "<< timeval2.tv_sec - timeval1.tv_sec << " seconds and "<< timeval2.tv_usec <<" microseconds." <<endl;		
			
			cout<<"Found MST with "<< tree.size() <<" edges and total weight " <<tree_weight <<"!" <<endl;
		}
		
		if (mode == 2)
		{
			cout<<"Printing MST as an edge list... " <<endl;
			for (int i = 0; i < tree.size(); i++)
			{
				cout<<"Edge " << i <<": ";
				tree[i]->print();
			}
		}
		
		tree.clear();
	}
	
	// finish calculating average
	average_weight /= num_trials;
	cout<< average_weight << " " <<num_points << " " <<num_trials << " " <<dimension <<endl;
	
	return 0;
}

void testSetCollection()
{
	DisjointSetCollection *coll = new DisjointSetCollection();
	
	Node *a = new Node(new Point());
	Node *b = new Node(new Point());
	Node *c = new Node(new Point());
	Node *d = new Node(new Point());
	
	a->print();
	
	coll->makeSet(a);
	coll->makeSet(b);
	coll->makeSet(c);
	coll->makeSet(d);
	
	cout<< "testing find";
	cout<< "a is in set " << coll->find(a) <<endl;
	cout<< "b is in set " << coll->find(b) <<endl;
	
	coll->print();
	
	cout<< "now uniting a and b" << endl;
	coll->unite(a, b);
	
	
	coll->print();
	
	cout<< "now linking 0 and 2" << endl;	
	coll->link(0,2);
	
	coll->print();
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
