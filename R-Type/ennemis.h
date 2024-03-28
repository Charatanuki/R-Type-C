#pragma once


#define MAX_ENEMIES 50 // D�finissez le nombre maximum d'ennemis que vous voulez afficher

typedef struct {
    SDL_Rect position;
    int speed;
    int active; // permet de g�rer les collisions
    int health;
} Enemy;

void initEnemies(Enemy enemies[], int numEnemies, int width, int height);
void moveEnemies(Enemy enemies[], int numEnemies);

extern int enemeyHealth;
extern int newSpeed;