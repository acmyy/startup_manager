#include "stdafx.h"
#include "regedit_key.h"


CRegeditKey::CRegeditKey(void) : m_hKey(NULL)
{
}


CRegeditKey::~CRegeditKey(void)
{
}


BOOL CRegeditKey::Init(HKEY hMainKey, LPCTSTR lpValueName)
{
    DWORD dwOpenOrCreate = 0;
    LONG lReturnValue = ::RegCreateKeyEx(
        hMainKey, lpValueName, 0L, NULL,
        REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS,
        NULL, &m_hKey, &dwOpenOrCreate);

    if (lReturnValue == ERROR_SUCCESS)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

BOOL CRegeditKey::UnInit(DWORD dwOperatorType)
{
    /*std::vector<RegKeyValue * >::iterator it;

    for (it = m_regKeyValueVec.begin(); it != m_regKeyValueVec.end(); it++)
    {
        delete *it;
    }*/

    if (DELETE_CURRENT_KEY == dwOperatorType)
    {
        LONG lReturnValue = ::SHDeleteKey(m_hKey, _T(""));
    }

    RegCloseKey(m_hKey);

    return TRUE;
}

RegKeyValue* CRegeditKey::_EnumRegKeyValue(DWORD dwMaxValueLen, DWORD dwSubKeyValueCount)
{
    TCHAR tcValueName[1024] = { 0 };
    DWORD dwValueNameSize = 128;
    DWORD dwValueType = 0;
    DWORD dwValueSize = 0;
    PBYTE pValueData = new BYTE[dwMaxValueLen];

    for (DWORD dwIndex = 0; dwIndex < dwSubKeyValueCount; dwIndex++)
    {
        dwValueSize = dwMaxValueLen;
        memset(pValueData, 0, dwMaxValueLen);
        ::RegEnumValue(m_hKey, dwIndex, tcValueName, &dwValueNameSize,
            NULL, &dwValueType, pValueData, &dwValueSize);

        dwValueNameSize = 128;
        return new RegKeyValue(
            tcValueName, dwValueType, pValueData, dwValueSize);
    }

    if (pValueData != NULL)
    {
        delete[]pValueData;
    }
    return NULL;
}

BOOL CRegeditKey::InsertValue(RegKeyValue& regKeyValue)
{
    LONG lReturnValue = ::RegSetValueEx(m_hKey, 
                    regKeyValue.strName.c_str(), 
                    0, regKeyValue.dwKeyType, 
                    regKeyValue.pKeyValue, 
                    regKeyValue.dwValueSize);

    if (ERROR_SUCCESS == lReturnValue)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

BOOL CRegeditKey::DeleteValue(LPCTSTR lpValueName)
{
    if (lpValueName == NULL)
    {
        return FALSE;
    }

    ::RegDeleteValue(m_hKey, lpValueName);

    return TRUE;
}

BOOL CRegeditKey::QueryValue(std::vector<RegKeyValue* >& regKeyValue)
{
    DWORD dwSubKeyValueCount = 0;
    DWORD dwMaxValueLen = 0;

    ::RegQueryInfoKey(m_hKey, NULL, NULL, NULL, NULL,
        NULL, NULL, &dwSubKeyValueCount, NULL,
        &dwMaxValueLen, NULL, NULL);

    if (!_EnumRegKeyValue(dwMaxValueLen, dwSubKeyValueCount))
    {
        return FALSE;
    }
    /**********************
    std::vector<RegKeyValue* >::const_iterator it;
    for (it = m_regKeyValueVec.begin(); it != m_regKeyValueVec.end(); it++)
    {
        regKeyValue.push_back(*it);//new RegKeyValue(
            //(*it)->strName.c_str(), (*it)->dwKeyType, 
            //(*it)->pKeyValue, (*it)->dwValueSize));
    }
    *********************/

    return TRUE;
}

BOOL CRegeditKey::GetSubRegKey(std::vector<RegKey* >& regKeyVec)
{
    DWORD dwSubKeyCount;

    ::RegQueryInfoKey(m_hKey, NULL, NULL, NULL, 
                &dwSubKeyCount, NULL ,NULL, NULL, 
                NULL, NULL, NULL, NULL);

    TCHAR tcKeyName[128] = { 0 };
    DWORD dwKeyNameSize = 128;

    for (DWORD dwIndex = 0; dwIndex < dwSubKeyCount; dwIndex++)
    {
        ::RegEnumKeyEx(m_hKey, dwIndex, 
                tcKeyName, &dwKeyNameSize, 
                NULL, NULL, NULL, NULL);
        regKeyVec.push_back(new RegKey(tcKeyName, m_hKey));
        dwKeyNameSize = 128;
    }

    return TRUE;
}
