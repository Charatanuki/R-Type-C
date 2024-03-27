#include "Projectile.h"
#include "PlayerScoreValues.h"

int P1_Score = 0;

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


void updateProjectiles(Enemy* enemies) {
	for (int i = 0; i < MAX_PROJECTILES; i++) {
		if (projectiles[i].active) {
			projectiles[i].x += projectiles[i].speed;
			if (projectiles[i].x >= 800) {
				projectiles[i].active = 0; //projectile inactif s'il sort de l'écran
			}
			for (int j = 0; j < MAX_ENEMIES; j++) {
				// vérifie si un projectile entre en contact avec un ennemy actif et désactive les deux si c'est le cas
				if (enemies[j].active && projectiles[i].x <= enemies[j].position.x + 
					enemies[j].position.w && projectiles[i].x >= enemies[j].position.x
					&& projectiles[i].y <= enemies[j].position.y + enemies[j].position.h && projectiles[i].y >= enemies[j].position.y) {
					projectiles[i].active = 0;//projectile inactif s'il touche un ennemi
					enemies[j].active = 0;//ennemi inactif s'il se fait détruire

					//ajout du score
					P1_Score += 200;
					printf("Score: %d\n", P1_Score);
					break;	
				}
			}
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
		}

	}
}