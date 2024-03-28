#include <SDL.h>
#include <stdio.h>
#include "isAlive.h"
#include "PlayerScoreValues.h"
bool isAlive = true;

void isAliveCheck() {
	while (isAlive && P1_Health <= 0)
	{
		isAlive = false;
		printf("GameOver \n");
		printf(" Kills : %d \n Score : %d\n Level: %d \n ",P1_Score / 200, P1_Score, P1_Score / 3500 +1);
		//SDL_Quit(); //si l'on souhaite quitter le jeu directement après
		break;
	}
}