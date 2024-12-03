#ifndef GAMEMAP_HEADER_INCLUDE
#define GAMEMAP_HEADER_INCLUDE
#endif
#include "mapPiece.h"

class GameMap {
    private:
        MapPiece gameMap[512][512];
    public:
        short getType(int x, int y);
        void setType(int x, int y, short value);
        short getOwner(int x, int y);
        void setOwner(int x, int y, short pid);
        //void printArray();
        GameMap();
};