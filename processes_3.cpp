/// For WinXp as a target, change accordingly

#define _WIN32_WINNT 0x0501

 

#include <windows.h>

#include <stdio.h>

 

int main(void)

{

STARTUPINFO si;

PROCESS_INFORMATION pi;

ZeroMemory(&si, sizeof(si));

si.cb = sizeof(si);

ZeroMemory(&pi, sizeof(pi));

 

// Start the child process.

if (!CreateProcess(TEXT("\"C:\\Windows\\System32\\notepad.exe\""), // module name which is the Windows cmd command

NULL, // Command line.

NULL, // Process handle not inheritable.

NULL, // Thread handle not inheritable.

FALSE, // Set handle inheritance to FALSE.

0, // No creation flags.

NULL, // Use parents environment block.

NULL, // Use parents starting directory.

&si, // Pointer to STARTUPINFO structure.

&pi) // Pointer to PROCESS_INFORMATION structure.

)

printf("\nSorry! CreateProcess() failed.\n\n");

else

printf("\nWell, CreateProcess() looks OK.\n\n");

 

// Wait until child process exits (in milliseconds). If INFINITE, the functions time-out interval never elapses except with user or other intervention.

WaitForSingleObject(pi.hProcess, INFINITE);

printf("\n");

 

// Close process and thread handles.

CloseHandle(pi.hProcess);

CloseHandle(pi.hThread);
return 0;
}
