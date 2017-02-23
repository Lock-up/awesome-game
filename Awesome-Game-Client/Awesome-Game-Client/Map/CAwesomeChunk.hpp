#ifndef AWESOMECHUNK_HPP
#define AWESOMECHUNK_HPP

#include "stdafx.h"

const std::uint8_t CHUNK_SIZE = 32;

class CAwesomeChunk{
private:
    std::vector<CMapPoint*> vMapPoints;

public:

    std::vector<CMapPoint*> getPoints();

    CMapPoint*              getMapPoint(std::uint8_t, std::uint8_t);
    CMapPoint*              getMapPoint(std::uint16_t);

    sf::Image               *cChunkImage;
    sf::Texture             *cChunkTexture;

    bool                    setMapPoint(std::uint8_t, std::uint8_t, CMapPoint*);
    bool                    setMapPoint(std::uint16_t, CMapPoint*);

    bool                    delMapPointData(std::uint8_t, std::uint8_t);
    bool                    delMapPointData(std::uint16_t);

    bool                    generateImageAndTexture();
    //bool                    generateImageAndTexture(ResourceHolder<sf::Image, Textures::ID>&, Textures::ID);

    bool                    generateImage();
    //bool                    generateImage(ResourceHolder<sf::Image, Textures::ID>&, Textures::ID);
    bool                    generateTexture();

    sf::Image               getImage(){ return *this->cChunkImage; };
    //sf::Texture             getTexture() { return *this->cChunkTexture; };
    sf::Texture&            getTexture() { return *this->cChunkTexture; };

    bool                    getTexture(sf::Texture&);
    unsigned char*          serialize();

    //TODO: Konstructor
    CAwesomeChunk();
    CAwesomeChunk(Textures::ID);
    //TODO: Destructor
    ~CAwesomeChunk();
private:
    bool                    pushMapPoint(CMapPoint*);
};

#endif