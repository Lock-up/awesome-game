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
        
    std::uint16_t uiTempVersion = (((int)pTempFile[0]) << 8);
    uiTempVersion += (int)pTempFile[1];

    this->cMapInfo = new CMapInfo();
    this->getMapInfo()->setVersion(uiTempVersion);

    std::uint16_t uiTempHeader = (((int)pTempFile[2]) << 8);
    uiTempHeader += (int)pTempFile[3];

    std::cout << uiTempHeader << std::endl;

    int* pTempHeader = new int[(unsigned int)uiTempHeader];

    for (std::uint8_t i = 0; i < uiTempHeader; i++)
    {
        pTempHeader[i] = (int)pTempFile[i];
    }

    switch (this->getMapInfo()->getVersion())
    {
    case 1: readHeader_1(pTempHeader, uiTempHeader); break;
    default: return false; break;
    }

    delete[] pTempHeader;
    delete[] pTempFile;

    file.close();
    return true;
}

bool CMap::readHeader_1(int* pHeader, std::uint16_t uiDataLength)
{
    if (pHeader == nullptr)
        return false;

    std::uint16_t uiSizeX = pHeader[4] << 8;
    uiSizeX += pHeader[5];

    std::uint16_t uiSizeY = pHeader[6] << 8;
    uiSizeY += pHeader[7];

    this->getMapInfo()->setMapSizes(uiSizeX, uiSizeY);

    std::uint8_t uiPlayerCount = pHeader[8];

    //unused
    //std::uint8_t uiAnimationCount = pHeader[9];


    //MAPNAME
    std::uint8_t uiMapNameLength = 0;
    for (std::uint8_t i = 10; i < uiDataLength; i++)
    {
        if (pHeader[i] == 0)
        {
            uiMapNameLength = i - 10;
            break;
        }
    }

    char* pTempMapName = new char[(unsigned int)uiMapNameLength];

    for (std::uint8_t i = 0; i < uiMapNameLength; i++)
        pTempMapName[i] = pHeader[i + 10];

    std::string strMapName;
    strMapName.assign(pTempMapName, uiMapNameLength);
    this->getMapInfo()->setMapName(strMapName);

    delete[] pTempMapName;

    //PLAYERS
    this->cMapPlayerInfo = new CMapPlayerInfo();
    for (std::uint8_t i = 0; i < uiPlayerCount; i++)
    {
        std::uint8_t uiOffset = 10 + uiMapNameLength + i * 4;

        std::uint16_t uiPosX = pHeader[uiOffset + 1] << 8;
        uiPosX += pHeader[uiOffset + 2];

        std::uint16_t uiPosY = pHeader[uiOffset + 3] << 8;
        uiPosY += pHeader[uiOffset + 4];

        this->getMapPlayerInfo()->pushPlayer(uiPosX, uiPosY);
    }

    //TODO: Animations

    return true;
};