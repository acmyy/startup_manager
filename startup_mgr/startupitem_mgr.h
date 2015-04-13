#ifndef STARTUP_ITEM_MANAGER_H
#define STARTUP_ITEM_MANAGER_H
#pragma once
#include "item_factory.h"
#include "pefileinfo_helper.h"

class CStartupItemManager
{
public:
    CStartupItemManager(void);
    ~CStartupItemManager(void);
    BOOL Init();
    BOOL UnInit();

public:
    BOOL GetStartupItem(std::vector<ItemDisData* >& itemDisData);
    BOOL DeleteStartupItem(DWORD dwIndex);
    BOOL AddStartupItem(DWORD dwIndex);

private:
    BOOL _GetPEFileInfo();

private:
    std::vector<ResultData* > m_resultDataVec;
    std::vector<ItemDisData* >m_itemDisDataVec;
    CItemFactory m_itemFactory;
    IStartupItem* m_startupItem;
    CPEFileInfoHelper m_pefileinfoHelper;
};
#endif

