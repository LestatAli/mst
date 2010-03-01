#include "DisjointSet.h"

DisjointSet::DisjointSet()
{
	my_root = NULL;
}

DisjointSet::DisjointSet(Node * new_root)
{
	my_root = new_root;
}

Node *DisjointSet::getRoot() const
{
	return my_root;
}

/*string DisjointSet::getName() const
{
	char * my_name;
	sprintf(my_name, "%d", my_root->getVertex());
	string str_my_name(my_name);
	return str_my_name;
}*/

bool DisjointSet::isMember(Node *target_node)
{
	// prepare stack for a DFS
	vector<Node *> dfs_stack;
	dfs_stack.push_back(my_root);
	while (!dfs_stack.empty())
	{
		Node *current_node = dfs_stack.back();
		dfs_stack.pop_back();
		
		if (current_node == target_node)
			return true;
		
		// stack in the children
		vector<Node *> children = current_node->getChildren();
		for (int i = 0; i < children.size(); i++)
			dfs_stack.push_back(children[i]);
	}
	return false;
}


void DisjointSet::print() const
{
	printHelper(my_root);
}

void DisjointSet::printHelper(Node *start) const
{
	Node *current_node = start;
	if (current_node == NULL)
		return;
	
	else
	{
		current_node->print();
		vector<Node *> children = current_node->getChildren();
		for (int i = 0; i < children.size(); i++)
			printHelper(children[i]);
	}
}

