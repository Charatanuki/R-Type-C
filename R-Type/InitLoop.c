#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include "HeaderFunction.h"
#include "Projectile.h"
#include "PlayerValues.h"
#include "ennemis.h"
#include "AttackFunctions.h"

#define FIRE_COOLDOWN 100 

void initializeGameObjects(Enemy enemies[], int* numEnemies, Player* player, Background* background) {
    initBackground(background, 0);
    initializeProjectiles();
    srand(time(NULL));
    *numEnemies = 10;
    initEnemies(enemies, *numEnemies, 800, 500);
    initPlayer(player);
}

void handleEnemySpawn(unsigned int* lastEnemyTime, int* numEnemies, Enemy enemies[]) {
    unsigned int currentTime = SDL_GetTicks();
    if (currentTime - *lastEnemyTime > 7500) {
        *lastEnemyTime = currentTime;
        if (*numEnemies < MAX_ENEMIES) {
            initEnemies(&enemies[*numEnemies], 1, 800, 600);
            (*numEnemies)++;
        }
    }
}

void handlePlayerFire(Player* player, unsigned int* lastFiredFrame) {
    unsigned int currentTime = SDL_GetTicks();
    if (isFiring == 1 && (currentTime - *lastFiredFrame) >= FIRE_COOLDOWN) {
        fireProjectile(player->pX + player->pSize, player->pY + player->pSize / 2, 5);
        *lastFiredFrame = currentTime;
    }
}

void updateGameObjects(Enemy enemies[], int numEnemies, Player* player, Background* background, SDL_Renderer* renderer) {
    handleBackground(renderer, background);
    handlePlayer(renderer, player);
    drawEnemies(enemies, numEnemies, renderer);
    moveEnemies(enemies, numEnemies);
    attackPlayer(enemies, player, numEnemies);
    updateProjectiles(enemies);
    levelChange();
}

void renderGameObjects(SDL_Renderer* renderer) {
    renderProjectiles(renderer);
    SDL_RenderPresent(renderer);
}