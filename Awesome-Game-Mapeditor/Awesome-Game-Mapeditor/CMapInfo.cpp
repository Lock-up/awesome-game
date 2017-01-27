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

bool CMapInfo::setVersion(std::uint16_t uiNewVersion, bool bForce)
{
    if (this->hasVersion() && !bForce)
        return false;

    this->uiVersion = uiNewVersion;
    return true;
}

std::uint16_t CMapInfo::getVersion()
{
    return this->uiVersion;
}

bool CMapInfo::hasVersion()
{
    if (this->getVersion() == 0)
        return false;

    return true;
}

CMapInfo::CMapInfo()
{
    this->strMapname = "New World";
    this->uiSize[0] = 0;
    this->uiSize[1] = 0;
    

    this->uiVersion = 1;
}

std::uint8_t* CMapInfo::serialize()
{
    unsigned long int ulData = 0;

    ulData += sizeof(this->uiSize[0]);
    std::cout << "Data: " << ulData << std::endl;

    return nullptr;
}