#include "raylib.h"
#include "car.h"
#include "player.h"

void changeCarAngle(Car *car, Player player){
    if((player.posX-car->posX)==0){
        if(player.posY>car->posY){
            car[0].angle = 90;
        }
        else if(player.posY<car->posY){
            car[0].angle = 270;
        }
    }
    else{

        car[0].angle = atan((player.posY-car->posY)/(player.posX-car->posX))*180/PI;
    }
}
