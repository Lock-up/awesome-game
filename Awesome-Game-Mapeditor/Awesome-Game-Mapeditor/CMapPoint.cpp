#include "stdafx.h"

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

bool CMapPoint::setFlags(Flag_Type eFlagType, std::uint8_t uiFlagValue)
{
    switch (eFlagType)
    {
    case Flag_Type::FLAG_SPECIAL: this->bsSpecial |= uiFlagValue; break;
    //case Flag_Type::FLAG_TYPE: this->bsType |= uiFlagValue; break;
    default: return false;
    }
    return true;
}

bool CMapPoint::testFlag(Flag_Type eFlagType, std::uint8_t uiOptID)
{
    switch (eFlagType)
    {
    case Flag_Type::FLAG_SPECIAL:   return bsSpecial.test(uiOptID); break;
    //case Flag_Type::FLAG_TYPE:      return bsType.test(uiOptID); break;
    default:                        return false;
    }
}

std::bitset<8> CMapPoint::getFlag(Flag_Type eFlagType)
{
    switch (eFlagType)
    {
    case Flag_Type::FLAG_SPECIAL: return bsSpecial; break;
    //case Flag_Type::FLAG_TYPE: return bsType; break;
    default: return bsSpecial;
    }
}

bool CMapPoint::setFlag(Flag_Type eFlagType, std::uint8_t uiIndex)
{
    switch (eFlagType)
    {
    case Flag_Type::FLAG_SPECIAL:
    {
        if (bsSpecial.test(uiIndex))
            return false;
        
        bsSpecial.set(uiIndex, 1);
        return true;
    }break;
    //case Flag_Type::FLAG_TYPE:
    //{
    //    if (bsType.test(uiIndex))
    //        return false;
    //
    //    bsType.set(uiIndex, 1);
    //    return true;
    //}break;
    default: return false;
    }
}

bool CMapPoint::letFlag(Flag_Type eFlagType, std::uint8_t uiIndex)
{
    switch (eFlagType)
    {
    case Flag_Type::FLAG_SPECIAL:
    {
        if (!bsSpecial.test(uiIndex))
            return false;

        bsSpecial.set(uiIndex, 0);
        return true;
    }break;
    //case Flag_Type::FLAG_TYPE:
    //{
    //    if (!bsType.test(uiIndex))
    //        return false;
    //
    //    bsType.set(uiIndex, 0);
    //    return true;
    //}break;
    default: return false;
    }
}

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

bool CMapPoint::setResource(std::uint8_t uiNewResource, std::uint8_t uiIndex, bool bForce)
{
    if (uiIndex > 1)
        return false;

    if (this->getResource(uiIndex) != 0 && !bForce)
        return false;

    this->uiResource[uiIndex] = uiNewResource;
    return true;
}

std::uint8_t CMapPoint::getResource(std::uint8_t uiIndex)
{
    if (uiIndex > 1)
        return false;

    return this->uiResource[uiIndex];
}

bool CMapPoint::addAmount(std::uint8_t uiAmount, std::uint8_t uiIndex, bool bForce)
{
    if (uiIndex > 1)
        return false;

    if (this->getAmount(uiIndex) + uiAmount > 255 && !bForce)
        return false;
    else if (this->getAmount(uiIndex) + uiAmount > 255 && bForce)
    { 
        this->uiAmount[uiIndex] = 255;
        return true;
    }

    this->uiAmount[uiIndex] += uiAmount;
    return true;
}

bool CMapPoint::setAmount(std::uint8_t uiNewAmount, std::uint8_t uiIndex)
{
    if (uiIndex > 1)
        return false;

    this->uiAmount[uiIndex] = uiNewAmount;
    return true;
}

bool CMapPoint::letAmount(std::uint8_t uiAmount, std::uint8_t uiIndex, bool bForce)
{
    if (uiIndex > 1)
        return false;

    if (this->getAmount(uiIndex) - uiAmount < 0 && !bForce)
        return false;
    else if (this->getAmount(uiIndex) - uiAmount < 0 && bForce)
    {
        this->uiAmount[uiIndex] = 0;
        return true;
    }

    this->uiAmount[uiIndex] -= uiAmount;
    return true;
}

