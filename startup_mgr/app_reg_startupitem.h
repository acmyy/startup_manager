#pragma once
#include "istartupitem.h"
class CAppRegStartupItem : public IStartupItem
{
public:
    CAppRegStartupItem(void);
    ~CAppRegStartupItem(void);
    BOOL Init();
    BOOL UnInit();

public:
    BOOL Add(void* p);
    BOOL Delete(void* p);
    BOOL Query(std::vector<ResultData* >& resultDataVec);

private:

};
