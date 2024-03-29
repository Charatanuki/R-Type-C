#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_audio.h>
#include "Projectile.h"
#include "LoopInitFunc.h"
#include "isAlive.h"
#include "Explosion.h"
#include "ExTextureManager.h"
#include "audio.h"

int mainLoop(SDL_Renderer* renderer, Option option);


