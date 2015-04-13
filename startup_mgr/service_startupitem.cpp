#include "stdafx.h"
#include "service_startupitem.h"


CServiceStartupItem::CServiceStartupItem(void)
{
}

BOOL CServiceStartupItem::Init()
{

    return TRUE;
}

BOOL CServiceStartupItem::UnInit()
{
    return TRUE;
}

CServiceStartupItem::~CServiceStartupItem(void)
{
}

BOOL CServiceStartupItem::Add(void* p)
{
    return TRUE;
}

BOOL CServiceStartupItem::Delete(void* p)
{
    return TRUE;
}

BOOL CServiceStartupItem::Query(std::vector<ResultData* >& resultDataVec)
{
    return TRUE;
}

