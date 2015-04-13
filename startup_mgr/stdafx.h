// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
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



// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
