#include "stdafx.h"

CMapInfo* CMap::getMapInfo()
{
    return this->cMapInfo;
}

CMapPlayerInfo* CMap::getMapPlayerInfo()
{
    return this->cMapPlayerInfo;
}

CAwesomeChunkContainer* CMap::getCAwesomeChunkContainer()
{
    return this->cAwesomeChunkContainer;
}

CMap::CMap()
{
    std::cout << "CMap::CMap()" << std::endl;
}

CMap::CMap(std::uint64_t uiSizeX, std::uint64_t uiSizeY, ResourceHolder<sf::Image, Textures::ID>& rhImages)
{
    std::cout << "CMap::CMap(uint64_t, uint64_t)" << std::endl;
    this->cAwesomeChunkContainer = new CAwesomeChunkContainer();

    for (std::uint64_t i = 0; i < uiSizeX*uiSizeY; i++)
    {
        CAwesomeChunk *tmpChunk = new CAwesomeChunk();
        tmpChunk->generateImageAndTexture(rhImages);
        this->getCAwesomeChunkContainer()->pushChunk(tmpChunk);
    }

    this->cMapInfo = new CMapInfo();
    this->cMapInfo->setMapSizes(std::uint16_t(uiSizeX), std::uint16_t(uiSizeY));

    this->cMapPlayerInfo = new CMapPlayerInfo();

    //this->cMapImage = new sf::Image();
}

CMap::CMap(std::uint64_t uiSizeX, std::uint64_t uiSizeY, ResourceHolder<sf::Image, Textures::ID>& rhImages, Textures::ID texID)
{
    std::cout << "CMap::CMap(uint64_t, uint64_t, Texture)" << std::endl;
    this->cAwesomeChunkContainer = new CAwesomeChunkContainer();

    for (std::uint64_t i = 0; i < uiSizeX*uiSizeY; i++)
    {
        CAwesomeChunk *tmpChunk = new CAwesomeChunk(texID);
        tmpChunk->generateImageAndTexture(rhImages);
        this->getCAwesomeChunkContainer()->pushChunk(tmpChunk);
    }

    this->cMapInfo = new CMapInfo();
    this->cMapInfo->setMapSizes(std::uint16_t(uiSizeX), std::uint16_t(uiSizeY));

    this->cMapPlayerInfo = new CMapPlayerInfo();
}

CMap::CMap(std::string strMapName)
{
    std::cout << "CMap::CMap(string)" << std::endl;
}

sf::Texture& CMap::getChunkTexture(std::uint64_t uiChunkID)
{
    return this->cAwesomeChunkContainer->getChunk(uiChunkID)->getTexture();
}

/*
static const Textures::ID aIDtoTexture[] =
{
    Textures::GREENLAND_01,
    Textures::DESERT_01,
    Textures::SNOW_01,
};


// This should be done in the Konstruktor as it creates the image
// or well I'll just move image creation to the constructor
bool CMap::generateImage(ResourceHolder<sf::Image, Textures::ID>& rhImages)
{
    std::cout << "MapsizeX: " << cMapInfo->getMapSizeX() << " | MapsizeY: " << cMapInfo->getMapSizeY() << std::endl;

    // Mapsize (in chunks) is used more than one time
    std::uint64_t uiChunks_X = cMapInfo->getMapSizeX();
    std::uint16_t uiChunks_Y = cMapInfo->getMapSizeY();

    this->cMapImage->create(unsigned int(uiChunks_X*CHUNK_SIZE), unsigned int(uiChunks_Y*CHUNK_SIZE));

    std::cout << "SizeX: " << this->cMapImage->getSize().x << "px | SizeY: " << this->cMapImage->getSize().y << "px" << std::endl;

    // Loop through all chunks
    for (int chunkx = 0; chunkx < uiChunks_X; chunkx++)
    {
        for (int chunky = 0; chunky < uiChunks_Y; chunky++)
        {
            CAwesomeChunk* cTempChunk = this->cAwesomeChunkContainer->getChunk(chunkx * uiChunks_Y + chunky);

            // loop through all mappoints
            for (int pointx = 0; pointx < CHUNK_SIZE; pointx++)
            {
                for (int pointy = 0; pointy < CHUNK_SIZE; pointy++)
                {
                    // std::cout << "No CMapPoint() please!" << std::endl;
                    // Hardcoded Snow for texting (this should create an image that is 64x64pixel wide and repeats the snow texture 2x in each direction
                    //this->cMapImage->setPixel(chunkx*CHUNK_SIZE + pointx, chunky*CHUNK_SIZE + pointy, rhImages.get(Textures::SNOW_01).getPixel(pointx, pointy));
                    // edit: old
                    // This was the Image I Hoped I'd get
                    //this->cMapImage->setPixel(chunkx*CHUNK_SIZE + pointx, chunky*CHUNK_SIZE + pointy, rhImages.get(aIDtoTexture[std::rand() % 3]).getPixel(pointx, pointy));

                    CMapPoint* cTempMapPoint = cTempChunk->getMapPoint(pointx, pointy);

                    // This should make code a bit easyier to understand
                    int uiTextureID = int(cTempMapPoint->getTexture(Texture_Type::TEXTURE_WORLD));
                    // std::uint8_t uiTextureID2 = this->cAwesomeChunkContainer->getChunk(chunkx * uiChunks_Y + chunky)->getPoints().at(pointx * CHUNK_SIZE + pointy)->getTexture(Texture_Type::TEXTURE_WORLD);
                    // Mhhhh or not
                    // Actually it gets the coresponding chunk  (maybe this should be done in the 2nd for loop), and gehts the correct mappoint and then the texture of that mappoint
                    // but now the following should work:

                    //std::cout << "TextureID: " << uiTextureID << std::endl;

                    // seems to be 204???
                    // or one... sometimes this way, sometimes that way
                    // still don't get why those values are returned
                    // std::cout << "TextureID: " << int(uiTextureID) << " or " << int(uiTextureID2) << " or " << int(cTempMapPoint->getTexture(Texture_Type::TEXTURE_WORLD)) << std::endl;

                    this->cMapImage->setPixel(chunkx*CHUNK_SIZE + pointx, chunky*CHUNK_SIZE + pointy, rhImages.get(aIDtoTexture[uiTextureID]).getPixel(pointx, pointy));
                    // As those are currently randomly generated when creating a new map, this should be a quite fuzzy image
                    // and it didn't work or the texture id only returned 0
                }
            }


        }
    }

    return true;
}

sf::Image CMap::getImage()
{
    return *this->cMapImage;
}
*/