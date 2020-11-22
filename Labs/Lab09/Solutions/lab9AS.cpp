#include <iostream>
#include <string>
#include <sstream>
#include "Node.h"
#include "Map.h"
#include "Vector.h"
using ulong = unsigned long;

template<typename T>
bool HasCycle(ds::sn::Node<T>* root)
{
	for(ds::sn::Node<T>* t = root;t != NULL;t = t->link)
	{
		ds::sn::Node<T>* s = root;
		
		while(true)
		{
			if(s == t->link)
			{
				return true;
			}
			else if(s == t)
			{
				break;
			}
			s = s->link;
		}
	}
	return false;
}
			
int main()
{
	ds::sn::Node<int> *a = ds::sn::Create(1), *b = ds::sn::Create(2), *c = ds::sn::Create(3), *d = ds::sn::Create(4);

	a->link = b;
	b->link = c;
	c->link = d;
	//no cycle
	std::cout << std::boolalpha;
	std::cout << HasCycle(a) << "\n";

	c->link = b;
	//cycle
	std::cout << HasCycle(a) << "\n";
	//null-terminated
	c->link = d;
	ds::sn::Clear(a);
	return 0;
}
