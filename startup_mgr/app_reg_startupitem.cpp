#include "stdafx.h"
#include "app_reg_startupitem.h"
#include "regedit_key.h"
#include "ifilescanner.h"
#include "configfile_scanner.h"

CAppRegStartupItem::CAppRegStartupItem(void)
{
    m_regKeyValueVec.clear();
    m_regeditKey = new CRegeditKey();
}


CAppRegStartupItem::~CAppRegStartupItem(void)
{
}

/****************************

BOOL CAppRegStartupItem::Init()
{
    
    return TRUE;
}

BOOL CAppRegStartupItem::UnInit()
{
    return TRUE;
}
*********************/

BOOL CAppRegStartupItem::Add(void* p)
{
    if (p == NULL)
    {
        return FALSE;
    }

    RegKeyValue* pTemp = (RegKeyValue*)p;
    HKEY hMainKey = pTemp->regKeyInfo.hMainKey;
    std::wstring str = pTemp->regKeyInfo.strName;
    m_regeditKey->Init(hMainKey, str.c_str());
    m_regeditKey->InsertValue(*pTemp);
    m_regeditKey->UnInit();
    return TRUE;
}

BOOL CAppRegStartupItem::Delete(void* p)
{
    RegKeyValue* pTemp = (RegKeyValue*)p;
    HKEY hMainKey = pTemp->regKeyInfo.hMainKey;
    std::wstring str = pTemp->regKeyInfo.strName;
    m_regeditKey->Init(hMainKey, str.c_str());
    m_regeditKey->DeleteValue(pTemp->strName.c_str());
    m_regeditKey->UnInit();
    return TRUE;
}

BOOL CAppRegStartupItem::Query(std::vector<ResultData* >& resultDataVec)
{
    std::vector<RegKey* >::iterator it;

    CConfigFileScanner fileScanner;
    fileScanner.GetFileContent(m_regKeyVec);

    for (it = m_regKeyVec.begin(); it != m_regKeyVec.end(); it++)
    {
        m_regeditKey->Init((*it)->hMainKey, (*it)->strName.c_str());
        m_regeditKey->QueryValue(m_regKeyValueVec);
        m_regeditKey->UnInit();
    }
    std::vector<RegKeyValue* >::iterator iit;
    for (iit = m_regKeyValueVec.begin(); iit != m_regKeyValueVec.end(); iit++)
    {
        ResultData* pTemp = new ResultData(APP_REG_ITEM, *iit, (WCHAR*)((*iit)->pKeyValue));
        resultDataVec.push_back(pTemp);
    }
    return TRUE;
}