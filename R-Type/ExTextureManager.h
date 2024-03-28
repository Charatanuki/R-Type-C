#pragma once

#include <SDL.h>

extern SDL_Texture* explosionTexture;

SDL_Texture* loadExplosionTexture(SDL_Renderer* renderer);
int initializeExplosionTexture(SDL_Renderer* renderer);
void freeExplosionTexture();