#ifndef STARTUP_ITEM_MANAGER_H
#define STARTUP_ITEM_MANAGER_H
#pragma once
//#include "item_factory.h"
//#include "pefileinfo_helper.h"

class CPEFileInfoHelper;
class CItemFactory;
class IStartupItem;

class CStartupItemManager
{
public:
    CStartupItemManager(void);
    ~CStartupItemManager(void);
    /****************
    BOOL Init();
    BOOL UnInit();
    *****************/

public:
    BOOL GetStartupItem(std::vector<PEFileInfoData* >& itemDisData);
    BOOL DeleteStartupItem(DWORD dwIndex);
    BOOL AddStartupItem(DWORD dwIndex);

protected:
    PEFileInfoData* _GetPEFileInfo(ResultData& resultData);
    BOOL _GetKeyValue(const std::wstring& strTempPath, std::wstring& str);

private:
    std::vector<ResultData* > m_resultDataVec;
    CItemFactory* m_itemFactory;
    IStartupItem* m_startupItem;
    CPEFileInfoHelper* m_pefileinfoHelper;
};
#endif

