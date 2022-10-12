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
    bool isReadytoHitCar; // começa sempre verdadeiro
    bool isReadytoHitSpikes; // começa sempre verdadeiro
} Player;

void movePlayer(Player *player);

bool verifyPlayerSpikesCollision(Player player, Spikes *spikes, int numberSpikes);

bool verifyPlayerCarsCollision(Player player, Car *cars, int numberCars);

void applyPlayerDamage(Player *player, Car *cars, Spikes *spikes, int numberCars, int numberSpikes);


#endif