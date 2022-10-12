#ifndef COLISAO
#define COLISAO
#include "player.h"
#include "car.h"

bool verifyPlayerSpikesCollision(Player player, Spikes *spikes, int numberSpikes);

bool verifyPlayerCarsCollision(Player player, Car *cars, int numberCars);

void applyPlayerDamage(Player *player, Car *cars, Spikes *spikes, int numberCars, int numberSpikes);

bool checkCarSpikesCollision(Spikes *spikes, Car car, int numberSpikes);

void applyCarDamage(Spikes *spikes, Car *cars, int numberCars, int numberSpikes);




#endif