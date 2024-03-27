#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#define MAX_ENEMIES 50 // D�finissez le nombre maximum d'ennemis que vous voulez afficher

typedef struct {
    SDL_Rect position;
    int speed;
    int active; // permet de g�rer les collisions
} Enemy;

void initEnemies(Enemy enemies[], int numEnemies, int width, int height);
void moveEnemies(Enemy enemies[], int numEnemies);

#endif // ENEMY_H