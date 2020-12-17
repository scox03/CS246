#ifndef BTNODE_H
#define BTNODE_H

#include <iostream>
#include <string>
#include <sstream>
using ulong = unsigned long;

//Binary Tree Macros
#define PARENT(x) 	(((x) - 1) / 2) //parent index
#define LEFT(x)		((x) * 2 + 1) //left child index
#define RIGHT(x) 	((x) * 2 + 2) //right child index
	
namespace ds
{
	namespace bn
	{
		template <class T>
		struct BTNode
		{
			T data;
			BTNode<T>* left;
			BTNode<T>* right;
		};

		template<typename T>
		BTNode<T>* Create(const T& itm)
		{
			BTNode<T> *t = new BTNode<T>;
			t->data = itm;
			t->left = NULL;
			t->right = NULL;
			return t;
		}

		template <typename T>
		BTNode<T>* Copy(const BTNode<T>* rt)
		{
			if(rt == NULL)
			{
				return NULL;
			}

			BTNode<T> *t = Create(rt->data);
			t->left = Copy(rt->left);
			t->right = Copy(rt->right);
			return t;
		}

		template <typename T>
		void Clear(BTNode<T>*& rt)
		{
			if(rt != NULL)
			{
				Clear(rt->left);
				Clear(rt->right);
				delete rt;
				rt = NULL;
			}
		}
	}
}
		
#endif
