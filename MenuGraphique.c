#include "MenuGraphique.h"



int fenetreMenu(){
    int largeur;
    int hauteur;
    largeur = GetScreenWidth();
    hauteur = GetScreenHeight();
    InitWindow(largeur,hauteur,"Menu");
    ToggleFullscreen();
    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangle(GetScreenWidth()/2,GetScreenHeight()/2,GetScreenWidth()/2,GetScreenHeight(),BLACK);
        DrawText("Test", GetScreenWidth()/2-24,GetScreenHeight()/2,20,WHITE);
        if(IsKeyPressed(KEY_ESCAPE)){
            WindowShouldClose();
        }
        EndDrawing();
    }
    return 0;
}
