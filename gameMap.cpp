#include "headers/gameMap.h"
#include <iostream>

short GameMap::getType(int x, int y) {
    return GameMap::gameMap[x][y].getType();
}
void GameMap::setType(int x, int y, short value) {
    GameMap::gameMap[x][y].setType(value);
}
short GameMap::getOwner(int x, int y) {
    return GameMap::gameMap[x][y].getPid();
}
void GameMap::setOwner(int x, int y, short pid) {
    GameMap::gameMap[x][y].setPid(pid);
}
GameMap::GameMap() {
}