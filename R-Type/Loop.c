#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_audio.h>
#include "HeaderFunction.h"
#include "Projectile.h"
#include "PlayerValues.h"
#include "ennemis.h"
#include "LoopInitFunc.h"
#include "Background.h"
#include "isAlive.h"
#include "menu.h"
#include "Explosion.h"
#include "ExTextureManager.h"
#include "audio.h"


void mainLoop(SDL_Renderer* renderer) {
    Enemy enemies[MAX_ENEMIES];
    int numEnemies;
    Player player;
    Background background;
    TTF_Font* font = TTF_OpenFont("sans.ttf", 24);
    isAlive = true;
    P1_Health = 3;

    initializeExplosionTexture(renderer);
    initializeExplosions();
    unsigned int lastEnemyTime = SDL_GetTicks();
    unsigned int lastFiredFrame = 0;

    initializeGameObjects(enemies, &numEnemies, &player, &background);
    while (1) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        updateExplosions();

        
        handleEnemySpawn(&lastEnemyTime, &numEnemies, enemies);
        handlePlayerFire(&player, &lastFiredFrame);
        updateGameObjects(enemies, numEnemies, &player, &background, renderer);
        levelChange(&numEnemies, enemies, &background);
        scoreDisplay(font, renderer);
        renderExplosions(renderer);
        renderGameObjects(renderer);
        isAliveCheck(isAlive);
        SDL_Delay(10);

        if (isAlive == false) {
            break;
        }
    }
    freeExplosionTexture();
    stopbgmusic();
}