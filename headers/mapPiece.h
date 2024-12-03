#ifndef MAP_PIECE_INCLUDE
#define MAP_PIECE_INCLUDE
#endif


class MapPiece {
    private:
        short pid;
        short type;
    public:
        void setType(short type);
        void setPid(short pid);
        short getType();
        short getPid();
};