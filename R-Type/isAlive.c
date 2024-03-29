#include <SDL.h>
#include <stdio.h>
#include "isAlive.h"
#include "PlayerScoreValues.h"

bool isAliveCheck(Player* player) {
	if (player->health > 0)
		return true;
	printf("GameOver \n");
	printf(" Kills : %d \n Score : %d\n Level: %d \n ",P1_Score / 200, P1_Score, P1_Score / 3500 +1);
	//SDL_Quit(); //si l'on souhaite quitter le jeu directement après
	return false;
}