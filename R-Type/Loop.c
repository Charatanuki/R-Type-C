#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include "HeaderFunction.h"
#include "Projectile.h"
#include "PlayerValues.h"
#include "ennemis.h"
#include "LoopInitFunc.h"


void mainLoop(SDL_Renderer* renderer) {
    Enemy enemies[MAX_ENEMIES];
    int numEnemies;
    Player player;

    unsigned int lastEnemyTime = SDL_GetTicks();
    unsigned int lastFiredFrame = 0;

    initializeGameObjects(enemies, &numEnemies, &player);

    while (1) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        handleEnemySpawn(&lastEnemyTime, &numEnemies, enemies);
        handlePlayerFire(&player, &lastFiredFrame);
        updateGameObjects(enemies, numEnemies, &player, renderer);
        renderGameObjects(renderer);

        SDL_Delay(10);
    }
}


