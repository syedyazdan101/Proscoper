
#include <windows.h>
#include <stdio.h>

void terminate_process(DWORD processID) {
    HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, processID);
    if (hProcess == NULL) {
        printf("Could not open process %1lu for termination.\n", processID);
        return;
    }

    if (TerminateProcess(hProcess, 0)) {
        printf("Process %1lu terminated successfully.\n", processID);
    } else {
        printf("Failed to terminate process %1lu.\n", processID);
    }

    CloseHandle(hProcess);
}

