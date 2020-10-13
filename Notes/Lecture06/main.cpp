#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Node.h"

int main()
{
	ds::sn::Node<int>* a = NULL;
	ds::mn::Node<int>* b = NULL;
	int v;

	srand(time(NULL));

	for(int i = 0;i < 10;i += 1)
	{
		v = rand() % 100 + 1;
		ds::sn::Insert(a,a,v);
		ds::mn::Insert(b,b,v);
	}

	for(ds::sn::Node<int>* p = a;p != NULL;p = p->link)
	{
		std::cout << p->data;

		if(p->link != NULL)
		{
			std::cout << ",";
		}
	}
	std::cout << "\n";

	for(ds::mn::Node<int>* q = b;q != NULL;q = q->next)
	{
		std::cout << q->data;

		if(q->next != NULL)
		{
			std::cout << ",";
		}
	}
	std::cout << "\n";

	ds::sn::Clear(a);
	ds::mn::Clear(b);

	return 0;
}
