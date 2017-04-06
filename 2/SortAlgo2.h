#ifndef SortAlgo2_h
#define SortAlgo2_h

#include <vector>
#include <iostream>
#include "StopWatch_QueryPerformanceCounter.h"
#include <string>
#include "SortAlgo.h"

using namespace std;

class SortAlgo2
{
	friend class StopWatch;

	public:
		void set_vector(vector<int> vec, string str);
		void Sort_time();
		void Shell_gapfactor(int h);
	
	private:
		vector<int> inner_vec;
		vector<int> sorted_vec;
		string inner_str;
		double time;
		StopWatch watch;
		int gap_factor;	
};

void SortAlgo2::set_vector(vector<int> vec, string str)
{
	inner_vec = vec;
	inner_str = str;
}

void SortAlgo2::Shell_gapfactor(int h)
{
	gap_factor =h;
}

void SortAlgo2::Sort_time()
{
	
	if(inner_str=="Insert")
	{
		watch.Start();
		sorted_vec = Insert_sort(inner_vec);
		watch.Stop();
		time = watch.GetCostMillisecond();
		cout<<inner_str<<" Sort time: "<<time<<endl;
	}
	else if(inner_str=="Shell")
	{
		watch.Start();
		sorted_vec = Shell_sort(inner_vec,gap_factor);
		watch.Stop();
		time = watch.GetCostMillisecond();
		cout<<inner_str<<" Sort time: "<<time<<endl;
	}
	else
	{
		cout<<"Sort mode error."<<endl;
	}
}

#endif
