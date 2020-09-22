#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Repository.h"

int main()
{
	ds::array<int> a;
	ds::Initialize(a,100);
	srand(time(NULL));

	for(int i = 0;i < a.data.Length() / 2;i += 1)
	{
		Insert(a,rand() % 100 + 1);
	}

	std::cout << a.data << "\n";

	return 0;
}
