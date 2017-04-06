#include <vector>
#include <iostream>
#include <random>
#include <ctime>

#include "random_vector.h"

using namespace std;

//Shell算法有点类似于插入排序，在不同的范围内分别排序，将长程无序状态变为长程有序，短程无序。将排序范围缩小后，再来排序，减小循环次数 

template <typename Comparable>
void Shellsort(vector<Comparable> &a, int x)  //是希尔排序的思想是使数组中任意间隔为 gap 的元素都是有序的。
{
	for(int gap=a.size()/x; gap>0; gap /=x) 
	//当x=3，a.size()=1093 时, gap = 364, 121,  40, 13, 4, 1
	//当x=2, a.size()=1093是，gap = 546,  273,  136, 68, 34, 17, 8, 4, 2, 1
	{
		for(int i=gap; i<a.size();++i)  
		{
			Comparable tmp = std::move(a[i]);
			int j =i;
			for( ; j>=gap && tmp<a[j-gap]; j-=gap)
			{
				a[j]=move(a[j-gap]);				
			}
			a[j]=move(tmp); //j在for循环外部定义，经过 for 循环后，j的值参与for循环中的改变 
		}
	}
}

template <typename Comparable>
vector<Comparable> Shell(vector<Comparable> a, int x)
{
	int N=a.size();
	int h = 1;
	while(h<N/x)
	{
		h = x*h+1;
	}
	//此时h的值为 N/x以下取整，例如 当x=3，a.size()=1093 时, h = 364
	//当x=3, a.size()=20 时， h=13
	//当 
	while(h>=1)
	{
		for(int i=h; i<N ; i++)
		{
			for(int j=i; j>=h&& a[j]<a[j-h]; j-=h)
			{
				swap(a[j],a[j-h]);
			}			
		}
		h = h/x;
	}
	return a;
}

int main()
{
	std::vector<int> vec = random_vector(20, 0, 1000);
   
   cout<<"Original vector:"<<endl;
   for(auto x :vec)
		cout<<x<<" ";
	
	cout<<'\n'<<"Sorted vector"<<endl;
	
	auto vec2 = vec; 
	
	Shellsort(vec2,3);  //采用这种编程方法，步长是固定的，只能将 x 设置为2 
	cout<<"Shellsort result:"<<endl;
	for(auto x: vec2)
		cout<<x<<" ";
	cout<<endl; 
	
	auto Y = Shell(vec, 5);
	
	//Shellsort和Shell的异同：同，都是希尔排序的思想，先做到长程有序，再用插入法做到短程有序
	//异：Shellsort，最后一位的大致位置是固定的，逐步往前迭代，第一个循环中第一个点的位置取决于vector.size()，gap的步长不可调，只能取 2, 4, 8, 16,  
	//Shell中各迭代的位置固定，不随着vector.size()变化而变化，且h的步长可调
	//其实不论h取多少，对于Shell算法来说最终都要回到 h=1 这一步来，就是回到相邻的元素比较，即插入算法这个根本算法上来，这一点与Shellsort是一样的。
	//只不过，因为到 h=1之前，已经做到了长程有序，所以这一步的circle最多只要迭代 h 步即可 
	cout<<"Shell result:"<<endl;
	for(auto x: Y)
		cout<<x<<" ";
	cout<<endl;
	
	return 0;
}
