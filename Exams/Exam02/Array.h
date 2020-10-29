#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <sstream>

namespace ds
{
	template<class T>
	class Array
	{
		private:
		T* data;
		int capacity;

		public:
		Array() : capacity(20) 
		{
			data = new T[capacity];

			for(int i = 0;i < capacity;i += 1)
			{
				data[i] = T();
			}
		}
		
		Array(const int capacity)
		{
			if(capacity < 0)
			{
				throw "Invalid Capacity";
			}

			this->capacity = capacity;
			data = new T[this->capacity];
			
			for(int i = 0;i < this->capacity;i += 1)
			{
				data[i] = T();
			}
		}

		Array(const Array<T>& obj)
		{
			capacity = obj.capacity;
			data = new T[capacity];

			for(int i = 0;i < capacity;i += 1)
			{
				data[i] = obj.data[i];
			}
		}

		Array<T>& operator=(const Array<T>& rhs)
		{
			if(this != &rhs)
			{
				capacity = rhs.capacity;
				delete[] data;
				data = new T[capacity];

				for(int i = 0;i < capacity;i += 1)
				{
					data[i] = rhs.data[i];
				}
			}
			return *this;
		}

		~Array() 
		{
			delete[] data;
		}

		int Length() const
		{
			return capacity;
		}

		T& operator[](int idx) 
		{
			if(idx < 0 || idx >= capacity)
			{
				throw "Out of Bound";
			}
			return data[idx];
		}

	
		const T& operator[](int idx) const 
		{
			if(idx < 0 || idx >= capacity)
			{
				throw "Out of Bound";
			}
			return data[idx];
		}
		
		bool Resize(int nc)
		{
			if(nc <= 0)
			{
				return false;
			}

			delete[] data;
			data = new T[nc];
			capacity = nc;

			for(int i = 0;i < capacity;i += 1)
			{
				data[i] = T();
			}
			return true;
		}

		std::string ToString() const 
		{
			std::stringstream out;

			out << "[";
		
			for(int i = 0;i < capacity;i += 1)
			{
				out << data[i];
				
				if(i + 1 < capacity)
				{
					out << ",";
				}
			}
			out << "]";
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Array<T>& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}

#endif
