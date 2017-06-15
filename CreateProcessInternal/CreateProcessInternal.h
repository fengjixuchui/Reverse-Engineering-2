#pragma once
#include <ntbase.h>

//////////////////////////////////////////////////////////////////////////

using fun$BaseFormatObjectAttributes = NTSTATUS(__stdcall *)(
    OBJECT_ATTRIBUTES* aObjectAttributes,
    SECURITY_ATTRIBUTES* aSecurityAttributes,
    UNICODE_STRING* aObjectName);


using fun$BaseIsDosApplication = UINT32(__stdcall *)(
    UNICODE_STRING* PathName,
    NTSTATUS Status);

using fun$BasepProcessInvalidImage = BOOL(__stdcall *)(
    NTSTATUS aStatus,
    HANDLE aToken,
    PCWSTR aDosName,
    PCWSTR *aApplicationName,
    PWSTR *aCommandLine,
    PCWSTR aCurrentDirectory,
    UINT32 *aCreationFlags,
    BOOL *aInheritHandles,
    UNICODE_STRING *aNtPath,
    BOOLEAN *aUnknown,
    void** aEnvironment,
    LPSTARTUPINFOW aStartupInfo,
    struct _BASE_API_MESSAGE *aApiMsg,
    UINT32 *aVdmTask,
    UNICODE_STRING *aVdmCommandLine,
    ANSI_STRING *aAnsiVdmEnvironment,
    UNICODE_STRING *aUnicodeVdmEnvironment,
    UINT32 *aVdmUndoStates,
    UINT32 *aVdmBinaryType,
    BOOL *aVdmValid,
    HANDLE *vVdmWaitHandle);

using fun$BasepCheckWinSaferRestrictions = NTSTATUS(__stdcall *)(
    HANDLE aToken,
    PCWSTR aApplicationName,
    HANDLE aFile,
    UNICODE_STRING *aUnknown);

using fun$BaseGetNamedObjectDirectory = NTSTATUS(__stdcall *)(
    HANDLE* aObjectDirectory);

using fun$RaiseInvalid16BitExeError = void(__stdcall *)(
    UNICODE_STRING* aExePath);

using fun$NtVdm64CreateProcessInternal = BOOL(__stdcall *)(
    HANDLE aToken,
    PCWSTR aApplicationName,
    PWSTR aCommandLine,
    LPSECURITY_ATTRIBUTES aProcessAttributes,
    LPSECURITY_ATTRIBUTES aThreadAttributes,
    BOOL aInheritHandles,
    UINT32 aCreationFlags,
    void* aEnvironment,
    PCWSTR aCurrentDirectory,
    LPSTARTUPINFOW aStartupInfo,
    LPPROCESS_INFORMATION aProcessInformation,
    HANDLE* aNewToken);


//////////////////////////////////////////////////////////////////////////

extern"C" {

    //
    // Kernel32
    //

    void* __stdcall GetProcAddress(void* hModule, PCSTR lpProcName);
    void* __stdcall GetModuleHandleW(PCWSTR lpModuleName);
    UINT32 __stdcall GetLastError(void);
    void __stdcall SetLastError(UINT32 dwErrCode);
    BOOL __stdcall IsProcessInJob(
            HANDLE ProcessHandle,
            HANDLE JobHandle,
            BOOL* Result);
}

//////////////////////////////////////////////////////////////////////////

BOOL CreateProcessInternal(
    HANDLE aToken,
    PCWSTR aApplicationName,
    PWSTR aCommandLine,
    LPSECURITY_ATTRIBUTES aProcessAttributes,
    LPSECURITY_ATTRIBUTES aThreadAttributes,
    BOOL aInheritHandles,
    UINT32 aCreationFlags,
    void* aEnvironment,
    PCWSTR aCurrentDirectory,
    LPSTARTUPINFOW aStartupInfo,
    LPPROCESS_INFORMATION aProcessInformation,
    HANDLE* aNewToken);