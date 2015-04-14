// startup_mgr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "regedit_key.h"
#include "startupitem_mgr.h"
#include "pefileinfo_helper.h"



void RegeditKeyTest()
{
    CRegeditKey test;
    std::vector<RegKeyValue* > regKeyValueVec;
    HKEY hMainKey = HKEY_CURRENT_USER;
    DWORD dwTest = 10;
    RegKeyValue regValueTest(_T("test"), REG_DWORD, (PBYTE)&dwTest, sizeof(dwTest));
    std::vector<RegKey* > regKeyVec;
    if (!test.Init(hMainKey, _T("aatest")))
    {
        std::cout << "test failed\n";
    }
    test.InsertValue(regValueTest);
    test.QueryValue(regKeyValueVec);
    for (int i = 0; i < regKeyValueVec.size(); i++)
    {
        std::wcout << regKeyValueVec[i]->strName << "" << *((DWORD*)regKeyValueVec[i]->pKeyValue) << std::endl;
    }
    //test.DeleteValue(_T("test"));
    /*test.GetSubRegKey(regKeyVec);
    
    for (int i = 0; i < regKeyVec.size(); i++)
    {
        CRegeditKey test1;
        test1.Init(regKeyVec[i]->hMainKey, regKeyVec[i]->strName.c_str());
        std::wcout<< regKeyVec[i]->strName << std::endl;
        test1.InsertValue(regValueTest, sizeof(dwTest));
        test1.UnInit(1);
    }*/
    if (!test.UnInit())
    {
        std::cout << "delete failed\n";
    }
    while (1);
}

void PefileinfoHelperTest()
{
    CPEFileInfoHelper getInfo;
    PEFILEVERSION_INFO peinfo;
    WCHAR s[100];
    wsprintf(s, _T("C:\\Program Files (x86)\\Tencent\\QQ\\Bin\\QQ.exe"));
    std::wstring str = s;

    peinfo[ProductName] = _T("");
    peinfo[CompanyName] = _T("");
    getInfo.GetPEFileInfo(str.c_str(), peinfo);
    PEFILEVERSION_INFO_IT it;
    for (it = peinfo.begin(); it != peinfo.end(); it++)
    {
        if (it->first == ProductName)
        {
            if (it->second == _T(""))
            {
                it->second = _T("UnKnow");
            }
            std::locale loc1 = std::locale::global(std::locale(".936"));
            {
                // 在这里使用std::ifstream 或者 std::fstream
            std::wcout << it->second << std::endl;
            }

            //恢复原来的代码页
            std::locale::global(std::locale(loc1));
        }
        else if (it->first == CompanyName)
        {
            if (it->second == _T(""))
            {
                it->second = _T("UnKnow");
            }
            std::wcout << it->second << std::endl;
        }
    }
    peinfo.clear();
}

void StartupTest()
{
    CStartupItemManager test;
    std::vector<PEFileInfoData* > testVec;
    test.GetStartupItem(testVec);
    for (int i = 0; i < testVec.size(); i++)
    {
        std::wcout << testVec[i]->strAppName << " " << testVec[i]->strCompanyName << std::endl;
    }
}

int main(int argc, _TCHAR* argv[])
{
    //RegeditKeyTest();
    //StartupTest();
    //PefileinfoHelperTest();
    StartupTest();
    system("pause");
    return 0;
}

