#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>


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
    selectMenu(renderer);

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


