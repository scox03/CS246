#include <iostream>
#include <string>
#include "BTNode.h"
#include "Repository.h"

int main()
{
	ds::da::BTNode<int>* a[2];
	ds::sn::BTNode<int>* b[2];
	ds::mn::BTNode<int>* c[2];

	a[0] = new ds::da::BTNode<int>(16);
	(*a[0])[0] = new int(1);
	b[0] = ds::sn::Create(1);
	c[0] = ds::mn::Create(1);

	(*a[0])[LEFT(0)] = new int(3);
	(*a[0])[RIGHT(0)] = new int(2);

	b[0]->left = ds::sn::Create(3);
	b[0]->right = ds::sn::Create(2);

	c[0]->left = ds::mn::Create(3);
	c[0]->right = ds::mn::Create(2);

	a[1] = new ds::da::BTNode<int>(*a[0]);
	b[1] = ds::sn::Copy(b[0]);
	c[1] = ds::mn::Copy(c[0]);

	for(int i = 0;i < 2;i += 1)
	{
		std::cout << "Infix:\n";
		ds::Infix(*a[i]);
		std::cout << "\n";
		ds::Infix(b[i]);
		std::cout << "\n";
		ds::Infix(c[i]);
		std::cout << "\n\n";
		
		std::cout << "Prefix:\n";
		ds::Prefix(*a[i]);
		std::cout << "\n";
		ds::Prefix(b[i]);
		std::cout << "\n";
		ds::Prefix(c[i]);
		std::cout << "\n\n";
	
		std::cout << "Postfix:\n";
		ds::Postfix(*a[i]);
		std::cout << "\n";
		ds::Postfix(b[i]);
		std::cout << "\n";
		ds::Postfix(c[i]);
		std::cout << "\n\n";
	}

	for(int i = 0;i < 2;i += 1)
	{
		delete a[i];
		ds::sn::Clear(b[i]);
		ds::mn::Clear(c[i]);
	}

	return 0;
}
