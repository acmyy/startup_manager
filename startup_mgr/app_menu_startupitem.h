#pragma once
#include "istartupitem.h"
class CAppMenuStartupItem : public IStartupItem
{
public:
    CAppMenuStartupItem(void);
    ~CAppMenuStartupItem(void);
    BOOL Init();
    BOOL UnInit();

public:
    BOOL Add(void* p);
    BOOL Delete(void* p);
    BOOL Query(std::vector<ResultData* >& resultDataVec);
};

