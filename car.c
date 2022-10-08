#include "raylib.h"
#include "car.h"
#include "player.h"
#include <math.h>




void changeCarAngle(Car *car, Player player){
    
    float dist = sqrt(pow(abs(player.posY+13-car[0].posY), 2)+pow(abs(player.posX+8-car[0].posX), 2));

    if(player.posX>car->posX){

        car[0].angle = asin((player.posY+13-car->posY)/dist)*180/PI;
    }
    else{
        car[0].angle = 180 - asin((player.posY+13-car->posY)/dist)*180/PI;
    }



}



void DrawCar(Car car, Texture2D carTexture){
    Rectangle source;
    source.x = 0;
    source.y = 0;
    source.width = 65;
    source.height = 45;
    Rectangle destination;
    destination.x = car.posX;
    destination.y = car.posY;
    destination.height = 45;
    destination.width = 65;
    Vector2 origin = (Vector2){30, 30};
    DrawTexturePro(carTexture, source, destination, origin, car.angle, RAYWHITE);

   
}

void moveCar(Car *car){
    car[0].posY+=sin(car->angle*PI/180)*car->speed;
    car[0].posX+=cos(car->angle*PI/180)*car->speed;

}






