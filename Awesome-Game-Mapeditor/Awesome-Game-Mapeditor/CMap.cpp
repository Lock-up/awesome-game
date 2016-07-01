#include "stdafx.h"
#include "CMapPointStackContainer.hpp"

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

    this->cMapStackContainer = new CMapPointStackContainer();

    int* pTempData = new int[(unsigned int)(uiFileLength - uiTempHeader)];

    for (std::uint8_t i = 0; i < (uiFileLength - uiTempHeader); i++)
    {
        pTempData[i] = (int)pTempFile[uiTempHeader + i];
    }

    switch (this->getMapInfo()->getVersion())
    {
    case 1:
    {
        this->readHeader_1(pTempHeader, uiTempHeader);
        this->readData_1(pTempData, (uiFileLength - uiTempHeader));
    }break;
    default: return false; break;
    }

    delete[] pTempHeader;
    delete[] pTempFile;
    delete[] pTempData;

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

bool CMap::readData_1(int* pData, std::uint64_t uiDataLength)
{
    if (pData == nullptr)
        return false;

    std::uint64_t uiOffset = 0;
    std::uint64_t uiStackID = 0;

    for (std::uint64_t i = 0; i < uiDataLength; i++)
    {
        //Stack ends, now we have both offsets
        if (pData[i] == 0)
        {
            //woopsie, cant store flags yet
            //this->cMapStackContainer.getStack(uiStackID)->set

            //1 Byte is Stack Modifier
            this->readPoint_1(pData, uiStackID, uiOffset + 2, i);
            uiStackID += 1;
            uiOffset = i;
        }
    }

    return true;
}

bool CMap::readPoint_1(int* pData, std::uint64_t uiStackID, std::uint64_t uiBegin, std::uint64_t uiEnd)
{
    if (pData == nullptr)
        return false;

    if (uiBegin >= uiEnd)
        return false;

    // length needs to be at least 6
    if ((uiEnd - uiBegin) < 6)
        return false;

    do
    {
        CMapPoint *cTempPoint = new CMapPoint();

        cTempPoint->setFlag(Flag_Type::FLAG_SPECIAL, (std::uint8_t)pData[uiBegin]);
        cTempPoint->setFlag(Flag_Type::FLAG_TYPE, (std::uint8_t)pData[uiBegin + 1]);

        cTempPoint->setHeight((std::uint8_t)pData[uiBegin + 2]);

        cTempPoint->setRGB((std::uint8_t)pData[uiBegin + 3], (std::uint8_t)pData[uiBegin + 4], (std::uint8_t)pData[uiBegin + 5]);

        cTempPoint->setAmount(pData[uiBegin + 6]);

        cTempPoint->setResource(pData[uiBegin + 7]);

        //cMapStackContainer->getStack(uiStackID)->pushBack(cTempPoint);

        std::cout << "Long point inserted" << std::endl;
        uiBegin += 8;

    //Full point is 8 long
    } while ((uiEnd - uiBegin) < 8);

    CMapPoint *cTempPoint = new CMapPoint();

    switch (uiEnd - uiBegin)
    {
    case 8:
        cTempPoint->setResource(pData[uiBegin + 7]);
    case 7:
        cTempPoint->setAmount(pData[uiBegin + 6]);
    case 6:
        cTempPoint->setFlag(Flag_Type::FLAG_SPECIAL, (std::uint8_t)pData[uiBegin]);
        cTempPoint->setFlag(Flag_Type::FLAG_TYPE, (std::uint8_t)pData[uiBegin + 1]);

        cTempPoint->setHeight((std::uint8_t)pData[uiBegin + 2]);

        cTempPoint->setRGB((std::uint8_t)pData[uiBegin + 3], (std::uint8_t)pData[uiBegin + 4], (std::uint8_t)pData[uiBegin + 5]);

        //this->getMapStackContainer()->getStack(uiStackID)->pushMapPoint(cTempPoint);

        std::cout << "Short point inserted" << std::endl;
    default: return false; break;
    }

    return true;
}