#include<iostream>
using namespace std;
double f(int k,int m)
{
    if(k==0)
        return 1;
    else if(k==1)
        return m;
        else
        return ((2*k-1)*m*f(k-1,m)-(k-1)*f(k-2,m))/k;
 
}
int main()
{
    int n,x;
    cin>>n>>x;
    cout<<f(n,x)<<endl;
    return 0;
}

