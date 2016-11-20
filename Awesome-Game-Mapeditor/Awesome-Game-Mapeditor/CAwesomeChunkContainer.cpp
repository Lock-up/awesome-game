#include "stdafx.h"

/*bool CMapPointStackContainer::setStack(CMapPointStack* cNewPointStack, std::uint32_t uiIndex)
{
    if (uiIndex > this->vMapPointsStacks.size())
        return false;
    else
    {
        this->vMapPointsStacks.at(uiIndex) = cNewPointStack;
        return true;
    }
}

bool CMapPointStackContainer::pushStack(CMapPointStack* cNewPointStack)
{
    if (this->vMapPointsStacks.size() >= sizeof(std::uint64_t))
        return false;

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

CMapPointStack* CMapPointStackContainer::getStack(std::uint64_t uiIndex)
{
    if (this->vMapPointsStacks.size() < uiIndex)
        return new CMapPointStack();
    else
    {
        return this->vMapPointsStacks.at((unsigned int)uiIndex);
    }
}

CMapPoint* CMapPointStackContainer::getLastStackPoint(std::uint64_t uiIndex)
{
    if (this->vMapPointsStacks.size() < uiIndex)
        return new CMapPoint();
    else
        return this->vMapPointsStacks.at((unsigned int)uiIndex)->getLastMapPoint();
}

CMapPointStack* CMapPointStackContainer::getLastStack()
{
    return this->vMapPointsStacks.back();
}*/

// TODO: Konstructor
// TODO: Destructor

bool CAwesomeChunkContainer::setChunk(CAwesomeChunk* cNewChunk, std::uint16_t uiChunkID)
{
    this->vChunks.at(uiChunkID) = cNewChunk;
    return true;
}

bool CAwesomeChunkContainer::pushChunk(CAwesomeChunk* cNewChunk)
{
    this->vChunks.push_back(cNewChunk);
    return true;
}

bool CAwesomeChunkContainer::popChunk()
{
    this->vChunks.pop_back();
    return true;
}

bool CAwesomeChunkContainer::popChunk(std::uint64_t uiChunkID)
{
    this->vChunks.erase(this->vChunks.begin() + uiChunkID);
    return true;
}

CAwesomeChunk* CAwesomeChunkContainer::getChunk(std::uint64_t uiChunkID)
{
    return this->vChunks.at(uiChunkID);
}

std::uint64_t CAwesomeChunkContainer::getChunkCount()
{
    return (std::uint64_t)this->vChunks.size();
}

// TODO: Konstructor
// TODO: Destructor