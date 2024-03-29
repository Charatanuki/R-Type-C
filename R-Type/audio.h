#pragma once

#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL_mixer.h>
#include "option.h"

void initAudio();
void loadbgmusic();
void playbgmusic(Option option);
void cleanupAudio();