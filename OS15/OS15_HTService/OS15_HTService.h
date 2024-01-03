#pragma once
#include <windows.h>
#include <iostream>
#include <fstream>
#include <tchar.h>
#include <string>
#include "sddl.h"

#include "D:/Univer/SP/OS15/OS15_HTCOM_LIB/pch.h"
#include "D:/Univer/SP/OS15/OS15_HTCOM_LIB/OS15_HTCOM_LIB.h"

#define SERVICENAME L"OS15_HTService"
#define HTPATH L"D:/Univer/SP/OS15/x64/Debug/os_15.ht"

#define USERNAME L"HTUser01"
#define PASSWORD L"9900"

#define TRACEPATH L"D:/Univer/SP/OS15/x64/Debug/os_15.trace"

VOID WINAPI ServiceMain(DWORD dwArgc, LPTSTR* lpszArgv);
VOID WINAPI ServiceHandler(DWORD fdwControl);

SECURITY_ATTRIBUTES getSecurityAttributes();
HANDLE createStopEvent(const wchar_t* stopEventName);
void startService();
void trace(const char* msg, int r = std::ofstream::app);
