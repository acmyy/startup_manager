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
    BOOL InsertValue(RegKeyValue& regKeyValue, DWORD dwKeyValueSize);
    BOOL DeleteValue(LPCTSTR lpValueName);
    BOOL QueryValue(std::vector<const RegKeyValue* >& regKeyValueVec);
    BOOL GetSubRegKey(std::vector<RegKey* >& regKeyVec);

private:
    BOOL _EnumRegKeyValue(DWORD dwMaxValueLen, DWORD dwSubKeyValueCount);

private:
    HKEY m_hKey;
    std::vector<RegKeyValue* > m_regKeyValueVec;
};
#endif

