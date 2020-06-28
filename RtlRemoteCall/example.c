#include <Windows.h>
#pragma comment(lib,"ntdll.lib")
extern "C" {
     NTSTATUS NTAPI
        RtlRemoteCall(
            HANDLE Process,
            HANDLE Thread,
            PVOID CallSite,
            ULONG ArgumentCount,
            PULONG_PTR Arguments,
            BOOLEAN PassContext,
            BOOLEAN AlreadySuspended
        );
}
VOID test(void) {
    LoadLibraryA("msgbox.dll");
    
}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow) {
  
    HANDLE hthread = CreateThread(NULL, NULL, 0, 0, 0x1, 0);
  
    NTSTATUS nt_stat=RtlRemoteCall(GetCurrentProcess(), hthread, &test, 0, NULL, FALSE,FALSE);
    ResumeThread(hthread);
    return 0;
}
