#ifndef CMAPPOINTSTACKCONTAINER_HPP
#define CMAPPOINTSTACKCONTAINER_HPP

#include "stdafx.h"

class CMapPointStackContainer{
private:
    //std::uint32_t   uiStacksCount;
    //CMapPointStack* pStacks;
    std::vector<CMapPointStack>    vMapPointsStacks;
public:
    bool            setStack(CMapPointStack, std::uint32_t);
    bool            pushStack(CMapPointStack);
    bool            popStack();
    //cant pass x and y as we dont know mapsizes here
    //bool            setStack(CMapPointStack, std::uint8_t, std::uint8_t);
    CMapPointStack  getStack(std::uint32_t);
    //cant pass x and y as we dont know mapsizes here
    //CMapPointStack  getStack(std::uint8_t, std::uint8_t);

    // TODO: Konstructor
    // TODO: Destructor
};

#endif