std::uint8_t CMapPoint::getAmount(std::uint8_t uiIndex)
{
    if (uiIndex > 1)
        return 0;
    else
        return this->uiAmount[uiIndex];
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

bool CMapPoint::addHeight(std::uint8_t uiHeight, bool bForce)
{
    if (this->getHeight() + uiHeight > 255 && !bForce)
        return false;
    else if (this->getHeight() + uiHeight > 255 && bForce)
        return this->setHeight(255);

    return this->setHeight(this->getHeight() + uiHeight);
}

bool CMapPoint::letHeight(std::uint8_t, bool bForce)
{
    if (this->getHeight() - uiHeight < 0 && !bForce)
        return false;
    else if (this->getHeight() - uiHeight < 0 && bForce)
        return this->setHeight(0);

    return this->setHeight(this->getHeight() - uiHeight);
}

bool CMapPoint::addAmount(std::uint8_t uiAmount, bool bForce)
{
    return this->addAmount(uiAmount, 0, bForce);
}

bool CMapPoint::setAmount(std::uint8_t uiAmount)
{
    return this->setAmount(uiAmount, 0);
}

bool CMapPoint::letAmount(std::uint8_t uiAmount, bool bForce)
{
    return this->letAmount(uiAmount, 0, bForce);
}

std::uint8_t CMapPoint::getAmount()
{
    return this->getAmount(0);
}

bool CMapPoint::addMineralAmount(std::uint8_t uiAmount, bool bForce)
{
    return this->addAmount(uiAmount, 1, bForce);
}

bool CMapPoint::setMineralAmount(std::uint8_t uiAmount)
{
    return this->setAmount(uiAmount, 1);
}

bool CMapPoint::letMineralAmount(std::uint8_t uiAmount, bool bForce)
{
    return this->letAmount(uiAmount, 1, bForce);
}

std::uint8_t CMapPoint::getMineralAmount()
{
    return this->getAmount(1);
}

bool CMapPoint::setResourceTextureID(std::uint8_t uiNewResourceTextureID, bool bForce)
{
    if (this->getResourceTextureID() != 0 && !bForce)
        return false;
    else if (this->getResourceTextureID() != 0 && !bForce)
    {
        this->uiResourceTextureID = uiNewResourceTextureID;
        return true;
    }

    this->uiResourceTextureID = uiNewResourceTextureID;
    return true;
}

std::uint8_t CMapPoint::getResourceTextureID()
{
    return this->uiResourceTextureID;
}

CMapPoint::CMapPoint()
{
    this->bsSpecial.reset();

    this->uiRGB[0] = 0;
    this->uiRGB[1] = 0;
    this->uiRGB[2] = 0;

    this->uiHeight = 0;

    this->uiResource[0] = 0;
    this->uiResource[1] = 0;

    this->uiAmount[0] = 0;
    this->uiAmount[1] = 0;

    this->uiResourceTextureID = 0;

    this->GUIDBuilding = 0;
    this->GUIDUnit = 0;
}

CMapPoint::CMapPoint(std::uint8_t uiFlag, std::uint8_t uiR, std::uint8_t uiG, std::uint8_t uiB, std::uint8_t uiHeight, std::uint8_t uiResource, std::uint8_t uiMineralResource, std::uint8_t uiAmount, std::uint8_t uiMineralAmount, std::uint8_t uiResourceID, std::uint64_t GUIDBuilding, std::uint64_t GUIDUnit)
{
    this->setFlags(Flag_Type::FLAG_SPECIAL, uiFlag);

    this->uiRGB[0] = uiR;
    this->uiRGB[1] = uiG;
    this->uiRGB[2] = uiB;

    this->uiHeight = uiHeight;

    this->uiResource[0] = uiResource;
    this->uiResource[1] = uiMineralResource;

    this->uiAmount[0] = uiAmount;
    this->uiAmount[1] = uiMineralAmount;

    this->uiResourceTextureID = uiResourceTextureID;

    this->GUIDBuilding = GUIDBuilding;
    this->GUIDUnit = GUIDUnit;
}