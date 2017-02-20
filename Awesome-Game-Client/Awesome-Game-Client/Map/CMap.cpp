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
        std::cout << "ChunkID: " << i << std::endl;
        tmpChunk->generateImageAndTexture(rhImages);
        this->getCAwesomeChunkContainer()->pushChunk(tmpChunk);
    }

    this->cMapInfo = new CMapInfo();
    this->cMapInfo->setMapSizes(std::uint16_t(uiSizeX), std::uint16_t(uiSizeY));

    this->cMapPlayerInfo = new CMapPlayerInfo();
}

CMap::CMap(std::string strMapName, ResourceHolder<sf::Image, Textures::ID>& rhImages)
{
    std::cout << "CMap::CMap(string)" << std::endl;
}

CMap::CMap(char name[], ResourceHolder<sf::Image, Textures::ID>& rhImages)
{
    std::cout << "CMap::CMap(char[])" << std::endl;

    FILE *mapfile = NULL;
    unsigned long Buffer = 0;

    char loadstring[60] = "Maps\\";
    strncat_s(loadstring, name, 29);
    strncat_s(loadstring, ".awf", 29);


    //strcpy(mapname, entered);
    fopen_s(&mapfile, loadstring, "rb");

    if (mapfile == NULL)
    {
        std::cout << "Mapfile " << name << "(" << loadstring << ") couldn't be loaded!" << std::endl;
        return;
    }
    else
    {
        std::cout << "Mapfile " << name << "(" << loadstring << ") loaded!" << std::endl;
    }

    fseek(mapfile, 0, SEEK_END);    //to the end of the file
    Buffer = ftell(mapfile);	    //save as Buffer
    fseek(mapfile, 0, SEEK_SET);    //to the start of the file

    unsigned char *tempmapfile = new unsigned char[Buffer]; //My array for the mapdata

    fread(tempmapfile, Buffer, 1, mapfile);

    std::uint16_t uiFileVersion = (std::uint16_t)(tempmapfile[0] * 256 + tempmapfile[1]);

    switch (uiFileVersion)
    {
    case 1:
    {
        deserializeVersion_1(tempmapfile, (std::uint64_t) Buffer);
    }break;
    default:
    {
        std::cout << "Invalid fileversion!" << std::endl;
    }
    }

    // avoid memleak
    tempmapfile = NULL;
    mapfile = NULL;
}

sf::Texture& CMap::getChunkTexture(std::uint64_t uiChunkID)
{
    return this->cAwesomeChunkContainer->getChunk(uiChunkID)->getTexture();
}

bool CMap::saveMapWithFilename(char name[])
{
    this->cMapInfo->serialize(name);
    this->cMapPlayerInfo->serialize(name);
    this->cAwesomeChunkContainer->serialize(name);
    return true;
}

