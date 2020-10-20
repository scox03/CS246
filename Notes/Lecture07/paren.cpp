#include <iostream>
#include <string>
#include "Stack.h"
#include "Node.h"

bool IsValidParentheses(std::string exp)
{
	int i = 0;
	ds::sn::Stack<char> s;

	while(exp[i] != '\0')
	{
		if(exp[i] == '(')
		{
			s.Push('a');
		}
		else if(exp[i] == ')')
		{
			if(s.IsEmpty())
			{
				return false;
			}
			else
			{
				s.Pop();
			}
		}
		else
		{
			return false;
		}
		i += 1;
	}
	return s.IsEmpty();
}

int main()
{
	std::string exp;
	bool r;

	std::cout << "Enter an expression: ";
	std::getline(std::cin,exp);
	
	r = IsValidParentheses(exp);

	std::cout << exp << ((r)?(" is"):(" is not")) << " a valid parentheses enclosure\n"; 
	return 0;
}
	
