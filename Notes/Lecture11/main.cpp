#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Array.h"
#include "Repository.h"

int main()
{
	int sz = 30;
	ds::Array<int> a[2] = {ds::Array<int>(sz),ds::Array<int>(sz)};
	void (*sorts[2])(ds::Array<int>&) = {ds::MergeSort<int>,ds::QuickSort<int>};
	std::string names[2] = {"MergeSort", "QuickSort"};
	srand(time(NULL));

	for(int i = 0;i < sz;i += 1)
	{
		a[0][i] = (rand() % 100) + 1;
	}

	a[1] = a[0];

	for(int i = 0;i < 2;i += 1)
	{
		std::cout << a[i] << "\n";
	}

	for(int i = 0;i < 2;i += 1)
	{
		sorts[i](a[i]);
	}

	std::cout << "\n";	
	
	for(int i = 0;i < 2;i += 1)
	{
		std::cout << names[i] << "\n";
		std::cout << a[i] << "\n";
	}
	return 0;
}
