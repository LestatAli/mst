#include "polygraph.h"
#include "DisjointSetCollection.h"

PolyGraph::PolyGraph(short d, int n)
{
	size = n;
	dim = d;
	
	// create a list of random vertices
	vertices = new Point *[n];
	for (int i = 0; i < size; i++)
	{
		switch(d)
		{
			case 3:
				vertices[i] = new Point3D();
				break;
			case 4:
				vertices[i] = new Point4D();
				break;
			default:
				vertices[i] = new Point();
				break;
		}
	}
	
	// create the list of edges
	// the graph is complete, so for each vertex we need to create an edge to every other vertex
	vector<Edge *> edge_list;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			Edge *e = new Edge(vertices[i], vertices[j]);
			edge_list.push_back(e);
		}
	}
	
	my_edges = new EdgeHeap(edge_list);
}

PolyGraph::PolyGraph()
{
	PolyGraph::PolyGraph(3, 1);
}

vector<Edge *> PolyGraph::getMST()
{
	vector<Edge *> spanning_tree;
	
	DisjointSetCollection *collection = new DisjointSetCollection();
	for (int i = 0; i < size; i++)
		collection->makeSet(new Node(vertices[i]));
	
	for (int j = 0; j < my_edges->getSize(); j++)
	{
		Edge *e = my_edges->extractMin();
		
		Node *u = new Node(e->getOriginVertex());
		Node *v = new Node(e->getEndVertex());
		if (collection->find(u) != collection->find(v))
		{
			spanning_tree.push_back(e);
			collection->unite(u, v);
		}
	}
	
	return spanning_tree;
}

void PolyGraph::print() const
{
	my_edges->print();
}