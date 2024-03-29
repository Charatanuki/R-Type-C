#include "Explosion.h"
#include "ExTextureManager.h"

#define MAX_EXPLOSION_FRAME 6
#define EXPLOSION_WIDTH 50
#define EXPLOSION_HEIGHT 50
#define FRAME_WIDTH 1800
#define FRAME_HEIGHT 360

Explosion explosions[MAX_EXPLOSIONS];

void initializeExplosions() {
    for (int i = 0; i < MAX_EXPLOSIONS; i++) {
        explosions[i].active = 0;
    }
}

void triggerExplosion(int x, int y) {
    for (int i = 0; i < MAX_EXPLOSIONS; i++) {
        if (!explosions[i].active) {
            explosions[i].x = x;
            explosions[i].y = y;
            explosions[i].frame = 0;
            explosions[i].active = 1;
            break;
        }
    }
}

void updateExplosions() {
    for (int i = 0; i < MAX_EXPLOSIONS; i++) {
        if (explosions[i].active) {
            // Update animation frame or other parameters as needed
            explosions[i].frame++;
            if (explosions[i].frame >= MAX_EXPLOSION_FRAME) {
                explosions[i].active = 0; // Deactivate explosion after animation
            }
        }
    }
}

void renderExplosions(SDL_Renderer* renderer) {
    for (int i = 0; i < MAX_EXPLOSIONS; i++) {
        if (explosions[i].active) {
            // Render explosion animation at (explosions[i].x, explosions[i].y)
            SDL_Rect explosionRect = { explosions[i].x, 
                explosions[i].y, EXPLOSION_WIDTH, EXPLOSION_HEIGHT };
            SDL_Rect srcRect = { explosions[i].frame * FRAME_WIDTH, 
                0, FRAME_WIDTH, FRAME_HEIGHT };
            SDL_RenderCopy(renderer, explosionTexture, 
                &srcRect, &explosionRect);
        }
    }
}
