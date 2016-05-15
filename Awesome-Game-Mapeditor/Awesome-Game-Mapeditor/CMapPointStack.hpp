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
    std::uint8_t    uiLayerCount;
    CMapPoint*      pMapPoints;
    std::uint32_t   uiGUIDBuilding;
    std::uint32_t   uiGUIDUnit;

public:
    CMapPoint       getLayerPoint();
    CMapPoint       getLayerPoint(std::uint8_t);

    std::uint8_t    getLayerCount();
    bool            setLayerCount(std::uint8_t);
    bool            addLayer(std::uint8_t);
    bool            letLayer(std::uint8_t);
    bool            letLayer(std::uint8_t, bool);

    std::uint32_t   getBuildingGUID();
    bool            setBuildingGUID(std::uint32_t, bool);
    bool            letBuildingGUID();
    bool            hasBuilding();

    std::uint32_t   getUnitGUID();
    bool            setUnitGUID(std::uint32_t, bool);
    bool            letUnitGUID();
    bool            hasUnit();
};

#endif