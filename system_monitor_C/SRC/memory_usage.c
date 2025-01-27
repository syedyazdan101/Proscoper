#include <windows.h>
#include <psapi.h>
#include <stdio.h>

void get_memory_usage(DWORD processID) {
    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);
    if (hProcess == NULL) {
        printf("Could not open process %lu.\n", processID);
        return;
    }

    PROCESS_MEMORY_COUNTERS pmc;
    if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc))) {
        printf("Process ID: %lu\n", processID);
        printf("Memory Usage: %llu KB\n", pmc.WorkingSetSize / 1024);
    } else {
        printf("Could not retrieve memory info for process %lu.\n", processID);
    }

    CloseHandle(hProcess);
}

