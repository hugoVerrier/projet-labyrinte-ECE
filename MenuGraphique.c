#include "MenuGraphique.h"



int fenetreMenu(){
    int largeur;
    int hauteur;
    largeur = GetScreenWidth();
    hauteur = GetScreenHeight();
    InitWindow(largeur,hauteur,"Menu");
    ToggleFullscreen();
    Image fondImage = LoadImage("../ImagesMenu/fond.png");
    ImageResize(&fondImage,GetScreenWidth(),GetScreenHeight());
    Texture2D fond = LoadTextureFromImage(fondImage);
    Image boutonImage = LoadImage("../ImagesMenu/parcheminhorizontal.png");
    ImageResize(&boutonImage,GetScreenWidth()/4,GetScreenHeight()/12);
    Texture2D bouton = LoadTextureFromImage(boutonImage);
    SetTargetFPS(30);
    while (!WindowShouldClose()){
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawTextureEx(fond,(Vector2){0,0},0.0f,1.0f,WHITE);
        DrawTextureEx(bouton,(Vector2){(GetScreenWidth()/2)-GetScreenWidth()/8,GetScreenHeight()/8},0.0f,1.25f,WHITE);
        DrawTextureEx(bouton,(Vector2){(GetScreenWidth()/2)-GetScreenWidth()/8,GetScreenHeight()/8+GetScreenWidth()/8},0.0f,1.25f,WHITE);
        DrawTextureEx(bouton,(Vector2){(GetScreenWidth()/2)-GetScreenWidth()/8,GetScreenHeight()/8+2*GetScreenWidth()/8},0.0f,1.25f,WHITE);
        DrawTextureEx(bouton,(Vector2){(GetScreenWidth()/2)-GetScreenWidth()/8,GetScreenHeight()/8+3*GetScreenWidth()/8},0.0f,1.25f,WHITE);
        if(IsKeyPressed(KEY_ESCAPE)){
            WindowShouldClose();

        }
        EndDrawing();
    }
    UnloadImage(fondImage);
    UnloadTexture(fond);
    return 0;
}
