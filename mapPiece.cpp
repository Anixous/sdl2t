#include "headers/mapPiece.h"

void MapPiece::setType(short type) { MapPiece::type = type; }
void MapPiece::setPid(short pid) { MapPiece::pid = pid; }
short MapPiece::getPid() { return MapPiece::pid; }
short MapPiece::getType() { return MapPiece::type; }