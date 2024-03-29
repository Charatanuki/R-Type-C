#pragma once

#include <SDL.h>
#include "ennemis.h"
#include "option.h"

typedef struct {
    int x;
    int y;
    int speed;
    int active;
} Projectile;

#define MAX_PROJECTILES 100

void initializeProjectiles();
void fireProjectile(int x, int y, int speed, Option option);
void updateProjectiles(Enemy* ennemies, Option option); // prend la liste des ennemies pour gérer les collisions
void renderProjectiles(SDL_Renderer* renderer);

extern int isFiring;