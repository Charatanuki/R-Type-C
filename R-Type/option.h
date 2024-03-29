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

SDL_Texture* SettingBgTexture;
SDL_Texture* SFXTexture;
SDL_Texture* musicTexture;
SDL_Texture* returnTexture;

void initOption(Option* option);
int handleOptionMenu(SDL_Renderer* renderer, Option* option);

int musicVolumeOpt(Option* option);
int soundVolumeOpt(Option* option);