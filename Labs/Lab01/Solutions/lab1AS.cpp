#include <iostream>
#include <string>

bool HasDuplicates(double data[],int n)
{
	for(int i = 0;i < n;i += 1)
	{
		for(int j = i + 1;j < n;j += 1)
		{
			if(data[i] == data[j])
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	return 0;
}
