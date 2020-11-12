#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <iostream>
#include <string>
#include "Array.h"

namespace ds
{
	//Generic Swap() Function
	template<typename T>
	void Swap(T& a,T& b)
	{
		T t = a;
		a = b;
		b = t;
	}

	//Merge() Function
	template<typename T>
	void Merge(Array<T>& data,int p,int q,int r)
	{
		int i, lc = 0, rc = 0;
		int ln = r - p + 1, rn = q - r;
		Array<T> L(ln), R(rn);

		//copy elements to left subarray
		for(i = 0;i < ln;i += 1)
		{ 
			L[i] = data[p+i];
		}

		//copy elements to right subarray
		for(i = 0;i < rn;i += 1)
		{
			R[i] = data[r+1+i];
		}

		i = p;
		
		//sort elements from the two subarray into the array  
		while(lc < ln && rc < rn)
		{
			if(L[lc] <= R[rc])
			{
				data[i] = L[lc];
				lc += 1;
			}
			else
			{
				data[i] = R[rc];
				rc += 1;
			}
			i += 1;
		}

		//copy the remaining elements
		//only one loop will be executed
		while(lc < ln)
		{
			data[i] = L[lc];
			i += 1;
			lc += 1;
		}

		while(rc < rn)
		{
			data[i] = R[rc];
			i += 1;
			rc += 1;
		}
	}

	//Recursive MergeSort() Function
	template<typename T>
	void MergeSort(Array<T>& data,int p,int q)
	{
		if(p < q)
		{
			//find middle index
			int r = (p + q) / 2;
			//divide 
			MergeSort(data,p,r);
			MergeSort(data,r+1,q);
			//combine
			Merge(data,p,q,r);
		}
	}

	//Overloaded MergeSort() Function
	template<typename T>
	void MergeSort(Array<T>& data)
	{
		MergeSort(data,0,data.Length()-1);
	}

	//Partition() Function
	template<typename T>
	int Partition(Array<T>& data,int p,int q)
	{
		T pv = data[q];
		int i = p - 1;

		for(int j = p;j < q;j += 1)
		{
			if(data[j] < pv)
			{
				i += 1;
				Swap(data[i],data[j]);
			}
		}
		Swap(data[i+1],data[q]);
		return (i + 1);
	}

	//Recursive QuickSort() Function
	template<typename T>
	void QuickSort(Array<T>& data,int p,int q)
	{
		if(p < q)
		{
			int r = Partition(data,p,q);
			QuickSort(data,p,r-1);
			QuickSort(data,r+1,q);
		}
	}

	//Overloaded QuickSort() Function
	template<typename T>
	void QuickSort(Array<T>& data)
	{
		QuickSort(data,0,data.Length()-1);
	}

}

#endif
