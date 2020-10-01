#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Vector.h"

int main()
{
	ds::Vector<int> a;
	srand(time(NULL));

	for(int i = 0;i < 10;i += 1)
	{
		a.Insert(rand() % 100 + 1);
	}

	std::cout << a << "\n";

	return 0;
}
