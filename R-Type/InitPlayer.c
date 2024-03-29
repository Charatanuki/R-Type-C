#include "PlayerValues.h"


void initPlayer(Player* player)
{
    player->pX = 250;
    player->pY = 250;
    player->pSize = 50;
    player->dx = 0;
    player->dy = 0;
    player->immortal = 0;
    player->health = 3;
}