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
    if (uiIndex > 1)
        return false;

    this->uiSize[uiIndex] = uiNewSize;
    return true;
}

std::uint16_t CMapInfo::getMapSize(std::uint8_t uiIndex)
{
    if (uiIndex > 1)
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
    this->strMapname = "File has been saved";
    this->uiSize[0] = 0;
    this->uiSize[1] = 0;
    

    this->uiVersion = 1;
}

CMapInfo::CMapInfo(std::string strName, std::uint16_t size_x, std::uint16_t size_y, std::uint16_t uiVersion)
{
    std::cout << "CMapInfo(" << strName << ", " << (int)size_x << ", " << (int)size_y << ", " << (int)uiVersion << ")" << std::endl;

    this->strMapname = strName;
    this->uiSize[0] = size_x;
    this->uiSize[1] = size_y;

    this->uiVersion = uiVersion;
}

unsigned char* CMapInfo::serialize(char name[])
{
    // Mapinfo block size
    unsigned long int ulData = 0;
    unsigned long int ulOffset = 0;

    // Data length = 2 Bytes
    ulData += 2;

    // Mapnamelength = length
    // no sizeof here!
    ulData += (unsigned long)this->strMapname.length();

    // sizeof sizex = 2 Bytes
    ulData += sizeof(this->uiSize[0]);

    // sizeof sizey = 2 Bytes
    ulData += sizeof(this->uiSize[1]);

    // sizeof version = 2 Bytes
    ulData += sizeof(this->uiVersion);
    std::cout << "Data: " << ulData << std::endl;

    //Version
    unsigned char* ucData = new unsigned char[ulData];
    ucData[ulOffset] = (int)this->uiVersion / 256;
    ucData[ulOffset + 1] = this->uiVersion - ((int)this->uiVersion / 256) * 256;
    ulOffset += 2;

    // Datalength
    ucData[ulOffset] = (int)ulData / 256;
    ucData[ulOffset + 1] = (unsigned char)(ulData - ((int)ulData / 256) * 256);
    ulOffset += 2;

    // SizeX
    ucData[ulOffset] = (int)this->uiSize[0] / 256;
    ucData[ulOffset + 1] = this->uiSize[0] - ((int)this->uiSize[0] / 256) * 256;
    ulOffset += 2;

    // SizeY
    ucData[ulOffset] = (int)this->uiSize[1] / 256;
    ucData[ulOffset + 1] = this->uiSize[1] - ((int)this->uiSize[1] / 256) * 256;
    ulOffset += 2;

    unsigned long int ulBuffer = (unsigned long)this->strMapname.length();
    unsigned char* trap = new unsigned char[this->strMapname.length()];

    char* destString = new char[this->strMapname.length()];
    strcpy_s(destString, this->strMapname.length() + 1, this->strMapname.c_str());

    for (int i = 0; i < this->strMapname.length(); i++)
    {
        ucData[ulOffset] = destString[i];
        ulOffset++;
    }

    std::fstream tempmapsave;
    char savestring[60] = "Maps\\";
    strncat_s(savestring, name, 29);
    strncat_s(savestring, ".awf", 29);
    tempmapsave.open(savestring, std::ios_base::binary | std::ios_base::out);
    for (unsigned long int j = 0; j <= ulData - 1; j++)
    {
        tempmapsave << ucData[j];
    }
    tempmapsave.close();

    return nullptr;
}