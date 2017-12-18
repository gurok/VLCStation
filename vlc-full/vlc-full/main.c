#define _WIN32_WINNT      0x0600
#define _WIN32_IE         0x0600

#define PATH_EXECUTABLE   L"\\vlc.exe"

#define ARGUMENT_DEFAULT  L"-f --play-and-exit --no-random --no-loop --playlist-autostart "

#define SYMBOL_SPACE      L' '
#define SYMBOL_QUOTE      L'"'
#define SYMBOL_TAB        L'\t'

#include <windows.h>
#include "Shlwapi.h"

DWORD CALLBACK EntryPoint(void)
{
	HANDLE    hHeap;
	INT_PTR   uResult;
	PWSTR     pwszCommandLine;
	wchar_t  *lpArgumentList;
	wchar_t   lpPath[MAX_PATH + 1];

	/* Get the arguments from the command line */
	pwszCommandLine = GetCommandLineW();
	if(*pwszCommandLine == SYMBOL_QUOTE)
	{
		++pwszCommandLine;
		while(*pwszCommandLine && *pwszCommandLine++ != SYMBOL_QUOTE);
	}
	else
	{
		while(*++pwszCommandLine && *pwszCommandLine != SYMBOL_SPACE && *pwszCommandLine != SYMBOL_TAB);
		while(*++pwszCommandLine && (*pwszCommandLine == SYMBOL_SPACE || *pwszCommandLine == SYMBOL_TAB));
	}
	/* Get the path to the executable */
	GetModuleFileName(NULL, lpPath, MAX_PATH);
	PathRemoveFileSpec(lpPath);
	wcscat(lpPath, PATH_EXECUTABLE);
	/* Build the argument list */
	hHeap = HeapCreate(0, 0, 0);
	lpArgumentList = (wchar_t *) HeapAlloc(hHeap, 0, sizeof(wchar_t) * wcslen(pwszCommandLine) + sizeof(ARGUMENT_DEFAULT));
	wcscpy(lpArgumentList, ARGUMENT_DEFAULT);
	wcscat(lpArgumentList, (wchar_t *) pwszCommandLine);
	/* Launch the executable */
	uResult = (INT_PTR) ShellExecute(NULL, NULL, lpPath, lpArgumentList, NULL, SW_SHOWNORMAL);
	HeapFree(hHeap, 0, lpArgumentList);
	ExitProcess(uResult);

	return(0);
}
