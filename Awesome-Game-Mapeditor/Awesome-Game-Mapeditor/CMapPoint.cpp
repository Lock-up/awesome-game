#include "stdafx.h"

bool CMapPoint::setResource(Resource rNewResource, bool bForce)
{
    if (this->rResource != Resource::None && !bForce)
        return false;

    this->rResource = rNewResource;
    return true;
}

bool CMapPoint::letResource(std::uint8_t uiLetAmount, bool bForce)
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

bool CMapPoint::addAmount(std::uint8_t uiAddAmount, bool bForce)
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

bool CMapPoint::letAmount(std::uint8_t uiLetAmount, bool bForce)
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

bool CMapPoint::setRGB(std::uint8_t uiRValue, std::uint8_t uiGValue, std::uint8_t uiBValue)
{
    this->setRGBComponent(0, uiRValue);
    this->setRGBComponent(1, uiGValue);
    this->setRGBComponent(2, uiBValue);
    return true;
}

bool CMapPoint::getRGB(std::uint8_t& uiTargetR, std::uint8_t& uiTargetG, std::uint8_t& uiTargetB)
{
    uiTargetR = this->getRGBComponent(0);
    uiTargetG = this->getRGBComponent(1);
    uiTargetB = this->getRGBComponent(2);
    return true;
}

bool CMapPoint::changeRGB(std::int16_t iByValue)
{
    this->changeRGBComponent(0, iByValue);
    this->changeRGBComponent(1, iByValue);
    this->changeRGBComponent(2, iByValue);
    return true;
}

bool CMapPoint::setR(std::uint8_t uiNewValue)
{
    return this->setRGBComponent(0, uiNewValue);
}

bool CMapPoint::changeR(std::int16_t iByValue)
{
    return this->changeRGBComponent(0, iByValue);
}

std::uint8_t CMapPoint::getR()
{
    return this->getRGBComponent(0);
}

bool CMapPoint::setG(std::uint8_t uiNewValue)
{
    return this->setRGBComponent(1, uiNewValue);
}

bool CMapPoint::changeG(std::int16_t iByValue)
{
    return this->changeRGBComponent(1, iByValue);
}

std::uint8_t CMapPoint::getG()
{
    return this->getRGBComponent(1);
}

bool CMapPoint::setB(std::uint8_t uiNewValue)
{
    return this->setRGBComponent(2, uiNewValue);
}

bool CMapPoint::changeB(std::int16_t iByValue)
{
    return this->changeRGBComponent(2, iByValue);
}

std::uint8_t CMapPoint::getB()
{
    return this->getRGBComponent(2);
}

std::uint8_t CMapPoint::getHeight()
{
    return this->uiHeight;
}

bool CMapPoint::setHeight(std::uint8_t uiNewHeight)
{
    this->uiHeight = uiNewHeight;
    return true;
}

bool CMapPoint::addHeight(std::uint8_t uiAmount, bool bForce)
{
    if (uiAmount + this->uiHeight > 255 && !bForce)
        return false;
    else if (uiAmount + this->uiHeight > 255 && bForce)
    {
        this->uiHeight = 255;
        return true;
    }
    else
    {
        this->uiHeight += uiAmount;
        return true;
    }
}
bool CMapPoint::letHeight(std::uint8_t uiAmount, bool bForce)
{
    if (uiAmount - this->uiHeight > 0 && !bForce)
        return false;
    else if (uiAmount - this->uiHeight > 0 && bForce)
    {
        this->uiHeight = 0;
        return true;
    }
    else
    {
        this->uiHeight -= uiAmount;
        return true;
    }
}

//TODO: Flags

bool CMapPoint::setRGBComponent(std::uint8_t uiIndex, std::uint8_t uiNewValue)
{
    if (uiIndex > 3)
        return false;

    uiRGB[uiIndex] = uiNewValue;
    return true;
}

std::uint8_t CMapPoint::getRGBComponent(std::uint8_t uiIndex)
{
    if (uiIndex > 3)
        return 0;

    return uiRGB[uiIndex];
}

bool CMapPoint::changeRGBComponent(std::uint8_t uiIndex, std::int16_t iValue, bool bForce)
{
    if (uiIndex > 3)
        return false;

    if (iValue < 0)
    {
        if (uiRGB[uiIndex] + iValue < 0 && !bForce)
            return false;
        else if (uiRGB[uiIndex] + iValue < 0 && bForce)
        {
            uiRGB[uiIndex] = 0;
            return true;
        }
        else
        {
            uiRGB[uiIndex] += iValue;
            return true;
        }
    }
    else
    {
        if (uiRGB[uiIndex] + iValue > 0 && !bForce)
            return false;
        else if (uiRGB[uiIndex] + iValue > 0 && bForce)
        {
            uiRGB[uiIndex] = 255;
            return true;
        }
        else
        {
            this->uiRGB[uiIndex] += iValue;
            return true;
        }
    }
}