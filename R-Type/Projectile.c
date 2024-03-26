#include "Projectile.h"

Projectile projectiles[MAX_PROJECTILES];

void initializeProjectiles() {
	for (int i = 0; i < MAX_PROJECTILES; i++) {
		projectiles[i].active = 0;
	}
}

void fireProjectile(int x, int y, int speed) {
	for (int i = 0; i < MAX_PROJECTILES; i++) {
		if (!projectiles[i].active) {
			projectiles[i].x = x;
			projectiles[i].y = y;
			projectiles[i].speed = speed;
			projectiles[i].active = 1;
			break;
		}
	}
}


void updateProjectiles() {
	for (int i = 0; i < MAX_PROJECTILES; i++) {
		if (projectiles[i].active) {
			projectiles[i].x += projectiles[i].speed;

			if (projectiles[i].x >= 800) {
				projectiles[i].active = 0;
			}
		}
	}
}

void renderProjectiles(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	for (int i = 0; i < MAX_PROJECTILES; i++) {
		if (projectiles[i].active) {
			SDL_Rect projectileRect = { projectiles[i].x, projectiles[i].y, 5, 5 };
			SDL_RenderFillRect(renderer, &projectileRect);
			SDL_Delay(1);
		}

	}
}