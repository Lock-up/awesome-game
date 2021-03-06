#ifndef CMAPPOINT_HPP
#define CMAPPOINT_HPP

#include "stdafx.h"

enum class Resource{
    Wood,
    Stone,
    Salt,
    Food,
    Iron,
    None,
    Empty,
};

enum class Flag_Opt{
    OPT1 = 1,
    OPT2 = 2,
    OPT3 = 4,
    OPT4 = 8,
    OPT5 = 16,
    OPT6 = 32,
    OPT7 = 64,
    OPT8 = 128,
};

enum class Flag_Type
{
    FLAG_SPECIAL,
    FLAG_TYPE,
    FLAG_RESOURCE,
};

enum class Texture_Type
{
    TEXTURE_WORLD,
    TEXTURE_RESOURCE,
};

class CMapPoint{
private:
    std::bitset<8>  bsSpecial;
    // 0x01 - canBurn 
    // 0x02 - isBurning
    // 0x04 - 
    // 0x08 - 
    // 0x10 - 
    // 0x20 - 
    // 0x40 - 
    // 0x80 - 
    std::uint8_t    uiTextureIDs[2];
    std::uint8_t    uiHeight;
    std::uint8_t    uiResource[2];
    std::uint8_t    uiAmount[2];

    std::uint64_t   GUIDBuilding;
    std::uint64_t   GUIDUnit;

public:
    bool            setResource(std::uint8_t, bool bForce = true);
    std::uint8_t    getResource();
    bool            setResources(std::uint8_t, std::uint8_t);

    bool            setMineralResource(std::uint8_t, bool bForce = true);
    std::uint8_t    getMineralResource();

    bool            setTexture(Texture_Type, std::uint8_t);
    bool            setTextures(std::uint8_t, std::uint8_t);
    std::uint8_t    getTexture(Texture_Type);

    bool            addAmount(std::uint8_t, bool bForce = true);
    bool            setAmount(std::uint8_t);
    bool            setAmounts(std::uint8_t, std::uint8_t);
    bool            letAmount(std::uint8_t, bool bForce = true);
    std::uint8_t    getAmount();

    bool            addMineralAmount(std::uint8_t, bool bForce = true);
    bool            setMineralAmount(std::uint8_t);
    bool            letMineralAmount(std::uint8_t, bool bForce = true);
    std::uint8_t    getMineralAmount();

    std::uint8_t    getHeight();
    bool            setHeight(std::uint8_t);
    bool            addHeight(std::uint8_t, bool bForce = true);
    bool            letHeight(std::uint8_t, bool bForce = true);

    bool            setFlags(Flag_Type, std::uint8_t);
    bool            testFlag(Flag_Type, std::uint8_t);
    std::bitset<8>  getFlag(Flag_Type);
    bool            setFlag(Flag_Type, std::uint8_t);
    bool            setFlag(Flag_Type, unsigned long);
    bool            letFlag(Flag_Type, std::uint8_t);

    unsigned char*  serialize();

    //TODO: Konstructor
                    CMapPoint();
                    CMapPoint(Textures::ID);
                    CMapPoint(std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t, std::uint64_t, std::uint64_t);

    //TODO: Destructor
                    //~CMapPoint();
private:
    bool            setResource(std::uint8_t, std::uint8_t);

    // internal amount functions
    bool            addAmount(std::uint8_t, std::uint8_t, bool bForce = true);
    bool            setAmount(std::uint8_t, std::uint8_t);
    bool            letAmount(std::uint8_t, std::uint8_t, bool bForce = true);
    std::uint8_t    getAmount(std::uint8_t);

    // internal resource functions
    bool            setResource(std::uint8_t, std::uint8_t, bool bForce = true);
    std::uint8_t    getResource(std::uint8_t);
};

#endif