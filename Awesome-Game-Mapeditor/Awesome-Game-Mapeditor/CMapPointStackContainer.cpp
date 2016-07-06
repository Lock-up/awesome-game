#include "stdafx.h"

bool CMapPointStackContainer::setStack(CMapPointStack cNewPointStack, std::uint32_t uiIndex)
{
    if (uiIndex > this->vMapPointsStacks.size())
        return false;
    else
    {
        this->vMapPointsStacks.at(uiIndex) = cNewPointStack;
        return true;
    }
}

bool CMapPointStackContainer::pushStack(CMapPointStack cNewPointStack)
{
    // TODO: check if we add more stacks than maximum map size
    //if (this->vMapPointsStacks.size())
    this->vMapPointsStacks.push_back(cNewPointStack);
    return true;
}

bool CMapPointStackContainer::popStack()
{
    if (this->vMapPointsStacks.size() <= 0)
        return false;
    else
    {
        this->vMapPointsStacks.pop_back();
        return true;
    }
}

CMapPointStack CMapPointStackContainer::getStack(std::uint64_t uiIndex)
{
    // TODO: check if we read out of bounds
    //if (this->vMapPointsStacks.size() < uiIndex)
    //    return nullptr;
    //else
    {
        return this->vMapPointsStacks.at(uiIndex);
    }
}

// TODO: Konstructor
// TODO: Destructor