#pragma once
#include <SDL.h>

typedef struct {
	int dx;
	int dy;
	int pX;
	int pY;
	int pSize;
	int immortal;
	Uint32 hurtTime;
} Player;

