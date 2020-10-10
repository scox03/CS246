#include <iostream>

int Occurrences(double data[], int n, double value)
{
	int cnt = 0;

	for(int i = 0;i < n;i += 1)
	{
		if(data[i] == value)
		{
			cnt += 1;
		}
	}
	return cnt;
}

int main()
{
	return 0;
}
