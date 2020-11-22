#include <iostream>
#include "lab9BS.h"

int main()
{
	ds::MyCalendar a, b(2020);

	std::cout << std::boolalpha;
	std::cout << a.Book(0,20) << "\n";
	std::cout << a.Book(10,40) << "\n";
	std::cout << a.Book(5,15) << "\n";
	std::cout << b.Book(0,365) << "\n";

	return 0;
} 
