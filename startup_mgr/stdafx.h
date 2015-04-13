// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <vector>
#include <iostream>
#include <Shlwapi.h>

#pragma comment(lib,"shlwapi.lib")


#define DELETE_CURRENT_KEY 1

struct RegKeyValue
{
	std::wstring strName;
	DWORD dwKeyType;
	std::wstring dwKeyValue;
	RegKeyValue(){}

	RegKeyValue(TCHAR* strTempName,
		DWORD dwTempKeyType, TCHAR* dwTempKeyValue
		) :strName(strTempName), dwKeyType(dwTempKeyType),
		dwKeyValue(dwTempKeyValue){}
};

struct RegKey
{
	std::wstring strName;
	HKEY hMainKey;
};


struct ResultData
{
	std::wstring strAppName;
	std::wstring strCompanyName;
	SYSTEMTIME systemTime;
	std::wstring strKeyName;

	ResultData()
	{
		strAppName = L"";
		strCompanyName = L"";
		strKeyName = L"";
	}
};

struct MyRegData
{
	std::wstring strKeyName;
	DWORD dwKeyType;
	std::wstring strKeyValue;
	HKEY hMainKey;
	std::wstring strKeyPath;
	DWORD startType;

	MyRegData(){}

	MyRegData(std::wstring strTempName,
		DWORD dwTempKeyType, std::wstring strTempKeyValue
		) :strKeyName(strTempName), dwKeyType(dwTempKeyType),
		strKeyValue(strTempKeyValue){}
};



// TODO: 在此处引用程序需要的其他头文件
