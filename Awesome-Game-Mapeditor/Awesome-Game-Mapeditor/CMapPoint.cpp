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

bool CMapPoint::setResource(std::uint8_t uiNewResource, std::uint8_t uiIndex, bool bForce = true)
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