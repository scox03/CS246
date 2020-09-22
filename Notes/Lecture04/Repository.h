#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <iostream>
#include <string>
#include "Array.h"

namespace ds
{
	template<class T>
	struct array
	{
		Array<T> data;
		int size;
	};

	template<typename T>
	void Initialize(array<T>& obj,int cp)
	{
		obj.data.Resize(cp);
		obj.size = 0;
	}

	template<typename T>
	void Initialize(array<T>& obj)
	{
		obj.size = 0;
	}

	//Insert at any index
	template<typename T>
	void Insert(array<T>& obj,int idx,const T& item)
	{
		if(obj.size < obj.data.Length())
		{
			if(idx >= 0 && idx <= obj.size)
			{
				for(int i = obj.size;i > idx;i -= 1)
				{
					obj.data[i] = obj.data[i-1];
				}
				obj.data[idx] = item;
				obj.size += 1;
			}
		}
	}

	//Insert at the end
	template<typename T>
	void Insert(array<T>& obj,const T& item)
	{
		if(obj.size < obj.data.Length())
		{
			obj.data[obj.size] = item;
			obj.size += 1;
		}
	}

	//Insert at the beginning		
	template<typename T>
	void InsertAtBeginning(array<T>& obj,const T& item)
	{
		if(obj.size < obj.data.Length())
		{
			for(int i = obj.size;i > 0;i -= 1)
			{
				obj.data[i] = obj.data[i-1];
			}
			obj.data[0] = item;
			obj.size += 1;
		}
	}

	//Remove at any index
	template<typename T>
	void Remove(array<T>& obj,int idx)
	{
		if(obj.size > 0)
		{
			if(idx >= 0 && idx < obj.size)
			{
				obj.size -= 1;

				for(int i = idx;i < obj.size;i += 1)
				{
					obj.data[i] = obj.data[i+1];
				}
			}
		}
	}

	//Remove from the end
	template<typename T>
	void Remove(array<T>& obj)
	{	
		if(obj.size > 0)
		{
			obj.size -= 1;
		}
	}

	//Remove from the beginning
	template<typename T>
	void RemoveFromBeginning(array<T>& obj)
	{
		if(obj.size > 0)
		{
			obj.size -= 1;

			for(int i = 0;i < obj.size;i += 1)
			{
				obj.data[i] = obj.data[i+1];
			}
		}
	}

	//Find the index of an item starting at an specific index
	template<typename T>
	int Search(array<T>& obj,int idx,const T& item)
	{
		for(int i = idx;i >= 0 && i < obj.size;i += 1)
		{
			if(obj.data[i] == item)
			{
				return i;
			}
		}
		return -1;
	}

	//Find the index of an item
	template<typename T>
	int Search(array<T>& obj,const T& item)
	{
		for(int i = 0;i < obj.size;i += 1)
		{
			if(obj.data[i] == item)
			{
				return i;
			}
		}
		return -1;
	}

	//Find the index of an item starting at size to an specific index in reverse
	template<typename T>
	int ReversrSearch(array<T>& obj,int idx,const T& item)
	{
		for(int i = obj.size-1;i >= 0 && i >= idx;i -= 1)
		{
			if(obj.data[i] == item)
			{
				return i;
			}
		}
		return -1;
	}

	//Find the index of an item in reverse
	template<typename T>
	int ReverseSearch(array<T>& obj,const T& item)
	{
		for(int i = obj.size-1;i >= 0;i -= 1)
		{
			if(obj.data[i] == item)
			{
				return i;
			}
		}
		return -1;
	}

	//Determine if an item is present
	template<typename T>
	bool Contains(array<T>& obj,const T& item)
	{
		for(int i = 0;i < obj.size;i += 1)
		{
			if(obj.data[i] == item)
			{
				return true;
			}
		}
		return false;
	}
	
	//Count of items
	template<typename T>
	int Count(array<T>& obj,const T& item)
	{
		int cnt = 0;
		
		for(int i = 0;i < obj.size;i += 1)
		{
			if(obj.data[i] == item)
			{
				cnt += 1;
			}
		}
		return cnt;
	}

	//Resize an array to x2 its size
	template<typename T>
	void Reset(array<T>& obj)
	{
		int sz = obj.data.Length();
		T* tmp = new T[sz];
		
		for(int i = 0;i < sz;i += 1)
		{
			tmp[i] = obj.data[i];
		}
		
		obj.data.Reset(sz * 2);
		
		for(int i = 0;i < sz;i += 1)
		{
			obj.data[i] = tmp[i];
		}
		delete[] tmp;
	}

	//Determines if the array is empty
	template<typename T>
	bool IsEmpty(array<T>& obj)
	{
		return (obj.size == 0);
	}

	//Determines if the array is full
	template<typename T>
	bool IsFull(array<T>& obj)
	{
		return (obj.size == obj.data.Length());
	}
}

#endif 
