#ifndef SortAlgo_h
#define SortAlgo_h

#include <vector>
#include <iostream>
#include "StopWatch_QueryPerformanceCounter.h"

using namespace std;

template <typename Comparable>
vector<Comparable> Insert_sort(vector<Comparable> vec)
{
	int n=vec.size();
	for(int i=0; i<n; i++)
	{
		for(int j=i; j>0 ;j--)
		{
			if(vec[j]<vec[j-1])
				swap(vec[j],vec[j-1]);
		}
	}
	return vec;
}

template <typename Comparable>
vector<Comparable> Shell_sort(vector<Comparable> a, int x) //x决定h的跨度 
{
	int N=a.size();
	int h = 1;
	while(h<N/x)
	{
		h = x*h+1;
	}
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

template <typename Comparable>
vector<Comparable> Select_sort(vector<Comparable> vec)
{
	vector<int> vec1;
	int N=vec.size();
	for(int i=0; i<N; i++)
	{
		int min_lo=i; //最小值的位置 
		for(int j=i; j<N; j++)
		{
			if(vec[j]<vec[min_lo])
			{
				min_lo=j;
			}
		}
		swap(vec[i],vec[min_lo]);   //交换 min_lo 和 i 的值		
	}
	return vec;
}


#endif
