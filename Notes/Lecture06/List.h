#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <sstream>
#include "Node.h"
using ulong = unsigned long;

namespace ds
{
	namespace sn
	{	
		template<class T>
		class List
		{
			private:
			Node<T>* head;
			ulong size;

			public:
			List() : size(0), head(NULL) {}
		

			List(const List<T>& obj)
			{
				size = obj.size;
				head = Copy(obj.head);
			}

			List<T>& operator=(const List<T>& rhs)
			{
				if(this != &rhs)
				{
					size = rhs.size;
					Clear(head);
					head = Copy(rhs.head);
				}
				return *this;
			}

			~List() 
			{
				Clear(head);
				head = NULL;
			}

			ulong Length() const
			{
				return size;
			}

			bool IsEmpty() const 
			{
				return (head == NULL);
			}

			//prev must be a node of the list or NULL
			void Insert(Node<T>* node,const T& item)
			{
				if(head == NULL)
				{
					head = Create(item);
				}
				else if(node == NULL)
				{
					Node<T>* t = Create(item);
					t->link = head;
					head = t;
				}
				else
				{
					Node<T>* t = Create(item);
					t->link = node->link;
					node->link = t;
				}
				size += 1;	
			}

			//Insert at the end of the list
			void Insert(const T& item)
			{
				if(head == NULL)
				{
					head = Create(item);
				}
				else
				{
					Node<T>* t = head;

					while(t->link != NULL)
					{
						t = t->link;
					}
					t->link = Create(item);
				}
				size += 1;
			}		
			
			//ct must be in the list. 
			void Remove(Node<T>* ct)
			{
				if(head != NULL && ct != NULL)
				{
					Node<T>* t;

					if(ct == head)
					{
						t = head;
						head = head->link;
						delete t;
						t = NULL;
					}
					else
					{
						t = head;

						while(t->link != ct)
						{
							t = t->link;
						}
						t->link = ct->link;
						delete ct;
						ct = NULL;
					}
					size -= 1;
				}	
			}

			//Remove from the end of the list
			void Remove() 
			{
				if(head != NULL)
				{
					if(head->link == NULL)
					{
						delete head;
						head = NULL;
					}
					else
					{
						Node<T>* t = head->link;
						Node<T>* tp = head;

						while(t->link != NULL)
						{
							tp = t;
							t = t->link;
						}	
						tp->link = NULL;
						delete t;
						t = NULL;
					}	
					size -= 1;
				}
			}

			//ct must be a node of the list
			Node<T>* Search(Node<T>* ct,const T& item) const
			{
				Node<T>* t = ct;
				
				while(t != NULL && t->data != item)
				{
					t = t->link;
				}
				return t;
			}	
		
			Node<T>* Search(const T& item) const
			{
				Node<T>* t = head;
			
				while(t != NULL && t->data != item)
				{
					t = t->link;
				}
				return t;
			}
		
			bool Contains(const T& item) const
			{
				for(Node<T>* t = head;t != NULL;t = t->link)
				{
					if(t->data == item)
					{
						return true;
					}
				}
				return false;
			}

			Node<T>* Get(int idx) 
			{
				if(idx < 0 || idx >= size)
				{
					return NULL;
				}
				else
				{
					Node<T>* t = head;
					ulong i = 0;
					
					while(i < idx)
					{
						i += 1;
						t = t->link;
					}
					return t;
				}
			}

			T& operator[](int idx) 
			{
				if(idx < 0 || idx >= size)
				{
					throw "Out of Bound";
				}
				else
				{
					Node<T>* t = head;
					ulong i = 0;
					
					while(i < idx)
					{
						i += 1;
						t = t->link;
					}
					return t->data;
				}
			}
		
			const T& operator[](int idx) const
			{
				if(idx < 0 || idx >= size)
				{
					throw "Out of Bound";
				}
				else
				{
					Node<T>* t = head;
					ulong i = 0;
					
					while(i < idx)
					{
						i += 1;
						t = t->link;
					}
					return t->data;
				}
			}

			std::string ToString() const 
			{
				std::stringstream out;

				out << "[";
		
				for(Node<T>* t = head;t != NULL;t = t->link)
				{
					out << t->data;
				
					if(t->link != NULL)
					{
						out << ",";
					}
				}
				out << "]";
				return out.str();
			}	

			friend std::ostream& operator<<(std::ostream& out,const List<T>& obj)
			{
				out << obj.ToString();
				return out;
			}
		};
	}

