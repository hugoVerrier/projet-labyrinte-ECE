#include "MenuGraphique.h"



int fenetreMenu(){
    int largeur;
    int hauteur;
    largeur = GetScreenWidth();
    hauteur = GetScreenHeight();
    InitWindow(largeur,hauteur,"Menu");
    ToggleFullscreen();
    Image fondImage = LoadImage("/Users/eliotrineau/CLionProjects/projet-labyrinte-ECE/ImagesMenu/fond.png");
    ImageResize(&fondImage,GetScreenWidth(),GetScreenHeight());
    Texture2D fond = LoadTextureFromImage(fondImage);
    SetTargetFPS(30);
    while (!WindowShouldClose()){
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawTextureEx(fond,(Vector2){0,0},0.0f,1.0f,WHITE);
        DrawRectangle((GetScreenWidth()/2)-GetScreenWidth()/8,GetScreenHeight()/8,GetScreenWidth()/4,GetScreenHeight()/12,RED);
        DrawRectangle((GetScreenWidth()/2)-GetScreenWidth()/8,GetScreenHeight()/8+GetScreenWidth()/8,GetScreenWidth()/4,GetScreenHeight()/12,RED);
        DrawRectangle((GetScreenWidth()/2)-GetScreenWidth()/8,GetScreenHeight()/8+2*GetScreenWidth()/8,GetScreenWidth()/4,GetScreenHeight()/12,RED);
        DrawRectangle((GetScreenWidth()/2)-GetScreenWidth()/8,GetScreenHeight()/8+3*GetScreenWidth()/8,GetScreenWidth()/4,GetScreenHeight()/12,RED);

        if(IsKeyPressed(KEY_ESCAPE)){
            WindowShouldClose();

        }


        EndDrawing();

    }
    UnloadImage(fondImage);
    UnloadTexture(fond);
    return 0;
}
