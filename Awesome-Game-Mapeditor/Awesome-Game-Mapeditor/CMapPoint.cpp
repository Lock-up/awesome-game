#include "includes.hpp"

Error CMapPoint::setResource(Resource resource, std::uint8_t uiLayer)
{
    if (uiLayer > this->uiLayerCount)
        return Error::OUT_OF_BOUND;

    this->pResource[uiLayer] = resource;
    return Error::NO_ERROR;

}