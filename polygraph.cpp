#include "PolyGraph.h"
#include "DisjointSetCollection.h"

PolyGraph::PolyGraph(short d, int n)
{
	size = n;
	dim = d;
	
	// create a list of random vertices
	//my_ = new Point *[n];
	my_nodes.reserve(n);
	for (int i = 0; i < size; i++)
	{
		switch(d)
		{
			case 3:
				my_nodes.push_back(new Node(new Point3D()));
				break;
			case 4:
				my_nodes.push_back(new Node(new Point4D()));
				break;
			default:
				my_nodes.push_back(new Node(new Point()));
				break;
		}
	}
	cout<< "Created vertices!" <<endl;
	
	// create the list of edges
	// the graph is complete, so for each vertex we need to create an edge to every other vertex
	vector<Edge *> edge_list;
	
	float max_weight = 0;
	if (dim == 0)
		max_weight = 0.00579123;
	else
		max_weight = 0.058637;
	
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			Edge *e;
			if (d > 0)
				e = new Edge(my_nodes[i], my_nodes[j]);
			else
				e = new Edge(my_nodes[i], my_nodes[j], myrand());
			
			if (e->getWeight() > max_weight)
				delete e;
			else
				edge_list.push_back(e);
		}
	}
	cout<< "Created edges!" <<endl;
		
	my_edges = new EdgeHeap(edge_list);
	cout<< "Created edge heap!" <<endl;
}

PolyGraph::PolyGraph()
{
	PolyGraph::PolyGraph(3, 1);
}

vector<Edge *> PolyGraph::getMST()
{
	vector<Edge *> spanning_tree;
	int tree_size = 0;
	
	DisjointSetCollection *collection = new DisjointSetCollection();
	for (int i = 0; i < size; i++)
		collection->makeSet(my_nodes[i]);
	
	for (int j = 0; j < my_edges->getSize(); j++)
	{
		Edge *e = my_edges->extractMin();
		
		Node *u = e->getOriginNode();
		Node *v = e->getEndNode();
		//cout<<"Finding..." <<endl;
		if (collection->find(u) != collection->find(v))
		{
			//cout<<"Inserting edge "<<tree_size <<" < " <<size <<"..." <<endl;
			spanning_tree.push_back(e);
			if (tree_size ==  size - 2)
				break;
			else
			{
				//cout<<"Union begin..." <<endl;
				collection->unite(u, v);
				//cout<<"Union end..." <<endl;
				tree_size++;
			}
		}
		//delete u;
		//delete v;
	}
	
	delete collection;
	return spanning_tree;
}

void PolyGraph::print() const
{
	my_edges->print();
}