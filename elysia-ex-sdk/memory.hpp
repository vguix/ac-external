// Memory Header
// 1/27/25 - Date created
// Memory class designed for memory edition/reading efficiently and clean.
// No anti-cheat bypasses have been implemented yet.

#pragma once

#include "Windows.h"
#include "TlHelp32.h"

class Mem 
{
	private:
		LPCWSTR processName;
		DWORD processId;

	public:
		bool write(uintptr_t address, void* buffer) 
		{
			return WriteProcessMemory()
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
					}
				}
			}
		}
};