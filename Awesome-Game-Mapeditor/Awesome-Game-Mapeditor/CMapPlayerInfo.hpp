#ifndef CMAPPLAYERINFO_HPP
#define CMAPPLAYERINFO_HPP

#include "stdafx.h"

struct SPosition
{
    std::uint16_t uiX;
    std::uint16_t uiY;

    inline bool operator==(SPosition cmp)
    {
        return (cmp.uiX == uiX && cmp.uiY == uiY);
    }
};

class CMapPlayerInfo{
private:
    //std::uint8_t            uiPlayerCount;
    //sPosition*      pPositions;
    std::vector<SPosition>  vPositions;

public:
    std::uint8_t    getPlayerCount();
    bool            popPlayer(std::uint8_t);
    bool            popPlayer(std::uint16_t, std::uint16_t);
    std::uint8_t    getPlayerID(std::uint16_t, std::uint16_t);
    std::uint8_t    getPlayerID(SPosition);
    SPosition       getPlayerPosition(std::uint8_t);
    bool            pushPlayer(SPosition);
    bool            pushPlayer(std::uint16_t, std::uint16_t);
};

#endif