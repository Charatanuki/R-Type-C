#include <stdio.h>;
#include <stdlib.h>
#include <SDL.h>;
#include "HeaderFunction.h";
#include "Projectile.h";
#include "PlayerValues.h";
#include "ennemis.h";

#define FIRE_COOLDOWN 100 

int mainLoop(SDL_Renderer* renderer) {
	initializeProjectiles();
	// Initialisation de la graine pour la génération aléatoire
	srand(time(NULL));

	// Tableau d'ennemis
	Enemy enemies[MAX_ENEMIES];
	int numEnemies = 10; // Nombre initial d'ennemis

	// Initialisation des ennemis
	initEnemies(enemies, numEnemies, 800, 500); // Passer la largeur et la hauteur de la fenêtre

	// Initialisation du temps pour la gestion des ennemis
	unsigned int dernierEnnemi = SDL_GetTicks();
	unsigned int popEnnemi = 7500; // Intervalle entre chaque apparition d'ennemi en millisecondes
	Enemy enemy;
	initEnemy(&enemy, 750, 250, 50, 50, 1);
	Player player;
	initPlayer(&player);

	unsigned int lastFiredFramed = 0;
	while (1) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		handlePlayer(renderer, &player);
		// Apparition des ennemis en fonction du temps
		unsigned int currentTime = SDL_GetTicks();
		if (currentTime - dernierEnnemi > popEnnemi) {
			dernierEnnemi = currentTime;
			if (numEnemies < MAX_ENEMIES) {
				initEnemies(&enemies[numEnemies], 1, 800, 600); // Initialiser un nouvel ennemi
				numEnemies++; // Augmenter le nombre d'ennemis
			}
		}

		// Dessiner les ennemis
		drawEnemies(enemies, numEnemies, renderer);
		// Déplacer les ennemis
		moveEnemies(enemies, numEnemies);

		if (isFiring == 1 && (currentTime - lastFiredFramed) >= FIRE_COOLDOWN) {
			fireProjectile(player.pX, player.pY + player.pSize / 2, 5);
			lastFiredFramed = currentTime;
		}

		updateProjectiles();
		renderProjectiles(renderer);
		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}
}