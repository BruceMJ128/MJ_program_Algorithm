#include <vector>
#include <iostream>
#include <random>
#include <ctime>

#include "random_vector.h"

using namespace std;

std::vector<int> insert_sort(vector<int> vec)
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

/*  ԭ����룬������ 
template<typename Iterator>
void insertionSort(const Iterator & begin, const Iterator & end)
{
	insertionSort(begin, end, less<decltype(*begin)>{ });
}

template<typename Iterator, typename Comparator> //����������ΪIterator, Comparator Ϊ���� 
void insertionSort(const Iterator & begin, const Iterator & end, Comparator lessThan)
{
	if(begin==end)
		return;
	Iterator j;
	
	for(Iterator p=begin+1; p!=end; ++p)
	{
		auto tmp = move(*p);
		for(j=p; j!=begin && lessThan(tmp, *(j-1));--j)
			*j = move(*(j-1));
		*j = std::move(tmp);
	}
}
*/

template <typename Comparable>
void insertionSort( vector<Comparable> & a, int left, int right )
{
    for( int p = left + 1; p <= right; ++p )
    {
        Comparable tmp = std::move( a[ p ] );
        int j;

        for( j = p; j > left && tmp < a[ j - 1 ]; --j )
            a[ j ] = std::move( a[ j - 1 ] );
        a[ j ] = std::move( tmp );
    }
}

int main()
{
	std::vector<int> vec = random_vector(100, 0, 30);
   
   cout<<"Original vector:"<<endl;
   for(auto x :vec)
		cout<<x<<" ";
	
	cout<<'\n'<<"Sorted vector"<<endl;
	for(auto x: insert_sort(vec))
		cout<<x<<" ";
	cout<<endl;
	
	insertionSort(vec, 10,20);  //��������ֻ����10~20λ�Ĳ��� 
	
	cout<<"Partly sort:"<<endl;
	for(auto x:vec)
		cout<<x<<" ";
	cout<<endl;
	
    return 0;
}

