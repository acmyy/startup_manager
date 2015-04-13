#include "stdafx.h"
#include "startupitem_mgr.h"
#include "item_factory.h"
#include "istartupitem.h"

CStartupItemManager::CStartupItemManager(void)
{
    m_itemDisDataVec.clear();
    m_resultDataVec.clear();
}


CStartupItemManager::~CStartupItemManager(void)
{
}

BOOL CStartupItemManager::Init()
{
    for (DWORD dwIndex = 1; dwIndex <= 3; dwIndex++)
    {
        m_startupItem = m_itemFactory.Create(m_resultDataVec[dwIndex]->itemType);
        m_startupItem->Init();
        m_startupItem->Query(m_resultDataVec);
        m_startupItem->UnInit();
    }

    _GetPEFileInfo();

    return TRUE;
}

BOOL CStartupItemManager::UnInit()
{
    return TRUE;
}

BOOL CStartupItemManager::_GetPEFileInfo()
{
    return TRUE;
}

BOOL CStartupItemManager::GetStartupItem(std::vector<ItemDisData* >& itemDisData)
{
    return TRUE;
}

BOOL CStartupItemManager::DeleteStartupItem(DWORD dwIndex)
{
    m_startupItem = m_itemFactory.Create(m_resultDataVec[dwIndex]->itemType);
    m_startupItem->Init();
    m_startupItem->Delete(m_resultDataVec[dwIndex]->test);
    m_startupItem->UnInit();
    return TRUE;
}

BOOL CStartupItemManager::AddStartupItem(DWORD dwIndex)
{
    m_startupItem = m_itemFactory.Create(m_resultDataVec[dwIndex]->itemType);
    m_startupItem->Init();
    m_startupItem->Add(m_resultDataVec[dwIndex]->test);
    m_startupItem->UnInit();
    return TRUE;
}
