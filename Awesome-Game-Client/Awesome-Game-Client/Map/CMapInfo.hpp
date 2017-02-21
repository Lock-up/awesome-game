#ifndef CMAPINFO_HPP
#define CMAPINFO_HPP

#define MAP_MAJOR_VERSION = 1
#define MAP_MINOR_VERSION = 1

#include "stdafx.h"

class CMapInfo{
private:
    std::string     strMapname;
    std::uint16_t   uiSize[2];
    std::uint16_t   uiVersion;

public:
    std::string     getMapName();
    bool            setMapName(std::string);
    bool            setMapSizes(std::uint16_t, std::uint16_t);
    std::uint16_t   getMapSizeX();
    std::uint16_t   getMapSizeY();
    bool            getMapSizes(std::uint16_t&, std::uint16_t&);
    bool            setVersion(std::uint16_t, bool bForce = true);
    std::uint16_t   getVersion();
    bool            hasVersion();
    unsigned char*  serialize(char name[]);
    bool            changeMapSize(std::uint8_t, std::int64_t);

                    CMapInfo();
                    CMapInfo(std::string, std::uint16_t, std::uint16_t, std::uint16_t);

private:
    bool            setMapSize(std::uint8_t, std::uint16_t);
    
    std::uint16_t   getMapSize(std::uint8_t);
    
};

#endif