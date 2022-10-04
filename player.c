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