#pragma once


#define MAX_ENEMIES 100 // Définissez le nombre maximum d'ennemis que vous voulez afficher

typedef struct {
    SDL_Rect position;
    int speed;
    int active; // permet de gérer les collisions
    int health;
} Enemy;

void initEnemies(Enemy enemies[], int numEnemies, int width, int height, int newSpeed, int enemeyHealth);
void moveEnemies(Enemy enemies[], int numEnemies);

extern int enemeyHealth;
extern int newSpeed;