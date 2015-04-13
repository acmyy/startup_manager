#pragma once
#ifndef ITEM_FACTORY_H
#define ITEM_FACTORY_H

#define APP_REG_ITEM 1
#define APP_MENU_ITEM 2
#define SERVICE_ITEM 3

class IStartupItem;

class CItemFactory
{
public:
    CItemFactory();
    ~CItemFactory();

public:
    IStartupItem* Create(DWORD dwCreateType);
};
#endif
