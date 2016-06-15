#include "stdafx.h"

std::string CMapInfo::getMapName()
{
    return this->strMapname;
}

bool CMapInfo::setMapName(std::string strNewMapName)
{
    this->strMapname = strNewMapName;
    return true;
}

bool CMapInfo::setMapSizes(std::uint16_t uiSizeX, std::uint16_t uiSizeY)
{
    return this->setMapSize(0, uiSizeX) && this->setMapSize(1, uiSizeY);
}

std::uint16_t CMapInfo::getMapSizeX()
{
    return this->getMapSize(0);
}

std::uint16_t CMapInfo::getMapSizeY()
{
    return this->getMapSize(1);
}

bool CMapInfo::getMapSizes(std::uint16_t& uiSizeX, std::uint16_t& uiSizeY)
{
    uiSizeX = this->getMapSizeX();
    uiSizeY = this->getMapSizeY();
    return true;
}


bool CMapInfo::setMapSize(std::uint8_t uiIndex, std::uint16_t uiNewSize)
{
    if (uiIndex > 2)
        return false;

    this->uiSize[uiIndex] = uiNewSize;
    return true;
}

std::uint16_t CMapInfo::getMapSize(std::uint8_t uiIndex)
{
    if (uiIndex > 2)
        return 0;

    return this->uiSize[uiIndex];
}