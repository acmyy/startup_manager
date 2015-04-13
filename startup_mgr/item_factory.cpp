#include "stdafx.h"
#include "item_factory.h"
#include "istartupitem.h"
#include "app_menu_startupitem.h"
#include "app_reg_startupitem.h"
#include "service_startupitem.h"

CItemFactory::CItemFactory()
{
}


CItemFactory::~CItemFactory()
{
}

IStartupItem* CItemFactory::Create(DWORD dwCreateType)
{
    switch (dwCreateType)
    {
    case APP_REG_ITEM:
        return new CAppRegStartupItem();
        break;
    case APP_MENU_ITEM:
        return new CAppMenuStartupItem();
        break;
    case SERVICE_ITEM:
        return new CServiceStartupItem();
        break;
    default:
        return NULL;
        break;
    }
}