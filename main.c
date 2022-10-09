#include "raylib.h"
#include <math.h>
#include "car.c"
#include "player.C"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>





#define AIMING 100
#define RUNNING 101
#define INITMENU 10
#define GAME 11
#define UPGRADE 12

int main()
{
   
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

   

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);

    Texture2D carTexture = LoadTexture("SportsRacingCar_0.png");
    Texture2D playerTexture = LoadTexture("Assets/CharacterSprites/PlayerIdleLeft.png");
    Rectangle exemplo;
    exemplo.x = 0;
    exemplo.y = 0;
    exemplo.height = 10;
    exemplo.y = 10;
    Car car = (Car){300, 300, exemplo, exemplo, 0, 5, 0, 5, 0, false};
    Player player = (Player){400, 400, 0, 5, exemplo, exemplo, 5, 5, false};
    float timer = 0;
    int gameMode = GAME;
    
    
    
    while (!WindowShouldClose()){    
        
        switch(gameMode){
            case INITMENU:
                // código de implementação e funcionalidade do menu

                break;
            case GAME:
                
                timer+=GetFrameTime();
                
                movePlayer(&player);
                BeginDrawing();
                ClearBackground(RAYWHITE);
                DrawCar(car, carTexture);
                DrawTexture(playerTexture, player.posX, player.posY, RAYWHITE);
                
                if(timer<5){
                    changeCarAngle(&car, player);

                }
                else{
                    moveCar(&car);
                }
                if(timer>=7){
                    timer=0;
                }
                



                
                EndDrawing();
                break;
            case UPGRADE:
                //código da escolha do upgrade no final de cada wave
            break;
        }

        
        
    }
    UnloadTexture(playerTexture);
    UnloadTexture(carTexture);
    CloseWindow();
          
    return 0;
}