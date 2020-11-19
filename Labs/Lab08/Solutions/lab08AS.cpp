#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Vector.h"
using ulong = unsigned long;

ulong GCD(ulong m,ulong n)
{
	ulong r;

	while(n != 0)
	{
		r = m % n;
		m = n;
		n = r;
	}
	return ((m == 0)?(1):(m));
}

ulong GCD(ds::Vector<ulong>& data)
{
	if(data.Length() == 0)
	{
		return 0;
	}

	ulong r = data[0];
	ulong n = data.Length();

	for(ulong i = 1;i < n;i += 1)
	{
		r = GCD(r,data[i]);
	}
	return r;
}
	
int main()
{
	ds::Vector<ulong> a(10), b(10);
	srand(time(NULL));

	for(int i = 0;i < 10;i += 1)
	{
		a[i] = rand() % 11 + 2;
		b[i] = 5 * (rand() % 20) + 5 * (rand() % 2);
	}

	std::cout << a << "\n";
	std::cout << "gcd = " << GCD(a) << "\n";

	std::cout << "\n" << b << "\n";
	std::cout << "gcd = " << GCD(b) << "\n";

	return 0;
}
