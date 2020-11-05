#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Map.h"

int main()
{
	srand(time(NULL));
	ds::MapInterface<char,int>* a[3] = {new ds::da::Map<char,int>(30),new ds::sn::Map<char,int>(),new ds::mn::Map<char,int>()};
	std::string types[3] = {"Array Map", "Singly Linked List Map", "Doubly Linked List Map"};
	int v, n = rand() % 11 + 5, t = 26;
	char alpha[50] = "abcdefghijklmnopqrstuvwxyz";

	srand(time(NULL));

	std::cout << "Values entered into the map:\n";
	int i;
	char c;

	for(i = 1,c = 'a';i <= 26 ;i += 1,c += 1)
	{
		a[0]->Put(c,i);
		a[1]->Put(c,i);
		a[2]->Put(c,i);
	}
	
	for(i = 0;i < 3;i += 1)
	{
		std::cout << a[i]->ToString() << "\n";
	}
	std::cout << "\n";

	for(int i = 0;i < n;i += 1)
	{
		v = rand() % t;
		
		std::cout << "\nRemoving " << alpha[v] << "\n";
		
		for(int i = 0;i < 3;i += 1)
		{
			a[i]->Remove(alpha[v]);
			std::cout << types[i] << ":\n" << a[i]->ToString() << "\n";
		}
		alpha[v] = alpha[t-1];
		t -= 1;
	}

	for(int i = 0;i < 3;i += 1)
	{
		delete a[i];
	}
	return 0;
}
