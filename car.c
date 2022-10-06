#include "raylib.h"
#include "car.h"
#include "player.h"
#include <math.h>


/*void changeCarAngle(Car *car, Player player){
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
}*/

void changeCarAngle(Car *car, Player player){
    
    float dist = sqrt(pow(abs(player.posX+12-car->posX), 2)+pow(abs(player.posY+10-car->posY), 2));
    if(player.posX>car->posX){
        car[0].angle = asin((player.posY+10-car->posY)/dist)*180/PI+90;

    }
    else{
        car[0].angle = 180 - asin((player.posY+10-car->posY)/dist)*180/PI+90;
    }

    



}



void DrawCar(Car car, Texture2D carTexture){
    Rectangle source;
    source.x = 0;
    source.y = 0;
    source.width=45;
    source.height = 65;
    Rectangle destination;
    destination.x = car.posX;
    destination.y = car.posY;
    destination.width = 45;
    destination.height = 65;
    Vector2 origin;
    origin.x = 30;
    origin.y = 33;

    DrawTexturePro(carTexture, source, destination, origin, car.angle, RAYWHITE);

   
}






