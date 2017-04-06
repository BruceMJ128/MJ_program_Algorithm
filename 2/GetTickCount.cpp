#include<iostream>  
#include<Windows.h>  
  
using namespace std;  
  
int main()  
{  
    DWORD start_time = GetTickCount();  
    for (int i = 0; i < 100000000; i++)  
    {  
        i++;  
    }  
    DWORD end_time = GetTickCount();  
    cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;  
    system("pause");  
    return 0;  
}
