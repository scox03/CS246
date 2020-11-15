#include <iostream>
#include <cctype>
#include "Node.h"
#include "Stack.h"

bool IsValidWord(std::string word)
{
	ds::sn::Stack<char> s;
	int i = 0;

	while(word[i] != '\0')
	{
		if(tolower(word[i]) == 'a')
		{
			if(s.IsEmpty() || s.Top() == 'x')
			{	
				//first a
				s.Push('a');
			}
			else if(s.Top() == 'a')
			{
				//second a
				s.Push('A');
			}	
		}
		else if(tolower(word[i]) == 'b')
		{	
			if(!s.IsEmpty())
			{
				if(s.Top() == 'A')
				{
					s.Push('b');
					break;
				}
				else
				{
					//restart cycle
					s.Push('x');
				}
			}
		}
		else 
		{
			return false;
		}
		i += 1;
	}
	//check remaining characters
	while(word[i] != '\0')
	{
		if(tolower(word[i]) != 'a' && tolower(word[i]) != 'b')
		{
			return false;
		}
		i += 1;
	}
	return (!s.IsEmpty() && s.Top() == 'b');
}		


int main()
{
	std::string word[5] = {"aAabbB","aBAb","ababab","aabbaabba","aabsaab"};

	std::cout << std::boolalpha;
	
	for(int i = 0;i < 5;i += 1)
	{
		std::cout << "IsValidWord(\"" << word[i] << "\") = " << IsValidWord(word[i]) << "\n";
	}
	
	return 0;
}
