#include <vector>
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

std::vector<int> Selec_sort(vector<int> vec)
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
		int temp = vec[min_lo];  //交换 min_lo 和 i 的值 
		vec[min_lo]=vec[i];
		vec[i]=temp;		
	}
	return vec;
}

std::vector<int> randomGenerate(int leng, const int low, const int high)
{
    static std::default_random_engine e(time(0));
    static std::uniform_int_distribution<unsigned> u(low, high);

    std::vector<int> vec;
    for (int i = 0; i < leng; i++)
        vec.push_back(u(e));
    return vec;
}

int main()
{
	std::vector<int> vec = randomGenerate(10, 0, 30);
    cout<<"Original vector:"<<endl;
    
    for(auto x: vec)
    	cout<<x<<" ";
    cout<<endl;
    
    cout<<"Sorted vector:"<<endl;
    for(auto x: Selec_sort(vec))
    	cout<<x<<" ";
    cout<<endl;
    
    return 0;
}

