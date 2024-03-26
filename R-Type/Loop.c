#include <stdio.h>;
#include <SDL.h>;
#include "HeaderFunction.h";
#include "Projectile.h"
#include "PlayerValues.h"



int mainLoop(SDL_Renderer* renderer) {
	initializeProjectiles();

	while (1) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		handlePlayer(renderer); 

		if (isFiring == 1) {
			fireProjectile(pX, pY + pSize / 2, 5);
		}

		updateProjectiles();
		renderProjectiles(renderer);

		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}
}