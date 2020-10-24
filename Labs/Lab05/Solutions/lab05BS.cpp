#include <iostream>
#include <string>
#include "Node.h"

template<typename T>
void MidAppend(ds::sn::Node<T>*& data,ds::sn::Node<T>* addon)
{
	if(data == NULL)
	{
		data = addon;
	}
	else if(addon != NULL)
	{
		ds::sn::Node<T>* t = data;
		ds::sn::Node<T>* s = addon;
		int c = 0;

		//get the count of data
		while(t != NULL)
		{
			c += 1;
			t = t->link;
		}

		c /= 2;
		t = data;

		//get the last link of addon
		while(s->link != NULL)
		{
			s = s->link;
		}
		
		//get the middle node of data
		for(int i = 0;i < c;i += 1)
		{
			t = t->link;
		}
	
		s->link = t->link;
		t->link = s;
	}
}

bool NotEqual(ds::mn::Node<bool>* op1,ds::mn::Node<bool>* op2)
{
	ds::mn::Node<bool>* a = op1, *b = op2;

	//get the last link of op1
	while(a->next != NULL)
	{
		a = a->next;
	}

	//get the last link of op2
	while(b->next != NULL)
	{
		b = b->next;
	}
		
	//check each digit of op1 and op2 in the same 
	//position are different or the same in reverse. 
	//if they are the same check to next digit; 
	//otherwise, return true 
	while(a != NULL && b != NULL)
	{
		if(a->data != b->data)
		{
			return true;
		}
		a = a->prev;
		b = b->prev;
	}
	
	//if op1 has more digits than op2 check if
	//any equals 1. if it does return true
	while(a != NULL)
	{
		if(a->data)
		{
			return true;
		}
		a = a->prev;
	}

	//if op2 has more digits than op1 check if
	//any equals 1. if it does return true
	while(b != NULL)
	{
		if(b->data)
		{
			return true;
		}
		b = b->prev;
	}
	//op1 and op2 are equal
	return false;
}

int main()
{
	return 0;
}
