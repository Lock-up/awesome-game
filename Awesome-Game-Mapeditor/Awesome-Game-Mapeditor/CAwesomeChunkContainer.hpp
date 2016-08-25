#ifndef CAWESOMECHUNKCONTAINER_HPP
#define CAWESOMECHUNKCONTAINER_HPP

#include "stdafx.h"

class CAwesomeChunkContainer{
private:
    std::vector<CAwesomeChunk*>    vChunks;
public:
    bool            setChunk(CAwesomeChunk*, std::uint16_t);
    bool            pushChunk(CAwesomeChunk*);
    bool            popChunk();
    CAwesomeChunk*  getChunk(std::uint64_t);


};

#endif