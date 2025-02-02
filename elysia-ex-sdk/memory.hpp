// Memory Header
// 1/27/25 - Date created
// Memory class designed for memory edition/reading efficiently and clean.
// No anti-cheat bypasses have been implemented yet.

#include "Windows.h"
#include "TlHelp32.h"

#ifndef MEMORY_HPP
#define MEMORY_HPP

class Mem 
{
	private:
		LPCWSTR processName;
		DWORD processId;
		HANDLE process;

	public:
		bool write(uintptr_t address, void* buffer, size_t size) 
		{
			return WriteProcessMemory(process, (LPVOID)address, buffer, sizeof(address), NULL);
		}

		bool read(uintptr_t address, void* buffer, size_t size)
		{
			return ReadProcessMemory(process, (LPCVOID)address, buffer, sizeof(address), NULL);
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
				while (Process32NextW(processSnap, &procEntry)) {
					if (wcscmp(processName, procEntry.szExeFile) == 0) {
						processId = procEntry.th32ProcessID;
						process = OpenProcess(PROCESS_ALL_ACCESS, 0, processId);
					}
				}
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