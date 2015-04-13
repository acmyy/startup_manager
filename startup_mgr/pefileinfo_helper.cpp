#include "stdafx.h"
#include "pefileinfo_helper.h"
#include <xstring>
#include <comdef.h>

CPEFileInfoHelper::CPEFileInfoHelper(void)
{
    m_hVersionMod = 0;
    PEGetFileVersionInfoSize = NULL;
    PEGetFileVersionInfo = NULL;
    PEVerQueryValue = NULL;
    InitInterFace();
}


CPEFileInfoHelper::~CPEFileInfoHelper(void)
{
    if (m_hVersionMod)
    {
        FreeLibrary(m_hVersionMod);
    }
}

BOOL CPEFileInfoHelper::InitInterFace()
{
    m_hVersionMod = LoadLibraryA("version.dll");

    if (!m_hVersionMod)
    {
        return FALSE;
    }

    PEGetFileVersionInfoSize = (pfnGetFileVersionInfoSize)GetProcAddress(
        m_hVersionMod, "GetFileVersionInfoSizeW");
    PEGetFileVersionInfo = (pfnGetFileVersionInfo)GetProcAddress(\
        m_hVersionMod, "GetFileVersionInfo");
    PEVerQueryValue = (pfnVerQueryValue)GetProcAddress(
        m_hVersionMod, "VerQueryValue");

    if (!PEGetFileVersionInfoSize ||
        !PEGetFileVersionInfo ||
        !PEVerQueryValue)
    {
        FreeLibrary(m_hVersionMod);
        m_hVersionMod = 0;
        return FALSE;
    }

    return TRUE;
}

DWORD CPEFileInfoHelper::GetPEFileInfo(TCHAR* lptPath, PEFILEVERSION_INFO& peInfo)
{
    if (m_hVersionMod == 0)
    {
        return READ_INVALID_INIT;
    }

    DWORD dwHandle = 0;
    DWORD dwInfoSize = 0;
    TCHAR* lpVersionInfoBuffer = NULL;


    dwInfoSize = PEGetFileVersionInfoSize(lptPath, &dwHandle);


    if (dwInfoSize <= 0)
    {
        return READ_ERROR;
    }

    lpVersionInfoBuffer = new TCHAR[dwInfoSize];


    if (!lpVersionInfoBuffer)
    {
        return READ_HEAP_REEO;
    }


    if (!PEGetFileVersionInfo(lptPath, 0,
        dwInfoSize, lpVersionInfoBuffer))
    {
        delete lpVersionInfoBuffer;
        return READ_ERROR;
    }

    LPLANGANDCODEPAGE lpTranslate = NULL;
    UINT cbTranslate = 0;

    if (!PEVerQueryValue(lpVersionInfoBuffer,
        _T("\\VarFileInfo\\Translation"),
        (void**)&lpTranslate, &cbTranslate) ||
        (cbTranslate / sizeof(struct LANGANDCODEPAGE)) == 0)
    {
        delete lpVersionInfoBuffer;
        return READ_ERROR;
    }


    TCHAR *lpBuffer = 0;
    UINT cbSizeBuf = 0;
    TCHAR szSubBlock[50];
    PEFILEVERSION_INFO_IT it;
    std::wstring szPerfix = _T("\\StringFileInfo\\%04x%04x\\");

    for (it = peInfo.begin(); it != peInfo.end(); it++)
    {
        wsprintf(szSubBlock,
            (szPerfix + it->first).c_str(),
            lpTranslate[0].wLanguage, lpTranslate[0].wCodePage);

        if (PEVerQueryValue(lpVersionInfoBuffer,
            szSubBlock, (void**)&lpBuffer, &cbSizeBuf))
        {
            it->second = lpBuffer;
        }
    }

    delete[]lpVersionInfoBuffer;
    return READ_SUCCESS;
}

