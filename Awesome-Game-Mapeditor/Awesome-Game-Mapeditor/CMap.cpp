#include "stdafx.h"

CMapInfo* CMap::getMapInfo()
{
    return this->cMapInfo;
}

CMapPlayerInfo* CMap::getMapPlayerInfo()
{
    return this->cMapPlayerInfo;
}

CAwesomeChunkContainer* CMap::getCAwesomeChunkContainer()
{
    return this->cAwesomeChunkContainer;
}

CMap::CMap()
{
    std::cout << "CMap::CMap()" << std::endl;
}

CMap::CMap(std::uint64_t uiSizeX, std::uint64_t uiSizeY)
{
    std::cout << "CMap::CMap(uint64_t, uint64_t)" << std::endl;
    this->cAwesomeChunkContainer = new CAwesomeChunkContainer();

    for (std::uint64_t i = 0; i < uiSizeX*uiSizeY; i++)
    {
        CAwesomeChunk *tmpChunk = new CAwesomeChunk();
        this->getCAwesomeChunkContainer()->pushChunk(tmpChunk);
    }
}

CMap::CMap(std::string strMapName)
{
    std::cout << "CMap::CMap(string)" << std::endl;
}