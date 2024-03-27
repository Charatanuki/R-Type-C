#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ennemis.h"
#include "HeaderFunction.h"

#define MAX_ENEMIES 50 //max ennemi souhaité

void initEnemy(Enemy* enemy, int x, int y, int width, int height, int speed) //initialise l'ennemi de base
{
    enemy->position.x = x;
    enemy->position.y = y;
    enemy->position.w = width;
    enemy->position.h = height;
    enemy->speed = speed;
}

void initEnemies(Enemy enemies[], int numEnemies, int width, int height) //position & vitesse de l'ennemi
{
    srand(time(NULL)); //initialise le generateur random

    for (int i = 0; i < numEnemies; ++i) {
        int x = rand() % width + 800;
        int y = rand() % height;
        int width = 50;
        int height = 50;
        int speed = 1;

        initEnemy(&enemies[i], x, y, width, height, speed);
    }
}

void moveEnemies(Enemy enemies[], int numEnemies) //mouv de l'ennemi
{
    for (int i = 0; i < numEnemies; ++i) {
        enemies[i].position.x -= enemies[i].speed;
    }
}

void drawEnemies(Enemy enemies[], int numEnemies, SDL_Renderer* renderer) //créer des ennemis
{
    SDL_Texture* enemyTexture = loadTexture(renderer, "./ennemy.png");
    for (int i = 0; i < numEnemies; ++i) {
        SDL_Rect enemyRect = { enemies[i].position.x, enemies[i].position.y, enemies[i].position.w, enemies[i].position.h};
        if (enemyTexture != NULL) {
            SDL_RenderCopy(renderer, enemyTexture, NULL, &enemyRect);
        }
        else {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
            SDL_RenderFillRect(renderer, &enemyRect);
        }
    }
}