#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Queue.h"

int main()
{
	ds::QueueInterface<int>* a[3] = {new ds::da::Queue<int>(),new ds::sn::Queue<int>(),new ds::mn::Queue<int>()};
	std::string types[3] = {"Array Queue", "Singly Linked List Queue", "Doubly Linked List Queue"};
	int v;

	srand(time(NULL));

	std::cout << "Values entered into the queue: ";

	for(int i = 0;i < 10;i += 1)
	{
		v = rand() % 100 + 1;
		std::cout << v << " ";
		a[0]->Enqueue(v);
		a[1]->Enqueue(v);
		a[2]->Enqueue(v);
	}
	std::cout << "\n\n";

	for(int i = 0;i < 3;i += 1)
	{
		std::cout << types[i] << "\nqueue: ";
		
		while(!a[i]->IsEmpty())
		{
			std::cout << a[i]->Peek() << " ";
			a[i]->Dequeue();
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
