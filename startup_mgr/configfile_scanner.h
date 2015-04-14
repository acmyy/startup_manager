#pragma once
#include "ifilescanner.h"
class CConfigFileScanner : public IFileScanner
{
public:
    CConfigFileScanner();
    ~CConfigFileScanner();

public:
    BOOL GetFileContent(std::vector<RegKey* >& regKeyVec);
};

