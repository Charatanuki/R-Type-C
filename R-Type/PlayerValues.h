#ifndef PLAYERVALUE_H
	#define PLAYERVALUE_H

#include <SDL.h>

	typedef struct {
		int dx;
		int dy;
		int pX;
		int pY;
		int pSize;
		int immortal;
		Uint32 hurtTime;
		int health;
	} Player;
#endif // !PLAYERVALUE_H