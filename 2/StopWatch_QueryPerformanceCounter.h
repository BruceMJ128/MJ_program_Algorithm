#pragma once  
#include<Windows.h> 
#include<iostream>
//#include "StdAfx.h"  
//#include "StopWatch.h"  

///������ø߷ֱ��ʸ����ܼ�����ʵ��  
///���ҵ�Intel T7500�����ϣ��ֱ��ʴ�Լ��279��΢��  
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
	    LARGE_INTEGER  frequency;//�����ܼ�������Ƶ�ʣ�ÿ��357,9545��tick  �ҵ�INTEL T7500
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
    unsigned long long cost=(unsigned long long)(endticks.QuadPart-beginticks.QuadPart);  //��¼��������ʱ���֮���ticks���� 
    double millsecond=(double)cost*1000.0/(double)frequency.QuadPart;   //��ticks�������� Ƶ�ʵĵ��� ���õ�ʱ�� 
    return millsecond;  
}  
unsigned long long StopWatch::GetFrequency()  
{  
    return (unsigned long long)frequency.QuadPart;  //��� ticksƵ�ʵĵ���������Ϊ2533339����˼Ϊÿ��tick��ʱ��Ϊ 1/2533339 s 
}


