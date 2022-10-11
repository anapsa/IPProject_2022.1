#ifndef CAR
#define CAR
#include "raylib.h"
#include "player.h"
#define AIMING 100
#define RUNNING 101


typedef struct{
    float posX;
    float posY;
    Rectangle carLife;
    float angle;
    float speed;
    int life;
    float timeChangingAngle;
    int mode;// aiming at player or running
    float timeCounter;
    bool isReadytoCollide;
    
} Car;

void changeCarAngle(Car *car, Player player);

void DrawCar(Car car, Texture2D carTexture);

void moveCar(Car *car);

bool collidedWalls(Car car, Rectangle walls[]);





#endif