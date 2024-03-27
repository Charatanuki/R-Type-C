#pragma once


#define MAX_ENEMIES 50 // Définissez le nombre maximum d'ennemis que vous voulez afficher

typedef struct {
    SDL_Rect position;
    int speed;
    int active; // permet de gérer les collisions
} Enemy;

void initEnemies(Enemy enemies[], int numEnemies, int width, int height);
void moveEnemies(Enemy enemies[], int numEnemies);


