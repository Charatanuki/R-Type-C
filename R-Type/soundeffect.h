#pragma once

#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL_mixer.h>
#include "audio.h"

void loadshootsound();
void playshootsound(Option option);
void loaddestroysound();
void playdestroysound(Option option);
void cleanupSoundeffect();