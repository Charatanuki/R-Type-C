#pragma once
#include <stdbool.h>
#include "PlayerValues.h"


// Init functions
int initSDL();
SDL_Renderer* createRenderer(SDL_Window* window);
void freeAll(SDL_Window* window, SDL_Renderer* renderer);
SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* path);



// Movement player function
void initPlayer(Player* player);
void handleKey(Player *player);
void handlePlayer(SDL_Renderer* renderer);
int mainLoop(SDL_Renderer* renderer);