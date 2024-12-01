#ifndef GAMEMAP_HEADER_INCLUDE
#define GAMEMAP_HEADER_INCLUDE
#endif

class GameMap {
    private:
        short gameMap[512][512];
    public:
        short getPos(int x, int y);
        void setPos(int x, int y, short value);
        void printArray();
        GameMap();
};