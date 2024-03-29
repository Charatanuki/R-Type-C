#pragma once
#include <SDL.h>
#include "ennemis.h"
#include "PlayerValues.h"
#include "Background.h"
#include "option.h"

void initializeGameObjects(Enemy enemies[], int* numEnemies, Player* player, Background* background, Option option);
void handleEnemySpawn(unsigned int* lastEnemyTime, int* numEnemies, Enemy enemies[]);
void handlePlayerFire(Player* player, unsigned int* lastFiredFrame, Option option);
void updateGameObjects(Enemy enemies[], int numEnemies, Player* player, Background* background, SDL_Renderer* renderer, Option option);
void renderGameObjects(SDL_Renderer* renderer);