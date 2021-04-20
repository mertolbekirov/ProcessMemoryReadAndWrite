// ReaderAndWriterOfMemory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <string>
#include <tchar.h>
#include <Psapi.h>

uintptr_t GetModuleBaseAddress(DWORD procId, const wchar_t* modName)
{
	uintptr_t modBaseAddr = 0;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);
	if (hSnap != INVALID_HANDLE_VALUE)
	{
		MODULEENTRY32 modEntry;
		modEntry.dwSize = sizeof(modEntry);
		if (Module32First(hSnap, &modEntry))
		{
			do
			{
				if (!_wcsicmp(modEntry.szModule, modName))
				{
					modBaseAddr = (uintptr_t)modEntry.modBaseAddr;
					break;
				}
			} while (Module32Next(hSnap, &modEntry));
		}
	}
	CloseHandle(hSnap);
	return modBaseAddr;
}


DWORD GetConsoleProcessId() {
	DWORD procId;
	HWND hwnd = FindWindow(NULL, _T("ConsoleAppToMessWIth"));
	GetWindowThreadProcessId(hwnd, &procId);
	//CloseHandle(hwnd);
	return procId;
}



int main()
{
	uintptr_t BaseAddress(NULL);
	DWORD procId = GetConsoleProcessId();
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procId);

	if (hProcess == NULL)
	{
		std::cout << "OpenProcess failed. GetLastError = " << std::dec << GetLastError() << std::endl;
		system("pause");
		return EXIT_FAILURE;
	}
	int intRead = 0;
	SIZE_T bytesRead = 0;

	BaseAddress = GetModuleBaseAddress(procId, _T("ConsoleAppToMessWith.exe"));
	DWORD intReadAddress = BaseAddress + 0x5018;
	std::cout << (LPCVOID)intReadAddress << std::endl;
	BOOL rpmReturn = ReadProcessMemory(hProcess, (LPCVOID)intReadAddress, &intRead, sizeof(int), NULL);
	if (rpmReturn == FALSE)
	{
		std::cout << "ReadProcessMemory failed. GetLastError = " << std::dec << GetLastError() << std::endl;
		system("pause");
		return EXIT_FAILURE;
	}
	std::cout << intRead << std::endl;

	return 0;
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
