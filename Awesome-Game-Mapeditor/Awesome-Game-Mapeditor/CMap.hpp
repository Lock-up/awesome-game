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
    CMapPointStackContainer*    getMapStackContainer();
    bool                        loadFromFile(std::string);
    bool                        saveToFile(std::string);
    sf::Uint8*                  getPixels();
    bool                        updatePixel(std::uint64_t);
    bool                        updatePixels(std::uint64_t);

    void                        toggleShowPlayers();
    bool                        getShowPlayers();
    void                        setShowPlayers(bool);

private:
    bool                        readHeader_1(int*, std::uint16_t);
    bool                        readData_1(int*, std::uint64_t);
    bool                        readPoints_1(int*, std::uint8_t, std::uint64_t);
    bool                        setPixel(std::uint64_t, std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t);
    bool                        createPixels();

    std::uint64_t               calcHeaderdataSize();
    std::uint64_t               calcDataSize();
    bool                        serializeHeaderdata(std::uint8_t*);
    bool                        serializeData(std::uint8_t*);
};

#endif