#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <sstream>
#include <string>
#include "Node.h"
using ulong = unsigned long;

namespace ds
{
	//Pair Structure
	template<class K,class V>
	struct Pair
	{
		K key;
		V value;
	};

	//Map Interface
	template <class K,class V>
	class MapInterface
	{
		public:
		virtual void Put(const K&,const V&) = 0;
		virtual void Remove(const K&) = 0;
		virtual ulong Length() const = 0;
		virtual bool IsEmpty() const = 0;
		virtual bool Contains(const K&) const = 0;
		virtual V& Get(const K&) = 0;
		virtual const V& Get(const K&) const = 0;
		virtual V& operator[](const K&) = 0;
		virtual const V& operator[](const K&) const = 0;
		virtual std::string ToString() const = 0;
	};

	namespace da 
	{
		template <class K,class V>
		class Map : public MapInterface<K,V>
		{
			private:
			Pair<K,V>* data;
			ulong size;
			ulong capacity;

			public:
			Map() : size(0), capacity(20)
			{
				data = new Pair<K,V>[capacity];
			}

			Map(ulong capacity) : size(0), capacity(capacity)
			{
				data = new Pair<K,V>[this->capacity];
			}

			Map(const Map<K,V>& obj)
			{
				size = obj.size;
				capacity = obj.capacity;
				data = new Pair<K,V>[capacity];

				for(ulong i = 0;i < size;i += 1)
				{
					data[i] = obj.data[i];
				}
			}

			Map<K,V>& operator=(const Map<K,V>& rhs)
			{
				if(this != &rhs)
				{
					size = rhs.size;
					capacity = rhs.capacity;
					delete[] data;
					data = new Pair<K,V>[capacity];

					for(ulong i = 0;i < size;i += 1)
					{
						data[i] = rhs.data[i];
					}
				}
				return *this;
			}

			~Map() 
			{
				delete[] data;
			}

			void Put(const K& key,const V& value)
			{
				if(size < capacity)
				{
					ulong idx = 0;
				
					while(idx < size && data[idx].key != key)
					{
						idx += 1;
					}

					if(idx == size)
					{
						data[size].key = key;
						data[size].value = value;
						size += 1;
					}
				}
			}

			void Remove(const K& key)
			{
				if(size > 0)
				{
					ulong idx = 0;
					
					while(idx < size && data[idx].key != key)
					{
						idx += 1;
					}

					if(idx != size)
					{
						size -= 1;

						for(ulong i = idx;i < size;i += 1)
						{
							data[i] = data[i+1];
						}
					}
				}
			}

			ulong Length() const
			{
				return size;
			}

			bool IsEmpty() const 
			{
				return (size == 0);
			}

			bool IsFull() const 
			{
				return (size == capacity);
			}

			bool Contains(const K& key) const
			{
				ulong idx = 0;

				while(idx < size && data[idx].key != key)
				{
					idx += 1;
				}
				return (idx != size);
			}

			V& Get(const K& key)
			{
				ulong idx = 0;

				while(idx < size && data[idx].key != key)
				{
					idx += 1;
				}

				if(idx != size)
				{
					return data[idx].value;
				}
				throw "Invalid Key";
			}

			const V& Get(const K& key) const
			{
				ulong idx = 0;

				while(idx < size && data[idx].key != key)
				{
					idx += 1;
				}

				if(idx != size)
				{
					return data[idx].value;
				}
				throw "Invalid Key";
			}
			
			V& operator[](const K& key)
			{
				ulong idx = 0;

				while(idx < size && data[idx].key != key)
				{
					idx += 1;
				}

				if(idx != size)
				{
					return data[idx].value;
				}
				throw "Invalid Key";
			}
			
			const V& operator[](const K& key) const
			{
				ulong idx = 0;

				while(idx < size && data[idx].key != key)
				{
					idx += 1;
				}

				if(idx != size)
				{
					return data[idx].value;
				}
				throw "Invalid Key";
			}

			std::string ToString() const
			{
				std::stringstream out;
				out << "{";

				for(ulong i = 0;i < size;i += 1)
				{
					out << "(" << data[i].key << "," << data[i].value << ")";
	
					if((i + 1) != size)
					{
						out << ",";
					}
				}
				out << "}";
				return out.str();
			}

			friend std::ostream& operator<<(std::ostream& out,const Map<K,V>& obj)
            		{
                		out << obj.ToString();
                		return out;
            		}
        	};
	}

	namespace sn
	{
		template<class K,class V>
		class Map : public MapInterface<K,V>
		{
			private:
			Node<Pair<K,V>>* head;
			ulong size;

			public:
			Map() : size(0), head(NULL) {}

			Map(const Map<K,V>& obj)
			{
				size = obj.size;
				head = Copy(obj.head);
			}

			Map<K,V>& operator=(const Map<K,V>& rhs)
			{
				if(this != &rhs)
				{
					size = rhs.size;
					Clear(head);
					head = Copy(rhs.head);
				}
				return *this;
			}

			~Map()
			{
				Clear(head);
				head = NULL;
			}

			void Put(const K& key,const V& value)
			{
				Pair<K,V> p;
				p.key = key;
				p.value = value;

				if(head == NULL)
				{
					head = Create(p);
					size += 1;
				}
				else
				{
					Node<Pair<K,V>>* t = head;

					while(t->link != NULL && t->data.key != key)
					{
						t = t->link;
					}

					if(t->link == NULL)
					{
						t->link = Create(p);
						size += 1;
					}
				}
			}

			void Remove(const K& key)
			{
				if(head != NULL)
				{
					Node<Pair<K,V>> *t, *p;

					if(head->data.key == key)
					{
						t = head;
						head = head->link;
						delete t;	
						t = NULL;
						size -= 1;
					}
					else
					{
						t = head->link;
						p = head;

						while(t != NULL && t->data.key != key)
						{
							p = t;
							t = t->link;
						}
					
						if(t != NULL)
						{
							p->link = t->link;
							delete t;
							t = NULL;
							size -= 1;
						}
					}
				}
			}

