#include <windows.h>
#include <tchar.h>

int main(void)
{
    DWORD dwError, dwPriClass;

    if (!SetPriorityClass(GetCurrentProcess(), PROCESS_MODE_BACKGROUND_BEGIN))
    {
        dwError = GetLastError();
        if (ERROR_PROCESS_MODE_ALREADY_BACKGROUND == dwError)
            _tprintf(TEXT("Already in background mode\n"));
        else _tprintf(TEXT("Failed to enter background mode (%d)\n"), dwError);
        goto Cleanup;
    }

    // Display priority class

    dwPriClass = GetPriorityClass(GetCurrentProcess());

    _tprintf(TEXT("Current priority class is 0x%x\n"), dwPriClass);

    //
    // Perform background work
    //
    ;

    if (!SetPriorityClass(GetCurrentProcess(), PROCESS_MODE_BACKGROUND_END))
    {
        _tprintf(TEXT("Failed to end background mode (%d)\n"), GetLastError());
    }

Cleanup:
    // Clean up
    ;
    return 0;
}