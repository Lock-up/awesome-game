#include "stdafx.h"

std::uint8_t CMapPlayerInfo::getPlayerCount()
{
    return (std::uint8_t)this->vPositions.size();
}

bool CMapPlayerInfo::popPlayer(std::uint8_t uiIndex)
{
    if (this->vPositions.size() < uiIndex)
        return false;
    else
    {
        this->vPositions.erase(this->vPositions.begin() + uiIndex);
        return true;
    }
}

bool CMapPlayerInfo::popPlayer(std::uint16_t uiPosX, std::uint16_t uiPosY)
{
    SPosition posTemp = { uiPosX, uiPosY };

    std::vector<SPosition>::iterator it = std::find(this->vPositions.begin(), this->vPositions.end(), posTemp);

    if (it == this->vPositions.end())
        return false;
    else
    {
        this->vPositions.erase(it);
        return true;
    }
}

std::uint8_t CMapPlayerInfo::getPlayerID(std::uint16_t uiPosX, std::uint16_t uiPosY)
{
    SPosition posTemp = { uiPosX, uiPosY };
    auto it = std::find(this->vPositions.begin(), this->vPositions.end(), posTemp);

    if (it == this->vPositions.end())
        return 0;
    else
    {
        std::uint8_t uiDist = (std::uint8_t)std::distance(it, this->vPositions.begin());
        return uiDist;
    }
}

std::uint8_t CMapPlayerInfo::getPlayerID(SPosition posTemp)
{
    auto it = std::find(this->vPositions.begin(), this->vPositions.end(), posTemp);

    if (it == this->vPositions.end())
        return 0;
    else
    {
        std::uint8_t uiDist = (std::uint8_t)std::distance(it, this->vPositions.begin());
        return uiDist;
    }
}

SPosition CMapPlayerInfo::getPlayerPosition(std::uint8_t uiPlayerID)
{
    if (uiPlayerID > this->getPlayerCount())
        return SPosition{ 0, 0 };
    else
        return this->vPositions.at(uiPlayerID);
}

bool CMapPlayerInfo::pushPlayer(SPosition posNewPlayer)
{
    if (posNewPlayer.uiX < 0 || posNewPlayer.uiY < 0)
        return false;
    else if (this->getPlayerID(posNewPlayer) != 0)
        return false;
    else
    {
        this->vPositions.push_back(posNewPlayer);
        return true;
    }
}

bool CMapPlayerInfo::pushPlayer(std::uint16_t uiPosX, std::uint16_t uiPosY)
{
    SPosition posNewPlayer = { uiPosX, uiPosY };
    return this->pushPlayer(posNewPlayer);
}

bool CMapPlayerInfo::createPlayerMarkerPixels(CMapInfo cMapInfo)
{
    this->pPlayerMarkerPixels = new sf::Uint8[(unsigned int)(cMapInfo.getMapSizeX() * cMapInfo.getMapSizeY() * 4)];

    for (std::uint64_t j = 0; j < (4 * cMapInfo.getMapSizeX() * cMapInfo.getMapSizeY()); j+=4)
    {
        pPlayerMarkerPixels[j] = 255;
        pPlayerMarkerPixels[j + 1] = 0;
        pPlayerMarkerPixels[j + 2] = 0;
        pPlayerMarkerPixels[j + 3] = 0;
    }

    for (std::uint8_t i = 0; i < this->getPlayerCount(); i++)
        this->updatePlayerMarkerPixels(cMapInfo, this->getPlayerPosition(i), false);

    return true;
}

bool CMapPlayerInfo::updatePlayerMarkerPixels(CMapInfo cMapInfo, std::uint32_t uiPosX, std::uint32_t uiPosY, bool doRemove)
{
    if (this->pPlayerMarkerPixels == nullptr)
        return false;

    if (uiPosX > cMapInfo.getMapSizeX() || uiPosY > cMapInfo.getMapSizeY())
        return false;

    std::uint64_t uiOffset = 4 * (cMapInfo.getMapSizeX() * uiPosY + uiPosX);

    pPlayerMarkerPixels[uiOffset] = 255;
    pPlayerMarkerPixels[uiOffset + 1] = 0;
    pPlayerMarkerPixels[uiOffset + 2] = 0;

    if (doRemove)
        pPlayerMarkerPixels[uiOffset + 3] = 0;
    else
        pPlayerMarkerPixels[uiOffset + 3] = 255;

    return true;
}

bool CMapPlayerInfo::updatePlayerMarkerPixels(CMapInfo cMapInfo, SPosition sPlayerPos, bool doRemove)
{
    return this->updatePlayerMarkerPixels(cMapInfo, sPlayerPos.uiX, sPlayerPos.uiY, doRemove);
}

sf::Uint8* CMapPlayerInfo::getPlayerMarker()
{
    return this->pPlayerMarkerPixels;
}

std::uint8_t* CMapPlayerInfo::serialize()
{
    // Mapinfo block size
    unsigned long int ulData = 0;
    unsigned long int ulOffset = 0;

    // Data length = 1 Bytes (255 players max)
    ulData += 1;

    // PlayerPosition = 4 Bytes (2x uint16)
    ulData += this->getPlayerCount() * 4;

    std::cout << "Data(Player): " << ulData << std::endl;

    // Datalength (= PlayerCount (no need to save 16Bit))
    unsigned char* ucData = new unsigned char[ulData];
    ucData[ulOffset] = (int)this->getPlayerCount();
    ulOffset += 1;

    for (int i = 0; i < this->getPlayerCount(); i++)
    {
        // PositionX
        ucData[ulOffset] = (int)this->getPlayerPosition(i).uiX / 256;
        ucData[ulOffset + 1] = this->getPlayerPosition(i).uiX - ((int)this->getPlayerPosition(i).uiX / 256) * 256;
        ulOffset += 2;

        //PositionY
        ucData[ulOffset] = (int)this->getPlayerPosition(i).uiY / 256;
        ucData[ulOffset + 1] = this->getPlayerPosition(i).uiY - ((int)this->getPlayerPosition(i).uiY / 256) * 256;
        ulOffset += 2;
    }

    std::fstream tempmapsave;
    char savestring[60] = "Maps\\CMapPlayerInfo.awf";
    tempmapsave.open(savestring, std::ios_base::binary | std::ios_base::out);
    for (unsigned long int j = 0; j <= ulData - 1; j++)
    {
        tempmapsave << ucData[j];
    }
    tempmapsave.close();

    return nullptr;
}