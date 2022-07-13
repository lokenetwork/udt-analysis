// lock.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
HANDLE m_AcceptLock = CreateMutex(NULL, false, NULL);

DWORD WINAPI do_job(LPVOID data)
{
    WaitForSingleObject(m_AcceptLock, INFINITE);
    for (int i = 0; i < 10; i++) {
        std::cout << i << " \n";
    }

    return 0;
}
int main()
{
    
    //HANDLE m_AcceptCond = CreateEvent(NULL, false, false, NULL);
    CreateThread(NULL, 0, do_job, NULL, 0, NULL);
    CreateThread(NULL, 0, do_job, NULL, 0, NULL);
    Sleep(10000);

    std::cout << "end end!\n";
}

