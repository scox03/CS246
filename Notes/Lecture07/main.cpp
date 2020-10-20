#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Stack.h"

int main()
{
	ds::StackInterface<int>* a[3] = {new ds::da::Stack<int>(),new ds::sn::Stack<int>(),new ds::mn::Stack<int>()};
	std::string types[3] = {"Array Stack", "Singly Linked List Stack", "Doubly Linked List Stack"};
	int v;

	srand(time(NULL));

	std::cout << "Values entered into the stacks: ";

	for(int i = 0;i < 10;i += 1)
	{
		v = rand() % 100 + 1;
		std::cout << v << " ";
		a[0]->Push(v);
		a[1]->Push(v);
		a[2]->Push(v);
	}
	std::cout << "\n\n";

	for(int i = 0;i < 3;i += 1)
	{
		std::cout << types[i] << "\nstack: ";
		
		while(!a[i]->IsEmpty())
		{
			std::cout << a[i]->Top() << " ";
			a[i]->Pop();
		}
		std::cout << "\n"; 
		
		delete a[i];
	}

	for(int i = 0;i < 3;i += 1)
	{
		delete a[i];
	}
	return 0;
}
