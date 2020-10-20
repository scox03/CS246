#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <sstream>
#include "Node.h"
using ulong = unsigned long;

namespace ds
{
	//Stack Interface
	template<class T>
	class StackInterface
	{
		public:
		virtual void Push(const T&) = 0;
		virtual void Pop() = 0;
		virtual const T& Top() const = 0;
		virtual bool IsEmpty() const = 0;
	};

	/*******************************************
	* da : array namespace
	* sn : singly linked node namespace
	* mn : doubly linked node namespace
	*******************************************/
	
	namespace da
	{
		template<class T>
		class Stack : public StackInterface<T>
		{
			private:
			T* data;
			ulong top;
			ulong capacity;
		
			public:
			Stack() : top(0), capacity(100) 
			{
				data = new T[capacity];
			}

			Stack(ulong capacity) : top(0), capacity(capacity)
			{
				data = new T[this->capacity];
			}

			Stack(const Stack<T>& obj)
			{
				top = obj.top;
				capacity = obj.capacity;
				data = new T[capacity];
				
				for(ulong i = 0;i < top;i += 1)
				{
					data[i] = obj.data[i];
				}
			}

			Stack<T>& operator=(const Stack<T>& rhs)
			{
				if(this != &rhs)
				{
					top = rhs.top;
					capacity = rhs.capacity;
					delete[] data;
					data = new T[capacity];

					for(ulong i = 0;i < top;i += 1)
					{
						data[i] = rhs.data[i];
					}
				}
				return *this;
			}

			~Stack() 
			{
				delete[] data;
			}

			void Push(const T& item)
			{
				if(top < capacity)
				{
					data[top] = item;
					top += 1;
				}
			}

			void Pop() 
			{
				if(top > 0)
				{
					top -= 1;
				}
			}

			const T& Top() const 
			{
				if(top == 0)
				{
					throw "Empty Stack";
				}
				return data[top-1];
			}

			bool IsEmpty() const 
			{
				return (top == 0);
			}

			bool IsFull() const 
			{
				return (top == capacity);
			}

			std::string ToString() const 
			{
				std::stringstream out;
				out << "[";
				
				if(top != 0)
				{
					out << data[top-1];
				}
				out << "]";
				return out.str();
			}

			friend std::ostream& operator<<(std::ostream& out,const Stack<T>& obj)
			{
				out << obj.ToString();
				return out;
			}
		};
	}

	namespace sn
	{	
		template<class T>
		class Stack : public StackInterface<T>
		{
			private:
			Node<T>* head;
		
			public:
			Stack() : head(NULL) {}

			Stack(const Stack<T>& obj)
			{
				head = Copy(obj.head);
			}

			Stack<T>& operator=(const Stack<T>& rhs)
			{
				if(this != &rhs)
				{
					Clear(head);
					head = Copy(rhs.head);
				}
				return *this;
			}

			~Stack() 
			{
				Clear(head);
				head = NULL;
			}

			void Push(const T& item)
			{
				Node<T>* t = Create(item);
				t->link = head;
				head = t;
			}

			void Pop() 
			{
				if(head != NULL)
				{
					Node<T>* t = head;
					head = head->link;
					delete t;	
					t = NULL;
				}
			}

			const T& Top() const 
			{
				if(head == NULL)
				{
					throw "Empty Stack";
				}
				return head->data;
			}

			bool IsEmpty() const 
			{
				return (head == NULL);
			}

			std::string ToString() const 
			{
				std::stringstream out;
				out << "[";
				
				if(head != NULL)
				{
					out << head->data;
				}
				out << "]";
				return out.str();
			}

			friend std::ostream& operator<<(std::ostream& out,const Stack<T>& obj)
			{
				out << obj.ToString();
				return out;
			}
		};
	}

	namespace mn
	{	
		template<class T>
		class Stack : public StackInterface<T>
		{
			private:
			Node<T>* head;
		
			public:
			Stack() : head(NULL) {}

			Stack(const Stack<T>& obj)
			{
				head = Copy(obj.head);
			}

			Stack<T>& operator=(const Stack<T>& rhs)
			{
				if(this != &rhs)
				{
					Clear(head);
					head = Copy(rhs.head);
				}
				return *this;
			}

			~Stack() 
			{
				Clear(head);
				head = NULL;
			}

			void Push(const T& item)
			{
				Node<T>* t = Create(item);
				t->next = head;
				
				if(head != NULL)
				{
					head->prev = t;
				}
				head = t;
			}

			void Pop() 
			{
				if(head != NULL)
				{
					Node<T>* t = head;
					head = head->next;
					
					if(head != NULL)
					{
						head->prev = NULL;
					}
					delete t;	
					t = NULL;
				}
			}

			const T& Top() const 
			{
				if(head == NULL)
				{
					throw "Empty Stack";
				}
				return head->data;
			}

			bool IsEmpty() const 
			{
				return (head == NULL);
			}

			std::string ToString() const 
			{
				std::stringstream out;
				out << "[";
				
				if(head != NULL)
				{
					out << head->data;
				}
				out << "]";
				return out.str();
			}

			friend std::ostream& operator<<(std::ostream& out,const Stack<T>& obj)
			{
				out << obj.ToString();
				return out;
			}
		};
	}
}

#endif
