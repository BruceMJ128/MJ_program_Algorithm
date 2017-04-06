#include <iostream> 
#include <vector>
#include <ctime>
#include <random>
#include "SortAlgo.h"
#include "random_vector.h"
#include "StopWatch_QueryPerformanceCounter.h"

using namespace std;

int main()
{
	vector<int> vec = random_vector(2000, 0, 10000);
	StopWatch watch;
	
	/*
	cout<<"Original vector:"<<endl;
	for(auto & x : vec)
		cout<<x<<" ";
	cout<<endl;
	*/
	
	
	watch.Start();
	auto vec2 = Shell_sort(vec, 3); //3 decide the gap length, h
	watch.Stop();	
	auto Shell_time3 = watch.GetCostMillisecond();	
	cout<<"Shell sort time, x=3: "<<Shell_time3<<endl;

	watch.Start();
	auto vec4 = Shell_sort(vec, 2); //3 decide the gap length, h
	watch.Stop();	
	auto Shell_time2 = watch.GetCostMillisecond();	
	cout<<"Shell sort time, x=2: "<<Shell_time2<<endl;

	watch.Start();
	auto vec5 = Shell_sort(vec, 10); //3 decide the gap length, h
	watch.Stop();	
	auto Shell_time10 = watch.GetCostMillisecond();	
	cout<<"Shell sort time, x=10: "<<Shell_time10<<" ms"<<endl;

	watch.Start();
	auto vec3 = Select_sort(vec);
	watch.Stop();	
	auto Select_time = watch.GetCostMillisecond();	
	cout<<"Select sort time: "<<Select_time<<endl;
	
	watch.Start();
	auto vec1 = Insert_sort(vec);
	watch.Stop();	
	auto Insert_time = watch.GetCostMillisecond();	
	cout<<"Insert sort time: "<<Insert_time<<endl;
	
	return 0;
}
