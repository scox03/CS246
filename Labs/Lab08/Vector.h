#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>
#include <sstream>
using ulong = unsigned long; //type alias

namespace ds
{	
	template<class T>
	class Vector
	{
		private:
		T* data;
		ulong size;
		ulong capacity;

		void Resize(ulong ncp)
		{
			if(ncp != 0)
			{
				ulong tcp = (ncp <= capacity)?(ncp):(capacity);
				T* tmp = new T[tcp];

				for(ulong i = 0;i < tcp;i += 1)
				{
					tmp[i] = data[i];
				}
				delete[] data;
				data = new T[ncp];

				for(ulong i = 0;i < tcp;i += 1)
				{
					data[i] = tmp[i];
				}
				delete[] tmp;

				if(size > ncp)
				{
					size = ncp - 1;
				}
			}
			else
			{
				throw "Allocation Error";
			}
		}

		public:
		Vector() : capacity(20), size(0) 
		{
			data = new T[capacity];
		}
		
		Vector(ulong csize)
		{	
			size = csize;
			capacity = size * 2; 
			data = new T[capacity];
			
			for(ulong i = 0;i < size;i += 1)
			{
				data[i] = T();
			}
		}

		Vector(const Vector<T>& obj)
		{
			capacity = obj.capacity;
			size = obj.size;
			data = new T[capacity];

			for(ulong i = 0;i < size;i += 1)
			{
				data[i] = obj.data[i];
			}
		}

		Vector<T>& operator=(const Vector<T>& rhs)
		{
			if(this != &rhs)
			{
				capacity = rhs.capacity;
				size = rhs.size;
				delete[] data;
				data = new T[capacity];

				for(ulong i = 0;i < size;i += 1)
				{
					data[i] = rhs.data[i];
				}
			}
			return *this;
		}

		~Vector() 
		{
			delete[] data;
		}

		ulong Length() const
		{
			return size;
		}

		bool IsEmpty() const 
		{
			return (size == 0);
		}

		void Insert(ulong idx,const T& item)
		{	
			if(size == capacity)
			{
				Resize(size + 50);
			} 
					
			if(idx >= 0 && idx <= size)
			{
				for(ulong i = size;i > idx;i -= 1)
				{
					data[i] = data[i-1];
				}
				data[idx] = item;
				size += 1;
			}
		}

		//Insert at the end of the array
		void Insert(const T& item)
		{
			if(size == capacity)
			{
				Resize(size + 50);
			}
			data[size] = item;
			size += 1;
		}		

		void Remove(ulong idx)
		{
			if(size > 0)
			{
				if(idx >= 0 && idx < size)
				{
					size -= 1;
					
					for(ulong i = idx;i < size;i += 1)
					{
						data[i] = data[i+1];
					}
				}
			}
		}

		//Remove from the end of the array
		void Remove() 
		{
			if(size > 0)
			{
				size -= 1;
			}
		}

		ulong Search(ulong idx,const T& item) const
		{
			ulong i = idx;
			while(i < size)
			{
				if(data[i] == item)
				{
					break;
				}
				i += 1;
			}
			return i;
		}	
		
		ulong Search(const T& item) const
		{
			ulong i = 0;
			while(i < size)
			{
				if(data[i] == item)
				{
					break;
				}
				i += 1;
			}
			return i;
		}
		
		bool Contains(const T& item) const
		{
			for(ulong i = 0;i < size;i += 1)
			{
				if(data[i] == item)
				{
					return true;
				}
			}
			return false;
		}

		T& operator[](int idx) 
		{
			if(idx < 0 || idx >= size)
			{
				throw "Out of Bound";
			}
			return data[idx];
		}

	
		const T& operator[](int idx) const 
		{
			if(idx < 0 || idx >= size)
			{
				throw "Out of Bound";
			}
			return data[idx];
		}
		
		std::string ToString() const 
		{
			std::stringstream out;

			out << "[";
		
			for(ulong i = 0;i < size;i += 1)
			{
				out << data[i];
				
				if(i + 1 < size)
				{
					out << ",";
				}
			}
			out << "]";
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Vector<T>& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}

#endif
