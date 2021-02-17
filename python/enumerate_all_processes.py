from ctypes import *

proc_privs = {
	"PROCESS_ALL_ACCESS" : 0x1F0FFF,
	"PROCESS_CREATE_PROCESS" : 0x0080, 
	"PROCESS_CREATE_THREAD": 0x0002, 
	"PROCESS_DUP_HANDLE": 0x0040, 
	"PROCESS_QUERY_INFORMATION": 0x0400, 
	"PROCESS_QUERY_LIMITED_INFORMATION": 0x1000, 
	"PROCESS_SET_INFORMATION": 0x0200, 
	"PROCESS_SET_QUOTA" : 0x0100, 
	"PROCESS_SUSPEND_RESUME" : 0x0800, 
	"PROCESS_TERMINATE" : 0x0001, 
	"PROCESS_VM_OPERATION" : 0x0008, 
	"PROCESS_VM_READ" :0x0010, 
	"PROCESS_VM_WRITE" : 0x0020, 
	"SYNCHRONIZE" : 0x00100000L
	}
	
def open_process(pid):
	priv_array = []
	for priv in proc_privs:
		temp2 = windll.kernel32.OpenProcess(proc_privs[priv], 0, pid)
		if temp2:
			#print("Can open with priv ", priv, " for pid ", pid)
			priv_array.append(priv)	
		#print("Process ", pid, " can access ", len(priv_array), " privs")
	return priv_array
	

def get_process_name(proc):
	ImageFileName = (c_char*260)()
	windll.psapi.GetProcessImageFileNameA(proc, ImageFileName, len(ImageFileName))
	if ImageFileName>0:
		#print("GetProcessImageFileNameA successful")
		#import pdb; pdb.set_trace();
		print("Process at ", ImageFileName.value)
	else:
		print("Error calling GetProcessImageFileNameA")
		print("calling getlasterror")
		print(windll.GetLastError())

	

def get_openable_processes():
	iterated_processes = {}
	for i in range(0, 10000):
		process_tmp = open_process(i)
		if process_tmp:
			get_process_name(i)
			iterated_processes[i] = process_tmp
			#print("PID ", i, " with following privs ", process_tmp)
		#print(iterated_processes[proc])
	return iterated_processes
	

if __name__ == "__main__":	  
	proc_pid =	windll.kernel32.GetCurrentProcessId()
	#print("PID is ", pid)
	
	b = get_openable_processes()
	"""
	for proc in b:
		print("PID ", proc)
		print(get_process_name(proc))
		print("Can open with following privs: ", b[proc])
	"""
	get_process_name(proc_pid)
	#import pdb; pdb.set_trace();
	