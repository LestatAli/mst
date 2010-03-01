#include "simplegraph.h"

SimpleGraph::SimpleGraph()
{
	size = 4;
	edge_weights = new float*[4];
	for (int i = 0; i < 4; i++)
		edge_weights[i] = new float[4];
}

SimpleGraph::SimpleGraph(int n)
{
	size = n;
	edge_weights = new float*[n];
	for (int i = 0; i < n; i++)
	{
		edge_weights[i] = new float[n];
		for (int j = 0; j < n; j++)
			edge_weights[i][j] = myrand();
	}
}

void SimpleGraph::print() const
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout<< edge_weights[i][j] << " ";
		cout<< endl;
	}
	
}