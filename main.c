#include "raylib.h"
#include <math.h>
#include "car.h"
#include "player.h"

#define HEADING_LEFT 1
#define HEADING_RIGHT 2

int main()
{
   
    const int screenWidth = 800;
    const int screenHeight = 450;

    Rectangle car;
    car.x=100;
    car.y = 100;
    car.height=30;
    car.width = 40;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);               
    int playerX, playerY;
    int playerSpeed = 3;
    playerX = 200;
    playerY = 200;
    float angle = 0;
    
    


    while (!WindowShouldClose()){    
        
        // movimentação básica do personagem
        if(IsKeyDown(KEY_LEFT)==true){
            playerX-=playerSpeed;
        }
        if(IsKeyDown(KEY_RIGHT)==true){
            playerX+=playerSpeed;
        }
        if(IsKeyDown(KEY_UP)==true){
            playerY-=playerSpeed;
        }
        if(IsKeyDown(KEY_DOWN)==true){
            playerY+=playerSpeed;
        }


        if((playerX-car.x)==0){
            if(playerY>car.y){
                angle = 90;
            }
            else if(playerY<car.y){
                angle = 270;
            }
        }
        else{

            angle = atan((playerY-car.y)/(playerX-car.x))*180/PI;
        }

        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawCircle(playerX, playerY, 15, RED);
            DrawRectanglePro(car, (Vector2){20,15}, angle, BLUE);

           

        EndDrawing();
        
    }
    
    CloseWindow();       
    return 0;
}