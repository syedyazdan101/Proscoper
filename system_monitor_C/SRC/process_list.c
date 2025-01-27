
#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>

void list_processes() {
    HANDLE hProcessSnap;
    PROCESSENTRY32 pe32;

    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcessSnap == INVALID_HANDLE_VALUE) {
        printf("Failed to take a snapshot of processes.\n");
        return;
    }

    pe32.dwSize = sizeof(PROCESSENTRY32);

    if (Process32First(hProcessSnap, &pe32)) {
        do {
            printf("Process ID: %1lu\n", pe32.th32ProcessID);
            printf("Process Name: %s\n", pe32.szExeFile);
            printf("----------------------------\n");
        } while (Process32Next(hProcessSnap, &pe32));
    } else {
        printf("Failed to retrieve process information.\n");
    }

    CloseHandle(hProcessSnap);
}

