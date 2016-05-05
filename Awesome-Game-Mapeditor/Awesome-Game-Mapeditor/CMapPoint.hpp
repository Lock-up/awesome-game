#ifndef CMAPPOINT_HPP
#define CMAPPOINT_HPP

#include "includes.hpp"
#include "stdafx.h"
#include <cstdint>

enum class Resource{
    Wood,
    Stone,
    Salt,
    Food,
    Iron,
    None,
    Empty,
};

enum class Type{
    None,
};

class CMapPoint{
private:
    Type            tType;
    std::uint8_t    uiRGB[3];
    std::uint8_t    uiHeight;
    std::uint8_t    uiAmount;
    Resource        rResource;

public:
    bool    setResource(Resource, bool);
    bool    letResource(std::uint8_t, bool);
    Resource getResource();

    bool    addAmount(std::uint8_t, bool);
    bool    setAmount(std::uint8_t);
    bool    letAmount(std::uint8_t, bool);
    std::uint8_t getAmount();

    bool    setRGB(std::uint8_t, std::uint8_t, std::uint8_t);
    bool    getRGB(std::uint8_t&, std::uint8_t&, std::uint8_t&);
    bool    changeRGB(std::int16_t);
    bool    setR(std::uint8_t);
    bool    changeR(std::int16_t);
    std::uint8_t getR();
    bool    setG(std::uint8_t);
    bool    changeG(std::int16_t);
    std::uint8_t getG();
    bool    setB(std::uint8_t);
    bool    changeB(std::int16_t);
    std::uint8_t getB();

private:
    bool setRGBComponent(std::uint8_t, std::uint8_t);
    std::uint8_t getRGBComponent(std::uint8_t);
    bool changeRGBComponent(std::int16_t, std::uint8_t);
};

#endif