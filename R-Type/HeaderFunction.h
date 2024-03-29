#ifndef HEADERFUNCTION_H
#define HEADERFUNCTION_H

#include <stdbool.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include "PlayerValues.h"
#include "Background.h"

// Init functions
int initSDL();
SDL_Renderer* createRenderer(SDL_Window* window);
void freeAll(SDL_Window* window, SDL_Renderer* renderer);
SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* path);

// Movement player function
void initPlayer(Player* player);
void handleKey(Player* player);
void handlePlayer(SDL_Renderer* renderer, Player* player);
void playerHurt(Player* player);

int scoreDisplay(TTF_Font* font, SDL_Renderer* renderer, Player player);

void levelChange(int* numEnemies, Enemy enemies[], Background* background);

// Menu
int handleMainMenu(SDL_Renderer* renderer);
int handleEnd(SDL_Renderer* renderer);
int endScoreDisplay(TTF_Font* font, SDL_Renderer* renderer);
#endif // !HEADERFUNCTION_H


