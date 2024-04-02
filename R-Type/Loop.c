#include "Loop.h"

unsigned int lastEnemyTime;
unsigned int lastFiredFrame;

int mainLoop(SDL_Renderer* renderer, Option option) {
    Enemy enemies[MAX_ENEMIES];
    int numEnemies;
    Player player;
    Background background;
    TTF_Font* font = TTF_OpenFont("./fonts/sans.ttf", 24);
    initValues();

    initializeGameObjects(enemies, &numEnemies, &player, &background,
        option, renderer, 1);
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
    freePlayerTextures();
    Mix_Pause(-1);

    return ENDSCREEN;
}


initValues() {

    level = 1;
    P1_Score = 0;

    lastEnemyTime = SDL_GetTicks();
    lastFiredFrame = 0;
}