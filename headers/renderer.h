#include <SDL2/SDL.h>
#include "gameMap.h"
#include <vector>
#ifndef GAMEREN_HEADER_INCLUDE
#define GAMEREN_HEADER_INCLUDE
#endif
class GameRenderer {
    private:
        SDL_Rect fieldRect {0, 0, 32, 32};
        SDL_Renderer* renderer;
        SDL_Window* window;
        std::vector<SDL_Texture*> textures;
        int w, h;
    public:
        void setRenderer(SDL_Renderer* ren);
        SDL_Renderer* getRenderer();
        void setWindow(SDL_Window* win);
        SDL_Window* getWindow();
        void addTexture(SDL_Texture* tex);
        void drawMap(GameMap gMap);
        void updateWindowGeometry();
        GameRenderer(SDL_Renderer* ren, SDL_Window* win);
};