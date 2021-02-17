// basic_functions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <libloaderapi.h>
#include <stdio.h>

#include <winnt.h>
#include <tchar.h> // for tchar printing
#include <psapi.h> // for process management api function calls

int PrintModules2(DWORD processID)
{
    HMODULE hMods[1024];
    HANDLE hProcess;
    DWORD cbNeeded;
    unsigned int i;


    // Print the process identifier.

    printf("\nProcess ID: %u\n", processID);

    // Get a handle to the process.

    hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
        PROCESS_VM_READ,
        FALSE, processID);
    if (NULL == hProcess)
        return 1;

    // Get a list of all the modules in this process.

    if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
        std::cout << "size of hmods is " << sizeof(hMods);
        std::cout << "\nvalue of cbNeeded is" << cbNeeded;
    {
        for (i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
        {
            TCHAR szModName[MAX_PATH];

            // Get the full path to the module's file.
            
            if (GetModuleFileName(hMods[i], szModName, sizeof(szModName) / sizeof(TCHAR)))
            {
                // Print the module name and handle value.

                _tprintf(TEXT("\t%s (0x%08X)\n"), szModName, hMods[i]);
            }
        }
    }

    // Release the handle to the process.

    CloseHandle(hProcess);

    return 0;
}


int main()
{
    std::cout << "Hello World!\n";
    HINSTANCE my_hinstance;
    my_hinstance = LoadLibrary(TEXT("msf.dll"));
    std::cout << my_hinstance << "\n";

    if (my_hinstance != NULL) {
        std::cout << "does not appear null\n";
    }
    else {
        std::cout << "Could not load msf.dll\n";
        std::cout << GetLastError();
    }

    //std::cout << "attempting to list all modules loaded\n";
    int pid = GetCurrentProcessId();
    //PrintModules2(pid);

    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
        PROCESS_VM_READ, FALSE, pid);

    HANDLE token_handle;
    DWORD buffer, dwSize = 1024;

    //pGroupInfo = (PTOKEN_GROUPS)GlobalAlloc(GPTR, dwSize);
    TOKEN_INFORMATION_CLASS TOKEN_USER;

    if (OpenProcessToken(hProcess, TOKEN_QUERY, &token_handle)) {
        std::cout << "Opened process token\n" << "getting security token info\n";

        if (!GetTokenInformation(token_handle, TOKEN_USER, NULL, dwSize, &dwSize)) {
            DWORD dwResult = GetLastError();
            if (dwResult != ERROR_INSUFFICIENT_BUFFER) {
                printf("GetTokenInformation Error %u\n", dwResult);
                return FALSE;
            }
            std::cout << "got token information\n";
            printf("dwSize located at %p", dwSize);
        }





    }


}
/*
TOKEN_ADJUST_DEFAULT 	Required to change the default owner, primary group, or DACL of an access token.
TOKEN_ADJUST_GROUPS 	Required to adjust the attributes of the groups in an access token.
TOKEN_ADJUST_PRIVILEGES 	Required to enable or disable the privileges in an access token.
TOKEN_ADJUST_SESSIONID 	Required to adjust the session ID of an access token.The SE_TCB_NAME privilege is required.
TOKEN_ASSIGN_PRIMARY 	Required to attach a primary token to a process.The SE_ASSIGNPRIMARYTOKEN_NAME privilege is also required to accomplish this task.
TOKEN_DUPLICATE 	Required to duplicate an access token.
TOKEN_EXECUTE 	Combines STANDARD_RIGHTS_EXECUTE and TOKEN_IMPERSONATE.
TOKEN_IMPERSONATE 	Required to attach an impersonation access token to a process.
TOKEN_QUERY 	Required to query an access token.
TOKEN_QUERY_SOURCE 	Required to query the source of an access token.
TOKEN_READ 	Combines STANDARD_RIGHTS_READ and TOKEN_QUERY.
TOKEN_WRITE 	Combines STANDARD_RIGHTS_WRITE, TOKEN_ADJUST_PRIVILEGES, TOKEN_ADJUST_GROUPS, and TOKEN_ADJUST_DEFAULT.
TOKEN_ALL_ACCESS 	Combines all possible access rights for a token.
*/