	namespace mn
	{	
		template<class T>
		class List
		{
			private:
			Node<T>* head;
			ulong size;

			public:
			List() : size(0), head(NULL) {}
		

			List(const List<T>& obj)
			{
				size = obj.size;
				head = Copy(obj.head);
			}

			List<T>& operator=(const List<T>& rhs)
			{
				if(this != &rhs)
				{
					size = rhs.size;
					Clear(head);
					head = Copy(rhs.head);
				}
				return *this;
			}

			~List() 
			{
				Clear(head);
				head = NULL;
			}

			ulong Length() const
			{
				return size;
			}

			bool IsEmpty() const 
			{
				return (head == NULL);
			}

			//prev must be a node of the list or NULL
			void Insert(Node<T>* node,const T& item)
			{
				if(head == NULL)
				{
					head = Create(item);
				}
				else if(node == NULL)
				{
					Node<T>* t = Create(item);
					t->next = head;
					head->prev = t;
					head = t;
				}
				else 
				{
					Node<T>* t = Create(item);
					t->next = node->next;
					node->next = t;
					t->prev = node;
					
					if(t->next != NULL)
					{
						t->next->prev = t;
					}
				}
				size += 1;	
			}

			//Insert at the end of the list
			void Insert(const T& item)
			{
				if(head == NULL)
				{
					head = Create(item);
				}
				else
				{
					Node<T>* t = head;

					while(t->next != NULL)
					{
						t = t->next;
					}
					t->next = Create(item);
					t->next->prev = t;
				}
				size += 1;
			}		
			
			//ct must be in the list. 
			void Remove(Node<T>* ct)
			{
				if(head != NULL && ct != NULL)
				{
					if(ct == head)
					{
						head = head->next;
						delete ct;
						ct = NULL;

						if(head != NULL) 
						{
							head->prev = NULL;
						}
					}
					else
					{
						ct->prev->next = ct->next;

						if(ct->next != NULL)
						{
							ct->next->prev = ct->prev;
						}
						delete ct;
						ct = NULL;
					}
					size -= 1;
				}	
			}

			//Remove from the end of the list
			void Remove() 
			{
				if(head != NULL)
				{
					if(head->next == NULL)
					{
						delete head;
						head = NULL;
					}
					else
					{
						Node<T>* t = head;
				
						while(t->next != NULL)
						{
							t = t->next;
						}
						t->prev->next = NULL;
						delete t;
						t = NULL;
					}	
					size -= 1;
				}
			}

			//ct must be a node of the list
			Node<T>* Search(Node<T>* ct,const T& item) const
			{
				Node<T>* t = ct;
				
				while(t != NULL && t->data != item)
				{
					t = t->next;
				}
				return t;
			}	
		
			Node<T>* Search(const T& item) const
			{
				Node<T>* t = head;
			
				while(t != NULL && t->data != item)
				{
					t = t->next;
				}
				return t;
			}
		
			bool Contains(const T& item) const
			{
				for(Node<T>* t = head;t != NULL;t = t->next)
				{
					if(t->data == item)
					{
						return true;
					}
				}
				return false;
			}

			Node<T>* Get(int idx) 
			{
				if(idx < 0 || idx >= size)
				{
					return NULL;
				}
				else
				{
					Node<T>* t = head;
					ulong i = 0;
					
					while(i < idx)
					{
						i += 1;
						t = t->next;
					}
					return t;
				}
			}

			T& operator[](int idx) 
			{
				if(idx < 0 || idx >= size)
				{
					throw "Out of Bound";
				}
				else
				{
					Node<T>* t = head;
					ulong i = 0;
					
					while(i < idx)
					{
						i += 1;
						t = t->next;
					}
					return t->data;
				}
			}
		
			const T& operator[](int idx) const
			{
				if(idx < 0 || idx >= size)
				{
					throw "Out of Bound";
				}
				else
				{
					Node<T>* t = head;
					ulong i = 0;
					
					while(i < idx)
					{
						i += 1;
						t = t->next;
					}
					return t->data;
				}
			}

			std::string ToString() const 
			{
				std::stringstream out;

				out << "[";
		
				for(Node<T>* t = head;t != NULL;t = t->next)
				{
					out << t->data;
				
					if(t->next != NULL)
					{
						out << ",";
					}
				}
				out << "]";
				return out.str();
			}	

			friend std::ostream& operator<<(std::ostream& out,const List<T>& obj)
			{
				out << obj.ToString();
				return out;
			}
		};
	}
}

#endif
