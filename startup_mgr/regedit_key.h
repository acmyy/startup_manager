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
    BOOL QueryValue(std::vector<const RegKeyValue* >& regKeyValue);
    BOOL GetSubRegKey();

private:
    HKEY m_hKey;
    std::vector<RegKeyValue* > m_regKeyValueVec;
};
#endif

