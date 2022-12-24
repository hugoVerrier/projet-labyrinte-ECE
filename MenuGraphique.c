#include "MenuGraphique.h"



int fenetreMenu(){
    // initialisation de la fenetre
    int largeur;
    int hauteur;
    largeur = GetScreenWidth();
    hauteur = GetScreenHeight();
    InitWindow(largeur,hauteur,"Menu");
    ToggleFullscreen();
    // chargement et redimension des textures
    Image fondImage = LoadImage("../ImagesMenu/fond.png");
    ImageResize(&fondImage,GetScreenWidth(),GetScreenHeight());
    Texture2D fond = LoadTextureFromImage(fondImage);
    Image boutonImage = LoadImage("../ImagesMenu/parcheminhorizontal.png");
    ImageResize(&boutonImage,GetScreenWidth()/4,GetScreenHeight()/12);
    Texture2D bouton = LoadTextureFromImage(boutonImage);
    Image quitterImage = LoadImage("../ImagesMenu/boutonQuitter.png");
    ImageResize(&quitterImage,GetScreenWidth()/22,GetScreenHeight()/18);
    Texture2D quitter = LoadTextureFromImage(quitterImage);
    Font font = LoadFont("../Font/Terserah.ttf");
    SetTargetFPS(30);
    int fin = 0; // fin inutile juste histoire de pas fermer la fenetre
    while (!fin ){
        BeginDrawing();
        Vector2 positionSouris;
        positionSouris = GetMousePosition();
        DrawTextureEx(fond,(Vector2){0,0},0.0f,1.0f,WHITE);
        DrawText(TextFormat("Position de la souris : (%f, %f)", positionSouris.x, positionSouris.y), 100, 100, 50, RED);
        DrawTextureEx(quitter,(Vector2){GetScreenWidth()-GetScreenWidth()/16,GetScreenHeight()/32},0.0f,1.0f,WHITE);
        DrawTextureEx(bouton,(Vector2){(GetScreenWidth()/2)-GetScreenWidth()/8,GetScreenHeight()/8},0.0f,1.25f,WHITE);
        DrawTextureEx(bouton,(Vector2){(GetScreenWidth()/2)-GetScreenWidth()/8,GetScreenHeight()/8+GetScreenWidth()/8},0.0f,1.25f,WHITE);
        DrawTextureEx(bouton,(Vector2){(GetScreenWidth()/2)-GetScreenWidth()/8,GetScreenHeight()/8+2*GetScreenWidth()/8},0.0f,1.25f,WHITE);
        DrawTextureEx(bouton,(Vector2){(GetScreenWidth()/2)-GetScreenWidth()/8,GetScreenHeight()/8+3*GetScreenWidth()/8},0.0f,1.25f,WHITE);
        DrawTextEx(font,"Nouvelle partie",(Vector2){(GetScreenWidth()/2-GetScreenWidth()/20),GetScreenHeight()/8+GetScreenHeight()/32},40,0,BLACK);
        DrawTextEx(font,"Charger partie",(Vector2){(GetScreenWidth()/2-GetScreenWidth()/20),GetScreenHeight()/8+GetScreenWidth()/8+GetScreenHeight()/32},40,0,BLACK);
        DrawTextEx(font,"Afficher regle",(Vector2){(GetScreenWidth()/2-GetScreenWidth()/20),GetScreenHeight()/8+2*GetScreenWidth()/8+GetScreenHeight()/32},40,0,BLACK);
        DrawTextEx(font,"Credits",(Vector2){(GetScreenWidth()/2-GetScreenWidth()/50),GetScreenHeight()/8+3*GetScreenWidth()/8+GetScreenHeight()/32},40,0,BLACK);
        if (IsKeyPressed(KEY_ESCAPE) ||  (positionSouris.x >= GetScreenWidth()-GetScreenWidth()/16) && (positionSouris.x <= GetScreenWidth()-GetScreenWidth()/16 + quitterImage.width) && (positionSouris.y >= GetScreenHeight()/32) && (positionSouris.y <= GetScreenHeight()/32 +quitterImage.height) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
        {
            UnloadImage(fondImage);
            UnloadTexture(fond);
            UnloadTexture(quitter);
            UnloadTexture(bouton);
            UnloadFont(font);
            EndDrawing();
            return 0;
        }
        else if ( (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) && (positionSouris.x >= (GetScreenWidth()/2)-GetScreenWidth()/8) && (positionSouris.x <= (GetScreenWidth()/2)-GetScreenWidth()/8+boutonImage.width) && (positionSouris.y >= GetScreenHeight()/8) && (positionSouris.y <= GetScreenHeight()/8+boutonImage.height) ){
            UnloadImage(fondImage);
            UnloadTexture(fond);
            UnloadTexture(quitter);
            UnloadTexture(bouton);
            UnloadFont(font);
            ClearBackground(BLACK);
            EndDrawing();
        }
        else if ( (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) && (positionSouris.x >= (GetScreenWidth()/2)-GetScreenWidth()/8) && (positionSouris.x <= (GetScreenWidth()/2)-GetScreenWidth()/8+boutonImage.width) && (positionSouris.y >= GetScreenHeight()/8+GetScreenWidth()/8) && (positionSouris.y <= GetScreenHeight()/8+GetScreenWidth()/8+boutonImage.height) ){
            UnloadImage(fondImage);
            UnloadTexture(fond);
            UnloadTexture(quitter);
            UnloadTexture(bouton);
            UnloadFont(font);
            ClearBackground(BLACK);
            EndDrawing();
        }
        else if ( (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) && (positionSouris.x >= (GetScreenWidth()/2)-GetScreenWidth()/8) && (positionSouris.x <= (GetScreenWidth()/2)-GetScreenWidth()/8+boutonImage.width) && (positionSouris.y >= GetScreenHeight()/8+2*GetScreenWidth()/8) && (positionSouris.y <= GetScreenHeight()/8+2*GetScreenWidth()/8+boutonImage.height) ){
            UnloadImage(fondImage);
            UnloadTexture(fond);
            UnloadTexture(quitter);
            UnloadTexture(bouton);
            UnloadFont(font);
            ClearBackground(BLACK);
            EndDrawing();
        }
        else if ( (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) && (positionSouris.x >= (GetScreenWidth()/2)-GetScreenWidth()/8) && (positionSouris.x <= (GetScreenWidth()/2)-GetScreenWidth()/8+boutonImage.width) && (positionSouris.y >= GetScreenHeight()/8+3*GetScreenWidth()/8) && (positionSouris.y <= GetScreenHeight()/8+3*GetScreenWidth()/8+boutonImage.height) ){
            UnloadImage(fondImage);
            UnloadTexture(fond);
            UnloadTexture(quitter);
            UnloadTexture(bouton);
            UnloadFont(font);
            ClearBackground(BLACK);
            EndDrawing();
        }
        EndDrawing();
    }

    return 0;
}

int credits(){
    int largeur;
    int hauteur;
    largeur = GetScreenWidth();
    hauteur = GetScreenHeight();
    InitWindow(largeur,hauteur,"Menu");
    ToggleFullscreen();
    SetTargetFPS(30);

    Font font = LoadFont("../Font/Terserah.ttf");

    Image fondImage = LoadImage("../ImagesMenu/fond.png");
    ImageResize(&fondImage,GetScreenWidth(),GetScreenHeight());
    Texture2D fond = LoadTextureFromImage(fondImage);

    Image EliotImage = LoadImage("../ImagesCredits/Eliot.PNG");
    ImageResize(&EliotImage,GetScreenWidth()/8,GetScreenHeight()/8);
    Texture2D Eliot = LoadTextureFromImage(EliotImage);

    Image HugoImage = LoadImage("../ImagesCredits/Hugo.JPG");
    ImageResize(&HugoImage,GetScreenWidth()/8,GetScreenHeight()/8);
    Texture2D Hugo = LoadTextureFromImage(HugoImage);

    Image HeninImage = LoadImage("../ImagesCredits/Henin.jpg");
    ImageResize(&HeninImage,GetScreenWidth()/8,GetScreenHeight()/8);
    Texture2D Henin = LoadTextureFromImage(HeninImage);

    Image XavierImage = LoadImage("../ImagesCredits/Xavier.jpg");
    ImageResize(&XavierImage,GetScreenWidth()/8,GetScreenHeight()/8);
    Texture2D Xavier = LoadTextureFromImage(XavierImage);

    int fin = 0;
    while(!fin){
        BeginDrawing();

        DrawTextureEx(fond,(Vector2){0,0},0.0f,1.0f,WHITE);
        DrawTextureEx(Eliot,(Vector2){GetScreenWidth()/4,GetScreenHeight()/3-GetScreenHeight()/10},0.0f,1.0f,WHITE);
        DrawTextEx(font,"Eliot Rineau",(Vector2){GetScreenWidth()/4,GetScreenHeight()/3},40,2,WHITE);

        DrawTextureEx(Hugo,(Vector2){GetScreenWidth()-GetScreenWidth()/4,GetScreenHeight()/3-GetScreenHeight()/10},0.0f,1.0f,WHITE);
        DrawTextEx(font,"Hugo Verrier",(Vector2){GetScreenWidth()-GetScreenWidth()/4,GetScreenHeight()/3},40,2,WHITE);

        DrawTextureEx(Henin,(Vector2){GetScreenWidth()/4,GetScreenHeight()/3+GetScreenHeight()/3-GetScreenHeight()/10},0.0f,1.0f,WHITE);
        DrawTextEx(font,"Henin",(Vector2){GetScreenWidth()/4,GetScreenHeight()/3+GetScreenHeight()/3},40,2,WHITE);

        DrawTextureEx(Xavier,(Vector2){GetScreenWidth()-GetScreenWidth()/4,GetScreenHeight()+GetScreenHeight()/3-GetScreenHeight()/10},0.0f,1.0f,WHITE);
        DrawTextEx(font,"Xavier",(Vector2){GetScreenWidth()-GetScreenWidth()/4,GetScreenHeight()/3+GetScreenHeight()/3},40,2,WHITE);
        if (IsKeyPressed(KEY_ESCAPE)){
            UnloadFont(font);
            UnloadTexture(Eliot);
            UnloadTexture(Hugo);
            UnloadTexture(Henin);
            UnloadTexture(Xavier);
            EndDrawing();

            fin = 1;
        }
        EndDrawing();
    }
    return 0;

}


