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



// TODO: 在此处引用程序需要的其他头文件
