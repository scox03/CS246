#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "List.h"

int main()
{
	ds::sn::List<int> a;
	ds::mn::List<int> b;
	int v;

	srand(time(NULL));

	for(int i = 0;i < 10;i += 1)
	{
		v = rand() % 100 + 1;
		a.Insert(v);
		b.Insert(v);
	}

	std::cout << a << "\n";
	std::cout << b << "\n";

	return 0;
}
