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
#include <string>
#include <Shlwapi.h>
#include <map>

#pragma comment(lib,"shlwapi.lib")

#define DELETE_CURRENT_KEY 1


#define APP_REG_ITEM 1
#define APP_MENU_ITEM 2
#define SERVICE_REG_ITEM 3

struct RegKey
{
    std::wstring strName;
    HKEY hMainKey;
    RegKey(){}
    RegKey(TCHAR* strTemp, HKEY hKey) :
        strName(strTemp), hMainKey(hKey)
    {}
};


struct RegKeyValue
{
    std::wstring strName;
    DWORD dwKeyType;
    DWORD dwValueSize;
    PBYTE pKeyValue;
    RegKey regKeyInfo;
    RegKeyValue(){}

    RegKeyValue(TCHAR* strTempName, DWORD dwTempKeyType,
            PBYTE pTempKeyValue, DWORD dwTempValueSize) : strName(strTempName), 
            dwKeyType(dwTempKeyType), dwValueSize(dwTempValueSize)
    {
        //pKeyValue = pTempKeyValue;
        pKeyValue = new BYTE[dwTempValueSize];
        for (DWORD dwIndex = 0; dwIndex < dwValueSize; dwIndex++)
        {
            pKeyValue[dwIndex] = pTempKeyValue[dwIndex];
        }
    }
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

struct PEFileInfoData
{
    std::wstring strAppName;
    std::wstring strCompanyName;
    SYSTEMTIME systemTime;
    PEFileInfoData(){}
};

struct AppRegItemData
{
    std::wstring strName;
    HKEY hMainKey;
    AppRegItemData(){}
    AppRegItemData(TCHAR* strTemp, HKEY hKey) :
        strName(strTemp), hMainKey(hKey)
    {}
};


// TODO: 在此处引用程序需要的其他头文件
