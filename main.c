#include "raylib.h"
#include <math.h>
#include "car.c"
#include "player.c"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include "colisao.c"







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
    Car *cars;
    cars = malloc(sizeof(Car)*4);

    cars[0] = (Car){25, 25, exemplo, 0, 5, 30, 5, AIMING, 0, false, false};
    cars[1] = (Car){1500, 25, exemplo, 0, 5, 30, 5, AIMING, 0, false, false};
    cars[2] = (Car){1000, 25, exemplo, 0, 5, 30, 5, AIMING, 0, false, false};
    cars[3] = (Car){1500, 1000, exemplo, 0, 5, 30, 5, AIMING, 0, false, false};
    Rectangle playerCollision;
    playerCollision.x = 100;
    playerCollision.y = 100;
    playerCollision.width = 30;
    playerCollision.height = 35;
    Player player = (Player){400, 400, 0, 50, playerCollision, exemplo, 5, 5, false, true, true, 2};
    
    
    int gameMode = GAME;

    Rectangle walls[4];
    walls[0].x = 30;
    walls[0].y = 30;
    walls[0].width = 10;
    walls[0].height = 1000;
    walls[1].x = 30;
    walls[1].y = 30;
    walls[1].width = 1500;
    walls[1].height = 10;
    walls[2].x = 1500;
    walls[2].y = 0;
    walls[2].width = 10;
    walls[2].height = 1000;
    walls[3].x = 0;
    walls[3].y = 1000;
    walls[3].width = 1500;
    walls[3].height = 10;

    float mainTimer = 0;
    Rectangle spikeCollision;
    spikeCollision.x = 700;
    spikeCollision.y = 700;
    spikeCollision.width = 55;
    spikeCollision.height = 55;
    Texture2D spikeTexture = LoadTexture("spike.png");
    Spikes spike;
    spike.posX = 700;
    spike.posY = 700;
    spike.spikeCollision = spikeCollision;
    char playerlife[5];
    
    
    while (!WindowShouldClose()){    
        
        switch(gameMode){
            case INITMENU:
                // código de implementação e funcionalidade do menu

                break;
            case GAME:
                sprintf(playerlife, "%d", player.life);
                mainTimer+=GetFrameTime();
                player.playerCollision.x = player.posX;
                player.playerCollision.y = player.posY;
                for(int i=0;i<4;i++){
                    cars[i].timeCounter+=GetFrameTime();
                }
                if(verifyPlayerSpikesCollision(player, &spike, 1)==true){
                    player.invencibilityTime-=GetFrameTime();
                }
                
                
                DrawText(playerlife, 600, 600, 30, PINK);
                
                movePlayer(&player);
                
                BeginDrawing();
                ClearBackground(RAYWHITE);
                
                
                DrawTextureEx(spikeTexture, (Vector2){700, 700}, 0, 0.4, RAYWHITE);
                for(int i=0;i<4;i++){
                    DrawRectangleRec(walls[i], BLACK);
                }
                DrawTexture(playerTexture, player.posX, player.posY, RAYWHITE);
                for(int i=0;i<4;i++){
                    DrawCar(cars[i], carTexture);
                }
                if(player.life<=0){
                    DrawText("morreu", 500, 500, 30, BLACK);
                }

                MasterUpdateCars(cars, 4, walls, player, &mainTimer);

                applyCarDamage(&spike, cars, 4, 1);

                applyPlayerDamage(&player, cars, &spike, 4, 1);



                
                EndDrawing();
                break;
            case UPGRADE:
                //código da escolha do upgrade no final de cada wave
            break;
        }

        
        
    }
    UnloadTexture(playerTexture);
    UnloadTexture(carTexture);
    UnloadTexture(spikeTexture);
    free(cars);
    CloseWindow();
          
    return 0;
}