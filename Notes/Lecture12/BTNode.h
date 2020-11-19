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
	namespace da
	{
		
		template<class T>
		class BTNode
		{
			T** data;
			ulong capacity;
			public:
			BTNode() 
			{
				capacity = 64;
				data = new T*[capacity];
				
				for(ulong i = 0;i < capacity;i += 1)
				{
					data[i] = NULL;
				}
			}

			BTNode(ulong size)
			{
				capacity = (size > 0)?(size):(64);
				data = new T*[capacity];
		
				for(ulong i = 0;i < capacity;i += 1)
				{
					data[i] = NULL;
				}
			}

			BTNode(const BTNode<T>& obj)
			{
				capacity = obj.capacity;
				data = new T*[capacity];

				for(ulong i = 0;i < capacity;i += 1)
				{
					if(obj.data[i] == NULL)
					{
						data[i] = NULL;
					}
					else 
					{
						data[i] = new T(*(obj.data[i]));
					}
				}
			}

			BTNode operator=(const BTNode<T>& rhs)
			{ 
				if(this != &rhs)
				{
					for(ulong i = 0;i < capacity;i += 1)
					{
						if(data[i] != NULL)
						{
							delete data[i];
						}
					}
					delete data;
					capacity = rhs.capacity;
					data = new T*[capacity];

					for(ulong i = 0;i < capacity;i += 1)
					{
						if(rhs.data[i] == NULL)
						{
							data[i] = NULL;
						}
						else 
						{
							data[i] = new T(*(rhs.data[i]));
						}	
					}
				}
				return *this;
			}
			
			ulong Length() const 
			{
				return capacity;
			}

			~BTNode()
			{
				for(ulong i = 0;i < capacity;i += 1)
				{
					if(data[i] != NULL)
					{
						delete data[i];
					}
				}
				delete data;
			}

			T*& operator[](ulong idx)
			{
				if(idx >= capacity)
				{
					throw "Out of Bound";
				}
				return data[idx];
			}
		
			const T*& operator[](ulong idx) const 
			{
				if(idx >= capacity)
				{
					throw "Out of Bound";
				}
				return data[idx];
			}
		};
	}

	namespace sn
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

	namespace mn
	{
		template<class T>
		struct BTNode
		{
			T data;
			BTNode<T>* p; //parent node
			BTNode<T>* left;
			BTNode<T>* right;
		};
		
		template<typename T>
		BTNode<T>* Create(const T& itm)
		{
			BTNode<T>* t = new BTNode<T>;
			t->data = itm;
			t->p = NULL;
			t->left = NULL;
			t->right = NULL;
		}

		template<typename T>
		BTNode<T>* Copy(const BTNode<T>* rt,BTNode<T>* p)
		{
			if(rt == NULL)
			{
				return NULL;
			}

			BTNode<T> *t = Create(rt->data);
			t->p = p;
			t->left = Copy(rt->left,t);
			t->right = Copy(rt->right,t);
			return t;
		}

		/*Call this version of Copy()*/
		template<typename T>
		BTNode<T>* Copy(const BTNode<T>* rt)
		{
			if(rt == NULL)
			{
				return NULL;
			}
			BTNode<T>* p = NULL;
			return Copy(rt,p);
		}

		template<typename T>
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
