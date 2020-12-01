#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <iostream>
#include <string>
#include "BTNode.h"

namespace ds
{
	//Print Functions

	template<typename T>
	void Infix(da::BTNode<T>& rt,ulong idx)
	{
		if(idx >= 0 && idx <= rt.Length())
		{
			if(rt[idx] != NULL)
			{
				Infix(rt,LEFT(idx));
				std::cout << *(rt[idx]) << " ";
				Infix(rt,RIGHT(idx));
			}
		}
	}

	template<typename T>
	void Infix(da::BTNode<T>& rt)
	{
		Infix(rt,0);
	}

	template<typename T>
	void Infix(sn::BTNode<T>* rt)
	{
		if(rt != NULL)
		{
			Infix(rt->left);
			std::cout << rt->data << " ";
			Infix(rt->right);
		}
	}

	template<typename T>
	void Infix(mn::BTNode<T>* rt)
	{
		if(rt != NULL)
		{
			Infix(rt->left);
			std::cout << rt->data << " ";
			Infix(rt->right);
		}
	}

	template<typename T>
	void Prefix(da::BTNode<T>& rt,ulong idx)
	{
		if(idx >= 0 && idx <= rt.Length())
		{
			if(rt[idx] != NULL)
			{
				std::cout << *(rt[idx]) << " ";
				Prefix(rt,LEFT(idx));
				Prefix(rt,RIGHT(idx));
			}
		}
	}

	template<typename T>
	void Prefix(da::BTNode<T>& rt)
	{
		Prefix(rt,0);
	}

	template<typename T>
	void Prefix(sn::BTNode<T>* rt)
	{
		if(rt != NULL)
		{
			std::cout << rt->data << " ";
			Prefix(rt->left);
			Prefix(rt->right);
		}
	}

	template<typename T>
	void Prefix(mn::BTNode<T>* rt)
	{
		if(rt != NULL)
		{
			std::cout << rt->data << " ";
			Prefix(rt->left);
			Prefix(rt->right);
		}
	}


	template<typename T>
	void Postfix(da::BTNode<T>& rt,ulong idx)
	{
		if(idx >= 0 && idx <= rt.Length())
		{
			if(rt[idx] != NULL)
			{
				Postfix(rt,LEFT(idx));
				Postfix(rt,RIGHT(idx));
				std::cout << *(rt[idx]) << " ";
			}
		}
	}

	template<typename T>
	void Postfix(da::BTNode<T>& rt)
	{
		Postfix(rt,0);
	}

	template<typename T>
	void Postfix(sn::BTNode<T>* rt)
	{
		if(rt != NULL)
		{
			Postfix(rt->left);
			Postfix(rt->right);
			std::cout << rt->data << " ";
		}
	}

	template<typename T>
	void Postfix(mn::BTNode<T>* rt)
	{
		if(rt != NULL)
		{
			Postfix(rt->left);
			Postfix(rt->right);
			std::cout << rt->data << " ";
		}
	}
}

#endif
