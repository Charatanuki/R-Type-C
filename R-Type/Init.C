#include <SDL.h>
#include <stdio.h>
#include "HeaderFunction.h"


int initSDL() {
    // init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return -1;
    }

    return 0;
}

SDL_Renderer* createRenderer(SDL_Window* window) {
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }   mainLoop(renderer);



    return renderer;
}

void freeAll(SDL_Window* window, SDL_Renderer* renderer) {
    SDL_DestroyRenderer(*&renderer);
    SDL_DestroyWindow(*&window);
    SDL_Quit();
}