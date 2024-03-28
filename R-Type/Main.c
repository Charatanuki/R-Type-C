#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include "HeaderFunction.h"
#include "ValuesHeader.h"
#include "ennemis.h"
#include "soundeffect.h"
#include "audio.h"

int main(int argc, char* argv[]) {
	initSDL();	
	SDL_Window* window = SDL_CreateWindow("R-type-game",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		winX, winY, SDL_WINDOW_SHOWN);

	if (TTF_Init() == -1) {
		printf("Failed to initialize TTF");
		return -1;
	}

	if (window == NULL) {
		SDL_Quit();
		return -1;
	}

	initAudio();
	loadbgmusic();
	loadshootsound();
	loaddestroysound();
	SDL_Renderer* renderer = createRenderer(window);
	cleanupAudio();
	cleanupSoundeffect();
	freeAll(window, renderer);

	return 0;
}