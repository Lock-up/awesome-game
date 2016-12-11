#ifndef AWESOMECHUNK_HPP
#define AWESOMECHUNK_HPP

#include "stdafx.h"

const std::uint8_t CHUNK_SIZE = 32;

class CAwesomeChunk{
private:
    std::vector<CMapPoint*> vMapPoints;

public:

    std::vector<CMapPoint*> getPoints();

    CMapPoint*              getMapPoint(std::uint8_t, std::uint8_t);
    CMapPoint*              getMapPoint(std::uint16_t);

    bool                    setMapPoint(std::uint8_t, std::uint8_t, CMapPoint*);
    bool                    setMapPoint(std::uint16_t, CMapPoint*);

    bool                    delMapPointData(std::uint8_t, std::uint8_t);
    bool                    delMapPointData(std::uint16_t);

    //TODO: Konstructor
                            CAwesomeChunk();
    //TODO: Destructor
                            ~CAwesomeChunk();
private:
    bool                    pushMapPoint(CMapPoint*);
};

#endif