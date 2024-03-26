#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include "ErrorCodes.h"

int errorHandler(int errorNumber) {
	int lengthError = sizeof(errors) / sizeof(errors[0]);
	if (errorNumber > lengthError - 1) {
		printf("%s Error number %d\n", errors[0], errorNumber);
		SDL_Quit();
		return -1;
	}
	else {
		printf("%s\n", errors[errorNumber]);
		SDL_Quit();
		return -1;
	}
}