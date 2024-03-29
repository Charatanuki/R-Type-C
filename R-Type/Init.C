#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "HeaderFunction.h"
#include "menu.h"
#include "option.h"


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
        return NULL;
    }
    int gameState = handleMainMenu(renderer);
    Option option;
    initOption(&option);
    while (gameState != ERROR && gameState != QUIT)
    {
        switch (gameState)
        {
        case PLAY:
            mainLoop(renderer, option);
            break;
        case OPTION:
            gameState = QUIT; // changer QUIT par l'appel pour aller sur l'écran des options
            break;
        case MENU:
            gameState = handleMainMenu(renderer);
            break;
        case ENDSCREEN:
            gameState = QUIT; // changer QUIT par l'appel pour aller sur l'endscreen
            break;
        default:
            break;
        }
    }
    return renderer;
}

void freeAll(SDL_Window* window, SDL_Renderer* renderer) {
    SDL_DestroyRenderer(*&renderer);
    SDL_DestroyWindow(*&window);
    SDL_Quit();
}

// permet de générer n'importe quel png comme texture
SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* path) {
    SDL_Texture* texture = NULL;

    // Load player image
    SDL_Surface* surface = IMG_Load(path);
    if (surface == NULL) {
        printf("Failed to load %s: %s\n", path, IMG_GetError());
        return NULL;
        // Handle error
    }
    // Create texture from surface
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL) {
        printf("Failed to create texture from %s surface: %s\n", path, SDL_GetError());
        return NULL;
        // Handle error
    }
    SDL_FreeSurface(surface); // Free the surface once the texture is created
    return texture;
}


