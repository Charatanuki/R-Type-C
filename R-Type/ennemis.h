#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#define MAX_ENEMIES 50 // Définissez le nombre maximum d'ennemis que vous voulez afficher

typedef struct {
    SDL_Rect position;
    int x;
    int y;
    int width;
    int height;
    int speed;
} Enemy;

void initEnemies(Enemy enemies[], int numEnemies);
void moveEnemies(Enemy enemies[], int numEnemies);

#endif // ENEMY_H