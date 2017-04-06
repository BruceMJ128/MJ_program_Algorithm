#include <iostream>
#include <vector>
#include <random>
#include <ctime>
using namespace std;

vector<int> randomvec(int n, const int low, const int high)
{
	static std::default_random_engine e(time(0));
	static std::uniform_int_distribution<int> u(low, high);
	
	vector<int> vec;
	vec.push_back(n);
	for(int i=0; i<n;i++)
	{
		vec.push_back(u(e));
	}	
	return vec;
}

int Max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}

//遍历求出所有和，再比较选出，耗时 O(n^2) 
vector<int> maxsum(vector<int> vec)
{
	int max=0, s=0, e=0; //max为数值，s为开始位置，e为结束位置
	for(int i=0; i<vec.size(); i++)
	{
		int sum=0;
		for(int j=i;j<vec.size();j++)
		{
			sum += vec[j];
			max=Max(max,sum);
			if(max==sum)
			{
				s=i;
				e=j;
			}
		}
	}
	vector<int> final_vec={max, s, e};
	return final_vec;
}


//动态规划

vector<int> dy_vec(vector<int> vec)
{
	int max=0, s=0, e=0;
	int sum=0, s_temp, e_temp;  //求过程中的和，并作为判断 
	for(int i=0; i<vec.size(); i++)
	{		
		if(sum>0)
		{
			sum += vec[i];
			e_temp = i;
		}			
		else
		{
			sum = vec[i];
			s_temp = i;
		}		
		/*
		if(vec[i]>0)
		{
			sum +=vec[i];
			e_temp=i;
		}
		else
		{
			sum = vec[i];
			s_temp=i;
		}
		*/
		max=Max(max, sum);
		if(max==sum)
		{
			s=s_temp;
			e=e_temp;
		}
	}
	
	vector<int> final_vec={max, s, e};
	return final_vec;	
}
 
int main()
{
	int T=2, low=-1000, high=1000;
	int N_max=20; //某一行产生N个数字 
	cout<<T<<endl;
	
	static std::default_random_engine e(time(0));
	static std::uniform_int_distribution<int> ui(1, N_max);
	
	for(int i=0;i<T;i++)
	{
		auto N=ui(e);
		vector<int> vec;
		vec=randomvec(N,low,high);
		for(auto x: vec)
			cout<<x<<" ";
		cout<<endl;
		
		vector<int> show_vec = maxsum(vec);
		
		cout<<"Case "<<i+1<<endl;
		cout<<"Normal traverse: "<<endl;
		for(auto x: show_vec)
			cout<<x<<" ";
		cout<<endl;
		
		cout<<"Dynamic programming:"<<endl;
		vector<int> Dyn_vec= dy_vec(vec);
		for(auto x: Dyn_vec)
			cout<<x<<" ";
		cout<<endl;
	}
	return 0;
}
