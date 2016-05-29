#include "stdafx.h"

std::uint8_t CMapPointStack::getMapPointCount()
{
    return this->lMapPoints.size();
}

std::uint32_t CMapPointStack::getBuildingGUID()
{
    return this->uiGUIDBuilding;
}

bool CMapPointStack::setBuildingGUID(std::uint32_t uiGUIDNewBuilding, bool bForce)
{
    if (this->uiGUIDBuilding != 0 && !bForce)
        return false;
    else
    {
        this->uiGUIDBuilding = uiGUIDNewBuilding;
        return true;
    }
}

bool CMapPointStack::letBuildingGUID()
{
    this->uiGUIDBuilding = 0;
    return true;
}

bool CMapPointStack::hasBuilding()
{
    return this->uiGUIDBuilding != 0;
}

std::uint32_t CMapPointStack::getUnitGUID()
{
    return this->uiGUIDUnit;
}

bool CMapPointStack::setUnitGUID(std::uint32_t uiGUIDNewUnit, bool bForce)
{
    if (this->uiGUIDUnit != 0 && !bForce)
        return false;
    else
    {
        this->uiGUIDUnit = uiGUIDNewUnit;
        return true;
    }
}

bool CMapPointStack::letUnitGUID()
{
    this->uiGUIDUnit = 0;
    return true;
}

bool CMapPointStack::hasUnit()
{
    return this->uiGUIDUnit != 0;
}

bool CMapPointStack::popMapPoint()
{
    if (lMapPoints.size() <= 0)
        return false;

    lMapPoints.pop_back();
    return true;
}

bool CMapPointStack::pushMapPoint(CMapPoint cMapPoint)
{
    if (lMapPoints.size() >= 255)
        return false;

    lMapPoints.push_back(cMapPoint);
    return true;
}

std::list<CMapPoint> CMapPointStack::getMapPoints()
{
    return this->lMapPoints;
}

//TODO: Flags
//TODO: Konstructor
//TODO: Destructor