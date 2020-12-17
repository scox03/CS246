#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <sstream>

namespace ds
{
	namespace sn
	{
		template<class T>
		struct Node
		{
			T data;
			struct Node<T>* link;
		};

		template<typename T>
		Node<T>* Create(const T& itm)
		{
			Node<T> *t = new Node<T>;
			t->data = itm;
			t->link = NULL;
			return t;
		}

		template<typename T>
		Node<T>* Copy(Node<T>* rt)
		{
			if(rt == NULL)
			{
				return NULL;
			}
			Node<T>* hd = Create(rt->data);
			Node<T>* ta = rt;
			Node<T>* tb = hd;

			while(ta->link != NULL)
			{
				tb->link = Create(ta->link->data);
				ta = ta->link;
				tb = tb->link;
			}
			return hd;
		}

		template<typename T>
		void Clear(Node<T>*& rt)
		{
			Node<T>* t;
			
			while(rt != NULL)
			{
				t = rt;
				rt = rt->link;
				delete t;
				t = NULL;
			}
		}
	}

	namespace mn
	{
		template<class T>
		struct Node
		{
			T data;
			struct Node<T>* prev;
			struct Node<T>* next;
		};

		template<typename T>
		Node<T>* Create(const T& itm)
		{
			Node<T> *t = new Node<T>;
			t->data = itm;
			t->prev = NULL;
			t->next = NULL;
			return t;
		}

		template<typename T>
		Node<T>* Copy(Node<T>* rt)
		{
			if(rt == NULL)
			{
				return NULL;
			}
			Node<T>* hd = Create(rt->data);
			Node<T>* ta = rt;
			Node<T>* tb = hd;

			while(ta->next != NULL)
			{
				tb->next = Create(ta->next->data);
				tb->next->prev = tb;
				ta = ta->next;
				tb = tb->next;
			}
			return hd;
		}

		template<typename T>
		void Clear(Node<T>*& rt)
		{
			Node<T>* t;
			
			while(rt != NULL)
			{
				t = rt;
				rt = rt->next;
				delete t;
				t = NULL;
			}
		}
	}

}

#endif
