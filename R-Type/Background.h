#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "PlayerScoreValues.h"
#include "ennemis.h"

typedef struct {
    int bX;
    int bY;
    int bdx;
    int backgroundId;
} Background;

void initBackground(Background* background, int backgroundId);
void handleBackground(SDL_Renderer* renderer, Background* background);
void initBackground(Background* background, int backgroundId);