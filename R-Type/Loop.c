#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include "HeaderFunction.h"
#include "Projectile.h"
#include "PlayerValues.h"
#include "ennemis.h"
#include "LoopInitFunc.h"
#include "Background.h"
#include "isAlive.h"
#include "menu.h"
#include "option.h"


void mainLoop(SDL_Renderer* renderer, Option option) {
    Enemy enemies[MAX_ENEMIES];
    int numEnemies;
    Player player;
    Background background;
    TTF_Font* font = TTF_OpenFont("sans.ttf", 24);
    if (font == NULL) {
        printf("Font not loaded");
        return -1;
    }

    unsigned int lastEnemyTime = SDL_GetTicks();
    unsigned int lastFiredFrame = 0;

    initializeGameObjects(enemies, &numEnemies, &player, &background, option);
    printf("x%d    y%d", background.bX, background.bY);
    while (1) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        
        handleEnemySpawn(&lastEnemyTime, &numEnemies, enemies);
        handlePlayerFire(&player, &lastFiredFrame, option);
        updateGameObjects(enemies, numEnemies, &player, &background, renderer, option);
        levelChange(&numEnemies, enemies, &background);
        scoreDisplay(font, renderer, player);
        renderGameObjects(renderer);
        isAliveCheck(player);
        SDL_Delay(10);
    }
}