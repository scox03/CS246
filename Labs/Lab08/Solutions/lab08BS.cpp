#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include "Node.h"
#include "Vector.h"
#include "Map.h"
using ulong = unsigned long;

void Frequency(std::ifstream& in)
{
	if(!in.is_open())
	{
		return;
	}

	ds::sn::Map<char,int> letters;
	char lt;

	for(int i = 0;i < 26;i += 1)
	{
		letters.Put((char)('a' + i),0);
	}

	while(in >> lt)
	{
		if(isalpha(lt))
		{
			letters[tolower(lt)] += 1;
		}
	}

	for(char i = 'a';i <= 'z';i += 1)
	{
		std::cout << i << " = " << letters[i] << "\n";
	}
	
}
 
int main()
{
	std::string path;

	std::cout << "Enter file: ";
	std::cin >> path;

	std::ifstream in(path.data());

	Frequency(in);

	in.close();
	return 0;
}
