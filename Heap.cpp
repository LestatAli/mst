#include "Heap.h"
#include <cmath>

EdgeHeap::EdgeHeap()
{
	my_list.reserve(1);
}

EdgeHeap::EdgeHeap(vector<Edge *> &some_list)
{
	my_list.swap(some_list);
	buildHeap();
}

int EdgeHeap::getParent(int i)
{
	return floor((i-1)/2);
}

int EdgeHeap::getLeft(int i)
{
	return (2*i + 1);
}

int EdgeHeap::getRight(int i)
{
	return (2*i + 2);
}

int EdgeHeap::getSize() const
{
	return my_list.size();
}

bool EdgeHeap::exists(int x)
{
	return x < my_list.size();
}

void EdgeHeap::buildHeap()
{
	for (int i = floor(my_list.size()/2); i >= 0; i--)
		minHeapify(i);
}

void EdgeHeap::minHeapify(int n)
{
	int smallest = 0;
	
	int l = getLeft(n);
	int r = getRight(n);
	
	if (exists(l) && my_list[l]->getWeight() < my_list[n]->getWeight())
		smallest = l;
	else
		smallest = n;
	
	if (exists(r) && my_list[r]->getWeight() < my_list[smallest]->getWeight())
		smallest = r;
	
	if (smallest != n)
	{
		Edge *tmp = my_list[n];
		my_list[n] = my_list[smallest];
		my_list[smallest] = tmp;
		
		minHeapify(smallest);
	}
	
	else
		return;
}

Edge *EdgeHeap::extractMin()
{
	if (my_list.empty())
		return NULL;
	else
	{
		Edge *max = my_list[0];
		my_list[0] = my_list.back();
		my_list.pop_back();
		minHeapify(0);
		return max;
	}
}

void EdgeHeap::print() const
{
	int whereiam = 0;
	
	// Tree-style print
	/*for (int i = 0; i <= ceil(log(my_list.size())); i++)
	{
		for (int j = 0; j < ceil(pow((double) 2, i)); j ++)
		{
			if (whereiam < my_list.size())
			{
				Edge *e = my_list[whereiam++];
				cout<< e->getWeight() << " ";
			}
			else
				break;
		}
		
		cout<<endl;
	}*/
	 
	// Array print
	for (int i= 0; i < my_list.size(); i++)
		my_list[i]->print();
}
	
