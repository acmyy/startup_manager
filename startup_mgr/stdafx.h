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
#include <string>
#include <Shlwapi.h>

#pragma comment(lib,"shlwapi.lib")


#define DELETE_CURRENT_KEY 1

struct RegKeyValue
{
    std::wstring strName;
    DWORD dwKeyType;
    PBYTE pKeyValue;
    RegKeyValue(){}

    RegKeyValue(TCHAR* strTempName,
        DWORD dwTempKeyType, PBYTE pTempKeyValue
        ) :strName(strTempName), dwKeyType(dwTempKeyType),
        pKeyValue(pTempKeyValue){}
};

struct RegKey
{
    std::wstring strName;
    HKEY hMainKey;
    RegKey(){}
    RegKey(TCHAR* strTemp, HKEY hKey) :
        strName(strTemp), hMainKey(hKey)
    {}
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
