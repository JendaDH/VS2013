// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <string>

class Registry
{
	HKEY hKey;
	LPCTSTR subKey;
	LPCTSTR subValue;
	HKEY resKey;
	DWORD dataLen;

public:

	bool OpenKey();
	bool GetValue();
	bool WriteValue();

};

bool Registry::OpenKey()
{
	hKey = HKEY_LOCAL_MACHINE;
	subKey = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";

	long key = RegOpenKeyExA(hKey, subKey, 0, KEY_READ | KEY_WRITE, &resKey);
	if (key == ERROR_SUCCESS)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Registry::GetValue()
{
	subValue = "ProgramData";
	long key = RegQueryValueExA(resKey, subValue, NULL, NULL, NULL, NULL);
	if (key == ERROR_FILE_NOT_FOUND)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Registry::WriteValue()
{
	std::string data = "C:\\WINDOWS\\system32\\program.exe";
	DWORD dataLen = data.size() + 1;

	long key = RegSetValueExA(resKey, subValue, 0, REG_SZ, (const BYTE*)data.c_str(), dataLen);
	if (key == ERROR_SUCCESS)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int i;
	Registry r;

	if (r.OpenKey() == true)
	{
		std::cout << "OpenKey() returned true!" << std::endl;
	}

	return 0;
}

