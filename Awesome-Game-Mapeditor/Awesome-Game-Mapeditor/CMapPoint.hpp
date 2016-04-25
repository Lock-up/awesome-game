#ifndef CMAPPOINT_HPP
#define CMAPPOINT_HPP

#include "includes.hpp"
#include <cstdint>

enum class Resource{
    Wood,
    Stone,
    Salt,
    Food,
    Iron,
};

enum class Type{
    None,
};

enum class Error{
    OUT_OF_BOUND,
    NO_ERROR,
};

class CMapPoint{
private:
    std::uint8_t    uiLayerCount;
    Type*           pType;
    unsigned char*  pRGB;
    std::uint8_t*   pHeight;
    std::uint8_t*   pAmount;
    Resource*       pResource;

public:
    Error setResource(Resource, std::uint8_t);
    Error letResource(std::uint8_t);
    Resource getResource();
    Resource getResource(std::uint8_t);

    Error setAmount(std::uint8_t);
    Error letAmount(std::uint8_t);
    std::uint8_t getAmount(std::uint8_t);
};

#endif