#ifndef PLAYER
#define PLAYER
#include "raylib.h"
#include "car.h"


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
    bool isReadytoHitCar; // começa sempre verdadeiro
    bool isReadytoHitSpikes; // começa sempre verdadeiro
    float invencibilityTime;
    
} Player;

void movePlayer(Player *player, Rectangle walls_player[]);



#endif