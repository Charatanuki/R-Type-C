#include <stdio.h>;
#include <SDL.h>;
#include "HeaderFunction.h";


int mainLoop(SDL_Renderer* renderer) {

	while (1) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		handlePlayer(renderer);


		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}
}