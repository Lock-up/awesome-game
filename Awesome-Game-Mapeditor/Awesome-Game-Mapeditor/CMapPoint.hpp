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

const std::uint8_t uiOption1 = 0x01;
const std::uint8_t uiOption2 = 0x02;
const std::uint8_t uiOption3 = 0x04;
const std::uint8_t uiOption4 = 0x08;
const std::uint8_t uiOption5 = 0x10;
const std::uint8_t uiOption6 = 0x20;
const std::uint8_t uiOption7 = 0x40;
const std::uint8_t uiOption8 = 0x80;

class CMapPoint{
private:
    std::bitset<8>  bsSpecial;
    // 0x01 - isTransparent
    // 0x02 - isStandalone
    // 0x04 - isAnimated
    // 0x08 - canBurn
    // 0x10 -
    // 0x20 -
    // 0x40 -
    // 0x80 -
    std::bitset<8>  bsType;
    // 0x01 - isFluid
    // 0x02 - isFarmland
    // 0x04 - isLight
    // 0x08 - 
    // 0x10 -
    // 0x20 -
    // 0x40 -
    // 0x80 -
    std::uint8_t    uiRGB[3];
    std::uint8_t    uiHeight;
    std::uint8_t    uiAmount;
    Resource        rResource;

public:
    bool            setResource(Resource, bool bForce = true);
    bool            letResource(std::uint8_t, bool bForce = true);
    Resource        getResource();

    bool            addAmount(std::uint8_t, bool bForce = true);
    bool            setAmount(std::uint8_t);
    bool            letAmount(std::uint8_t, bool bForce = true);
    std::uint8_t    getAmount();

    bool            setRGB(std::uint8_t, std::uint8_t, std::uint8_t);
    bool            getRGB(std::uint8_t&, std::uint8_t&, std::uint8_t&);
    bool            changeRGB(std::int16_t);
    bool            setR(std::uint8_t);
    bool            changeR(std::int16_t);
    std::uint8_t    getR();
    bool            setG(std::uint8_t);
    bool            changeG(std::int16_t);
    std::uint8_t    getG();
    bool            setB(std::uint8_t);
    bool            changeB(std::int16_t);
    std::uint8_t    getB();

    std::uint8_t    getHeight();
    bool            setHeight(std::uint8_t);
    bool            addHeight(std::uint8_t, bool bForce = true);
    bool            letHeight(std::uint8_t, bool bForce = true);

    //TODO: Flags
    //TODO: Konstructor
    //TODO: Destructor

private:
    bool            setRGBComponent(std::uint8_t, std::uint8_t);
    std::uint8_t    getRGBComponent(std::uint8_t);
    bool            changeRGBComponent(std::uint8_t, std::int16_t, bool bForce = true);

    bool            hasFlag(std::uint8_t, std::uint8_t);
};

#endif