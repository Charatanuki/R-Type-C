#pragma once
#include <SDL.h>
#include "ennemis.h"
#include "PlayerValues.h"
#include "Background.h"

void initializeGameObjects(Enemy enemies[], int* numEnemies, Player* player, Background* background);
void handleEnemySpawn(unsigned int* lastEnemyTime, int* numEnemies, Enemy enemies[]);
void handlePlayerFire(Player* player, unsigned int* lastFiredFrame);
void updateGameObjects(Enemy enemies[], int numEnemies, Player* player, Background* background, SDL_Renderer* renderer);
void renderGameObjects(SDL_Renderer* renderer);