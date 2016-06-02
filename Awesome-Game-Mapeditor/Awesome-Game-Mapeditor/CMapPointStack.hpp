#ifndef CMAPPOINTSTACK_HPP
#define CMAPPOINTSTACK_HPP

#include "stdafx.h"

class CMapPointStack{
private:
    std::bitset<8>  bsModifier;
    // 0x01 - isDamaging
    // 0x02 - isHealing
    // 0x04 - isSlowing
    // 0x08 - isHasting
    // 0x10 -
    // 0x20 -
    // 0x40 -
    // 0x80 -
    std::uint8_t            uiLayerCount;
    //CMapPoint*            pMapPoints;
    //std::list<CMapPoint>    lMapPoints;
    std::vector<CMapPoint>  vMapPoints;
    std::uint32_t           uiGUIDBuilding;
    std::uint32_t           uiGUIDUnit;

public:
    std::uint8_t    getMapPointCount();

    std::uint32_t   getBuildingGUID();
    bool            setBuildingGUID(std::uint32_t, bool bForce = true);
    bool            letBuildingGUID();
    bool            hasBuilding();

    std::uint32_t   getUnitGUID();
    bool            setUnitGUID(std::uint32_t, bool bForce = true);
    bool            letUnitGUID();
    bool            hasUnit();

    bool            popMapPoint();
    bool            pushMapPoint(CMapPoint);
    std::vector<CMapPoint>  getMapPoints();

    //TODO: Flags
    //TODO: Konstructor
    //TODO: Destructor
};

#endif