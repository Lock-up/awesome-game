#ifndef CMAPPOINTSTACKCONTAINER_HPP
#define CMAPPOINTSTACKCONTAINER_HPP

#include "stdafx.h"

class CMapPointStackContainer{
private:
    //std::uint32_t   uiStacksCount;
    //CMapPointStack* pStacks;
    std::list<CMapPointStack>    lMapPointsStacks;
public:
    bool            setStack(CMapPointStack, std::uint32_t);
    bool            setStack(CMapPointStack, std::uint8_t, std::uint8_t);
    CMapPointStack  getStack(std::uint32_t);
    CMapPointStack  getStack(std::uint8_t, std::uint8_t);
};

#endif