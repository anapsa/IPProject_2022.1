#ifndef CAR
#define CAR
#include "raylib.h"
#include "player.h"

typedef struct{
    float posX;
    float posY;
    Rectangle carCollision;
    Rectangle carLife;
    float angle;
    int speed;
    int life;
    float timeChangingAngle;
    int mode;// aiming at player or running
    bool isColliding; //verifica se está colidindo com a parede
} Car;

void changeCarAngle(Car *car, Player player);

void DrawCar(Car car, Texture2D carTexture);



#endif