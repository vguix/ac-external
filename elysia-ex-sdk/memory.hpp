#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <Windows.h>
#include <TlHelp32.h>
#include <string>

class Mem
{
private:
    LPCWSTR processName;
    DWORD processId;
    HANDLE process;

public:
    bool write(uintptr_t address, void* buffer, size_t size)
    {
        return WriteProcessMemory(process, (LPVOID)address, buffer, size, NULL);
    }

    bool read(uintptr_t address, void* buffer, size_t size)
    {
        return ReadProcessMemory(process, (LPCVOID)address, buffer, size, NULL);
    }

    bool validityCheck() {
        return process != NULL;
    }

    DWORD getPid() {
        return processId;
    }

    Mem(LPCWSTR processName)
    {
        HANDLE processSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        if (processSnap == INVALID_HANDLE_VALUE) { return; }

        PROCESSENTRY32W procEntry;
        procEntry.dwSize = sizeof(PROCESSENTRY32W);
        if (Process32FirstW(processSnap, &procEntry)) {
            do {
                if (wcscmp(processName, procEntry.szExeFile) == 0) {
                    processId = procEntry.th32ProcessID;
                    process = OpenProcess(PROCESS_ALL_ACCESS, 0, processId);
                    break;
                }
            } while (Process32NextW(processSnap, &procEntry));
        }
        CloseHandle(processSnap);
    }

    ~Mem() {
        if (process != NULL) {
            CloseHandle(process);
        }
    }
};

#endif