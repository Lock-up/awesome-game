#include "stdafx.h"

bool CAwesomeChunk::pushMapPoint(CMapPoint *cMapPoint)
{
    if (vMapPoints.size() >= (CHUNK_SIZE * CHUNK_SIZE))
        return false;

    this->vMapPoints.push_back(cMapPoint);
    return true;
}

std::vector<CMapPoint*> CAwesomeChunk::getPoints()
{
    return this->vMapPoints;
}

CMapPoint* CAwesomeChunk::getMapPoint(std::uint8_t uiPosX, std::uint8_t uiPosY)
{
    return this->getMapPoint(uiPosY * CHUNK_SIZE + uiPosX);
    //return this->getMapPoint(uiPosX * CHUNK_SIZE + uiPosY);
}

CMapPoint* CAwesomeChunk::getMapPoint(std::uint16_t uiPosChunk)
{
    if (uiPosChunk > (CHUNK_SIZE * CHUNK_SIZE))
        return new CMapPoint();
    else
        return this->vMapPoints.at(uiPosChunk);
}

bool CAwesomeChunk::setMapPoint(std::uint8_t uiPosX, std::uint8_t uiPosY, CMapPoint* cNewMapPoint)
{
    return this->setMapPoint(uiPosY * CHUNK_SIZE + uiPosX, cNewMapPoint);
}

bool CAwesomeChunk::setMapPoint(std::uint16_t uiPosChunk, CMapPoint* cNewMapPoint)
{
    if (uiPosChunk > (CHUNK_SIZE * CHUNK_SIZE))
        return false;

    this->vMapPoints.at(uiPosChunk) = cNewMapPoint;
    return true;
}

bool CAwesomeChunk::delMapPointData(std::uint8_t uiPosX, std::uint8_t uiPosY)
{
    return this->delMapPointData(uiPosY * CHUNK_SIZE + uiPosX);
}
bool CAwesomeChunk::delMapPointData(std::uint16_t uiPosChunk)
{
    if (uiPosChunk > (CHUNK_SIZE * CHUNK_SIZE))
        return false;

    return this->setMapPoint(uiPosChunk, new CMapPoint());
}

//TODO: Konstructor
CAwesomeChunk::CAwesomeChunk()
{
    std::cout << "CAwesomeChunk::CAwesomeChunk()" << std::endl;

    for (std::uint16_t i = 0; i < (std::uint16_t)(CHUNK_SIZE * CHUNK_SIZE); i++)
    {
        CMapPoint *tmpPoint = new CMapPoint();
        this->vMapPoints.push_back(tmpPoint);
    }
}

CAwesomeChunk::CAwesomeChunk(Textures::ID texID)
{
    std::cout << "CAwesomeChunk::CAwesomeChunk(Textures::ID)" << std::endl;

    for (std::uint16_t i = 0; i < (std::uint16_t)(CHUNK_SIZE * CHUNK_SIZE); i++)
    {
        CMapPoint *tmpPoint = new CMapPoint(texID);
        this->vMapPoints.push_back(tmpPoint);
    }
}
//TODO: Destructor
CAwesomeChunk::~CAwesomeChunk()
{
    std::cout << "CAwesomeChunk::~CAwesomeChunk()" << std::endl;
    for (std::uint16_t i = 0; i < (std::uint16_t)(CHUNK_SIZE * CHUNK_SIZE); i++)
        this->vMapPoints.at(i)->~CMapPoint();
}

bool CAwesomeChunk::generateTexture()
{
    this->cChunkTexture = new sf::Texture;

    std::cout << "CAwesomeChunk::generateTexture" << std::endl;

    if (this->cChunkImage != nullptr)
    {
        this->cChunkTexture->loadFromImage(*this->cChunkImage);
        return true;
    }

    return false;
}

bool CAwesomeChunk::generateImage(ResourceHolder<sf::Image, Textures::ID>& rhImages)
{
    std::cout << "CAwesomeChunk::generateImage" << std::endl;

    // loop through all mappoints
    this->cChunkImage = new sf::Image;
    this->cChunkImage->create(unsigned int(CHUNK_SIZE), unsigned int(CHUNK_SIZE));

    for (int pointx = 0; pointx < CHUNK_SIZE; pointx++)
    {
        for (int pointy = 0; pointy < CHUNK_SIZE; pointy++)
        {
            CMapPoint* cTempMapPoint = this->getMapPoint(pointx, pointy);

            int uiTextureID = int(cTempMapPoint->getTexture(Texture_Type::TEXTURE_WORLD));

            this->cChunkImage->setPixel(pointx, pointy, rhImages.get(aIDToTexture[uiTextureID]).getPixel(pointx, pointy));
        }
    }

    return true;
}

bool CAwesomeChunk::generateImageAndTexture(ResourceHolder<sf::Image, Textures::ID>& rhImages)
{
    std::cout << "CAwesomeChunk::generateImageAndTexture" << std::endl;
    this->generateImage(rhImages);
    this->generateTexture();
    return true;
}

//bool CAwesomeChunk::generateImageAndTexture(ResourceHolder<sf::Image, Textures::ID>& rhImages, Textures::ID texID)
//{
//    std::cout << "CAwesomeChunk::generateImageAndTexture" << std::endl;
//    this->generateImage(rhImages, texID);
//    this->generateTexture();
//    return true;
//}

bool CAwesomeChunk::getTexture(sf::Texture& pTexture)
{
    pTexture = *this->cChunkTexture;
    return true;
}

unsigned char* CAwesomeChunk::serialize()
{
    // Mapinfo block size
    unsigned long int ulData = CHUNK_SIZE * CHUNK_SIZE * 8;
    unsigned long int ulOffset = 0;
    unsigned char* ucData = new unsigned char[ulData];

    for (int i = 0; i < (CHUNK_SIZE * CHUNK_SIZE); i++)
    {
        unsigned char* ucDataPoint = new unsigned char[8];
        ucDataPoint = this->getMapPoint(i)->serialize();
    }

    std::fstream tempmapsave;
    char savestring[60] = "Maps\\CMapInfo.awf";
    //strncat_s(savestring, ".\Maps\mapfile.awf", 29);
    tempmapsave.open(savestring, std::ios_base::binary | std::ios_base::out);
    for (unsigned long int j = 0; j <= ulData - 1; j++)
    {
        tempmapsave << ucData[j];
    }
    tempmapsave.close();

    return ucData;
}