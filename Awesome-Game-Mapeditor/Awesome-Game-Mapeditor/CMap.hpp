#ifndef CMAP_HPP
#define CMAP_HPP

#include "stdafx.h"

class CMap{
private:
    CMapInfo                *cMapInfo;
    CMapPlayerInfo          *cMapPlayerInfo;
    CAwesomeChunkContainer  *cAwesomeChunkContainer;
public:
    CMapInfo*                   getMapInfo();
    CMapPlayerInfo*             getMapPlayerInfo();
    CAwesomeChunkContainer*     getCAwesomeChunkContainer();
    //Constructor
                                CMap();
                                CMap(std::uint64_t, std::uint64_t);
                                CMap(std::string);

};

#endif