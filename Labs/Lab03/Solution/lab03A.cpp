template<typename T>
bool IsSorted(T data[],int n)
{
	for(int i = 1;i < n;i += 1)
	{
		if(data[i-1] > data[i])
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
