#include "MenuGraphique.h"



void fenetreMenu(int* menu){

    // initialisation de la fenetre
    InitWindow(GetScreenWidth(),GetScreenHeight(),"Menu");
    ToggleFullscreen();
    Fenetre FenetreActuelle = MENU;
    int compteurFPS=0;
    int compteurLettrePremierParam=0;
    int compteurLettreDeuxiemeParam=0;
    int compteurLettreTroisiemeParam=0;
    int compteurLettreZT1 = 0;
    int compteurLettreZT2 = 0;
    int compteurLettreZT3 = 0;
    int compteurLettreZT4 = 0;
    char premierParam[CHAR_OUI_NON + 1] = "\0";
    char deuxiemeParam[CHAR_CHOIXNBJOUEURS + 1] = "\0";
    char troisiemeParam[CHAR_CHOIX_COULEUR_PION + 1] = "\0";
    char zt1[CHAR_PSEUDO + 1] = "\0";
    char zt2[CHAR_PSEUDO + 1] = "\0";
    char zt3[CHAR_PSEUDO + 1] = "\0";
    char zt4[CHAR_PSEUDO + 1] = "\0";



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

    Image suivantImage = LoadImage("../ImagesMenu/boutonSuivant.png");
    ImageResize(&suivantImage,GetScreenWidth()/22,GetScreenHeight()/18);
    Texture2D suivant = LoadTextureFromImage(suivantImage);

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


    SetTargetFPS(60);
    while (!fin ){
        Vector2 positionSouris;
        positionSouris = GetMousePosition();
        Rectangle TexteBoutonRE = { GetScreenWidth()/6+GetScreenWidth()/40, GetScreenHeight()/6+2.5*GetScreenHeight()/40, GetScreenHeight()/8, GetScreenHeight()/8 };
        Rectangle TexteBoutonNJ = { GetScreenWidth()/6+GetScreenWidth()/40, GetScreenHeight()/6+10*GetScreenHeight()/40, GetScreenHeight()/8, GetScreenHeight()/8 };
        Rectangle TexteBoutonCC = { GetScreenWidth()/6+GetScreenWidth()/40, GetScreenHeight()/6+18*GetScreenHeight()/40, GetScreenHeight()/8, GetScreenHeight()/8 };
        Rectangle ZoneTexte1 = {GetScreenWidth()/6+GetScreenWidth()/40,GetScreenHeight()/6+2.5*GetScreenHeight()/40,GetScreenWidth()/6,GetScreenHeight()/16};
        Rectangle ZoneTexte2 = {GetScreenWidth()/6+GetScreenWidth()/40,GetScreenHeight()/6+7.5*GetScreenHeight()/40,GetScreenWidth()/6,GetScreenHeight()/16};
        Rectangle ZoneTexte3 = {GetScreenWidth()/6+GetScreenWidth()/40,GetScreenHeight()/6+12.5*GetScreenHeight()/40,GetScreenWidth()/6,GetScreenHeight()/16};
        Rectangle ZoneTexte4 = {GetScreenWidth()/6+GetScreenWidth()/40,GetScreenHeight()/6+17.5*GetScreenHeight()/40,GetScreenWidth()/6,GetScreenHeight()/16};
        bool sourisSurTexteRE = false;
        bool sourisSurTexteNJ = false;
        bool sourisSurTexteCC = false;
        bool sourisSurZT1 = false;
        bool sourisSurZT2 = false;
        bool sourisSurZT3 = false;
        bool sourisSurZT4 = false;

        if (CheckCollisionPointRec(GetMousePosition(), TexteBoutonRE)) sourisSurTexteRE = true;
        else sourisSurTexteRE = false;
        if (CheckCollisionPointRec(GetMousePosition(), TexteBoutonNJ)) sourisSurTexteNJ = true;
        else sourisSurTexteNJ = false;
        if (CheckCollisionPointRec(GetMousePosition(), TexteBoutonCC)) sourisSurTexteCC = true;
        else sourisSurTexteCC = false;
        if (CheckCollisionPointRec(GetMousePosition(), ZoneTexte1)) sourisSurZT1 = true;
        else sourisSurZT1 = false;
        if (CheckCollisionPointRec(GetMousePosition(), ZoneTexte2)) sourisSurZT2 = true;
        else sourisSurZT2 = false;
        if (CheckCollisionPointRec(GetMousePosition(), ZoneTexte3)) sourisSurZT3 = true;
        else sourisSurZT3 = false;
        if (CheckCollisionPointRec(GetMousePosition(), ZoneTexte4)) sourisSurZT4 = true;
        else sourisSurZT4 = false;

        if (sourisSurTexteRE)
        {
            SetMouseCursor(MOUSE_CURSOR_IBEAM);
            int key = GetCharPressed();
            while (key > 0){
                if ((key >= 32) && (key <= 125) && (compteurLettrePremierParam < CHAR_OUI_NON))
                {
                    premierParam[compteurLettrePremierParam] = (char)key;
                    premierParam[compteurLettrePremierParam+1] = '\0';
                    compteurLettrePremierParam++;
                }
                key = GetCharPressed();
            }
            if (IsKeyPressed(KEY_BACKSPACE))
            {
                compteurLettrePremierParam--;
                if (compteurLettrePremierParam < 0) compteurLettrePremierParam = 0;
                premierParam[compteurLettrePremierParam] = '\0';
            }
        }
        else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

        if (sourisSurTexteRE) compteurFPS++;
        else compteurFPS = 0;





        if (sourisSurTexteNJ)
        {
            SetMouseCursor(MOUSE_CURSOR_IBEAM);
            int key = GetCharPressed();
            while (key > 0){
                if ((key >= 32) && (key <= 125) && (compteurLettreDeuxiemeParam < CHAR_CHOIXNBJOUEURS))
                {
                    deuxiemeParam[compteurLettreDeuxiemeParam] = (char)key;
                    deuxiemeParam[compteurLettreDeuxiemeParam+1] = '\0';
                    compteurLettreDeuxiemeParam++;
                }
                key = GetCharPressed();
            }
            if (IsKeyPressed(KEY_BACKSPACE))
            {
                compteurLettreDeuxiemeParam--;
                if (compteurLettreDeuxiemeParam < 0) compteurLettreDeuxiemeParam = 0;
                deuxiemeParam[compteurLettreDeuxiemeParam] = '\0';
            }
        }
        else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

        if (sourisSurTexteNJ) compteurFPS++;
        else compteurFPS = 0;






        if (sourisSurTexteCC)
        {
            SetMouseCursor(MOUSE_CURSOR_IBEAM);
            int key = GetCharPressed();
            while (key > 0){
                if ((key >= 32) && (key <= 125) && (compteurLettreTroisiemeParam < CHAR_CHOIX_COULEUR_PION))
                {
                    troisiemeParam[compteurLettreTroisiemeParam] = (char)key;
                    troisiemeParam[compteurLettreTroisiemeParam+1] = '\0';
                    compteurLettreTroisiemeParam++;
                }
                key = GetCharPressed();
            }
            if (IsKeyPressed(KEY_BACKSPACE))
            {
                compteurLettreTroisiemeParam--;
                if (compteurLettreTroisiemeParam < 0) compteurLettreTroisiemeParam = 0;
                troisiemeParam[compteurLettreTroisiemeParam] = '\0';
            }
        }
        else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

        if (sourisSurTexteCC) compteurFPS++;
        else compteurFPS = 0;


        if (sourisSurZT1)
        {
            SetMouseCursor(MOUSE_CURSOR_IBEAM);
            int key = GetCharPressed();
            while (key > 0){
                if ((key >= 32) && (key <= 125) && (compteurLettreZT1 < CHAR_PSEUDO))
                {
                    zt1[compteurLettreZT1] = (char)key;
                    zt1[compteurLettreZT1+1] = '\0';
                    compteurLettreZT1++;
                }
                key = GetCharPressed();
            }
            if (IsKeyPressed(KEY_BACKSPACE))
            {
                compteurLettreZT1--;
                if (compteurLettreZT1 < 0) compteurLettreZT1 = 0;
                zt1[compteurLettreZT1] = '\0';
            }
        }
        else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

        if (sourisSurZT1) compteurFPS++;
        else compteurFPS = 0;


        if (sourisSurZT2)
        {
            SetMouseCursor(MOUSE_CURSOR_IBEAM);
            int key = GetCharPressed();
            while (key > 0){
                if ((key >= 32) && (key <= 125) && (compteurLettreZT2 < CHAR_PSEUDO))
                {
                    zt2[compteurLettreZT2] = (char)key;
                    zt2[compteurLettreZT2+1] = '\0';
                    compteurLettreZT2++;
                }
                key = GetCharPressed();
            }
            if (IsKeyPressed(KEY_BACKSPACE))
            {
                compteurLettreZT2--;
                if (compteurLettreZT2 < 0) compteurLettreZT2 = 0;
                zt2[compteurLettreZT2] = '\0';
            }
        }
        else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

        if (sourisSurZT2) compteurFPS++;
        else compteurFPS = 0;


        if (sourisSurZT3)
        {
            SetMouseCursor(MOUSE_CURSOR_IBEAM);
            int key = GetCharPressed();
            while (key > 0){
                if ((key >= 32) && (key <= 125) && (compteurLettreZT3 < CHAR_PSEUDO))
                {
                    zt3[compteurLettreZT3] = (char)key;
                    zt3[compteurLettreZT3+1] = '\0';
                    compteurLettreZT3++;
                }
                key = GetCharPressed();
            }
            if (IsKeyPressed(KEY_BACKSPACE))
            {
                compteurLettreZT3--;
                if (compteurLettreZT3 < 0) compteurLettreZT3 = 0;
                zt3[compteurLettreZT3] = '\0';
            }
        }
        else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

        if (sourisSurZT3) compteurFPS++;
        else compteurFPS = 0;


        if (sourisSurZT4)
        {
            SetMouseCursor(MOUSE_CURSOR_IBEAM);
            int key = GetCharPressed();
            while (key > 0){
                if ((key >= 32) && (key <= 125) && (compteurLettreZT4 < CHAR_PSEUDO))
                {
                    zt4[compteurLettreZT4] = (char)key;
                    zt4[compteurLettreZT4+1] = '\0';
                    compteurLettreZT4++;
                }
                key = GetCharPressed();
            }
            if (IsKeyPressed(KEY_BACKSPACE))
            {
                compteurLettreZT4--;
                if (compteurLettreZT4 < 0) compteurLettreZT4 = 0;
                zt4[compteurLettreZT4] = '\0';
            }
        }
        else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

        if (sourisSurZT4) compteurFPS++;
        else compteurFPS = 0;




        BeginDrawing();
        ClearBackground(RAYWHITE);


        switch (FenetreActuelle) {

            case MENU:{
                DrawTextureEx(fond,(Vector2){0,0},0.0f,1.0f,WHITE);
                DrawTextureEx(quitter,(Vector2){GetScreenWidth()-GetScreenWidth()/16,GetScreenHeight()/32},0.0f,1.0f,WHITE);
                DrawTextureEx(bouton,(Vector2){(GetScreenWidth()/2)-GetScreenWidth()/8,GetScreenHeight()/8},0.0f,1.25f,WHITE);
                DrawTextureEx(bouton,(Vector2){(GetScreenWidth()/2)-GetScreenWidth()/8,GetScreenHeight()/8+GetScreenWidth()/8},0.0f,1.25f,WHITE);
                DrawTextureEx(bouton,(Vector2){(GetScreenWidth()/2)-GetScreenWidth()/8,GetScreenHeight()/8+2*GetScreenWidth()/8},0.0f,1.25f,WHITE);
                DrawTextureEx(bouton,(Vector2){(GetScreenWidth()/2)-GetScreenWidth()/8,GetScreenHeight()/8+3*GetScreenWidth()/8},0.0f,1.25f,WHITE);
                DrawTextureEx(bouton,(Vector2){(GetScreenWidth()/2)-GetScreenWidth()/6.5,0+GetScreenHeight()/40},0.0f,1.5f,WHITE);
                DrawTextEx(font,"KNOSSOS",(Vector2){GetScreenWidth()/2-GetScreenWidth()/30,0+GetScreenHeight()/20},60,0,BLACK);
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
                UnloadFont(font);
                UnloadTexture(fond);
                UnloadTexture(quitter);
                UnloadTexture(retourMenu);
                UnloadTexture(bouton);
                UnloadTexture(boutonCredits);
                UnloadTexture(Eliot);
                UnloadTexture(Hugo);
                UnloadTexture(Henin);
                UnloadTexture(Xavier);
            }break;
            case NOUVELLE_PARTIE:{
                DrawTextureEx(fond,(Vector2){0,0},0.0f,1.0f,WHITE);
                DrawTextureEx(retourMenu,(Vector2){GetScreenWidth()-GetScreenWidth()/16,GetScreenHeight()/32},0.0f,1.0f,WHITE);
                DrawRectangle(GetScreenWidth()/6,GetScreenHeight()/6,GetScreenWidth()-2*GetScreenWidth()/6,GetScreenHeight()-2*GetScreenHeight()/6,BEIGE);
                if (sourisSurTexteRE){
                    DrawRectangle(TexteBoutonRE.x,TexteBoutonRE.y,TexteBoutonRE.width,TexteBoutonRE.height,WHITE);
                }
                else DrawRectangle(TexteBoutonRE.x,TexteBoutonRE.y,TexteBoutonRE.width,TexteBoutonRE.height,BROWN);
                DrawText(premierParam, (int)TexteBoutonRE.x + 5, (int)TexteBoutonRE.y + 8, 40, MAROON);
                if (sourisSurTexteNJ){
                    DrawRectangle(TexteBoutonNJ.x,TexteBoutonNJ.y,TexteBoutonNJ.width,TexteBoutonNJ.height,WHITE);
                }
                else DrawRectangle(TexteBoutonNJ.x,TexteBoutonNJ.y,TexteBoutonNJ.width,TexteBoutonNJ.height,BROWN);
                DrawText(deuxiemeParam, (int)TexteBoutonNJ.x + 5, (int)TexteBoutonNJ.y + 8, 40, MAROON);

                if (sourisSurTexteCC){
                    DrawRectangle(TexteBoutonCC.x,TexteBoutonCC.y,TexteBoutonCC.width,TexteBoutonCC.height,WHITE);
                }
                else DrawRectangle(TexteBoutonCC.x,TexteBoutonCC.y,TexteBoutonCC.width,TexteBoutonCC.height,BROWN);
                DrawText(troisiemeParam, (int)TexteBoutonCC.x + 5, (int)TexteBoutonCC.y + 8, 40, MAROON);
                DrawTextEx(font,"Regle enfant : (Oui ou Non)",(Vector2){GetScreenWidth()/6+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/40},30,2,BLACK);
                DrawTextEx(font,"Nombre de Joueurs (2, 3 ou 4 Joueurs)",(Vector2){GetScreenWidth()/6+GetScreenWidth()/40,GetScreenHeight()/6+8*GetScreenHeight()/40},30,2,BLACK);
                DrawTextEx(font,"Choisir la couleur de votre pion (Jaune,Bleu,Rouge,Vert)",(Vector2){GetScreenWidth()/6+GetScreenWidth()/40,GetScreenHeight()/6+16*GetScreenHeight()/40},30,2,BLACK);
                DrawTextureEx(suivant,(Vector2){GetScreenWidth()-GetScreenWidth()/16,GetScreenHeight()-GetScreenHeight()/12},0.0f,1.0f,WHITE);
                DrawRectangle(GetScreenWidth()-1.375*GetScreenWidth()/16,GetScreenHeight()-GetScreenHeight()/8,GetScreenWidth()/12,GetScreenHeight()/32,BEIGE);
                DrawTextEx(font,"Suivant",(Vector2){GetScreenWidth()-1.25*GetScreenWidth()/16,GetScreenHeight()-GetScreenHeight()/8},30,2,BLACK);
                if (IsKeyPressed(KEY_ESCAPE) ||  (positionSouris.x >= GetScreenWidth()-GetScreenWidth()/16) && (positionSouris.x <= GetScreenWidth()-GetScreenWidth()/16 + quitterImage.width) && (positionSouris.y >= GetScreenHeight()/32) && (positionSouris.y <= GetScreenHeight()/32 +quitterImage.height) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
                {
                    FenetreActuelle = MENU;
                }
                if ((positionSouris.x >= GetScreenWidth()-GetScreenWidth()/16) && (positionSouris.x <= GetScreenWidth()-GetScreenWidth()/16 + quitterImage.width) && (positionSouris.y >= GetScreenHeight()-GetScreenHeight()/12) && (positionSouris.y <= GetScreenHeight()-GetScreenHeight()/12 +suivantImage.height) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
                {
                    FenetreActuelle = NOUVELLE_PARTIE_SUITE;
                }

            }break;
            case NOUVELLE_PARTIE_SUITE:{
                DrawTextureEx(fond,(Vector2){0,0},0.0f,1.0f,WHITE);
                DrawTextureEx(retourMenu,(Vector2){GetScreenWidth()-GetScreenWidth()/16,GetScreenHeight()/32},0.0f,1.0f,WHITE);
                DrawRectangle(GetScreenWidth()/6,GetScreenHeight()/6,GetScreenWidth()-2*GetScreenWidth()/6,GetScreenHeight()-2*GetScreenHeight()/6,BEIGE);
                if (sourisSurZT1){
                    DrawRectangle(ZoneTexte1.x,ZoneTexte1.y,ZoneTexte1.width,ZoneTexte1.height,WHITE);
                }
                else DrawRectangle(ZoneTexte1.x,ZoneTexte1.y,ZoneTexte1.width,ZoneTexte1.height,BROWN);
                DrawText(zt1, (int)ZoneTexte1.x + 5, (int)ZoneTexte1.y + 8, 40, MAROON);
                if (sourisSurZT2){
                    DrawRectangle(ZoneTexte2.x,ZoneTexte2.y,ZoneTexte2.width,ZoneTexte2.height,WHITE);
                }
                else DrawRectangle(ZoneTexte2.x,ZoneTexte2.y,ZoneTexte2.width,ZoneTexte2.height,BROWN);
                DrawText(zt2, (int)ZoneTexte2.x + 5, (int)ZoneTexte2.y + 8, 40, MAROON);
                if (sourisSurZT3){
                    DrawRectangle(ZoneTexte3.x,ZoneTexte3.y,ZoneTexte3.width,ZoneTexte3.height,WHITE);
                }
                else DrawRectangle(ZoneTexte3.x,ZoneTexte3.y,ZoneTexte3.width,ZoneTexte3.height,BROWN);
                DrawText(zt3, (int)ZoneTexte3.x + 5, (int)ZoneTexte3.y + 8, 40, MAROON);
                if (sourisSurZT4){
                    DrawRectangle(ZoneTexte4.x,ZoneTexte4.y,ZoneTexte4.width,ZoneTexte4.height,WHITE);
                }
                else DrawRectangle(ZoneTexte4.x,ZoneTexte4.y,ZoneTexte4.width,ZoneTexte4.height,BROWN);
                DrawText(zt4, (int)ZoneTexte4.x + 5, (int)ZoneTexte4.y + 8, 40, MAROON);
                DrawTextureEx(suivant,(Vector2){GetScreenWidth()-1.75*GetScreenWidth()/16,GetScreenHeight()-GetScreenHeight()/12},0.0f,1.0f,WHITE);
                DrawRectangle(GetScreenWidth()-2.5*GetScreenWidth()/16,GetScreenHeight()-GetScreenHeight()/8,GetScreenWidth()/8,GetScreenHeight()/32,BEIGE);
                DrawTextEx(font,"Lancer partie",(Vector2){GetScreenWidth()-2.5*GetScreenWidth()/16,GetScreenHeight()-GetScreenHeight()/8},30,2,BLACK);
                if (IsKeyPressed(KEY_ESCAPE) ||  (positionSouris.x >= GetScreenWidth()-GetScreenWidth()/16) && (positionSouris.x <= GetScreenWidth()-GetScreenWidth()/16 + quitterImage.width) && (positionSouris.y >= GetScreenHeight()/32) && (positionSouris.y <= GetScreenHeight()/32 +quitterImage.height) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
                {
                    FenetreActuelle = NOUVELLE_PARTIE;
                }
                if ((positionSouris.x >= GetScreenWidth()-1.75*GetScreenWidth()/16) && (positionSouris.x <= GetScreenWidth()-1.75*GetScreenWidth()/16 + quitterImage.width) && (positionSouris.y >= GetScreenHeight()-GetScreenHeight()/12) && (positionSouris.y <= GetScreenHeight()-GetScreenHeight()/12 +suivantImage.height) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
                {
                    FenetreActuelle = MENU; /// TEMPORAIRE  efzQREFZQRGBFEFZQRDBEDEFQVFDEFQSDQEDFQSVDEFSQVDQDZEFDSVFS
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


