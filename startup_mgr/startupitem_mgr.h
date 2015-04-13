#ifndef STARTUP_ITEM_MANAGER_H
#define STARTUP_ITEM_MANAGER_H
#include "stdafx.h"
#pragma once
class CStartupItemManager
{
public:
	CStartupItemManager(void);
	~CStartupItemManager(void);

public:
	BOOL Init();
	BOOL UnInit();

public:
	BOOL GetStartupItem();
	BOOL DeleteStartupItem();
	BOOL AddStartupItem();

private:

};
#endif

