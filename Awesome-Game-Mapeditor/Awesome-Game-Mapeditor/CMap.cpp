#include "stdafx.h"

CMapInfo* CMap::getMapInfo()
{
    return this->cMapInfo;
}

CMapPlayerInfo* CMap::getMapPlayerInfo()
{
    return this->cMapPlayerInfo;
}

CMapPointStackContainer* CMap::getMapStackContainer()
{
    return this->cMapStackContainer;
}

bool CMap::loadFromFile(std::string strFileName)
{
    if (strFileName == "")
        return false;

    const char* pFileName = strFileName.c_str();

    std::ifstream file(pFileName, std::ifstream::binary);

    std::cout << "loaded" << std::endl;

    std::uint64_t uiFileLength = 0;

    file.seekg(0, file.end);
    uiFileLength = file.tellg();
    file.seekg(0, file.beg);

    std::cout << "Bytes: " << uiFileLength << std::endl;

    char* pTempFile = new char[(unsigned int)uiFileLength];

    file.read(pTempFile, uiFileLength);
        
    std::cout << "FileVersion: " << ((((int)pTempFile[0]) << 8) + (int)pTempFile[1]) << std::endl;

    this->cMapInfo = new CMapInfo();
    this->getMapInfo()->setVersion((std::uint16_t)((((int)pTempFile[0]) << 8) + (int)pTempFile[1]));

    file.close();
    return true;
}