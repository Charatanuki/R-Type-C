#include <stdio.h>;
#include <SDL.h>;
#include "HeaderFunction.h";
#include "ValuesHeader.h";


int main(int argc, char* argv[]) {
	
	initSDL();

	SDL_Window* window = SDL_CreateWindow("R-type-game",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		winX, winY, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		SDL_Quit();
		return(errorHandler(2));
	}
	
	SDL_Renderer* renderer = createRenderer(window);
	
	

	freeAll(window, renderer);
	return 0;
}