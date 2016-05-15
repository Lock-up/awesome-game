#ifndef CMAPPLAYERINFO_HPP
#define CMAPPLAYERINFO_HPP

#include "stdafx.h"

struct sPosition
{
    std::uint16_t uiX;
    std::uint16_t uiY;
};

class CMapPlayerInfo{
private:
    std::uint8_t    uiPlayerCount;
    sPosition*      pPositions;

public:
    std::uint8_t    getPlayerCount();
    bool            setPlayerCount(std::uint8_t);
    bool            removePlayer(std::uint8_t);
    bool            removePlayer(std::uint16_t, std::uint16_t);
    std::uint8_t    getPlayerID(std::uint16_t, std::uint16_t);
    std::uint8_t    getPlayerID(sPosition);
    sPosition       getPlayerPosition(std::uint8_t);
};

#endif