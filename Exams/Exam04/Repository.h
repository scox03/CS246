#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <iostream>
#include <string>
#include "BTNode.h"
#include "Vector.h"

namespace ds
{
	/**************************************
	IsLeaf() - returns true if the binary
	node is a leaf.
	**************************************/
	template <typename T>
	bool IsLeaf(bn::BTNode<T>* x)
	{
		if(x != NULL)
		{
			return ((x->left == NULL) && (x->right == NULL));
		}
		return false;
	}

	/**************************************
	Size() - returns the size of a binary 
	tree
	**************************************/	
	template <typename T>
	int Size(bn::BTNode<T>* rt)
	{
		if(rt == NULL)
        	{
			return 0;
		}
		else 
		{
			return 1 + Size(rt->left) + Size(rt->right);
		}
	}

	/**************************************
	Ancestors() - returns an array of 
	ancestor indices of a binary tree from 
	closest to farthest.
	**************************************/
	Vector<int> Ancestors(int p)
	{
		Vector<int> a;

		while(p > 0)
		{
			p = (p - 1) / 2;
			a.Insert(p);
		}
		return a;
	}
	
	/*************************************
	Get() - returns the tree node whose 
	index equals idx.
	*************************************/
	template <typename T>
	bn::BTNode<T>* Get(bn::BTNode<T>* rt,int idx)
	{
		int size = Size(rt);

		if(idx >= size)
		{
			throw "Out of Bound";
		}
		else if(idx == 0)
		{
			return rt;
		}
		Vector<int> ancs = Ancestors(idx);
		bn::BTNode<T>* t = rt;
		int n = ancs.Length();

		for(int i = n - 2;i >= 0;i -= 1)
		{
			t = (ancs[i] % 2 == 1)?(t->left):(t->right);
		}
		return (idx % 2 == 1)?(t->left):(t->right);
	}

	/*************************************
	BTSearch() - returns the first tree
	node whose data equals value.
	*************************************/
	template <typename T>
	bn::BTNode<T>* BTSearch(bn::BTNode<T>* rt,const T& value)
	{
		if(rt == NULL)
		{
			return NULL;
		}
		else if(rt->data == value)
		{
			return rt;
		}
		else
		{
			bn::BTNode<T>* ltNode = BTSearch(rt->left,value);
			bn::BTNode<T>* rtNode = BTSearch(rt->right,value);

			if(ltNode == NULL && rtNode == NULL)
			{
                		return NULL;
			}
			else if(ltNode != NULL)
			{
				return ltNode;
			}
			else
			{
				return rtNode;
			}
		}
	}
}

#endif
