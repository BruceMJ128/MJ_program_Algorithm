#include <iostream>

using namespace std;

int getPower(int x, int y)
{
	if(y<0)
		return 0;
	if(y==0)
		return 1;
	else
		return x*getPower(x, y-1);
}

double getPower(double x, double y)
{
	if(y<0)
		return 0;
	if(y==0)
		return 1;
	else
		return x*getPower(x, y-1);
}

int main()
{
	int a, m ,result1;
	double b, result2;
	cin>>a>>b>>m;
	
	result1 = getPower(a,m);
	cout<<result1<<endl;
	
	result2 = getPower(b,double(m));	
	cout<<result2<<endl;
	return 0;
}
