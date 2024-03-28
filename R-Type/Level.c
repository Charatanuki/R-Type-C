#include <stdio.h>
#include "PlayerScoreValues.h"
#include "ennemis.h"
#include "Background.h"
#include "HeaderFunction.h"

#define SCORE_REQ 3000

int level = 1;
int nextLevel = 2;
int levelCheck = 0;


void levelChange(int* numEnemies, Enemy enemies[], Background* background) {
    if (P1_Score >= levelCheck + SCORE_REQ && level != nextLevel) {
        level++;
        nextLevel++;

        *numEnemies += 2;
        newSpeed += 0;
        enemeyHealth += 1;

        levelCheck = P1_Score;
        if (background != NULL) {
            background->backgroundId++;
        }
        else {
            printf("Background is NULL\n");
            // Handle the error condition appropriately
        }
        initEnemies(enemies, *numEnemies, 800, 500, newSpeed, enemeyHealth);
        printf("Level Up!\n");
        printf("%d", *numEnemies);
    }
}