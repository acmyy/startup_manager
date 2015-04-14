#ifndef ISTARTUP_ITEM
#define ISTARTUP_ITEM
class IStartupItem
{
public:
    //virtual ~IStartupItem();
    /*
    virtual BOOL Init() = 0;
    virtual BOOL UnInit() = 0;
    */

public:
    virtual BOOL Add(void* p) = 0;
    virtual BOOL Delete(void* p) = 0;
    virtual BOOL Query(std::vector<ResultData* >& resultDataVec) = 0;
};
#endif