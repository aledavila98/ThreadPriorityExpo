#include <windows.h>
#include <tchar.h>

int main(void)
{
    DWORD dwError, dwThreadPri;

    if (!SetThreadPriority(GetCurrentThread(), THREAD_MODE_BACKGROUND_BEGIN))
    {
        dwError = GetLastError();
        if (ERROR_THREAD_MODE_ALREADY_BACKGROUND == dwError)
            _tprintf(TEXT("Already in background mode\n"));
        else _tprintf(TEXT("Failed to enter background mode (%d)\n"), dwError);
        goto Cleanup;
    }

    // Display thread priority

    dwThreadPri = GetThreadPriority(GetCurrentThread());

    _tprintf(TEXT("Current thread priority is 0x%x\n"), dwThreadPri);

    //
    // Perform background work
    //
    ;

    if (!SetThreadPriority(GetCurrentThread(), THREAD_MODE_BACKGROUND_END))
    {
        _tprintf(TEXT("Failed to end background mode (%d)\n"), GetLastError());
    }

Cleanup:
    // Clean up
    ;
    return 0;
}