/***************************************
//Generic Coding: Using Templates
***************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

//The following function will return
//the maximum value in an array of
//any type objects that are comparable
//using the < operator.
//You do not have to define a separate 
//function for each type as long as
//the type has a definition for all the
//operation that are performed on it in
//the template function
template<typename T>
T Maximum(T data[],int n)
{
	T mx = data[0];

	for(int i = 1;i < n;i += 1)
	{
		if(mx < data[i])
		{
			mx = data[i];
		}
	}
	return 0;
}

//Generic Print Function
//The type must overload the << operator
template<typename T>
void Print(T data[],int n)
{
	std::cout << "[";
	for(int i = 0;i < n;i += 1)
	{
		std::cout << data[i];

		if(i + 1 < n)
		{
			std::cout << ", ";
		}
	}
	std::cout << "]";
}


//Initialize int array with random values 
void InitializeIntArray(int data[],int n)
{
	for(int i = 0;i < n;i += 1)
	{
		data[i] = (rand() % 900) + 100; //Generates random numbers between 100 to 999
	}
}

//Initialize double array with random values 
void InitializeDoubleArray(double data[],int n)
{
	for(int i = 0;i < n;i += 1)
	{
		data[i] = (rand() % 101) / 100.0; //Generates random numbers between 0 to 1
	}
}

//Generic Struct
template<class T>
struct Array
{
	T* data;
	int capacity;
};

//Initialization Function
template<class T>
void Create(Array<T>& obj,int size)
{
	obj.capacity = size;
	
	if(obj.capacity <= 0)
	{
		obj.capacity = 20;
	}

	obj.data = new T[obj.capacity];
	
	//This loop assigns each element the default
	//constructor of its type. This works with
	//primative data types as well 
	for(int i = 0;i < obj.capacity;i += 1)
	{
		obj.data[i] = T();
	}
}

//Destruction Function
template<class T>
void Clear(Array<T>& obj)
{
	delete[] obj.data;
}

int main()
{
	Array<int> arr1;
	Array<double> arr2;
	
	Create(arr1,15);
	Create(arr2,15);

	InitializeIntArray(arr1.data,arr1.capacity);
	InitializeDoubleArray(arr2.data,arr2.capacity);
	
	std::cout << "\n";
	Print(arr1.data,arr1.capacity);
	std::cout << "\n\n";
	Print(arr2.data,arr2.capacity);

	Clear(arr1);
	Clear(arr2);

	return 0;
}
