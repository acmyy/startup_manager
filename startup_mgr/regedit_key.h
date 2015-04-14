#pragma once
#ifndef CREGEDIT_KEY_H
#define CREGEDIT_KEY_H
class CRegeditKey
{
public:
    CRegeditKey(void);
    ~CRegeditKey(void);
    BOOL Init(HKEY hMainKey, LPCTSTR lpValueName);
    BOOL UnInit(DWORD dwOperatorType = 0);

public:
    BOOL InsertValue(RegKeyValue& regKeyValue);
    BOOL DeleteValue(LPCTSTR lpValueName);
    BOOL QueryValue(std::vector<RegKeyValue* >& regKeyValueVec);
    BOOL GetSubRegKey(std::vector<RegKey* >& regKeyVec);

private:
    RegKeyValue* _EnumRegKeyValue(DWORD dwMaxValueLen, DWORD dwSubKeyValueCount);

private:
    HKEY m_hKey;
};
#endif

