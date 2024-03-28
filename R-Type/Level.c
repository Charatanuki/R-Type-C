#include <stdio.h>
#include "PlayerScoreValues.h"
#include "ennemis.h"
#include "Background.h"
#include "HeaderFunction.h"

#define SCORE_REQ 3500 

int level = 1;
int nextLevel = 2;
int levelCheck = 0;


void levelChange(int* numEnemies, Enemy enemies[], Background* background) {
    if (P1_Score >= levelCheck + SCORE_REQ && level != nextLevel) {
        level++;
        nextLevel++;

        *numEnemies += 10;
        newSpeed += 1;

        levelCheck = P1_Score;
        background->backgroundId++;
        initEnemies(enemies, *numEnemies, 800, 500, newSpeed);
        printf("Level Up!\n");
        printf("%d", *numEnemies);
    }
}