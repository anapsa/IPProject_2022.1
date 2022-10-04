#include "raylib.h"
#include <math.h>
#include "car.h"
#include "player.h"

#define HEADING_LEFT 1
#define HEADING_RIGHT 2
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
    
    
    int gameMode = MENU;


    while (!WindowShouldClose()){    
        
        switch(gameMode){
            case MENU:
                // código de implementação e funcionalidade do menu

                break;
            case GAME:
                //códigos do jogo em si

                break;
            case UPGRADE:
                //código da escolha do upgrade no final de cada wave
            break;
        }

        
        
    }
    
    CloseWindow();       
    return 0;
}