bool CMap::deserializeVersion_1(unsigned char* tempmapfile, std::uint64_t uiBuffer)
{
    // MapInfo
    std::uint16_t uiFileVersion = (std::uint16_t)(tempmapfile[0] * 256 + tempmapfile[1]);
    std::uint64_t uiMapInfoSize = (std::uint64_t)(tempmapfile[2] * 256 + tempmapfile[3]);
    std::uint16_t uiMapInfoSize_X = (std::uint16_t)(tempmapfile[4] * 256 + tempmapfile[5]);
    std::uint16_t uiMapInfoSize_Y = (std::uint16_t)(tempmapfile[6] * 256 + tempmapfile[7]);

    char *name = new char[(int)uiMapInfoSize - 8 + 1];

    for (int i = 0; i < (int)uiMapInfoSize - 8; i++)
        name[i] = tempmapfile[i + 8];

    name[(int)uiMapInfoSize - 8] = '\0';

    std::string strMapName = std::string(reinterpret_cast<const char*>(name));

    this->cMapInfo = new CMapInfo(strMapName, uiMapInfoSize_X, uiMapInfoSize_Y, uiFileVersion);

    name = NULL;
    // MapInfo loaded

    // MapPlayerInfo
    this->cMapPlayerInfo = new CMapPlayerInfo();

    std::uint8_t uiPlayerCount = (int)(tempmapfile[uiMapInfoSize]);
    std::uint64_t uiMapPlayerInfoSize = 1 + (int)(tempmapfile[uiMapInfoSize]) * 4;
    

    for (int j = 0; j < uiPlayerCount; j++)
    {
        // 1 + j * 4 = Offset
        std::uint64_t uiOffsetPlayer = uiMapInfoSize + 1 + j * 4;

        std::uint16_t uiPosX = tempmapfile[uiOffsetPlayer    ] * 256 + tempmapfile[uiOffsetPlayer + 1];
        std::uint16_t uiPosY = tempmapfile[uiOffsetPlayer + 2] * 256 + tempmapfile[uiOffsetPlayer + 3];

        //std::cout << "Loading player at: " << (int)uiPosX << ":" << (int)uiPosY << std::endl;

        this->cMapPlayerInfo->pushPlayer(uiPosX, uiPosY);
    }
    // MapPlayerInfo loaded

    // Chunks
    std::uint64_t uiChunksLength = uiBuffer - uiMapInfoSize - uiMapPlayerInfoSize;
    std::uint32_t uiChunkCount = (std::uint32_t)(uiChunksLength / 8 / 32 / 32);

    this->cAwesomeChunkContainer = new CAwesomeChunkContainer();

    std::uint64_t uiChunkOffset = uiMapInfoSize + uiMapPlayerInfoSize;

    for (std::uint32_t k = 0; k < uiChunkCount; k++)
    {
        CAwesomeChunk *tmpChunk = new CAwesomeChunk();
        // tmpChunk->generateImageAndTexture(rhImages);
        

        for (std::uint16_t l = 0; l < (CHUNK_SIZE * CHUNK_SIZE); l++)
        {
            // std::bitset<8>  bsSpecial;
            // std::uint8_t    uiTextureIDs[2];
            // std::uint8_t    uiHeight;
            // std::uint8_t    uiResource[2];
            // std::uint8_t    uiAmount[2];
            // tmpChunk->getMapPoint(l)->setTexture()

            // // Bitflags
            // ucData[ulOffset] = (int)this->bsSpecial.to_ulong();
            // // Textures
            // ucData[ulOffset] = (int)this->uiTextureIDs[0];
            // ucData[ulOffset] = (int)this->uiTextureIDs[1];
            // // Height
            // ucData[ulOffset] = (int)this->uiHeight;
            // // Resources
            // ucData[ulOffset] = (int)this->uiResource[0];
            // ucData[ulOffset] = (int)this->uiResource[1];
            // // Amounts
            // ucData[ulOffset] = (int)this->uiAmount[0];
            // ucData[ulOffset] = (int)this->uiAmount[1];

            tmpChunk->getMapPoint(l)->setFlag(Flag_Type::FLAG_SPECIAL, (unsigned long)tempmapfile[uiChunkOffset]);
            tmpChunk->getMapPoint(l)->setTextures((std::uint8_t)(tempmapfile[uiChunkOffset + 1]), (std::uint8_t)(tempmapfile[uiChunkOffset + 2]));
            tmpChunk->getMapPoint(l)->setHeight((std::uint8_t)tempmapfile[uiChunkOffset + 3]);
            tmpChunk->getMapPoint(l)->setResources((std::uint8_t)tempmapfile[uiChunkOffset + 4], (std::uint8_t)tempmapfile[uiChunkOffset + 5]);
            tmpChunk->getMapPoint(l)->setAmounts((std::uint8_t)tempmapfile[uiChunkOffset + 6], (std::uint8_t)tempmapfile[uiChunkOffset + 7]);

            uiChunkOffset += 8;
        }

        this->getCAwesomeChunkContainer()->pushChunk(tmpChunk);
    }



    //std::cout << "Chunks: " << (int)(uiChunksLength / 8 / 32 / 32) << std::endl;

    // Chunks loaded

    return true;
}

bool CMap::increaseSize(std::uint8_t uiSizeIndex)
{
    if (uiSizeIndex > 1)
        return false;

    cMapInfo->setMapSize(uiSizeIndex, cMapInfo->getMapSize(uiSizeIndex) + 1);
    return true;
}

bool CMap::decreaseSize(std::uint8_t uiSizeIndex)
{
    if (uiSizeIndex > 1)
        return false;

    cMapInfo->setMapSize(uiSizeIndex, cMapInfo->getMapSize(uiSizeIndex) - 1);
    return true;
}

/*
bool CMap::loadMapByFilename(char name[]){
    FILE *mapfile = NULL;
    unsigned long Buffer = 0;

    char loadstring[60] = "Maps\\";
    strncat_s(loadstring, name, 29);
    strncat_s(loadstring, ".awf", 29);


    //strcpy(mapname, entered);
    fopen_s(&mapfile, loadstring, "rb");

    if (mapfile == NULL)
    {
        std::cout << "Mapfile " << name << "(" << loadstring << ") couldn't be loaded!" << std::endl;
    }
    else
    {
        std::cout << "Mapfile " << name << "(" << loadstring << ") loaded!" << std::endl;
    }

    fseek(mapfile, 0, SEEK_END);    //to the end of the file
    Buffer = ftell(mapfile);	    //save as Buffer
    fseek(mapfile, 0, SEEK_SET);    //to the start of the file

    unsigned char *tempmapfile = new unsigned char[Buffer]; //My array for the mapdata

    fread(tempmapfile, Buffer, 1, mapfile);

    std::uint16_t uiFileVersion = (std::uint16_t)(tempmapfile[0] * 256 + tempmapfile[1]);

    return true;
}*/

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