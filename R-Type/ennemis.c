#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ennemis.h"
#include "HeaderFunction.h"

void initEnemy(Enemy* enemy, int x, int y, int width, 
    int height, int speed, int enemeyHealth) //initialise l'ennemi de base
{
    enemy->position.x = x;
    enemy->position.y = y;
    enemy->position.w = width;
    enemy->position.h = height;
    enemy->speed = speed;
    enemy->active = 1;
    enemy->health = enemeyHealth;
}

void initEnemies(Enemy enemies[], int numEnemies, int width, 
    int height, int newSpeed, int enemeyHealth) //position & vitesse de l'ennemi
{
    srand(time(NULL)); //initialise le generateur random

    for (int i = 0; i < numEnemies; ++i) {
        int x = rand() % width + 800;
        int y = rand() % height;
        int width = 50;
        int height = 50;
        int speed = newSpeed;
        int health = enemeyHealth;

        initEnemy(&enemies[i], x, y, width, height, speed, health);
    }
}

void moveEnemies(Enemy enemies[], int numEnemies) //mouv des ennmies actifs
{
    for (int i = 0; i < numEnemies; ++i) {
        if (enemies[i].active) {
            enemies[i].position.x -= enemies[i].speed;
        }
    }
}

void drawEnemies(Enemy enemies[], int numEnemies, SDL_Renderer* renderer) //affiche les ennemy actifs
{
    SDL_Texture* enemyTexture = loadTexture(renderer, "./ennemy.png");
    for (int i = 0; i < numEnemies; ++i) {
        if (enemies[i].active) {
            SDL_Rect enemyRect = { enemies[i].position.x, enemies[i].position.y, 
                enemies[i].position.w, enemies[i].position.h };
            if (enemyTexture != NULL) {
                SDL_RenderCopy(renderer, enemyTexture, NULL, &enemyRect);
            }
            else {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                SDL_RenderFillRect(renderer, &enemyRect);
            }
        }
    }
}


void attackPlayer(Enemy enemies[], Player *player, int numEnemies) {
    if (player->immortal != 1) {
        for (int i = 0; i < numEnemies; i++) {
            if (enemies[i].active) {
                if (enemies[i].active &&
                    player->pX <= enemies[i].position.x + enemies[i].position.w / 2
                    && player->pX >= enemies[i].position.x - enemies[i].position.w / 2

                    && player->pY <= enemies[i].position.y + enemies[i].position.h &&
                    player->pY >= enemies[i].position.y - enemies[i].position.h) {
                    enemies[i].active = 0;
                    printf("player got hurt\n");
                    playerHurt(player);
                }
            }
        }
    }
}