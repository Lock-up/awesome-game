#include "stdafx.h"

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

bool CMapPoint::setFlag(Flag_Type eFlagType, unsigned long ulValue)
{
    bsSpecial = std::bitset<8>(ulValue);
    return true;
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

bool CMapPoint::setResource(std::uint8_t uiNewResource, std::uint8_t uiIndex, bool bForce)
{
    if (uiIndex > 1)
        return false;

    if (this->getResource(uiIndex) != 0 && !bForce)
        return false;

    this->uiResource[uiIndex] = uiNewResource;
    return true;
}

bool CMapPoint::setResources(std::uint8_t uiResource1, std::uint8_t uiResource2)
{
    this->uiResource[0] = uiResource1;
    this->uiResource[1] = uiResource2;
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

bool CMapPoint::setAmounts(std::uint8_t uiNewAmount1, std::uint8_t uiNewAmount2)
{
    this->uiAmount[0] = uiNewAmount1;
    this->uiAmount[1] = uiNewAmount2;
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

bool CMapPoint::setTexture(Texture_Type eTextureType, std::uint8_t uiTextureID)
{
    switch (eTextureType)
    {
    case Texture_Type::TEXTURE_WORLD:
    {
        this->uiTextureIDs[0] = uiTextureID;
        return true;
    }break;
    case Texture_Type::TEXTURE_RESOURCE:
    {
        this->uiTextureIDs[1] = uiTextureID;
        return true;
    }break;
    default:
    {
        return false;
    }break;
    }
}

bool CMapPoint::setTextures(std::uint8_t uiTextureID_World, std::uint8_t uiTextureID_Resource)
{
    return(this->setTexture(Texture_Type::TEXTURE_WORLD, uiTextureID_World) && this->setTexture(Texture_Type::TEXTURE_RESOURCE, uiTextureID_Resource));
}

std::uint8_t CMapPoint::getTexture(Texture_Type eTextureType)
{
    //std::cout << "My Textures are: " << int(uiTextureIDs[0]) << " and " << int(uiTextureIDs[1]) << std::endl;

    switch (eTextureType)
    {
    case Texture_Type::TEXTURE_WORLD:
    {
        return this->uiTextureIDs[0];
    }break;
    case Texture_Type::TEXTURE_RESOURCE:
    {
        return this->uiTextureIDs[1];
    }break;
    default:
    {
        return 0;
    }break;
    }
}

CMapPoint::CMapPoint()
{
    this->bsSpecial.reset();

    //std::cout << "CMapPoint::CMapPoint()" << std::endl;

    // Testing, should be default 0
    this->uiTextureIDs[0] = 0;//std::rand() % 3;
    this->uiTextureIDs[1] = 0;//std::rand() % 3;

    // std::cout << "My Textures are: " << int(uiTextureIDs[0]) << " and " << int(uiTextureIDs[1]) << std::endl;
    // looks like it working at this point
    // std::cout << "Mappoint Textures: " << int(uiTextureIDs[0]) << " and " << int(uiTextureIDs[1]) << std::endl;

    this->uiHeight = 0;

    this->uiResource[0] = 0;
    this->uiResource[1] = 0;

    this->uiAmount[0] = 0;
    this->uiAmount[1] = 0;

    this->GUIDBuilding = 0;
    this->GUIDUnit = 0;
}

CMapPoint::CMapPoint(Textures::ID texID)
{
    this->bsSpecial.reset();

    //std::cout << "CMapPoint::CMapPoint()" << std::endl;

    // Testing, should be default 0
    this->uiTextureIDs[0] = texID;//std::rand() % 3;
    this->uiTextureIDs[1] = 0;//std::rand() % 3;

    // std::cout << "My Textures are: " << int(uiTextureIDs[0]) << " and " << int(uiTextureIDs[1]) << std::endl;
    // looks like it working at this point
    // std::cout << "Mappoint Textures: " << int(uiTextureIDs[0]) << " and " << int(uiTextureIDs[1]) << std::endl;

    this->uiHeight = 128;

    this->uiResource[0] = 0;
    this->uiResource[1] = 0;

    this->uiAmount[0] = 0;
    this->uiAmount[1] = 0;

    this->GUIDBuilding = 0;
    this->GUIDUnit = 0;
}

CMapPoint::CMapPoint(std::uint8_t uiFlag, std::uint8_t uiTextureID_World, std::uint8_t uiTextureID_Resource, std::uint8_t uiHeight, std::uint8_t uiResource, std::uint8_t uiMineralResource, std::uint8_t uiAmount, std::uint8_t uiMineralAmount, std::uint8_t uiResourceID, std::uint64_t GUIDBuilding, std::uint64_t GUIDUnit)
{
    this->setFlags(Flag_Type::FLAG_SPECIAL, uiFlag);

    this->uiTextureIDs[0] = uiTextureID_World;
    this->uiTextureIDs[1] = uiTextureID_Resource;

    this->uiHeight = uiHeight;

    this->uiResource[0] = uiResource;
    this->uiResource[1] = uiMineralResource;

    this->uiAmount[0] = uiAmount;
    this->uiAmount[1] = uiMineralAmount;

    this->GUIDBuilding = GUIDBuilding;
    this->GUIDUnit = GUIDUnit;
}

unsigned char* CMapPoint::serialize()
{
    // Mapinfo block size
    unsigned long int ulData = 0;
    unsigned long int ulOffset = 0;

    // Data length =
    //std::bitset<8>  bsSpecial;        -> 1Byte
    //std::uint8_t    uiTextureIDs[2];  -> 2Byte
    //std::uint8_t    uiHeight;         -> 1Byte
    //std::uint8_t    uiResource[2];    -> 2Byte
    //std::uint8_t    uiAmount[2];      -> 2Byte
    //                                  -> 8Byte

    ulData += 8;

    // Data Array
    unsigned char* ucData = new unsigned char[ulData];
    
    // Bitflags
    ucData[ulOffset] = (int)this->bsSpecial.to_ulong();
    ulOffset++;

    // Textures
    ucData[ulOffset] = (int)this->uiTextureIDs[0];
    ulOffset++;

    ucData[ulOffset] = (int)this->uiTextureIDs[1];
    ulOffset++;

    // Height
    ucData[ulOffset] = (int)this->uiHeight;
    ulOffset++;

    // Resources
    ucData[ulOffset] = (int)this->uiResource[0];
    ulOffset++;

    ucData[ulOffset] = (int)this->uiResource[1];
    ulOffset++;

    // Amounts
    ucData[ulOffset] = (int)this->uiAmount[0];
    ulOffset++;

    ucData[ulOffset] = (int)this->uiAmount[1];

    //std::fstream tempmapsave;
    //char savestring[60] = "Maps\\CMapPoint.awf";
    ////strncat_s(savestring, ".\Maps\mapfile.awf", 29);
    //tempmapsave.open(savestring, std::ios_base::binary | std::ios_base::out);
    //for (unsigned long int j = 0; j <= ulData - 1; j++)
    //{
    //    tempmapsave << ucData[j];
    //}
    //tempmapsave.close();

    return ucData;
}