#include "raylib.h"
#include "player.h"
#define HEADING_LEFT 1
#define HEADING_RIGHT 2

void movePlayer(Player *player){
    if(IsKeyDown(KEY_LEFT)==true){
        player[0].posX-=player[0].speed;
        player[0].heading = HEADING_LEFT;
        player[0].isMoving = true;
    }
    if(IsKeyDown(KEY_RIGHT)==true){
        player[0].posX+=player[0].speed;
        player[0].heading = HEADING_RIGHT;
        player[0].isMoving = true;
    }
    if(IsKeyDown(KEY_UP)==true){
        player[0].posY-=player[0].speed;
        player[0].isMoving = true;
    }
    if(IsKeyDown(KEY_DOWN)==true){
        player[0].posY+=player[0].speed;
        player[0].isMoving = true;
    }
    if(IsKeyDown(KEY_LEFT)==false && IsKeyDown(KEY_RIGHT)==false && IsKeyDown(KEY_UP)==false && IsKeyDown(KEY_DOWN)==false){
        player[0].isMoving = false;
    }

}

bool verifyPlayerSpikesCollision(Player player, Spikes *spikes, int numberSpikes){
    bool hit = false;
    for(int i=0;i<numberSpikes;i++){
        if(CheckCollisionRecs(player.playerCollision, spikes[i].spikeCollision)==true){
            hit = true;
        }
    }
    return hit;
}

bool verifyPlayerCarsCollision(Player player, Car *cars, int numberCars){
    bool hit = false;
    for(int i=0;i<numberCars;i++){
        if(CheckCollisionCircleRec((Vector2){cars[i].posX, cars[i].posY}, 30, player.playerCollision)==true){
            hit = true;
        }
    }
    return hit;
}

void applyPlayerDamage(Player *player, Car *cars, Spikes *spikes, int numberCars, int numberSpikes){
    // colisão com spikes primeiro:
    if(player[0].isReadytoHitSpikes==false && verifyPlayerSpikesCollision(player[0], spikes, numberSpikes)==false){
        player[0].isReadytoHitSpikes = true;
    }
    if(player[0].isReadytoHitSpikes = true && verifyPlayerSpikesCollision(player[0], spikes, numberSpikes)==true){
        player[0].life-=10; // diminuindo a vida do player em 10
        player[0].isReadytoHitSpikes = false;
    }
    // colisão com os carrinhos
    if(player[0].isReadytoHitCar==false && verifyPlayerCarsCollision(player[0], cars, numberCars)==false){
        player[0].isReadytoHitCar = true;
    }
    if(player[0].isReadytoHitCar == true && verifyPlayerCarsCollision(player[0], cars, numberCars)==true){
        player[0].life-=10;// diminuindo a vida do player em 10
        player[0].isReadytoHitCar = false;
    }
}