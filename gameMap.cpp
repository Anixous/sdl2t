#include "headers/gameMap.h"
#include <iostream>

short GameMap::getType(int x, int y) {
    return GameMap::gameMap[x][y].getType();
}
void GameMap::setType(int x, int y, short value) {
    GameMap::gameMap[x][y].setType(value);
}
GameMap::GameMap() {
}