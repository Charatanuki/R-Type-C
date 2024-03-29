#include <SDL.h>
#include <SDL_image.h>
#include "PTextureManager.h"

SDL_Texture* playerTextureNormal;
SDL_Texture* playerTextureInvincible;

SDL_Texture* loadPlayerTexture(SDL_Renderer* renderer, int type) {
    SDL_Surface* normalSurface;
    if (type == 0) {
        normalSurface = IMG_Load("./spaceship.png"); // Remove SDL_Surface* 
    }
    else {
        normalSurface = IMG_Load("./Shield-ship.png"); // Remove SDL_Surface* 
    }
    if (!normalSurface) { // Remove & from normalSurface
        printf("Failed to load normal player texture: %s\n", IMG_GetError());
        return NULL;
    }

    // Set color key for transparency (optional)
    SDL_SetColorKey(normalSurface, SDL_TRUE, 
        SDL_MapRGB(normalSurface->format, 255, 0, 255)); // Remove & from normalSurface

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, normalSurface); // Remove & from normalSurface
    SDL_FreeSurface(normalSurface); // Free the surface as it's no longer needed

    return texture;
}


int loadPlayerTextures(SDL_Renderer* renderer) {
    playerTextureNormal = loadPlayerTexture(renderer, 0);
    if (!playerTextureNormal) {
        printf("Failed to load normal player texture.");
        SDL_Quit();
        return -1;
    }
    playerTextureInvincible = loadPlayerTexture(renderer, 1);
    if (!playerTextureInvincible) {
        printf("Failed to load invincible player texture.");
        SDL_Quit();
        return -1;
    }
}



void freePlayerTextures() {
    if (playerTextureNormal != NULL) {
        SDL_DestroyTexture(playerTextureNormal);
        playerTextureNormal = NULL;
    }
    if (playerTextureInvincible != NULL) {
        SDL_DestroyTexture(playerTextureInvincible);
        playerTextureInvincible = NULL;
    }
}