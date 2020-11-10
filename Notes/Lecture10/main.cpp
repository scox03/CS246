#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include "Node.h"
#include "HashTable.h"

ulong alphaIndex(const char& ch)
{
	if(tolower(ch) >= 'a' && tolower(ch) <= 'z')
	{
		return (tolower(ch) - 'a');
	}
	return 26;
}

int main()
{
	srand(time(NULL));
	ds::AbstractHashTable<char>* a[2] = {new ds::sn::HashTable<char>(27,alphaIndex),new ds::mn::HashTable<char>(27,alphaIndex)};
	std::string types[3] = {"Singly Linked List HashTable", "Doubly Linked List HashTable"};
	int v, n = rand() % 11 + 5, t = 26;
	char alpha[50] = "abcdefghijklmnopqrstuvwxyz";

	srand(time(NULL));

	std::cout << "Values entered into the hashtable:\n";
	int i;
	char c;

	for(c = 'a';c <= 'z';c += 1)
	{
		a[0]->Insert(c);
		a[1]->Insert(c);
	}
	
	for(i = 0;i < 2;i += 1)
	{
		std::cout << a[i]->ToString() << "\n";
	}
	std::cout << "\n";

	for(int i = 0;i < n;i += 1)
	{
		v = rand() % t;
		
		std::cout << "\nRemoving " << alpha[v] << "\n";
		
		for(int i = 0;i < 2;i += 1)
		{
			a[i]->Remove(alpha[v]);
			std::cout << types[i] << ":\n" << a[i]->ToString() << "\n";
		}
		alpha[v] = alpha[t-1];
		t -= 1;
	}

	for(int i = 0;i < 2;i += 1)
	{
		delete a[i];
	}
	return 0;
}
