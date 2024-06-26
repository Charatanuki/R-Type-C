#include "Projectile.h"
#include "PlayerScoreValues.h"
#include "soundeffect.h"
#include "Explosion.h"
#include "option.h"

int P1_Score = 0;

Projectile projectiles[MAX_PROJECTILES];

void initializeProjectiles() {
	for (int i = 0; i < MAX_PROJECTILES; i++) {
		projectiles[i].active = 0;
	}
}

void fireProjectile(int x, int y, int speed, Option option) {
	for (int i = 0; i < MAX_PROJECTILES; i++) {
		if (!projectiles[i].active) {
			projectiles[i].x = x;
			projectiles[i].y = y;
			projectiles[i].speed = speed;
			projectiles[i].active = 1;
			playshootsound(option);
			break;
		}
	}
}

void isHurt(Enemy enemies[], Option option, Projectile projectiles[]) {
	projectiles->active = 0;//projectile inactif s'il touche un ennemi
	enemies->health--;
	if (enemies->health <= 0) {
		enemies->active = 0;//ennemi inactif s'il se fait d�truire
		triggerExplosion(enemies->position.x, enemies->position.y);
		playdestroysound(option);
		//ajout du score
		P1_Score += 200;
		printf("Score: %d\n", P1_Score);
	}
}

void updateProjectiles(Enemy* enemies, Option option) {
	for (int i = 0; i < MAX_PROJECTILES; i++) {
		if (projectiles[i].active) {
			projectiles[i].x += projectiles[i].speed;
			if (projectiles[i].x >= 775) {
				projectiles[i].active = 0; //projectile est "supprim�" s'il atteint sa zone d'attaque max
			}
			for (int j = 0; j < MAX_ENEMIES; j++) {
				// v�rifie si un projectile entre en contact avec un ennemy 
				if (enemies[j].active && projectiles[i].x <= 
					enemies[j].position.x +
					enemies[j].position.w && projectiles[i].x >= 
					enemies[j].position.x && projectiles[i].y <= 
					enemies[j].position.y + enemies[j].position.h 
					&& projectiles[i].y >= enemies[j].position.y) {
					isHurt(&enemies[j], option, &projectiles[i]);
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
			SDL_Rect projectileRect = { projectiles[i].x, 
				projectiles[i].y, 5, 5 };
			SDL_RenderFillRect(renderer, &projectileRect);
		}

	}
}