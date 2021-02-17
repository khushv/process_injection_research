from ctypes import *

def get_access_token(pid):
	PROCESS_QUERY_INFORMATION = 0x040
	this_handle = windll.kernel32.OpenProcess(PROCESS_QUERY_INFORMATION, 0, pid)
	return this_handle


if __name__ == "__main__":

    LPVOID = c_void_p
    PVOID = LPVOID
    PSID = PVOID
    DWORD = c_uint32

    class SID_AND_ATTRIBUTES(Structure):
        _fields_ = [
            ("Sid",         PSID),
            ("Attributes",  DWORD),
    ]

    class TOKEN_USER(Structure):
        _fields_ = [
            ("User", SID_AND_ATTRIBUTES),]

tokenprivs = (winappdbg.win32.TOKEN_QUERY | winappdbg.win32.TOKEN_READ | winappdbg.win32.TOKEN_IMPERSONATE | winappdbg.win32.TOKEN_QUERY_SOURCE | winappdbg.win32.TOKEN_DUPLICATE | winappdbg.win32.TOKEN_ASSIGN_PRIMARY)
hProcess = winappdbg.win32.OpenProcess(winappdbg.win32.PROCESS_QUERY_INFORMATION, False, winappdbg.win32.GetCurrentProcessId())
hToken = winappdbg.win32.OpenProcessToken(hProcess, DesiredAccess = tokenprivs)

dwSize = DWORD(0)
pStringSid = winappdbg.win32.LPSTR()

windll.advapi32.GetTokenInformation(hToken, winappdbg.win32.TokenUser, None, 0, byref(dwSize))

address = windll.kernel32.LocalAlloc(0x0040, dwSize)
print "Address: " + str(address)

windll.advapi32.GetTokenInformation(hToken, winappdbg.win32.TokenUser, address, dwSize, byref(dwSize))
print FormatError(GetLastError())

pToken_User = cast(address, POINTER(TOKEN_USER))

windll.advapi32.ConvertSidToStri
  
	pid =  windll.kernel32.GetCurrentProcessId()
	print("PID is %d", pid)
	a = get_access_token(pid)
	print("Handle to access token %d", a)
    