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
public:
    CMapInfo*                   getMapInfo();
    CMapPlayerInfo*             getMapPlayerInfo();
    CMapPointStackContainer*    getMapStackContainer();
    bool                        loadFromFile(std::string);
    sf::Uint8*                  getPixels();
    bool                        updatePixel(std::uint64_t);
    bool                        updatePixels(std::uint64_t);

private:
    bool                        readHeader_1(int*, std::uint16_t);
    bool                        readData_1(int*, std::uint64_t);
    bool                        readPoints_1(int*, std::uint8_t, std::uint64_t);
    bool                        setPixel(std::uint64_t, std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t);
    bool                        createPixels();
};

#endif