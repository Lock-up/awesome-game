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
    //char* pFileName = new char[strFileName.length() + 1];
    //std::copy(strFileName.begin(), strFileName.end(), pFileName);

    //std::ifstream file("w1.awf", std::ifstream::binary | std::ifstream::ate);

    std::ifstream file(pFileName, std::ifstream::binary | std::ifstream::ate);
    std::cout << "loaded" << std::endl;
        
    return true;
}