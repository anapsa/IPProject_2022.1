#include "raylib.h"
#include <math.h>
#include "car.c"
#include "player.C"



#define AIMING 100
#define RUNNING 101
#define MENU 10
#define GAME 11
#define UPGRADE 12

int main()
{
   
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

   

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);
    Rectangle playerCollision;
    playerCollision.x = 300;
    playerCollision.y = 300;
    playerCollision.height = 40;
    playerCollision.width = 30;               
    Player player = (Player){300, 300, 0, 10, playerCollision, playerCollision, 3, HEADING_LEFT, false};
    Texture2D playerText = LoadTexture("Assets/CharacterSprites/PlayerIdleLeft.png");
    Texture2D car = LoadTexture("SportsRacingCar_0.png");
    Car carro = (Car){400, 400, playerCollision, playerCollision, 0, 10, 10, 10, 10 ,false};
    
    
    
    int gameMode = GAME;
    
    

    while (!WindowShouldClose()){    
        
        switch(gameMode){
            case MENU:
                // código de implementação e funcionalidade do menu

                break;
            case GAME:
                
                BeginDrawing();
                movePlayer(&player);
                changeCarAngle(&carro, player);
                DrawCar(carro, car);
                carro.posX+=cos(carro.angle)*2;
                carro.posY+=sin(carro.angle)*2;
                
                ClearBackground(RAYWHITE);
                DrawTexture(playerText, player.posX, player.posY, RAYWHITE);
                
                
                
                



                EndDrawing();

                break;
            case UPGRADE:
                //código da escolha do upgrade no final de cada wave
            break;
        }

        
        
    }
    
    CloseWindow();
    UnloadTexture(playerText);       
    return 0;
}