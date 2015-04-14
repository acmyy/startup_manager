#include "stdafx.h"
#include "startupitem_mgr.h"
#include "item_factory.h"
#include "istartupitem.h"
#include "pefileinfo_helper.h"

CStartupItemManager::CStartupItemManager()
{
    m_itemFactory = new CItemFactory();
    m_pefileinfoHelper = new CPEFileInfoHelper();
    m_startupItem = NULL;
    m_resultDataVec.clear();
}


CStartupItemManager::~CStartupItemManager()
{
    std::vector<ResultData* >::iterator itResult;

    for (itResult = m_resultDataVec.begin();
        itResult != m_resultDataVec.end(); itResult++)
    {
        if (*itResult != NULL)
        {
            delete *itResult;
        }
    }

    if (m_itemFactory != NULL)
    {
        delete m_itemFactory;
    }

    if (m_pefileinfoHelper != NULL)
    {
        delete m_pefileinfoHelper;
    }

    if (m_startupItem != NULL)
    {
        delete m_startupItem;
    }
}

/***********************
BOOL CStartupItemManager::Init()
{
    return TRUE;
}

BOOL CStartupItemManager::UnInit()
{
    return TRUE;
}
************************/

PEFileInfoData* CStartupItemManager::_GetPEFileInfo(ResultData& resultData)
{
    PEFILEVERSION_INFO peinfo;
    std::wstring strTemp;
   
    peinfo[ProductName] = L"";
    peinfo[CompanyName] = L"";

    if (!_GetKeyValue(resultData.strPeFilePath, strTemp))
    {
        return NULL;
    }
    m_pefileinfoHelper->GetPEFileInfo(strTemp.c_str(), peinfo);

    PEFileInfoData* pTemp = new PEFileInfoData();
    if (pTemp == NULL)
    {
        return NULL;
    }

    PEFILEVERSION_INFO_IT it;
    for (it = peinfo.begin(); it != peinfo.end(); it++)
    {
        if (it->first == ProductName)
        {
            if (it->second == _T(""))
            {
                it->second = L"UnKnow";
            }
            pTemp->strAppName = it->second;
        }
        else if (it->first == CompanyName)
        {
            if (it->second == L"")
            {
                it->second = L"UnKnow";
            }
            pTemp->strCompanyName = it->second;
        }
    }
    peinfo.clear();

    return pTemp;
}

BOOL CStartupItemManager::_GetKeyValue(const std::wstring& strTemp, std::wstring& str)
{
    if (strTemp[0] == L'"')
    {
        int nCnt = 0;
        for (int nIndex = 1; nIndex < strTemp.size(); nIndex++)
        {
            if (strTemp[nIndex] == L'"')
                break;
            str += strTemp[nIndex];
        }
    }
    return TRUE;
}

BOOL CStartupItemManager::GetStartupItem(std::vector<PEFileInfoData* >& itemDisData)
{
    for (DWORD dwIndex = 1; dwIndex <= 3; dwIndex++)
    {
        m_startupItem = m_itemFactory->Create(dwIndex);
        m_startupItem->Query(m_resultDataVec);
        delete m_startupItem;
    }

    std::vector<ResultData* >::iterator itResult;
    PEFileInfoData* pTemp = NULL;
    for (itResult = m_resultDataVec.begin();
        itResult != m_resultDataVec.end(); itResult++)
    {
        if (*itResult != NULL)
        {
            pTemp = _GetPEFileInfo(**itResult);
        }

        if (pTemp != NULL)
        {
            itemDisData.push_back(pTemp);
            pTemp = NULL;
        }
    }

    return TRUE;
}

BOOL CStartupItemManager::DeleteStartupItem(DWORD dwIndex)
{
    if (dwIndex >= m_resultDataVec.size())
    {
        goto exit0;
    }

    m_startupItem = m_itemFactory->Create(m_resultDataVec[dwIndex]->itemType);
    if (m_startupItem != NULL)
    {
        m_startupItem->Delete(m_resultDataVec[dwIndex]->test);
        delete m_startupItem;
        m_startupItem = NULL;

        return TRUE;
    }

exit0:
    return FALSE;
}

BOOL CStartupItemManager::AddStartupItem(DWORD dwIndex)
{
    if (dwIndex >= m_resultDataVec.size())
    {
        goto exit0;
    }

    m_startupItem = m_itemFactory->Create(m_resultDataVec[dwIndex]->itemType);
    if (m_startupItem != NULL)
    {
        m_startupItem->Add(m_resultDataVec[dwIndex]->test);
        delete m_startupItem;
        m_startupItem = NULL;

        return TRUE;
    }

exit0:
    return FALSE;
}
