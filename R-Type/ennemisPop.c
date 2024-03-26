#include <stdio.h>;
#include <SDL.h>;
#include "HeaderFunction.h";
#include "ennemis.h"



void popennemi(SDL_Renderer* renderer) 
{
    // Initialisation de la graine pour la génération aléatoire
    srand(time(NULL));

    // Tableau d'ennemis
    Enemy enemies[MAX_ENEMIES];
    int numEnemies = 10; // Nombre initial d'ennemis

    // Initialisation des ennemis
    initEnemies(enemies, numEnemies, 800, 600); // Passer la largeur et la hauteur de la fenêtre

    // Initialisation du temps pour la gestion des ennemis
    Uint32 dernierEnnemi = SDL_GetTicks();
    Uint32 popEnnemi = 7500; // Intervalle entre chaque apparition d'ennemi en millisecondes

    // Initialisation de l'ennemi
    Enemy enemy;
    initEnemy(&enemy, 750, 250, 50, 50, 1);

    while (1) {
        // Apparition des ennemis en fonction du temps
        Uint32 currentTime = SDL_GetTicks();
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
    }
}