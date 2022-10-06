#ifndef PLAYER
#define PLAYER
#include "raylib.h"


typedef struct{
    int posX;
    int posY;
    int frameCounter;
    int life;
    Rectangle playerCollision;
    Rectangle playerLife;
    int speed;
    int heading; //left or right
    bool isMoving;
} Player;

void movePlayer(Player *player);

#endif