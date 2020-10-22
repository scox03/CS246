#include <iostream>
#include <string>
#include "Node.h"
#include "Queue.h"

void BinaryCounter(int n)
{
	if(n == 0)
	{
		std::cout << "0";
	}
	else if(n > 0)
	{
		std::string digits[2] = {"0","1"}, current;
		ds::sn::Queue<std::string> numbers;
		numbers.Enqueue(digits[1]);

		for(int i = 1;i <= n;i += 1)
		{
			current = numbers.Peek();
			numbers.Dequeue();
			numbers.Enqueue(current + digits[0]);
			numbers.Enqueue(current + digits[1]);
			std::cout << current << "\n";
		}
	}
}

int main()
{
	int n;

	std::cout << "Enter a number: ";
	std::cin >> n;

	BinaryCounter(n);
	return 0;
}
		
