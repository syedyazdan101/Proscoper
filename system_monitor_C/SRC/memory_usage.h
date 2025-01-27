#ifndef MEMORY_USAGE_H
#define MEMORY_USAGE_H

#include <windows.h>
#include <psapi.h>

void get_memory_usage(DWORD processID);

#endif // MEMORY_USAGE_H
