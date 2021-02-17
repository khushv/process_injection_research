// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <iostream>
#include "custom_Header.h"
#include <stdio.h>
#include <fstream>
#include <Windows.h>


int test(int b) {
    std::cout << "teseting";
    FILE* f_ptr;
    fopen_s(&f_ptr, "C:\\test.txt", "w");
    if (f_ptr == NULL)
    {
        printf("Error!");
        exit(0);
    }
    char write_data[] = "something";
    fwrite(&write_data, 12, 1, f_ptr);
    return 1;
};




/*
When a DLL is first mapped into a process's address space, the system calls the DLL's DllMain function, passing it a value of DLL_PROCESS_ATTACH for the fdwReason parameter. This happens only when the DLL's file image is first mapped. If a thread later calls LoadLibrary(Ex) for a DLL that is already mapped into the process's address space, the operating system simply increments the DLL's usage count; it does not call the DLL's DllMain function again with a value of DLL_PROCESS_ATTACH.
*/
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    WinExec("C:\\Windows\\System32\\calc.exe", 1);
    FILE* f_ptr;
    fopen_s(&f_ptr, "C:\\test.txt", "w");
    return 1;
}


