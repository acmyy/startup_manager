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
#include <map>

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
    DWORD itemType;
    std::wstring strPeFilePath;
    void* test;
    ResultData(){}
    ResultData(DWORD dwType, void* test, TCHAR* strTemp) : 
        itemType(dwType), test(test), strPeFilePath(strTemp)
    {}
};

struct ItemDisData
{
    std::wstring strAppName;
    std::wstring strCompanyName;
    SYSTEMTIME systemTime;
    ItemDisData(){}
};

struct MyRegData
{

};



// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
