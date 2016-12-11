#ifndef CMAP_HPP
#define CMAP_HPP

#include "stdafx.h"

class CMap{
private:
    CMapInfo                *cMapInfo;
    CMapPlayerInfo          *cMapPlayerInfo;
    CAwesomeChunkContainer  *cAwesomeChunkContainer;
    sf::Image               *cMapImage;
    sf::Texture             *cMapTexture;
public:
    CMapInfo*                   getMapInfo();
    CMapPlayerInfo*             getMapPlayerInfo();
    CAwesomeChunkContainer*     getCAwesomeChunkContainer();
    
    bool                        generateImage(ResourceHolder<sf::Image, Textures::ID>&);
    bool                        generateTexture();
    sf::Image                   getImage();
    sf::Texture                 getTexture();


    //Constructor
                                CMap();
                                CMap(std::uint64_t, std::uint64_t);
                                CMap(std::string);
};

#endif