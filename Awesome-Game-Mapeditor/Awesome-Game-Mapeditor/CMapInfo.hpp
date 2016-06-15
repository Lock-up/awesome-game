#ifndef CMAPINFO_HPP
#define CMAPINFO_HPP

#include "stdafx.h"

class CMapInfo{
private:
    std::string     strMapname;
    std::uint16_t   uiSize[2];

public:
    std::string     getMapName();
    bool            setMapName(std::string);
    bool            setMapSizes(std::uint16_t, std::uint16_t);
    std::uint16_t   getMapSizeX();
    std::uint16_t   getMapSizeY();
    bool            getMapSizes(std::uint16_t&, std::uint16_t&);
    //bool            getMapSizes(std::uint16_t*);

private:
    bool            setMapSize(std::uint8_t, std::uint16_t);
    std::uint16_t   getMapSize(std::uint8_t);
};

#endif