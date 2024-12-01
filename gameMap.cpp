#include "headers/gameMap.h"
#include <iostream>

short GameMap::getPos(int x, int y) {
    return GameMap::gameMap[x][y];
}
void GameMap::setPos(int x, int y, short value) {
    GameMap::gameMap[x][y] = value;
}
void GameMap::printArray() {
    for(int y = 0; y < 512; y++) {
        for(int x = 0; x < 512; x++) {
            std::cout << "Array (X: " << x << " Y: " << y << ") : " << gameMap[x][y] << std::endl;
        }
    }
    
}
GameMap::GameMap() {
    for(int y = 0; y < 512; y++) {
        for(int x = 0; x < 512; x++) {
            gameMap[x][y] = 0;
        }
    }
}