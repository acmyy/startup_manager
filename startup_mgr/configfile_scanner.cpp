#include "stdafx.h"
#include "configfile_scanner.h"

CConfigFileScanner::CConfigFileScanner()
{

}


CConfigFileScanner::~CConfigFileScanner()
{

}


BOOL CConfigFileScanner::GetFileContent(std::vector<RegKey* >& regKeyVec)
{
    regKeyVec.push_back(new RegKey(L"Software\\Microsoft\\Windows\\CurrentVersion\\Run", HKEY_CURRENT_USER));
    regKeyVec.push_back(new RegKey(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", HKEY_LOCAL_MACHINE));
    regKeyVec.push_back(new RegKey(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Run", HKEY_LOCAL_MACHINE));
    return TRUE;
}