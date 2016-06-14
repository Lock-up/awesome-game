#include "stdafx.h"

std::uint8_t CMapPlayerInfo::getPlayerCount()
{
    return this->vPositions.size();
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
        //std::distance(it,this->vPositions.begin());
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
        std::uint8_t uiDist = std::distance(it,this->vPositions.begin());
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
        std::uint8_t uiDist = std::distance(it, this->vPositions.begin());
        return uiDist;
    }
}

SPosition CMapPlayerInfo::getPlayerPosition(std::uint8_t uiPlayerID)
{
    SPosition posTemp = { 0, 0};
    auto it = std::find(this->vPositions.begin(), this->vPositions.end(), posTemp);

    if (it == this->vPositions.end())
        return posTemp;
    else
        return this->vPositions.at(std::distance(it, this->vPositions.begin()));
}

bool CMapPlayerInfo::pushPlayer(SPosition posNewPlayer)
{
    if (posNewPlayer.uiX <= 0 || posNewPlayer.uiY <= 0)
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