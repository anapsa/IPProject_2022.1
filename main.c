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
    Texture2D backgroundTexture = LoadTexture("fundojogo.png");
    Texture2D menuTexture = LoadTexture("menu.png");
    Texture2D rulesTexture = LoadTexture("rules.png");
    Texture2D lostTexture = LoadTexture("lost.png");



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
    walls[0].x = 00;
    walls[0].y = 00;
    walls[0].width = 2250;
    walls[0].height = 5;
    walls[1].x = 00;
    walls[1].y = 00;
    walls[1].width = 5;
    walls[1].height = 2250;
    walls[2].x = 2250;
    walls[2].y = 0;
    walls[2].width = 5;
    walls[2].height = 2250;
    walls[3].x = 0;
    walls[3].y = 2250;
    walls[3].width = 2250;
    walls[3].height = 5; 


    




    Rectangle walls_player[4];
    walls_player[0].x = 335;
    walls_player[0].y = 335;
    walls_player[0].width = 1580;
    walls_player[0].height = 5;
    walls_player[1].x = 335;
    walls_player[1].y = 335;
    walls_player[1].width = 5;
    walls_player[1].height = 1580;
    walls_player[2].x = 1915;
    walls_player[2].y = 335;
    walls_player[2].width = 5;
    walls_player[2].height = 1580;
    walls_player[3].x = 335;
    walls_player[3].y = 1915;
    walls_player[3].width = 1580;
    walls_player[3].height = 5;

    
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
    char playerPosX[5];
    char playerPosY[5];

    Camera2D cam;
    cam.offset = (Vector2){GetScreenWidth()/2, GetScreenHeight()/2};
    cam.rotation = 0;
    cam.zoom = 1;
    
    
    
    while (!WindowShouldClose()){    
        
        switch(gameMode){
            case INITMENU:
                DrawTextureEx(menuTexture, (Vector2){0,0},0,1, GRAY);

                break;
            case GAME:
                sprintf(playerPosX, "%d", player.posX);
                sprintf(playerPosY, "%d", player.posY);
                sprintf(playerlife, "%d", player.life);
                player.isMoving = false;
                mainTimer+=GetFrameTime();
                player.playerCollision.x = player.posX;
                player.playerCollision.y = player.posY;
                for(int i=0;i<4;i++){
                    cars[i].timeCounter+=GetFrameTime();
                }
                if(verifyPlayerSpikesCollision(player, &spike, 1)==true){
                    player.invencibilityTime-=GetFrameTime();
                }

                // tentativa falha de barreira pro personagem não sair pelos cantos
                /* if(player.posX < 220) {
                    player.posX = 220;
                    player.isMoving = false;
                }
                else if ((player.posX + playerCollision.width) > 1250) {
                    player.posX = 1250 ;
                    player.isMoving = false;
                }

                if(player.posY < 225) {
                    player.posY = 225;
                    player.isMoving = false;
                }
                else if ((player.posY + playerCollision.height) > 1245) {
                    player.posY = 1245 ;
                    player.isMoving = false;
                } */ 



                
                
                cam.target = (Vector2){player.posX, player.posY};
                
                
                
                movePlayer(&player, walls_player);
                
                BeginDrawing();
                BeginMode2D(cam);
                ClearBackground(RAYWHITE);
                DrawTextureEx (backgroundTexture, (Vector2) {0,0},0, 1.5, RAYWHITE);
                DrawText(playerlife, 600, 600, 30, PINK);
                DrawText(playerPosX, 600, 300, 30, RED);
                DrawText(playerPosY, 700, 400, 30, RED);
                
                
                
                
                DrawTextureEx(spikeTexture, (Vector2){700, 700}, 0, 0.4, RAYWHITE);
                for(int i=0;i<4;i++){
                    DrawRectangleRec(walls[i], BLACK);
                    DrawRectangleRec(walls_player[i], RED);
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
                EndMode2D();
                break;
            case UPGRADE:
                //código da escolha do upgrade no final de cada wave
            break;
        }

        
        
    }
    UnloadTexture(playerTexture);
    UnloadTexture(carTexture);
    UnloadTexture(spikeTexture);
    UnloadTexture(backgroundTexture);
    UnloadTexture(menuTexture);
    UnloadTexture(rulesTexture);
    UnloadTexture(lostTexture);
    free(cars);
    CloseWindow();
          
    return 0;
}