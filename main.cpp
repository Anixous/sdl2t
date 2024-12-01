#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
//#include "gameMap.h"
#include "headers/renderer.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main (int argc, char ** args) {
    
    if( SDL_Init( SDL_INIT_EVERYTHING ) != 0 )
    {
        return 1;
    }

    SDL_Surface* screen_surface = NULL;
    SDL_Window* window = NULL;

    window = SDL_CreateWindow("Hello, SDL 2!",SDL_WINDOWPOS_UNDEFINED, 
    SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 
    SDL_WINDOW_SHOWN);
    SDL_Renderer *ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == nullptr){
	    std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
	    return 1;
    }   
    if (window == NULL) {
        return 1;
    }
    screen_surface = SDL_GetWindowSurface(window);
    SDL_Texture *square = IMG_LoadTexture(ren, "resources/square.png");
    SDL_Texture *squareB = IMG_LoadTexture(ren, "resources/square_blacked.png");
    SDL_Texture *squareM = IMG_LoadTexture(ren, "resources/square_money.png");
    SDL_Texture *squareF = IMG_LoadTexture(ren, "resources/square_fact.png");
    SDL_Texture *squareS = IMG_LoadTexture(ren, "resources/square_star.png");
    SDL_Texture *squareT = IMG_LoadTexture(ren, "resources/square_taken.png");
    SDL_Texture *bottom_pane = IMG_LoadTexture(ren, "resources/palette.png");
    bool isRunning = true;
    bool fullscreen = false;

    SDL_UpdateWindowSurface(window);
    SDL_RenderClear(ren);
    int w, h;
    SDL_GetWindowSize(window, &w, &h);
    SDL_Rect rect {0, 0, 32, 32};
    
    GameMap gMap;
    
    SDL_Event e;
    GameRenderer myRender(ren, window);
    myRender.updateWindowGeometry();
    myRender.addTexture(square);
    myRender.addTexture(squareB);
    myRender.addTexture(squareM);
    myRender.addTexture(squareF);
    myRender.addTexture(squareS);
    myRender.addTexture(squareT);
    short fieldType = 1;
    while(isRunning){
        SDL_GetWindowSize(window, &w, &h);
        myRender.drawMap(gMap);
        SDL_RenderPresent(ren);
        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_1) { fieldType = 1; }
            if(e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_2) { fieldType = 2; }
            if(e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_3) { fieldType = 3; }
            if(e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_4) { fieldType = 4; }
            if(e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_5) { fieldType = 5; }
            if(e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_0) { fieldType = 0; }
            if(fullscreen) {
                SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
            } else {
                SDL_SetWindowFullscreen(window, 0); 
            }
            if(e.type == SDL_QUIT) {
                isRunning = false;
            }
            if(e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                isRunning = false;
            }
            if(e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
                myRender.updateWindowGeometry();
                myRender.drawMap(gMap); 
             }
            if(e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_F11) {
                fullscreen = !fullscreen;
            }
            if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
                gMap.setPos(e.button.x / 32, e.button.y / 32, fieldType);
                if(fieldType == 4) {
                    for(int x = -2; x < 3; x++) {
                        for(int y = -2; y < 3; y++) {
                            gMap.setPos(e.button.x / 32 + x, e.button.y / 32 + y, 5);
                        }
                    }
                    gMap.setPos(e.button.x / 32, e.button.y / 32, fieldType);
                } 
                SDL_RenderClear(ren);
                myRender.drawMap(gMap);
                SDL_RenderPresent(ren);
            }
        }
        myRender.drawMap(gMap);
        SDL_RenderPresent(ren);
    }

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
};