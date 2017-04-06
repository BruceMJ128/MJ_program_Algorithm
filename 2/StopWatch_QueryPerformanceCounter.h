#pragma once  
#include<Windows.h> 
#include<iostream>
//#include "StdAfx.h"  
//#include "StopWatch.h"  

///本类采用高分辨率高性能计数器实现  
///在我的Intel T7500机器上，分辨率大约是279毫微秒  
class StopWatch
{  
	public:  
	    StopWatch(void);  
	    ~StopWatch(void);
		void Start();
	    void Stop();  
	    double  GetCostMillisecond();  
	    unsigned long long  GetFrequency();
	    
	private:  
	    LARGE_INTEGER beginticks;  
	    LARGE_INTEGER endticks ;
	    LARGE_INTEGER  frequency;//高性能计数器的频率：每秒357,9545个tick  我的INTEL T7500
};  


using namespace std;  
StopWatch::StopWatch(void)  
{  
    beginticks.QuadPart=0;  
    endticks.QuadPart=0;  
    frequency.QuadPart=0;  
    QueryPerformanceFrequency(&frequency);  
}  
  
StopWatch::~StopWatch(void)  
{  
}  
void StopWatch::Start()  
{  
    //beginticks=GetTickCount();  
    QueryPerformanceCounter(&beginticks);  
      
}  
void StopWatch::Stop()  
{  
    QueryPerformanceCounter(&endticks);  
      
}  

double  StopWatch::GetCostMillisecond()  
{  
    unsigned long long cost=(unsigned long long)(endticks.QuadPart-beginticks.QuadPart);  //记录的是两个时间点之间的ticks次数 
    double millsecond=(double)cost*1000.0/(double)frequency.QuadPart;   //用ticks次数除以 频率的倒数 ，得到时间 
    return millsecond;  
}  
unsigned long long StopWatch::GetFrequency()  
{  
    return (unsigned long long)frequency.QuadPart;  //结果 ticks频率的倒数，本机为2533339，意思为每个tick的时间为 1/2533339 s 
}


