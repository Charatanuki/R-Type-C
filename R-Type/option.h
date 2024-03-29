#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "menu.h"

typedef struct {
	int musicVolume;
	int soundVolume;
} Option;

void initOption(Option* option);