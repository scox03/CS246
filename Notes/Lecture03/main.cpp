/********************************************
*Runtime Functions and Big-O Notation 
********************************************/
#include <iostream>

//Algorithm 1
//What is its runtime function?
//What is its Big-O?
template<typename T>
bool Search(T data[],int n,const T& value)
{
	for(int i = 0;i < n;i += 1)
	{
		if(data[i] == value)
		{
			return true;
		}
	}
	return false;
}


//Algorithm 2
//What is its runtime function?
//What is its Big-O?
int Digits(int n)
{
	int cnt = 0;

	if(n < 0)
	{
		n *= -1;
	}

	while(n > 10)
	{
		cnt += 1;
		n /= 10;
	}
	return cnt;
}
	

//Algorithm 3
//What is its runtime function?
//What is its Big-O?
template<typename T>
T MinL(T data[],int n)
{
	T mn = data[0];

	for(int i = 1;i < n;i += 1)
	{
		if(mn > data[i])
		{
			mn = data[i];
		}
	}
	return mn;
}

//Algorithm 4
//What is its runtime function?
//What is its Big-O?
template<typename T>
T MinB(T data[],int n)
{
	int hn = n/2;
	T mn;
	
	if(data[0] < data[n-1])
	{
		mn = data[0];
	}
	else
	{
		mn = data[n-1];
	}

	for(int i = 1;i <= hn;i += 1)
	{
		if(data[i] < data[n-i-1]) 
		{
			if(mn > data[i])
			{
				mn = data[i];
			}
		}
		else
		{
			if(mn > data[n-i-1])
			{
				mn = data[n-i-1];
			}
		}
	}
	return mn;
}

//Algorithm 5
//What is its runtime function?
//What is its Big-O?
bool IsPrimeO(int n)
{
	if(n >= -1 && n <= 1)
	{
		return false;
	}
	else if(n < 0)
	{
		n *= -1;
	}

	for(int i = 2;i < n;i += 1)
	{
		if(n % i == 0)
		{
			return false;
		}
	}
	return true;
}


//Algorithm 6
//What is its runtime function?
//What is its Big-O?
bool IsPrimeT(int n)
{
	if(n >= -1 && n <= 1)
	{
		return false;
	}
	else if(n < 0)
	{
		n *= -1;
	}

	for(int i = 2;i * i < n;i += 1)
	{
		if(n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	return 0;
}
