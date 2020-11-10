#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
using ulong = unsigned long;

namespace ds
{
	//the key is a property of the data
	template<class T>
	class HashTableInterface
	{
		public:
		virtual void Insert(const T& data) = 0;
		virtual void Remove(const T& data) = 0;
		virtual bool Search(const T& data) const = 0;
		virtual std::string ToString() const = 0;
	};

	template<class T>
	class AbstractHashTable: public HashTableInterface<T>
	{
		protected:
		ulong Default(const T& data)
		{
			return 0;
		}
	};

	namespace sn
	{
		template<class T>
		class HashTable: public AbstractHashTable<T>
		{
			private:
			Node<T>** heads; //array of node pointers
			ulong (*hash)(const T& data); //hash function
			ulong capacity;
		
			public:
			HashTable() : capacity(1), hash(AbstractHashTable<T>::Default)
			{
				heads = new Node<T>*[1];
				heads[0] = NULL;
			}

			HashTable(ulong capacity,ulong (*func)(const T& data)) : capacity(capacity), hash(func)
			{
				//make array of linked list
				heads = new Node<T>*[capacity];
				
				//make each linked list empty
				for(ulong i = 0;i < capacity;i += 1)
				{
					heads[i] = NULL;
				}
			}

			HashTable(const HashTable<T>& obj)
			{
				capacity = obj.capacity;
				hash = obj.hash;
				heads = new Node<T>*[capacity];

				for(ulong i = 0;i < capacity;i += 1)
				{
					heads[i] = Copy(obj.heads[i]);
				}
			}

			HashTable<T>& operator=(const HashTable<T>& rhs)
			{
				if(this != &rhs)
				{
					for(ulong i = 0;i < capacity;i += 1)
					{
						Clear(heads[i]);
					}
					delete[] heads;

					capacity = rhs.capacity;
					hash = rhs.hash;
					heads = new Node<T>*[capacity];

					for(ulong i = 0;i < capacity;i += 1)
					{
						heads[i] = Copy(rhs.heads[i]);
					}
				}
				return *this;
			}

			~HashTable() 
			{
				for(ulong i = 0;i < capacity;i += 1)
				{
					Clear(heads[i]);
					heads[i] = NULL;
				}
				delete[] heads;
			}

			bool Search(const T& data) const 
			{
				ulong idx = hash(data);
				Node<T>* t = heads[idx];

				while(t != NULL && t->data != data)
				{
					t = t->link;
				}
				return (t != NULL);
			}

			void Insert(const T& data)
			{
				ulong idx = hash(data);
				
				if(heads[idx] == NULL)
				{
					heads[idx] = Create(data);
				}
				else 
				{
					Node<T>* t = heads[idx];
					
					//determine if data is a member of the list 
					//or get to the end of the list
					while(t->link != NULL && t->data != data)
					{
						t = t->link;
					}

					if(t->link == NULL)
					{
						t->link = Create(data);
					}
				}
			}

			void Remove(const T& data)
			{
				ulong idx = hash(data);

				if(heads[idx] != NULL)
				{
					if(heads[idx]->data == data)
					{
						Node<T>* t = heads[idx];
						heads[idx] = heads[idx]->link;
						delete t;
						t = NULL;
					}
					else
					{
						Node<T> *t = heads[idx]->link, *p = heads[idx];

						while(t != NULL && t->data != data)
						{
							p = t;
							t = t->link;
						}

						if(t != NULL)
						{
							p->link = t->link;
							delete t;
							t = NULL;
						}
					}
				}
			}

			std::string ToString() const 
			{
				std::stringstream out;
				ulong content = 0;
				out << "[";

				for(ulong i = 0;i < capacity;i += 1)
				{
					Node<T>* t = heads[i];
					content += (t != NULL)?(1):(0);

					while(t != NULL)
					{
						out << t->data;

						if(t->link != NULL)
						{
							out << ",";
						}
						t = t->link;
					}

					if((content > 0) && (i + 1 != capacity) && (heads[i+1] != NULL))
					{
						out << ",";
					}
				}
				out << "]";
				return out.str();
			}

