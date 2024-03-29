#include "Loop.h"


int mainLoop(SDL_Renderer* renderer, Option option) {
    Enemy enemies[MAX_ENEMIES];
    int numEnemies;
    Player player;
    Background background;
    TTF_Font* font = TTF_OpenFont("sans.ttf", 24);

    initializeExplosionTexture(renderer);
    initializeExplosions();
    unsigned int lastEnemyTime = SDL_GetTicks();
    unsigned int lastFiredFrame = 0;

    initializeGameObjects(enemies, &numEnemies, &player, &background, option);
    while (isAliveCheck(&player)) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        updateExplosions();
        handleEnemySpawn(&lastEnemyTime, &numEnemies, enemies);
        handlePlayerFire(&player, &lastFiredFrame, option);
        updateGameObjects(enemies, numEnemies, &player, &background, renderer, option);
        levelChange(&numEnemies, enemies, &background);
        scoreDisplay(font, renderer, player);
        renderExplosions(renderer);
        renderGameObjects(renderer);
        SDL_Delay(10);
    }
    freeExplosionTexture();
    Mix_Pause(-1);

    return ENDSCREEN;
}