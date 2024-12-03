#include "headers/renderer.h"

void GameRenderer::setRenderer(SDL_Renderer* ren) {
    GameRenderer::renderer = ren;
}
void GameRenderer::setWindow(SDL_Window* win) {
    GameRenderer::window = win;
}
void GameRenderer::addTexture(SDL_Texture* tex) {
    GameRenderer::textures.push_back(tex);
}
SDL_Renderer* GameRenderer::getRenderer() {
    return GameRenderer::renderer;
}
SDL_Window* GameRenderer::getWindow() {
    return GameRenderer::window;
}
void GameRenderer::updateWindowGeometry() {
    int w, h;
    SDL_GetWindowSize(GameRenderer::window, &w, &h);
    GameRenderer::w = w;
    GameRenderer::h = h;
}
void GameRenderer::drawMap(GameMap gMap) {
    SDL_Rect localRect = GameRenderer::fieldRect;
    for(int y = 0; y < GameRenderer::h / 32 + 1; y++) {
        for(int x = 0; x <= GameRenderer::w / 32 + 1; x++) {     
            SDL_RenderCopy(GameRenderer::renderer, GameRenderer::textures[gMap.getType(x, y)], NULL, &localRect);
            localRect.x += 32;  
        }
        localRect.y += 32;
        localRect.x = 0;
    }
    localRect.x = 0;
    localRect.y = 0;
}
GameRenderer::GameRenderer(SDL_Renderer* ren, SDL_Window* win) {
    GameRenderer::renderer = ren;
    GameRenderer::window = win;
}   