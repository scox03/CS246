#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Array.h"

int MinimumDistance(ds::Array<int>& data)
{
	//Verify the minimum constraint  
	if(data.Length() <= 1)
	{
		return 0;
	}

	//Calculate the first adjacent (consecutive) distance and make 
	//it the first minimum value
	int d = (data[0] < data[1])?(data[1] - data[0]):(data[0] - data[1]);
	int mn = d;

	//Loop through the array to calculate the remaining adjacent distances
	//and compare them to the current minimum distance. 
	for(int i = 2;i < data.Length();i += 1)
	{
		d = (data[i] < data[i-1])?(data[i-1] - data[i]):(data[i] - data[i-1]);
		
		if(mn > d)
		{
			mn = d;
		}
	}
	//Return the minimum value
	return mn;
}

template <typename T>
bool Similar(ds::Array<T>& ar1,ds::Array<T>& ar2)
{
	//Assign n the smaller of the two array lengths
	int n = (ar1.Length() <= ar2.Length())?(ar1.Length()):(ar2.Length());

	//Loop through the first n elements of both array and check if 
	//elements with the same index are not equal.
	for(int i = 0;i < n;i += 1)
	{
		if(ar1[i] != ar2[i])
		{
			return false;
		}
	}
	//Return true if the loop terminates
	return true;
}

template <typename T>
void MidAppend(ds::Array<T>& data,ds::Array<T>& addon)
{
	//Assign the lengths of each array to their own varaible and 
	//assign half the length of to the variable md 
	int n = data.Length();
	int m = addon.Length();
	int md = n / 2;
	
	//Copy the array data to a temporary array
	ds::Array<T> tmp = data;
	//Resize data to the sum of lengths of data and addon.
	data.Resize(n + m);

	//Copy the first half of temporary array to the beginning 
	//of data
	for(int i = 0;i < md;i += 1)
	{
		data[i] = tmp[i];
	}

	//Copy addon to data starting at the offset of md for data 
	for(int i = 0;i < m;i += 1)
	{
		data[md+i] = addon[i];
	}

	//Copy the remainder of the temporary array to data starting at the
	//offset m + md
	for(int i = md;i < n;i += 1)
	{
		data[m+i] = tmp[i];
	}
}

/***********************************************
Runtime Table 
cost	| time	| operation 
================================================
1	| 1	| int t;
1	| 1	| int lo = low;
1	| 1	| lo > high
1	| 1	| lo = high;
1	| 1	| int hi = (high + low) - lo;
1	| 1	| int i = lo - 1;
1	| 1	| int pivot = a[hi];
1	| 1	| int j = lo
1	| n	| j < hi
1	| n - 1	| a[j] < pivot
1	| n - 1	| i += 1;
1	| n - 1 | t = a[i];
1	| n - 1	| a[i] = a[j];
1	| n - 1	| a[j] = t;
1	| n - 1	| j += 1
1	| 1	| t = a[i+1];
1	| 1	| a[i+1] = a[hi];
1	| 1	| a[hi] = t;
1	| 1	| return (i + 1);
=================================================
T(n) = 7n + 6 
*************************************************/
  
int main()
{
	return 0;
}
