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
    bool            popChunk(std::uint64_t);
    CAwesomeChunk*  getChunk(std::uint64_t);
    std::uint64_t   getChunkCount();
};

#endif