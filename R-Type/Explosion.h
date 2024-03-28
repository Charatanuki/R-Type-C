#pragma once


#include <SDL.h>

#define MAX_EXPLOSIONS 10

typedef struct {
    int x;
    int y;
    int frame;
    int active;
} Explosion;

extern Explosion explosions[MAX_EXPLOSIONS];

void initializeExplosions();
void triggerExplosion(int x, int y);
void updateExplosions();
void renderExplosions(SDL_Renderer* renderer);
