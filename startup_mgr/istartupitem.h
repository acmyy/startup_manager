#ifndef ISTARTUP_ITEM
#define ISTARTUP_ITEM
class IStartupItem
{
	virtual bool Add() = 0;
	virtual bool Delete() = 0;
	virtual bool Query() = 0;
};
#endif