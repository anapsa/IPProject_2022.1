#ifndef CAR
#define CAR
#include "raylib.h"
#include "player.h"

typedef struct{
    int posX;
    int posY;
    Rectangle carCollision;
    Rectangle carLife;
    float angle;
    int speed;
    int life;
    float timeChangingAngle;
} Car;

void changeCarAngle(Car *car, Player *player);



#endif