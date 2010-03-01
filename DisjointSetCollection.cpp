#include "DisjointSetCollection.h"

DisjointSetCollection::DisjointSetCollection()
{
	my_sets.reserve(1);
}

void DisjointSetCollection::makeSet(Node *some_root)
{
	DisjointSet *new_set = new DisjointSet(some_root);
	my_sets.push_back(new_set);
}

int DisjointSetCollection::find(Node *target_node)
{
	// naive find
	for (int i = 0; i < my_sets.size(); i++)
	{
		if (my_sets[i]->isMember(target_node))
			return i;
	}
	
	// not found
	return -1;
}

void DisjointSetCollection::link(int set_x_addr, int set_y_addr)
{
	// get the disjoint sets at the provided addresses
	DisjointSet *set_x = my_sets[set_x_addr];
	DisjointSet *set_y = my_sets[set_y_addr];
	
	// hook up the set x to the root of set y
	set_x->getRoot()->setParent(set_y->getRoot());
	set_y->getRoot()->addChild(set_x->getRoot());
	
	// we no longer need the disjoint set x
	my_sets.erase(my_sets.begin() + set_x_addr);
}

void DisjointSetCollection::unite(Node *node_x, Node *node_y)
{
	link(find(node_x), find(node_y));
}

void DisjointSetCollection::print() const
{
	for (int i = 0; i < my_sets.size(); i++)
	{
		cout<< "Set " << i <<": ";
		my_sets[i]->print();
	}
}