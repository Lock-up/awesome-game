#ifndef CMAP_HPP
#define CMAP_HPP

#include "stdafx.h"
#include "CMapPointStackContainer.hpp"

class CMap{
private:
    CMapInfo                cMapInfo;
    CMapPlayerInfo          cMapPlayerInfo;
    CMapPointStackContainer cMapStackContainer;
public:
    CMapInfo*                getMapInfo();
    CMapPlayerInfo*          getMapPlayerInfo();
    CMapPointStackContainer* getMapStackContainer();
};

#endif