#include <stdio.h>;
#include <SDL.h>;
#include "HeaderFunction.h";
#include "Projectile.h"
#include "PlayerValues.h"

#define FIRE_COOLDOWN 100 

int mainLoop(SDL_Renderer* renderer) {
	initializeProjectiles();

	Uint32 lastFiredFramed = 0;
	while (1) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		Uint32 currentTime = SDL_GetTicks();

		handlePlayer(renderer); 

		if (isFiring == 1 && (currentTime - lastFiredFramed) >= FIRE_COOLDOWN) {
			fireProjectile(pX + pSize, pY + pSize / 2, 5);
			lastFiredFramed = currentTime;
		}

		updateProjectiles();
		renderProjectiles(renderer);

		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}
}