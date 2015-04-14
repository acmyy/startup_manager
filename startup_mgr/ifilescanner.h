#ifndef IFILE_SCANNER_H
#define IFILE_SCANNER_H
class IFileScanner
{
    virtual BOOL GetFileContent(std::vector<RegKey* >& regKeyVec) = 0;
};
#endif