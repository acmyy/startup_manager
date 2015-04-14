#ifndef PEFILEINFO_HELPER_H
#define PEFILEINFO_HELPER_H
#pragma once

#define READ_SUCCESS      0x00//获取成功
#define READ_ERROR        0x01//获取失败
#define READ_INVALID_INIT 0x02//错误的初始化导致的，失败
#define READ_HEAP_REEO    0x03//内部的new操作挂掉导致的

#define CompanyName         _T("CompanyName")
#define FileDescription     "FileDescription"
#define ProductName         _T("ProductName")
#define ProductVersion      "ProductVersion"

typedef DWORD(__stdcall*pfnGetFileVersionInfoSize)(LPCTSTR, LPDWORD);
typedef BOOL(__stdcall*pfnGetFileVersionInfo)(LPCTSTR, DWORD, DWORD, LPVOID);
typedef BOOL(__stdcall*pfnVerQueryValue)(const LPVOID, LPCTSTR, LPVOID*, PUINT);

typedef std::map<std::wstring, std::wstring> PEFILEVERSION_INFO;

typedef PEFILEVERSION_INFO::iterator  PEFILEVERSION_INFO_IT;

typedef struct LANGANDCODEPAGE
{
    WORD wLanguage;
    WORD wCodePage;
}*LPLANGANDCODEPAGE;

class CPEFileInfoHelper
{
public:
    CPEFileInfoHelper(void);
    ~CPEFileInfoHelper(void);

public:
    DWORD GetPEFileInfo(const WCHAR* lptPath, PEFILEVERSION_INFO& peInfo);

protected:
    BOOL InitInterFace();

protected:
    HMODULE m_hVersionMod;
    pfnGetFileVersionInfoSize PEGetFileVersionInfoSize;
    pfnGetFileVersionInfo PEGetFileVersionInfo;
    pfnVerQueryValue PEVerQueryValue;
};
#endif
