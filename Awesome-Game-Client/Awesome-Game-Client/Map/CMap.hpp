#ifndef CMAP_HPP
#define CMAP_HPP

#include "stdafx.h"

class CMap{
private:
    CMapInfo                *cMapInfo;
    CMapPlayerInfo          *cMapPlayerInfo;
    CAwesomeChunkContainer  *cAwesomeChunkContainer;
    //sf::Image             *cMapImage;
    //sf::Texture           *cMapTexture;
public:
    CMapInfo*               getMapInfo();
    CMapPlayerInfo*         getMapPlayerInfo();
    CAwesomeChunkContainer* getCAwesomeChunkContainer();
    
    //bool                  generateImage(ResourceHolder<sf::Image, Textures::ID>&);
    //bool                  generateTexture();
    //sf::Image             getImage();
    //sf::Texture           getTexture();
    sf::Texture&            getChunkTexture(std::uint64_t);
    bool                    saveMapWithFilename(char []);
    //bool                  loadMapByFilename(char[]);
    bool                    deserializeVersion_1(unsigned char*, std::uint64_t);

    bool                    increaseSize(std::uint8_t /* uiSizeIndex */);
    bool                    decreaseSize(std::uint8_t /* uiSizeIndex */);

    //Constructor
                            CMap();
                            CMap(std::uint64_t, std::uint64_t, ResourceHolder<sf::Image, Textures::ID>&);
                            CMap(std::uint64_t, std::uint64_t, ResourceHolder<sf::Image, Textures::ID>&, Textures::ID);
                            CMap(std::string, ResourceHolder<sf::Image, Textures::ID>&);
                            CMap(char[], ResourceHolder<sf::Image, Textures::ID>&);
};

#endif