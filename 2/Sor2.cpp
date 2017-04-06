#include <iostream> 
#include <vector>
#include <ctime>
#include <random>
#include "SortAlgo.h"
#include "random_vector.h"
#include "StopWatch_QueryPerformanceCounter.h"
#include "SortAlgo2.h"
#include <string>

int main()
{
	string sortmode;	
	vector<int> vec = random_vector(2000, 0, 10000);	
	SortAlgo2 SA2;	
	cout<<"Input sortmode:"<<endl;
	
	while(cin>>sortmode)
	{	
		if(sortmode == "Shell")
		{
			cout<<"Input Shell sort gap factor:"<<endl;
			int h;
			cin>>h;
			SA2.Shell_gapfactor(h);
		}
		SA2.set_vector(vec, sortmode);
		SA2.Sort_time();
		
		cout<<"Input sortmode:"<<endl;
	}
	return 0;
}
