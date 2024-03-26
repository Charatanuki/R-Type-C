#pragma once

#include <SDL.h>

typedef struct {
    int x;
    int y;
    int speed;
    int active;
} Projectile;

#define MAX_PROJECTILES 100

void initializeProjectiles();
void fireProjectile(int x, int y, int speed);
void updateProjectiles();
void renderProjectiles(SDL_Renderer* renderer);

extern int isFiring;