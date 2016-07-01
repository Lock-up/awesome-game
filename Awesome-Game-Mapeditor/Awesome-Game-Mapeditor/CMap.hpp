#ifndef CMAP_HPP
#define CMAP_HPP

#include "stdafx.h"

class CMap{
private:
    CMapInfo                *cMapInfo;
    CMapPlayerInfo          *cMapPlayerInfo;
    CMapPointStackContainer *cMapStackContainer;
public:
    CMapInfo*                   getMapInfo();
    CMapPlayerInfo*             getMapPlayerInfo();
    CMapPointStackContainer*    getMapStackContainer();
    bool                        loadFromFile(std::string);

private:
    bool                        readHeader_1(int*, std::uint16_t);
    bool                        readData_1(int*, std::uint64_t);
    bool                        readPoint_1(int*, std::uint64_t, std::uint64_t, std::uint64_t);
};

#endif