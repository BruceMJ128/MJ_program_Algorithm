#include <iostream>

using namespace std;

int func(int n)
{
	int sum=0;
	for(int i=0;i<n+1;i++)
	{
		sum = sum +i;
	}
	return sum;
}

int main()
{
	int n=100;
	int x=0;
	x = func(n);
	
	cout<<x<<endl;
	return 0;	
}

