#include "ExTextureManager.h" 
#include "Explosion.h"
#include <SDL_image.h>

SDL_Texture* explosionTexture;

SDL_Texture* loadExplosionTexture(SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load("explosion.png"); // Replace with actual path
    if (!surface) {
        printf("Failed to load explosion texture: %s\n", IMG_GetError());
        return NULL;
    }

    // Set color key for transparency (optional)
    SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 255, 0, 255));

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface); // Free the surface as it's no longer needed

    return texture;
}

int initializeExplosionTexture(SDL_Renderer* renderer) {
    explosionTexture = loadExplosionTexture(renderer);
    if (!explosionTexture) {
        printf("Failed to load explosion texture.");
        SDL_Quit();
        return -1;
    }
}

void freeExplosionTexture() {
    if (explosionTexture) {
        SDL_DestroyTexture(explosionTexture);
        explosionTexture = NULL;
    }
}
