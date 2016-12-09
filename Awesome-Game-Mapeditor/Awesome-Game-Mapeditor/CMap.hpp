#ifndef CMAP_HPP
#define CMAP_HPP

#include "stdafx.h"

class CMap{
private:
    CMapInfo                *cMapInfo;
    CMapPlayerInfo          *cMapPlayerInfo;
    CAwesomeChunkContainer  *cAwesomeChunkContainer;
public:
    CMapInfo*                  getMapInfo();
    CMapPlayerInfo*            getMapPlayerInfo();
    CAwesomeChunkContainer*    getCAwesomeChunkContainer();
};

#endif