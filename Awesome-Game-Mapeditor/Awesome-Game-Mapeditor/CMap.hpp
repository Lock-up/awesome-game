#ifndef CMAP_HPP
#define CMAP_HPP

#include "stdafx.h"

const std::uint64_t MAX_POINT_LENGTH = 8;

class CMap{
private:
    CMapInfo                *cMapInfo;
    CMapPlayerInfo          *cMapPlayerInfo;
    CMapPointStackContainer *cMapStackContainer;
    sf::Uint8*              pPixels;
    bool                    showPlayers;
public:
    CMapInfo*                   getMapInfo();
    CMapPlayerInfo*             getMapPlayerInfo();
    //CMapPointStackContainer*    getMapStackContainer();
};

#endif