#include "MenuGraphique.h"



int fenetreMenu(){
    int largeur;
    int hauteur;
    largeur = GetScreenWidth();
    hauteur = GetScreenHeight();
    InitWindow(largeur,hauteur,"Menu");
    ToggleFullscreen();
    //Texture2D fond = LoadTexture("/Users/eliotrineau/CLionProjects/projet-labyrinte-ECE/ImagesMenu/fond.png");
    Texture2D fond = LoadTexture("./ImagesMenu/fond.png");

    SetTargetFPS(30);
    while (!WindowShouldClose()){
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawRectangle((GetScreenWidth()/2)-GetScreenWidth()/8,GetScreenHeight()/8,GetScreenWidth()/4,GetScreenHeight()/12,RED);
        DrawRectangle((GetScreenWidth()/2)-GetScreenWidth()/8,GetScreenHeight()/8+GetScreenWidth()/8,GetScreenWidth()/4,GetScreenHeight()/12,RED);
        DrawRectangle((GetScreenWidth()/2)-GetScreenWidth()/8,GetScreenHeight()/8+2*GetScreenWidth()/8,GetScreenWidth()/4,GetScreenHeight()/12,RED);
        DrawRectangle((GetScreenWidth()/2)-GetScreenWidth()/8,GetScreenHeight()/8+3*GetScreenWidth()/8,GetScreenWidth()/4,GetScreenHeight()/12,RED);
        DrawTextureEx(fond,(Vector2){0,0},0.0f,1.0f,WHITE);

        if(IsKeyPressed(KEY_ESCAPE)){
            WindowShouldClose();

        }


        EndDrawing();

    }
    UnloadTexture(fond);
    return 0;
}