			ulong Length() const 
			{
				return size;
			}

			bool IsEmpty() const 
			{
				return (head == NULL);
			}

			bool Contains(const K& key) const
			{
				Node<Pair<K,V>>* t = head;

				while(t != NULL && t->data.key != key)
				{
					t = t->link;	
				}

				return (t != NULL);
			}
			
			V& Get(const K& key)
			{
				Node<Pair<K,V>>* t = head;

				while(t != NULL && t->data.key != key)
				{
					t = t->link;
				}

				if(t == NULL)
				{
					throw "Invalid Key";
				}
				return t->data.value;
			} 		 

			const V& Get(const K& key) const
			{
				Node<Pair<K,V>>* t = head;

				while(t != NULL && t->data.key != key)
				{
					t = t->link;
				}

				if(t == NULL)
				{
					throw "Invalid Key";
				}
				return t->data.value;
			} 		 


			V& operator[](const K& key)
			{
				Node<Pair<K,V>>* t = head;

				while(t != NULL && t->data.key != key)
				{
					t = t->link;
				}

				if(t == NULL)
				{
					throw "Invalid Key";
				}
				return t->data.value;
			} 		 

			const V& operator[](const K& key) const
			{
				Node<Pair<K,V>>* t = head;

				while(t != NULL && t->data.key != key)
				{
					t = t->link;
				}

				if(t == NULL)
				{
					throw "Invalid Key";
				}
				return t->data.value;
			}

			std::string ToString() const
			{
				std::stringstream out;
				out << "{";

				Node<Pair<K,V>>* t = head;

				while(t != NULL)
				{
					out << "(" << t->data.key << "," << t->data.value << ")";

					if(t->link != NULL)
					{
						out << ",";
					}
					t = t->link;
				}
				out << "}";
				return out.str();
			} 		 

			friend std::ostream& operator<<(std::ostream& out,const Map<K,V>& obj)
			{
				out << obj.ToSTring();
				return out;
			}
		};
	}


	namespace mn
	{
		template<class K,class V>
		class Map : public MapInterface<K,V>
		{
			private:
			Node<Pair<K,V>>* head;
			ulong size;

			public:
			Map() : size(0), head(NULL) {}

			Map(const Map<K,V>& obj)
			{
				size = obj.size;
				head = Copy(obj.head);
			}

			Map<K,V>& operator=(const Map<K,V>& rhs)
			{
				if(this != &rhs)
				{
					size = rhs.size;
					Clear(head);
					head = Copy(rhs.head);
				}
				return *this;
			}

			~Map()
			{
				Clear(head);
				head = NULL;
			}

			void Put(const K& key,const V& value)
			{
				Pair<K,V> p;
				p.key = key;
				p.value = value;

				if(head == NULL)
				{
					head = Create(p);
					size += 1;
				}
				else
				{
					Node<Pair<K,V>>* t = head;

					while(t->next != NULL && t->data.key != key)
					{
						t = t->next;
					}

					if(t->next == NULL)
					{
						t->next = Create(p);
						t->next->prev = t;
						size += 1;
					}
				}
			}

			void Remove(const K& key)
			{
				if(head != NULL)
				{
					Node<Pair<K,V>> *t;

					if(head->data.key == key)
					{
						t = head;
						head = head->next;
						
						if(head != NULL)
						{
							head->prev = NULL;
						}
						delete t;	
						t = NULL;
						size -= 1;
					}
					else
					{
						t = head->next;

						while(t != NULL && t->data.key != key)
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
							size -= 1;
						}
					}
				}
			}

			ulong Length() const 
			{
				return size;
			}

			bool IsEmpty() const 
			{
				return (head == NULL);
			}

			bool Contains(const K& key) const
			{
				Node<Pair<K,V>>* t = head;

				while(t != NULL && t->data.key != key)
				{
					t = t->next;	
				}

				return (t != NULL);
			}
			
			V& Get(const K& key)
			{
				Node<Pair<K,V>>* t = head;

				while(t != NULL && t->data.key != key)
				{
					t = t->next;
				}

				if(t == NULL)
				{
					throw "Invalid Key";
				}
				return t->data.value;
			} 		 

			const V& Get(const K& key) const
			{
				Node<Pair<K,V>>* t = head;

				while(t != NULL && t->data.key != key)
				{
					t = t->next;
				}

				if(t == NULL)
				{
					throw "Invalid Key";
				}
				return t->data.value;
			} 		 


			V& operator[](const K& key)
			{
				Node<Pair<K,V>>* t = head;

				while(t != NULL && t->data.key != key)
				{
					t = t->next;
				}

				if(t == NULL)
				{
					throw "Invalid Key";
				}
				return t->data.value;
			} 		 

			const V& operator[](const K& key) const
			{
				Node<Pair<K,V>>* t = head;

				while(t != NULL && t->data.key != key)
				{
					t = t->next;
				}

				if(t == NULL)
				{
					throw "Invalid Key";
				}
				return t->data.value;
			}

			std::string ToString() const
			{
				std::stringstream out;
				out << "{";

				Node<Pair<K,V>>* t = head;

				while(t != NULL)
				{
					out << "(" << t->data.key << "," << t->data.value << ")";

					if(t->next != NULL)
					{
						out << ",";
					}
					t = t->next;
				}
				out << "}";
				return out.str();
			} 		 

			friend std::ostream& operator<<(std::ostream& out,const Map<K,V>& obj)
			{
				out << obj.ToSTring();
				return out;
			}
		};
	}
}

#endif
