#include "stdafx.h"

bool CAwesomeChunk::pushMapPoint(CMapPoint *cMapPoint)
{
    if (vMapPoints.size() >= (CHUNK_SIZE * CHUNK_SIZE))
        return false;

    vMapPoints.push_back(cMapPoint);
    return true;
}

std::vector<CMapPoint*> CAwesomeChunk::getChunk()
{
    return this->vMapPoints;
}

CMapPoint* CAwesomeChunk::getMapPoint(std::uint8_t uiPosX, std::uint8_t uiPosY)
{
    return this->getMapPoint(uiPosY * CHUNK_SIZE + uiPosX);
}

CMapPoint* CAwesomeChunk::getMapPoint(std::uint16_t uiPosChunk)
{
    if (uiPosChunk > (CHUNK_SIZE * CHUNK_SIZE))
        return new CMapPoint();
    else
        return this->vMapPoints.at(uiPosChunk);
}

bool CAwesomeChunk::setMapPoint(std::uint8_t uiPosX, std::uint8_t uiPosY, CMapPoint* cNewMapPoint)
{
    return this->setMapPoint(uiPosY * CHUNK_SIZE + uiPosX, cNewMapPoint);
}

bool CAwesomeChunk::setMapPoint(std::uint16_t uiPosChunk, CMapPoint* cNewMapPoint)
{
    if (uiPosChunk > (CHUNK_SIZE * CHUNK_SIZE))
        return false;
    
    this->vMapPoints.at(uiPosChunk) = cNewMapPoint;
    return true;
}

bool CAwesomeChunk::delMapPointData(std::uint8_t uiPosX, std::uint8_t uiPosY)
{
    return this->delMapPointData(uiPosY * CHUNK_SIZE + uiPosX);
}
bool CAwesomeChunk::delMapPointData(std::uint16_t uiPosChunk)
{
    if (uiPosChunk > (CHUNK_SIZE * CHUNK_SIZE))
        return false;

    return this->setMapPoint(uiPosChunk, &CMapPoint());
}

//TODO: Konstructor
CAwesomeChunk::CAwesomeChunk()
{
    std::cout << "CAwesomeChunk::CAwesomeChunk()" << std::endl;

    for (std::uint16_t i = 0; i < (std::uint16_t)(CHUNK_SIZE * CHUNK_SIZE); i++)
        this->vMapPoints.push_back(&CMapPoint());
}
//TODO: Destructor
CAwesomeChunk::~CAwesomeChunk()
{
    for (std::uint16_t i = 0; i < (std::uint16_t)(CHUNK_SIZE * CHUNK_SIZE); i++)
        this->vMapPoints.at(i)->~CMapPoint();
}