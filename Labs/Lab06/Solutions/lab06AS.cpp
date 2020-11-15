#include <iostream>
#include "Node.h"

template<typename T>
void ForwardRotation(ds::mn::Node<T>*& root) 
{
	//check if the linked list has at 
	//least two nodes. If not root == NULL (0)
	//and root->next == NULL (1) 
	if(root != NULL && root->next != NULL)
	{
		ds::mn::Node<T>* t = root;
		
		//get the last node of the list
		while(t->next != NULL)
		{
			t = t->next;
		}
		
		//make the list circular
		t->next = root;
		root->prev = t;

		//move root to the end
		root = t;

		//make the list null terminated
		root->prev->next = NULL;
		root->prev = NULL;
	}
}

template<typename T>
void Print(ds::mn::Node<T>* r)
{
	ds::mn::Node<T>* t = r;

	while(t != NULL)
	{
		std::cout << t->data << " ";
		t = t->next;
	}
	std::cout << "\n";
}


int main()
{
	char letters[27] = "abcd";
	ds::mn::Node<char>* t = NULL;
	
	for(int i = 0;letters[i] != '\0';i += 1)
	{
		std::cout << "Before: ";
		Print(t);
		std::cout << "\n";
		ForwardRotation(t);
		std::cout << "After: ";
		Print(t);
		std::cout << "\n\n";

		ds::mn::Insert(t,t,letters[i]);
	}
	
	return 0;
}
