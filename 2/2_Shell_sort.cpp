#include <vector>
#include <iostream>
#include <random>
#include <ctime>

#include "random_vector.h"

using namespace std;

//Shell�㷨�е������ڲ��������ڲ�ͬ�ķ�Χ�ڷֱ����򣬽���������״̬��Ϊ�������򣬶̳����򡣽�����Χ��С���������򣬼�Сѭ������ 

template <typename Comparable>
void Shellsort(vector<Comparable> &a, int x)  //��ϣ�������˼����ʹ������������Ϊ gap ��Ԫ�ض�������ġ�
{
	for(int gap=a.size()/x; gap>0; gap /=x) 
	//��x=3��a.size()=1093 ʱ, gap = 364, 121,  40, 13, 4, 1
	//��x=2, a.size()=1093�ǣ�gap = 546,  273,  136, 68, 34, 17, 8, 4, 2, 1
	{
		for(int i=gap; i<a.size();++i)  
		{
			Comparable tmp = std::move(a[i]);
			int j =i;
			for( ; j>=gap && tmp<a[j-gap]; j-=gap)
			{
				a[j]=move(a[j-gap]);				
			}
			a[j]=move(tmp); //j��forѭ���ⲿ���壬���� for ѭ����j��ֵ����forѭ���еĸı� 
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
	//��ʱh��ֵΪ N/x����ȡ�������� ��x=3��a.size()=1093 ʱ, h = 364
	//��x=3, a.size()=20 ʱ�� h=13
	//�� 
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
	
	Shellsort(vec2,3);  //�������ֱ�̷����������ǹ̶��ģ�ֻ�ܽ� x ����Ϊ2 
	cout<<"Shellsort result:"<<endl;
	for(auto x: vec2)
		cout<<x<<" ";
	cout<<endl; 
	
	auto Y = Shell(vec, 5);
	
	//Shellsort��Shell����ͬ��ͬ������ϣ�������˼�룬�����������������ò��뷨�����̳�����
	//�죺Shellsort�����һλ�Ĵ���λ���ǹ̶��ģ�����ǰ��������һ��ѭ���е�һ�����λ��ȡ����vector.size()��gap�Ĳ������ɵ���ֻ��ȡ 2, 4, 8, 16,  
	//Shell�и�������λ�ù̶���������vector.size()�仯���仯����h�Ĳ����ɵ�
	//��ʵ����hȡ���٣�����Shell�㷨��˵���ն�Ҫ�ص� h=1 ��һ���������ǻص����ڵ�Ԫ�رȽϣ��������㷨��������㷨��������һ����Shellsort��һ���ġ�
	//ֻ��������Ϊ�� h=1֮ǰ���Ѿ������˳�������������һ����circle���ֻҪ���� h ������ 
	cout<<"Shell result:"<<endl;
	for(auto x: Y)
		cout<<x<<" ";
	cout<<endl;
	
	return 0;
}
