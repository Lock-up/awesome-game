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

    //TODO: constructor
    this->showPlayers = false;
    
    const char* pFileName = strFileName.c_str();

    std::ifstream file(pFileName, std::ifstream::binary);

    std::cout << "Loading map '" << strFileName << "' ..." << std::endl;

    std::uint64_t uiFileLength = 0;

    file.seekg(0, file.end);
    uiFileLength = file.tellg();
    uiFileLength -= 1;
    file.seekg(0, file.beg);

    char* pTempFile = new char[(unsigned int)uiFileLength];

    file.read(pTempFile, uiFileLength);
        
    std::uint16_t uiTempVersion = (((int)pTempFile[0]) << 8);
    uiTempVersion += (int)pTempFile[1];

    this->cMapInfo = new CMapInfo();
    this->getMapInfo()->setVersion(uiTempVersion);

    std::uint16_t uiTempHeader = (((int)pTempFile[2]) << 8);
    uiTempHeader += (int)pTempFile[3];

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

    this->createPixels();

    delete[] pTempHeader;
    delete[] pTempFile;
    delete[] pTempData;

    file.close();

    std::cout << "Map '" << strFileName << "' has been loaded!" << std::endl;

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
    // 1
    // PointsCount
    // 1
    // StackFlags
    //
    // PointFlags1
    // PointSlags2
    // R
    // G
    // B
    // Height
    // Resource
    // Amount

    std::uint64_t uiOffset = 0;

    while (uiOffset < uiDataLength)
    {
        CMapPointStack *cTempStack = new CMapPointStack();

        std::uint8_t uiPoints = pData[uiOffset];
        uiOffset += 1;

        //cTempStack->setStackFlag(pData[uiOffset + 1]);
        uiOffset += 1;

        this->cMapStackContainer->pushStack(cTempStack);

        this->readPoints_1(pData, uiPoints, uiOffset);

        uiOffset += (uiPoints * MAX_POINT_LENGTH);
    }

    return true;
}

bool CMap::readPoints_1(int* pData, std::uint8_t uiPoints, std::uint64_t uiOffset)
{
    for (std::uint64_t i = 0; i < uiPoints; i++)
    {
        CMapPoint *cTempPoint = new CMapPoint();

        cTempPoint->setFlags(Flag_Type::FLAG_TYPE, pData[uiOffset]);
        uiOffset += 1;

        cTempPoint->setFlags(Flag_Type::FLAG_SPECIAL, pData[uiOffset]);
        uiOffset += 1;

        cTempPoint->setR(pData[uiOffset]);
        uiOffset += 1;

        cTempPoint->setG(pData[uiOffset]);
        uiOffset += 1;

        cTempPoint->setB(pData[uiOffset]);
        uiOffset += 1;

        cTempPoint->setHeight(pData[uiOffset]);
        uiOffset += 1;

        cTempPoint->setResource(pData[uiOffset]);
        uiOffset += 1;

        cTempPoint->setAmount(pData[uiOffset]);
        uiOffset += 1;

        this->cMapStackContainer->getLastStack()->pushMapPoint(cTempPoint);
    }

    return true;
}

sf::Uint8* CMap::getPixels()
{
    return this->pPixels;
}

bool CMap::updatePixel(std::uint64_t uiID)
{
    if (uiID > this->cMapInfo->getMapSizeX() * this->cMapInfo->getMapSizeY())
        return false;

    std::uint8_t uiNewR, uiNewG, uiNewB, uiNewA;

    this->cMapStackContainer->getLastStackPoint(uiID)->getRGB(uiNewR, uiNewG, uiNewB);
    //TODO
    //uiNewA = this->cMapStackContainer->getStack(uiID).getLastMapPoint().getAlpha();
    uiNewA = 255;

    return this->setPixel(uiID, uiNewR, uiNewG, uiNewB, uiNewA);
}

bool CMap::updatePixels(std::uint64_t uiPixelUpdates)
{
    if (uiPixelUpdates == 0)
    {
        for (std::uint64_t i = 0; i < (cMapInfo->getMapSizeX() * cMapInfo->getMapSizeY()); i++)
            this->updatePixel(i);
    }
    //TODO
    else
    {

    }
    return true;
}

bool CMap::setPixel(std::uint64_t uiID, std::uint8_t uiR, std::uint8_t uiG, std::uint8_t uiB, std::uint8_t uiA)
{
    if (uiID > this->cMapInfo->getMapSizeX() * this->cMapInfo->getMapSizeY())
        return false;

    std::uint64_t uiOffset = uiID * 4;

    this->pPixels[uiOffset] = uiR;
    this->pPixels[uiOffset + 1] = uiG;
    this->pPixels[uiOffset + 2] = uiR;
    this->pPixels[uiOffset + 3] = uiA;

    return true;
}

bool CMap::createPixels()
{
    this->pPixels = new sf::Uint8[(unsigned int)(this->cMapInfo->getMapSizeX() * this->cMapInfo->getMapSizeY() * 4)];
    
    this->updatePixels(0);
    
    return true;
}

void CMap::toggleShowPlayers()
{
    this->showPlayers = !this->showPlayers;
}

bool CMap::getShowPlayers()
{
    return this->showPlayers;
}
void CMap::setShowPlayers(bool bValue)
{
    this->showPlayers = bValue;
}