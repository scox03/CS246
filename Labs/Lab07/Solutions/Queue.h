#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include <sstream>
#include "Node.h"
using ulong = unsigned long;

namespace ds
{
	//Queue Interface
	template<class T>
	class QueueInterface
	{
		public:
		virtual void Enqueue(const T&) = 0;
		virtual void Dequeue() = 0;
		virtual const T& Peek() const = 0;
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
		class Queue : public QueueInterface<T>
		{
			private:
			T* data;
			ulong front;
			ulong back;
			ulong capacity;
		
			public:
			Queue() : front(0), back(0), capacity(101) 
			{
				data = new T[capacity];
			}

			Queue(ulong capacity) : front(0), back(0), capacity(capacity+1)
			{
				data = new T[this->capacity];
			}

			Queue(const Queue<T>& obj)
			{
				front = obj.front;
				back = obj.back;
				capacity = obj.capacity;
				data = new T[capacity];
				
				for(ulong i = front;i != back;i = (i + 1) % capacity)
				{
					data[i] = obj.data[i];
				}
			}

			Queue<T>& operator=(const Queue<T>& rhs)
			{
				if(this != &rhs)
				{
					front = rhs.front;
					back = rhs.back;
					capacity = rhs.capacity;
					delete[] data;
					data = new T[capacity];

					for(ulong i = front;i != back;i = (i + 1) % capacity)
					{
						data[i] = rhs.data[i];
					}
				}
				return *this;
			}

			~Queue() 
			{
				delete[] data;
			}

			void Enqueue(const T& item)
			{
				if((back + 1) % capacity != front)
				{
					data[back] = item;
					back = (back + 1) % capacity;
				}
			}

			void Dequeue() 
			{
				if(front != back)
				{
					front = (front + 1) % capacity;
				}
			}

			const T& Peek() const 
			{
				if(front == back)
				{
					throw "Empty Queue";
				}
				return data[front];
			}

			bool IsEmpty() const 
			{
				return (front == back);
			}

			bool IsFull() const 
			{
				return ((back + 1) % capacity == front);
			}

			std::string ToString() const 
			{
				std::stringstream out;
				out << "[";
				
				if(front != back)
				{
					out << data[front];
				}
				out << "]";
				return out.str();
			}

			friend std::ostream& operator<<(std::ostream& out,const Queue<T>& obj)
			{
				out << obj.ToString();
				return out;
			}
		};
	}

	namespace sn
	{	
		template<class T>
		class Queue : public QueueInterface<T>
		{
			private:
			Node<T>* head;
			Node<T>* tail;
		
			public:
			Queue() : head(NULL), tail(NULL) {}

			Queue(const Queue<T>& obj)
			{
				head = Copy(obj.head);
				tail = head;

				while(tail->link != NULL)
				{
					tail = tail->link;
				}
			}

			Queue<T>& operator=(const Queue<T>& rhs)
			{
				if(this != &rhs)
				{
					Clear(head);
					head = Copy(rhs.head);
					tail = head;

					while(tail->link != NULL)
					{
						tail = tail->link;
					}
				}
				return *this;
			}

			~Queue() 
			{
				Clear(head);
				head = NULL;
				tail = NULL;
			}

			void Enqueue(const T& item)
			{
				if(head == NULL)
				{
					head = Create(item);
					tail = head;
				}
				else
				{
					tail->link = Create(item);
					tail = tail->link;
				}
			}

			void Dequeue() 
			{
				if(head != NULL)
				{
					Node<T>* t = head;
					head = head->link;
					delete t;	
					t = NULL;
					
					if(head == NULL)
					{
						tail = NULL;
					}
				}
			}

			const T& Peek() const 
			{
				if(head == NULL)
				{
					throw "Empty Queue";
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

			friend std::ostream& operator<<(std::ostream& out,const Queue<T>& obj)
			{
				out << obj.ToString();
				return out;
			}
		};
	}

	namespace mn
	{
		template<class T>
		class Queue : public QueueInterface<T>
		{
			private:
			Node<T>* head;
			Node<T>* tail;
		
			public:
			Queue() : head(NULL), tail(NULL) {}

			Queue(const Queue<T>& obj)
			{
				head = Copy(obj.head);
				tail = head;

				while(tail->next != NULL)
				{
					tail = tail->next;
				}
			}

			Queue<T>& operator=(const Queue<T>& rhs)
			{
				if(this != &rhs)
				{
					Clear(head);
					head = Copy(rhs.head);
					tail = head;

					while(tail->next != NULL)
					{
						tail = tail->next;
					}
				}
				return *this;
			}

			~Queue() 
			{
				Clear(head);
				head = NULL;
				tail = NULL;
			}

			void Enqueue(const T& item)
			{
				if(head == NULL)
				{
					head = Create(item);
					tail = head;
				}
				else
				{
					tail->next = Create(item);
					tail->next->prev = tail;
					tail = tail->next;
				}
			}

			void Dequeue() 
			{
				if(head != NULL)
				{
					Node<T>* t = head;
					head = head->next;
					delete t;	
					t = NULL;
					
					if(head == NULL)
					{
						tail = NULL;
					}
					else
					{
						head->prev = NULL;
					}
				}
			}

			const T& Peek() const 
			{
				if(head == NULL)
				{
					throw "Empty Queue";
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

			friend std::ostream& operator<<(std::ostream& out,const Queue<T>& obj)
			{
				out << obj.ToString();
				return out;
			}
		};
	}
}

#endif	
