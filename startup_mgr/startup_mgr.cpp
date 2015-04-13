// startup_mgr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "regedit_key.h"

void RegeditKeyTest()
{
    CRegeditKey test;
    HKEY hMainKey = HKEY_CURRENT_USER;
    DWORD dwTest = 10;
    RegKeyValue regValueTest(_T("test"), REG_DWORD, (PBYTE)&dwTest);
    std::vector<RegKey* > regKeyVec;
    if (!test.Init(hMainKey, _T("aatest")))
    {
        std::cout << "test failed\n";
    }
    test.InsertValue(regValueTest, sizeof(dwTest));
    //test.DeleteValue(_T("test"));
    test.GetSubRegKey(regKeyVec);
    
    for (int i = 0; i < regKeyVec.size(); i++)
    {
        CRegeditKey test1;
        test1.Init(regKeyVec[i]->hMainKey, regKeyVec[i]->strName.c_str());
        std::wcout<< regKeyVec[i]->strName << std::endl;
        test1.InsertValue(regValueTest, sizeof(dwTest));
        test1.UnInit(1);
    }
    if (!test.UnInit())
    {
        std::cout << "delete failed\n";
    }
    while (1);
}

int main(int argc, _TCHAR* argv[])
{
    
    return 0;
}

