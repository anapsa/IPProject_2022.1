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
} Player;

#endif