			friend std::ostream& operator<<(std::ostream& out,const HashTable<T>& obj)
			{
				out << obj.ToString();
				return out;
			}
		};
					
	}

	namespace mn
	{
		template<class T>
		class HashTable: public AbstractHashTable<T>
		{
			private:
			Node<T>** heads; //array of node pointers
			ulong (*hash)(const T& data); //hash function
			ulong capacity;
		
			public:
			HashTable() : capacity(1), hash(AbstractHashTable<T>::Default) 
			{
				heads = new Node<T>*[1];
				heads[0] = NULL;
			}

			HashTable(ulong capacity,ulong (*func)(const T& data)) : capacity(capacity), hash(func)
			{
				//make array of linked list
				heads = new Node<T>*[capacity];
				
				//make each linked list empty
				for(ulong i = 0;i < capacity;i += 1)
				{
					heads[i] = NULL;
				}
			}

			HashTable(const HashTable<T>& obj)
			{
				capacity = obj.capacity;
				hash = obj.hash;
				heads = new Node<T>*[capacity];

				for(ulong i = 0;i < capacity;i += 1)
				{
					heads[i] = Copy(obj.heads[i]);
				}
			}

			HashTable<T>& operator=(const HashTable<T>& rhs)
			{
				if(this != &rhs)
				{
					for(ulong i = 0;i < capacity;i += 1)
					{
						Clear(heads[i]);
					}
					delete[] heads;

					capacity = rhs.capacity;
					hash = rhs.hash;
					heads = new Node<T>*[capacity];

					for(ulong i = 0;i < capacity;i += 1)
					{
						heads[i] = Copy(rhs.heads[i]);
					}
				}
				return *this;
			}

			~HashTable() 
			{
				for(ulong i = 0;i < capacity;i += 1)
				{
					Clear(heads[i]);
					heads[i] = NULL;
				}
				delete[] heads;
			}

			bool Search(const T& data) const 
			{
				ulong idx = hash(data);
				Node<T>* t = heads[idx];

				while(t != NULL && t->data != data)
				{
					t = t->next;
				}
				return (t != NULL);
			}

			void Insert(const T& data)
			{
				ulong idx = hash(data);
				
				if(heads[idx] == NULL)
				{
					heads[idx] = Create(data);
				}
				else 
				{
					Node<T>* t = heads[idx];
					
					//determine if data is a member of the list 
					//or get to the end of the list
					while(t->next != NULL && t->data != data)
					{
						t = t->next;
					}

					if(t->next == NULL)
					{
						t->next = Create(data);
						t->next->prev = t;
					}
				}
			}

			void Remove(const T& data)
			{
				ulong idx = hash(data);

				if(heads[idx] != NULL)
				{
					if(heads[idx]->data == data)
					{
						Node<T>* t = heads[idx];
						heads[idx] = heads[idx]->next;
						delete t;
						t = NULL;

						if(heads[idx] != NULL)
						{
							heads[idx]->prev = NULL;
						}
					}
					else
					{
						Node<T> *t = heads[idx]->next;

						while(t != NULL && t->data != data)
						{
							t = t->next;
						}

						if(t != NULL)
						{
							t->prev->next = t->next;
							
							if(t->next != NULL)
							{
								t->next->prev = t->prev;
							}
							delete t;
							t = NULL;
						}
					}
				}
			}

			std::string ToString() const 
			{
				std::stringstream out;
				ulong content = 0;
				out << "[";

				for(ulong i = 0;i < capacity;i += 1)
				{
					Node<T>* t = heads[i];
					content += (t != NULL)?(1):(0);

					while(t != NULL)
					{
						out << t->data;

						if(t->next != NULL)
						{
							out << ",";
						}
						t = t->next;
					}

					if((content < 0) && (i + 1 != capacity) && (heads[i+1] != NULL))
					{
						out << ",";
					}
				}
				out << "]";
				return out.str();
			}

			friend std::ostream& operator<<(std::ostream& out,const HashTable<T>& obj)
			{
				out << obj.ToString();
				return out;
			}
		};
					
	}
}
		
#endif
