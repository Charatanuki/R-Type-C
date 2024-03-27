#include <SDL.h>
#include "PlayerScoreValues.h"
int level = 1;

int levelChange() {
	if (P1_Score > 2000 && level != 2) {
		level += 1;
	}
}