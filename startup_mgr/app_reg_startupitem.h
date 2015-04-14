#ifndef APP_REG_STARTUP_ITEM_H
#define APP_REG_STARTUP_ITEM_H
#pragma once
#include "istartupitem.h"
class CRegeditKey;

class CAppRegStartupItem : public IStartupItem
{
public:
    CAppRegStartupItem(void);
    ~CAppRegStartupItem(void);
    /***************************
    BOOL Init();
    BOOL UnInit();
    **************************/

public:
    BOOL Add(void* p);
    BOOL Delete(void* p);
    BOOL Query(std::vector<ResultData* >& resultDataVec);

private:
    std::vector<RegKeyValue* > m_regKeyValueVec;
    std::vector<RegKey* >m_regKeyVec;
    CRegeditKey* m_regeditKey;
};
#endif