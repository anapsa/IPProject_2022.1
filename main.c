#include "raylib.h"
#include <math.h>
#include "car.c"
#include "player.C"
#include "menu.h"




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
    
    int gameMode = GAME;
    while (!WindowShouldClose()){    
        
        switch(gameMode){
            case MENU:
                // código de implementação e funcionalidade do menu

                break;
            case GAME:
                
                
                
                
                



                

                break;
            case UPGRADE:
                //código da escolha do upgrade no final de cada wave
            break;
        }

        
        
    }
    
    CloseWindow();
          
    return 0;
}