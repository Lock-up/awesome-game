#include "stdafx.h"

bool CMapPoint::setResource(Resource rNewResource, bool bForce = false)
{
    if (this->rResource != Resource::None && !bForce)
        return false;

    this->rResource = rNewResource;
    return true;
}

bool CMapPoint::letResource(std::uint8_t uiLetAmount, bool bForce = false)
{
    if (this->uiAmount < uiLetAmount && !bForce)
        return false;
    else if (this->uiAmount < uiLetAmount && bForce)
    {
        this->uiAmount = 0;
        return true;
    }
    else
    {
        this->uiAmount -= uiLetAmount;
        return true;
    }
}

Resource CMapPoint::getResource()
{
    return this->rResource;
}

bool CMapPoint::addAmount(std::uint8_t uiAddAmount, bool bForce = false)
{
    if (this->uiAmount + uiAddAmount > 255 && !bForce)
        return false;
    else if (this->uiAmount + uiAddAmount > 255 && bForce)
    {
        this->uiAmount = 255;
        return true;
    }
    else
    {
        this->uiAmount += uiAddAmount;
        return true;
    }
}

bool CMapPoint::setAmount(std::uint8_t uiNewAmount)
{
    this->uiAmount = uiNewAmount;
    return true;
}

bool CMapPoint::letAmount(std::uint8_t uiLetAmount, bool bForce = false)
{
    if (this->uiAmount - uiLetAmount < 0 && !bForce)
        return false;
    else if (this->uiAmount - uiLetAmount < 0 && bForce)
    {
        this->uiAmount = 0;
        return true;
    }
    else
    {
        this->uiAmount -= uiLetAmount;
        return true;
    }
}

std::uint8_t CMapPoint::getAmount()
{
    return this->uiAmount;
}