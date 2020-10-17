#include <iostream>
#include <string>
#include "Node.h"

double Maximum(ds::sn::Node<double>* root)
{
	if(root == NULL)
	{
		return 0;
	}

	double mx = root->data;

	for(ds::sn::Node<double>* t = root->link;t != NULL;t = t->link)
	{
		if(t->data > mx)
		{
			mx = t->data;
		}
	}
	return mx;
}

int main()
{
	return 0;
}
