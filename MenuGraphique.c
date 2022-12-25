#include "MenuGraphique.h"



void fenetreMenu(){

    // initialisation de la fenetre
    InitWindow(GetScreenWidth(),GetScreenHeight(),"Menu");
    ToggleFullscreen();
    Fenetre FenetreActuelle = MENU;
    int compteurFPS=0;
    SetTargetFPS(60);


    // chargement et redimension des textures MENU
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


    // chargement et redimension des textures REGLES
    Image reglesImage = LoadImage("../ImagesRegles/regles.png");
    ImageResize(&reglesImage,GetScreenWidth()*0.8,GetScreenWidth()*0.6);
    Texture2D regles = LoadTextureFromImage(reglesImage);
    UnloadImage(reglesImage);

    // chargement et redimension des textures CREDITS
    Image boutonCreditsImage = LoadImage("../ImagesMenu/parcheminhorizontal.png");
    ImageResize(&boutonCreditsImage,GetScreenWidth()/2.5,GetScreenHeight()/11);
    Texture2D boutonCredits = LoadTextureFromImage(boutonCreditsImage);
    UnloadImage(boutonCreditsImage);

    Image retourMenuImage = LoadImage("../ImagesMenu/boutonQuitter.png");
    ImageResize(&retourMenuImage,GetScreenWidth()/22,GetScreenHeight()/18);
    Texture2D retourMenu = LoadTextureFromImage(retourMenuImage);

    Image EliotImage = LoadImage("../ImagesCredits/Eliot.png");
    ImageResize(&EliotImage,GetScreenWidth()/4,GetScreenHeight()/3);
    Texture2D Eliot = LoadTextureFromImage(EliotImage);
    UnloadImage(EliotImage);

    Image HugoImage = LoadImage("../ImagesCredits/Hugo.png");
    ImageResize(&HugoImage,GetScreenWidth()/4,GetScreenHeight()/3);
    Texture2D Hugo = LoadTextureFromImage(HugoImage);
    UnloadImage(HugoImage);

    Image HeninImage = LoadImage("../ImagesCredits/Henin.png");
    ImageResize(&HeninImage,GetScreenWidth()/4,GetScreenHeight()/3);
    Texture2D Henin = LoadTextureFromImage(HeninImage);
    UnloadImage(HeninImage);

    Image XavierImage = LoadImage("../ImagesCredits/Xavier.png");
    ImageResize(&XavierImage,GetScreenWidth()/4,GetScreenHeight()/3);
    Texture2D Xavier = LoadTextureFromImage(XavierImage);
    UnloadImage(XavierImage);

    int fin = 0; // fin inutile juste histoire de pas fermer la fenetre
    while (!fin ){
        Vector2 positionSouris;
        positionSouris = GetMousePosition();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        compteurFPS++;

        switch (FenetreActuelle) {

            case MENU:{
                DrawTextureEx(fond,(Vector2){0,0},0.0f,1.0f,WHITE);
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
                    FenetreActuelle = QUITTER;
                }
                else if ( (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) && (positionSouris.x >= (GetScreenWidth()/2)-GetScreenWidth()/8) && (positionSouris.x <= (GetScreenWidth()/2)-GetScreenWidth()/8+boutonImage.width) && (positionSouris.y >= GetScreenHeight()/8) && (positionSouris.y <= GetScreenHeight()/8+boutonImage.height) ){
                    FenetreActuelle = NOUVELLE_PARTIE;
                }
                else if ( (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) && (positionSouris.x >= (GetScreenWidth()/2)-GetScreenWidth()/8) && (positionSouris.x <= (GetScreenWidth()/2)-GetScreenWidth()/8+boutonImage.width) && (positionSouris.y >= GetScreenHeight()/8+GetScreenWidth()/8) && (positionSouris.y <= GetScreenHeight()/8+GetScreenWidth()/8+boutonImage.height) ){
                    FenetreActuelle = CHARGER_PARTIE;
                }
                else if ( (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) && (positionSouris.x >= (GetScreenWidth()/2)-GetScreenWidth()/8) && (positionSouris.x <= (GetScreenWidth()/2)-GetScreenWidth()/8+boutonImage.width) && (positionSouris.y >= GetScreenHeight()/8+2*GetScreenWidth()/8) && (positionSouris.y <= GetScreenHeight()/8+2*GetScreenWidth()/8+boutonImage.height) ){
                    FenetreActuelle = REGLES;
                }
                else if ( (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) && (positionSouris.x >= (GetScreenWidth()/2)-GetScreenWidth()/8) && (positionSouris.x <= (GetScreenWidth()/2)-GetScreenWidth()/8+boutonImage.width) && (positionSouris.y >= GetScreenHeight()/8+3*GetScreenWidth()/8) && (positionSouris.y <= GetScreenHeight()/8+3*GetScreenWidth()/8+boutonImage.height) ){
                    FenetreActuelle = CREDITS;
                }
            }break;
            case QUITTER:{
                fin = 1;
                // tout unload
            }break;
            case NOUVELLE_PARTIE:{
                DrawTextureEx(fond,(Vector2){0,0},0.0f,1.0f,WHITE);
                // a faire
                if (IsKeyPressed(KEY_ESCAPE) ||  (positionSouris.x >= GetScreenWidth()-GetScreenWidth()/16) && (positionSouris.x <= GetScreenWidth()-GetScreenWidth()/16 + quitterImage.width) && (positionSouris.y >= GetScreenHeight()/32) && (positionSouris.y <= GetScreenHeight()/32 +quitterImage.height) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
                {
                    FenetreActuelle = MENU;
                }
            }break;
            case CHARGER_PARTIE:{
                DrawTextureEx(fond,(Vector2){0,0},0.0f,1.0f,WHITE);
                DrawTextureEx(retourMenu,(Vector2){GetScreenWidth()-GetScreenWidth()/16,GetScreenHeight()/32},0.0f,1.0f,WHITE);
                DrawRectangle(GetScreenWidth()/6,GetScreenHeight()/6,GetScreenWidth()-2*GetScreenWidth()/6,GetScreenHeight()-2*GetScreenHeight()/6,BEIGE);
                DrawTextEx(font,"Choisir sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/4.5,GetScreenHeight()/6+GetScreenHeight()/40},40,2,BLACK);
                DrawRectangle(GetScreenWidth()/6+GetScreenWidth()/24,GetScreenHeight()/6+GetScreenHeight()/15,GetScreenWidth()-2.5*GetScreenWidth()/6,GetScreenHeight()-2.5*GetScreenHeight()/6,WHITE);
                if (IsKeyPressed(KEY_ESCAPE) ||  (positionSouris.x >= GetScreenWidth()-GetScreenWidth()/16) && (positionSouris.x <= GetScreenWidth()-GetScreenWidth()/16 + quitterImage.width) && (positionSouris.y >= GetScreenHeight()/32) && (positionSouris.y <= GetScreenHeight()/32 +quitterImage.height) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
                {
                    FenetreActuelle = MENU;
                }
            }break;
            case REGLES:{
                DrawTextureEx(fond,(Vector2){0,0},0.0f,1.0f,WHITE);
                DrawTextureEx(retourMenu,(Vector2){GetScreenWidth()-GetScreenWidth()/16,GetScreenHeight()/32},0.0f,1.0f,WHITE);
                DrawTextureEx(regles,(Vector2){0+GetScreenWidth()*0.1,0},0.0f,1.0f,WHITE);
                if (IsKeyPressed(KEY_ESCAPE) ||  (positionSouris.x >= GetScreenWidth()-GetScreenWidth()/16) && (positionSouris.x <= GetScreenWidth()-GetScreenWidth()/16 + quitterImage.width) && (positionSouris.y >= GetScreenHeight()/32) && (positionSouris.y <= GetScreenHeight()/32 +quitterImage.height) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
                {
                    FenetreActuelle = MENU;
                }
            }break;
            case CREDITS:{
                DrawTextureEx(fond,(Vector2){0,0},0.0f,1.0f,WHITE);
                DrawTextureEx(retourMenu,(Vector2){GetScreenWidth()-GetScreenWidth()/16,GetScreenHeight()/32},0.0f,1.0f,WHITE);

                DrawTextureEx(Eliot,(Vector2){0+GetScreenWidth()/8,GetScreenHeight()/22+boutonImage.height},0.0f,1.0f,WHITE);
                DrawTextureEx(boutonCredits,(Vector2){0+GetScreenWidth()/22,GetScreenHeight()/22},0.0f,1.0f,WHITE);
                DrawTextEx(font,"Eliot Rineau",(Vector2){0+GetScreenWidth()/6,GetScreenHeight()/14},30,2,WHITE);

                DrawTextureEx(Hugo,(Vector2){0+GetScreenWidth()/8+GetScreenWidth()/2,GetScreenHeight()/22+boutonImage.height},0.0f,1.0f,WHITE);
                DrawTextureEx(boutonCredits,(Vector2){0+GetScreenWidth()/22+GetScreenWidth()/2,GetScreenHeight()/22},0.0f,1.0f,WHITE);
                DrawTextEx(font,"Hugo Verrier",(Vector2){0+GetScreenWidth()/6+GetScreenWidth()/2,0+GetScreenHeight()/14},30,2,WHITE);

                DrawTextureEx(Henin,(Vector2){0+GetScreenWidth()/8,GetScreenHeight()/22+boutonImage.height+GetScreenHeight()/2},0.0f,1.0f,WHITE);
                DrawTextureEx(boutonCredits,(Vector2){0+GetScreenWidth()/22,GetScreenHeight()/2+GetScreenHeight()/22},0.0f,1.0f,WHITE);
                DrawTextEx(font,"Henintsoa Ramakavelo",(Vector2){0+GetScreenWidth()/6-GetScreenWidth()/35,0+GetScreenHeight()/14+GetScreenHeight()/2},30,2,WHITE);

                DrawTextureEx(Xavier,(Vector2){0+GetScreenWidth()/8+GetScreenWidth()/2,GetScreenHeight()/22+boutonImage.height+GetScreenHeight()/2},0.0f,1.0f,WHITE);
                DrawTextureEx(boutonCredits,(Vector2){0+GetScreenWidth()/22+GetScreenWidth()/2,GetScreenHeight()/2+GetScreenHeight()/22},0.0f,1.0f,WHITE);
                DrawTextEx(font,"Xavier Ogandaga Wora",(Vector2){0+GetScreenWidth()/6+GetScreenWidth()/2-GetScreenWidth()/35,0+GetScreenHeight()/14+GetScreenHeight()/2},30,2,WHITE);

                if (IsKeyPressed(KEY_ESCAPE) ||  (positionSouris.x >= GetScreenWidth()-GetScreenWidth()/16) && (positionSouris.x <= GetScreenWidth()-GetScreenWidth()/16 + quitterImage.width) && (positionSouris.y >= GetScreenHeight()/32) && (positionSouris.y <= GetScreenHeight()/32 +quitterImage.height) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
                {
                    FenetreActuelle = MENU;
                }
            }break;
            default:break;
        }
        EndDrawing();
    }
    CloseWindow();
}
