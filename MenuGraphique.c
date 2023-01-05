
#include "MenuGraphique.h"

void fenetreMenu(int* menu){

    // initialisation de la fenetre
    InitWindow(GetScreenWidth(),GetScreenHeight(),"Menu");
    ToggleFullscreen();
    Fenetre FenetreActuelle = MENU;
    int compteurFPS=0;
    int nbJ = 0;
    int re = 0;
    int compteurLettrePremierParam=0;
    int compteurLettreDeuxiemeParam=0;
    int compteurLettrePremiereCouleur=0;
    int compteurLettreDeuxiemeCouleur=0;
    int compteurLettreTroisiemeCouleur=0;
    int compteurLettreQuatriemeCouleur=0;
    int compteurLettreZT1 = 0;
    int compteurLettreZT2 = 0;
    int compteurLettreZT3 = 0;
    int compteurLettreZT4 = 0;
    char premierParam[CHAR_OUI_NON + 1] = "\0";
    char deuxiemeParam[CHAR_CHOIXNBJOUEURS + 1] = "\0";
    char premiereCouleur[CHAR_CHOIX_COULEUR_PION + 1] = "\0";
    char deuxiemeCouleur[CHAR_CHOIX_COULEUR_PION + 1] = "\0";
    char troisiemeCouleur[CHAR_CHOIX_COULEUR_PION + 1] = "\0";
    char quatriemeCouleur[CHAR_CHOIX_COULEUR_PION + 1] = "\0";
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

    InitAudioDevice();
    Music music = LoadMusicStream("../SonMenu/son menu.mp3");
    //float jouerMusique = 0.0f;
    //bool pause = false;

    Sound sonBoutton = LoadSound("../SonMenu/CliqueBoutton.wav");


    int fin = 0; // fin inutile juste histoire de pas fermer la fenetre


    SetTargetFPS(60);
    while (!fin ){
        UpdateMusicStream(music);
        Vector2 positionSouris;
        positionSouris = GetMousePosition();
        Rectangle TexteBoutonRE = { GetScreenWidth()/6+GetScreenWidth()/40, GetScreenHeight()/6+2.5*GetScreenHeight()/40, GetScreenHeight()/8, GetScreenHeight()/8 };
        Rectangle TexteBoutonNJ = { GetScreenWidth()/6+GetScreenWidth()/40, GetScreenHeight()/6+10*GetScreenHeight()/40, GetScreenHeight()/8, GetScreenHeight()/8 };
        Rectangle TexteBoutonCC1 = { GetScreenWidth()/6+GetScreenWidth()/40, GetScreenHeight()/6+18*GetScreenHeight()/40, GetScreenHeight()/7, GetScreenHeight()/8 };
        Rectangle TexteBoutonCC2 = { GetScreenWidth()/6+GetScreenWidth()/40+GetScreenWidth()/8, GetScreenHeight()/6+18*GetScreenHeight()/40, GetScreenHeight()/7, GetScreenHeight()/8 };
        Rectangle TexteBoutonCC3 = { GetScreenWidth()/6+GetScreenWidth()/40+2*GetScreenWidth()/8, GetScreenHeight()/6+18*GetScreenHeight()/40, GetScreenHeight()/7, GetScreenHeight()/8 };
        Rectangle TexteBoutonCC4 = { GetScreenWidth()/6+GetScreenWidth()/40+3*GetScreenWidth()/8, GetScreenHeight()/6+18*GetScreenHeight()/40, GetScreenHeight()/7, GetScreenHeight()/8 };
        Rectangle ZoneTexte1 = {GetScreenWidth()-2*GetScreenWidth()/6-GetScreenWidth()/40,GetScreenHeight()/6+2.5*GetScreenHeight()/40,GetScreenWidth()/6,GetScreenHeight()/16};
        Rectangle ZoneTexte2 = {GetScreenWidth()-2*GetScreenWidth()/6-GetScreenWidth()/40,GetScreenHeight()/6+7.5*GetScreenHeight()/40,GetScreenWidth()/6,GetScreenHeight()/16};
        Rectangle ZoneTexte3 = {GetScreenWidth()-2*GetScreenWidth()/6-GetScreenWidth()/40,GetScreenHeight()/6+12.5*GetScreenHeight()/40,GetScreenWidth()/6,GetScreenHeight()/16};
        Rectangle ZoneTexte4 = {GetScreenWidth()-2*GetScreenWidth()/6-GetScreenWidth()/40,GetScreenHeight()/6+17.5*GetScreenHeight()/40,GetScreenWidth()/6,GetScreenHeight()/16};
        bool sourisSurTexteRE = false;
        bool sourisSurTexteNJ = false;
        bool sourisSurTexteCC1 = false;
        bool sourisSurTexteCC2 = false;
        bool sourisSurTexteCC3 = false;
        bool sourisSurTexteCC4 = false;
        bool sourisSurZT1 = false;
        bool sourisSurZT2 = false;
        bool sourisSurZT3 = false;
        bool sourisSurZT4 = false;
        bool regleEnfant = false;
        int* nombreJoueur = NULL;
        bool* jaune1 = false;
        bool* bleu1 = false;
        bool* rouge1 = false;
        bool* vert1 = false;
        bool* jaune2 = false;
        bool* bleu2 = false;
        bool* rouge2 = false;
        bool* vert2 = false;
        bool* jaune3 = false;
        bool* bleu3 = false;
        bool* rouge3 = false;
        bool* vert3 = false;
        bool* jaune4 = false;
        bool* bleu4 = false;
        bool* rouge4 = false;
        bool* vert4 = false;



        if (CheckCollisionPointRec(GetMousePosition(), TexteBoutonRE)) sourisSurTexteRE = true;
        else sourisSurTexteRE = false;
        if (CheckCollisionPointRec(GetMousePosition(), TexteBoutonNJ)) sourisSurTexteNJ = true;
        else sourisSurTexteNJ = false;
        if (CheckCollisionPointRec(GetMousePosition(), TexteBoutonCC1)) sourisSurTexteCC1 = true;
        else sourisSurTexteCC1 = false;
        if (CheckCollisionPointRec(GetMousePosition(), TexteBoutonCC2)) sourisSurTexteCC2 = true;
        else sourisSurTexteCC2 = false;
        if (CheckCollisionPointRec(GetMousePosition(), TexteBoutonCC3)) sourisSurTexteCC3 = true;
        else sourisSurTexteCC3 = false;
        if (CheckCollisionPointRec(GetMousePosition(), TexteBoutonCC4)) sourisSurTexteCC4 = true;
        else sourisSurTexteCC4 = false;
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
        if (strcmp(premierParam,"oui") == 0){
            regleEnfant = true;
        }else regleEnfant = false;
        if (regleEnfant == true){
            //regleEnfant();
        }




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
        if (strcmp(deuxiemeParam,"1") == 0){
            //*nombreJoueur = 1;
            //nbJoueur(nombreJoueur);
        }else if (strcmp(deuxiemeParam,"2") == 0){
            //*nombreJoueur = 2;
            //nbJoueur(nombreJoueur);
        }else if (strcmp(deuxiemeParam,"3") == 0){
            //*nombreJoueur = 3;
            //nbJoueur(nombreJoueur);
        }else if (strcmp(deuxiemeParam,"4") == 0){
            //*nombreJoueur = 4;
            //nbJoueur(nombreJoueur);
        }














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

        if (strcmp(deuxiemeParam,"2") == 0){
            nbJ = 1;
        }
        if (strcmp(deuxiemeParam,"3") == 0){
            nbJ = 2;
        }
        if (strcmp(deuxiemeParam,"4") == 0){
            nbJ = 3;
        }

        if (strcmp(premierParam,"\0") == 0){
            re = 1;
        }
        if (strcmp(premierParam,"oui") == 0 || strcmp(premierParam,"non") == 0){
            re = 2;
        }


        if (FenetreActuelle == MENU){
            PlayMusicStream(music);
        }

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
                    PlaySound(sonBoutton);
                }
                else if ( (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) && (positionSouris.x >= (GetScreenWidth()/2)-GetScreenWidth()/8) && (positionSouris.x <= (GetScreenWidth()/2)-GetScreenWidth()/8+boutonImage.width) && (positionSouris.y >= GetScreenHeight()/8) && (positionSouris.y <= GetScreenHeight()/8+boutonImage.height) ){
                    FenetreActuelle = NOUVELLE_PARTIE;
                    PlaySound(sonBoutton);
                    sleepf(0.216);
                    StopSound(sonBoutton);
                }
                else if ( (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) && (positionSouris.x >= (GetScreenWidth()/2)-GetScreenWidth()/8) && (positionSouris.x <= (GetScreenWidth()/2)-GetScreenWidth()/8+boutonImage.width) && (positionSouris.y >= GetScreenHeight()/8+GetScreenWidth()/8) && (positionSouris.y <= GetScreenHeight()/8+GetScreenWidth()/8+boutonImage.height) ){
                    FenetreActuelle = CHARGER_PARTIE;
                    PlaySound(sonBoutton);
                    sleepf(0.216);
                    StopSound(sonBoutton);
                }
                else if ( (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) && (positionSouris.x >= (GetScreenWidth()/2)-GetScreenWidth()/8) && (positionSouris.x <= (GetScreenWidth()/2)-GetScreenWidth()/8+boutonImage.width) && (positionSouris.y >= GetScreenHeight()/8+2*GetScreenWidth()/8) && (positionSouris.y <= GetScreenHeight()/8+2*GetScreenWidth()/8+boutonImage.height) ){
                    FenetreActuelle = REGLES;
                    PlaySound(sonBoutton);
                }
                else if ( (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) && (positionSouris.x >= (GetScreenWidth()/2)-GetScreenWidth()/8) && (positionSouris.x <= (GetScreenWidth()/2)-GetScreenWidth()/8+boutonImage.width) && (positionSouris.y >= GetScreenHeight()/8+3*GetScreenWidth()/8) && (positionSouris.y <= GetScreenHeight()/8+3*GetScreenWidth()/8+boutonImage.height) ){
                    FenetreActuelle = CREDITS;
                    PlaySound(sonBoutton);
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
                StopMusicStream(music);
            }break;
            case NOUVELLE_PARTIE:{
                switch (re) {
                    case 1:{
                        DrawTextureEx(fond,(Vector2){0,0},0.0f,1.0f,WHITE);
                        DrawTextureEx(retourMenu,(Vector2){GetScreenWidth()-GetScreenWidth()/16,GetScreenHeight()/32},0.0f,1.0f,WHITE);
                        DrawRectangle(GetScreenWidth()/6,GetScreenHeight()/6,GetScreenWidth()-2*GetScreenWidth()/6,GetScreenHeight()-2*GetScreenHeight()/6,BEIGE);
                        if (sourisSurTexteRE){
                            DrawRectangle(TexteBoutonRE.x,TexteBoutonRE.y,TexteBoutonRE.width,TexteBoutonRE.height,WHITE);
                        }
                        else DrawRectangle(TexteBoutonRE.x,TexteBoutonRE.y,TexteBoutonRE.width,TexteBoutonRE.height,BROWN);
                        DrawTextEx(font,"Regle enfant : (Oui ou Non)",(Vector2){GetScreenWidth()/6+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/40},30,2,BLACK);
                    }break;
                    case 2:{
                        DrawTextureEx(fond,(Vector2){0,0},0.0f,1.0f,WHITE);
                        DrawTextureEx(retourMenu,(Vector2){GetScreenWidth()-GetScreenWidth()/16,GetScreenHeight()/32},0.0f,1.0f,WHITE);
                        DrawRectangle(GetScreenWidth()/6,GetScreenHeight()/6,GetScreenWidth()-2*GetScreenWidth()/6,GetScreenHeight()-2*GetScreenHeight()/6,BEIGE);
                        if (sourisSurTexteRE){
                            DrawRectangle(TexteBoutonRE.x,TexteBoutonRE.y,TexteBoutonRE.width,TexteBoutonRE.height,WHITE);
                        }
                        else DrawRectangle(TexteBoutonRE.x,TexteBoutonRE.y,TexteBoutonRE.width,TexteBoutonRE.height,BROWN);
                        DrawTextEx(font,"Regle enfant : (Oui ou Non)",(Vector2){GetScreenWidth()/6+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/40},30,2,BLACK);
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
                        DrawTextEx(font,"Nombre de Joueurs (2, 3 ou 4 Joueurs)",(Vector2){GetScreenWidth()/6+GetScreenWidth()/40,GetScreenHeight()/6+8*GetScreenHeight()/40},30,2,BLACK);



                        switch (nbJ) {
                            case 1:{
                                if (sourisSurTexteCC1){
                                    DrawRectangle(TexteBoutonCC1.x,TexteBoutonCC1.y,TexteBoutonCC1.width,TexteBoutonCC1.height,WHITE);
                                }
                                else DrawRectangle(TexteBoutonCC1.x,TexteBoutonCC1.y,TexteBoutonCC1.width,TexteBoutonCC1.height,BROWN);
                                if (sourisSurTexteCC2){
                                    DrawRectangle(TexteBoutonCC2.x,TexteBoutonCC2.y,TexteBoutonCC2.width,TexteBoutonCC2.height,WHITE);
                                }
                                else DrawRectangle(TexteBoutonCC2.x,TexteBoutonCC2.y,TexteBoutonCC2.width,TexteBoutonCC2.height,BROWN);

                                if (sourisSurTexteCC1)
                                {
                                    SetMouseCursor(MOUSE_CURSOR_IBEAM);
                                    int key = GetCharPressed();
                                    while (key > 0){
                                        if ((key >= 32) && (key <= 125) && (compteurLettrePremiereCouleur < CHAR_CHOIX_COULEUR_PION))
                                        {
                                            premiereCouleur[compteurLettrePremiereCouleur] = (char)key;
                                            premiereCouleur[compteurLettrePremiereCouleur+1] = '\0';
                                            compteurLettrePremiereCouleur++;
                                        }
                                        key = GetCharPressed();
                                    }
                                    if (IsKeyPressed(KEY_BACKSPACE))
                                    {
                                        compteurLettrePremiereCouleur--;
                                        if (compteurLettrePremiereCouleur < 0) compteurLettrePremiereCouleur = 0;
                                        premiereCouleur[compteurLettrePremiereCouleur] = '\0';
                                    }
                                }
                                else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
                                if (sourisSurTexteCC1) compteurFPS++;
                                else compteurFPS = 0;
                                if (strcmp(premiereCouleur,"jaune") == 0){
                                    //*jaune1 = true;
                                    //couleurPion1(jaune1);
                                }
                                if (strcmp(premiereCouleur,"bleu") == 0){
                                    //*bleu1 = true;
                                    //couleurPion1(bleu1);
                                }
                                if (strcmp(premiereCouleur,"rouge") == 0){
                                    //*rouge1 = true;
                                    //couleurPion1(rouge1);
                                }
                                if (strcmp(premiereCouleur,"vert") == 0){
                                    //*vert1 = true;
                                    //couleurPion1(vert1);
                                }
                                ///DEUXIEME
                                if (sourisSurTexteCC2)
                                {
                                    SetMouseCursor(MOUSE_CURSOR_IBEAM);
                                    int key = GetCharPressed();
                                    while (key > 0){
                                        if ((key >= 32) && (key <= 125) && (compteurLettreDeuxiemeCouleur < CHAR_CHOIX_COULEUR_PION))
                                        {
                                            deuxiemeCouleur[compteurLettreDeuxiemeCouleur] = (char)key;
                                            deuxiemeCouleur[compteurLettreDeuxiemeCouleur+1] = '\0';
                                            compteurLettreDeuxiemeCouleur++;
                                        }
                                        key = GetCharPressed();
                                    }
                                    if (IsKeyPressed(KEY_BACKSPACE))
                                    {
                                        compteurLettreDeuxiemeCouleur--;
                                        if (compteurLettreDeuxiemeCouleur < 0) compteurLettreDeuxiemeCouleur = 0;
                                        deuxiemeCouleur[compteurLettreDeuxiemeCouleur] = '\0';
                                    }
                                }
                                else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

                                if (sourisSurTexteCC2) compteurFPS++;
                                else compteurFPS = 0;
                                if (strcmp(deuxiemeCouleur,"jaune") == 0){
                                    //*jaune2 = true;
                                    //couleurPion2(jaune2);
                                }
                                if (strcmp(deuxiemeCouleur,"bleu") == 0){
                                    //*bleu2 = true;
                                    //couleurPion2(bleu2);
                                }
                                if (strcmp(deuxiemeCouleur,"rouge") == 0){
                                    //*rouge2 = true;
                                    //couleurPion2(rouge2);
                                }
                                if (strcmp(deuxiemeCouleur,"vert") == 0){
                                    //*vert2 = true;
                                    //couleurPion2(vert2);
                                }
                            }break;
                            case 2:{
                                if (sourisSurTexteCC1){
                                    DrawRectangle(TexteBoutonCC1.x,TexteBoutonCC1.y,TexteBoutonCC1.width,TexteBoutonCC1.height,WHITE);
                                }
                                else DrawRectangle(TexteBoutonCC1.x,TexteBoutonCC1.y,TexteBoutonCC1.width,TexteBoutonCC1.height,BROWN);
                                if (sourisSurTexteCC2){
                                    DrawRectangle(TexteBoutonCC2.x,TexteBoutonCC2.y,TexteBoutonCC2.width,TexteBoutonCC2.height,WHITE);
                                }
                                else DrawRectangle(TexteBoutonCC2.x,TexteBoutonCC2.y,TexteBoutonCC2.width,TexteBoutonCC2.height,BROWN);
                                if (sourisSurTexteCC3){
                                    DrawRectangle(TexteBoutonCC3.x,TexteBoutonCC3.y,TexteBoutonCC3.width,TexteBoutonCC3.height,WHITE);
                                }
                                else DrawRectangle(TexteBoutonCC3.x,TexteBoutonCC3.y,TexteBoutonCC3.width,TexteBoutonCC3.height,BROWN);
                                if (sourisSurTexteCC1) compteurFPS++;
                                else compteurFPS = 0;
                                if (strcmp(premiereCouleur,"jaune") == 0){
                                    //*jaune1 = true;
                                    //couleurPion1(jaune1);
                                }
                                if (strcmp(premiereCouleur,"bleu") == 0){
                                    //*bleu1 = true;
                                    //couleurPion1(bleu1);
                                }
                                if (strcmp(premiereCouleur,"rouge") == 0){
                                    //*rouge1 = true;
                                    //couleurPion1(rouge1);
                                }
                                if (strcmp(premiereCouleur,"vert") == 0){
                                    //*vert1 = true;
                                    //couleurPion1(vert1);
                                }
                                if (sourisSurTexteCC1)
                                {
                                    SetMouseCursor(MOUSE_CURSOR_IBEAM);
                                    int key = GetCharPressed();
                                    while (key > 0){
                                        if ((key >= 32) && (key <= 125) && (compteurLettrePremiereCouleur < CHAR_CHOIX_COULEUR_PION))
                                        {
                                            premiereCouleur[compteurLettrePremiereCouleur] = (char)key;
                                            premiereCouleur[compteurLettrePremiereCouleur+1] = '\0';
                                            compteurLettrePremiereCouleur++;
                                        }
                                        key = GetCharPressed();
                                    }
                                    if (IsKeyPressed(KEY_BACKSPACE))
                                    {
                                        compteurLettrePremiereCouleur--;
                                        if (compteurLettrePremiereCouleur < 0) compteurLettrePremiereCouleur = 0;
                                        premiereCouleur[compteurLettrePremiereCouleur] = '\0';
                                    }
                                }
                                else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
                                if (sourisSurTexteCC1) compteurFPS++;
                                else compteurFPS = 0;
                                if (strcmp(premiereCouleur,"jaune") == 0){
                                    //*jaune1 = true;
                                    //couleurPion1(jaune1);
                                }
                                if (strcmp(premiereCouleur,"bleu") == 0){
                                    //*bleu1 = true;
                                    //couleurPion1(bleu1);
                                }
                                if (strcmp(premiereCouleur,"rouge") == 0){
                                    //*rouge1 = true;
                                    //couleurPion1(rouge1);
                                }
                                if (strcmp(premiereCouleur,"vert") == 0){
                                    //*vert1 = true;
                                    //couleurPion1(vert1);
                                }
                                ///DEUXIEME
                                if (sourisSurTexteCC2)
                                {
                                    SetMouseCursor(MOUSE_CURSOR_IBEAM);
                                    int key = GetCharPressed();
                                    while (key > 0){
                                        if ((key >= 32) && (key <= 125) && (compteurLettreDeuxiemeCouleur < CHAR_CHOIX_COULEUR_PION))
                                        {
                                            deuxiemeCouleur[compteurLettreDeuxiemeCouleur] = (char)key;
                                            deuxiemeCouleur[compteurLettreDeuxiemeCouleur+1] = '\0';
                                            compteurLettreDeuxiemeCouleur++;
                                        }
                                        key = GetCharPressed();
                                    }
                                    if (IsKeyPressed(KEY_BACKSPACE))
                                    {
                                        compteurLettreDeuxiemeCouleur--;
                                        if (compteurLettreDeuxiemeCouleur < 0) compteurLettreDeuxiemeCouleur = 0;
                                        deuxiemeCouleur[compteurLettreDeuxiemeCouleur] = '\0';
                                    }
                                }
                                else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

                                if (sourisSurTexteCC2) compteurFPS++;
                                else compteurFPS = 0;
                                if (strcmp(deuxiemeCouleur,"jaune") == 0){
                                    //*jaune2 = true;
                                    //couleurPion2(jaune2);
                                }
                                if (strcmp(deuxiemeCouleur,"bleu") == 0){
                                    //*bleu2 = true;
                                    //couleurPion2(bleu2);
                                }
                                if (strcmp(deuxiemeCouleur,"rouge") == 0){
                                    //*rouge2 = true;
                                    //couleurPion2(rouge2);
                                }
                                if (strcmp(deuxiemeCouleur,"vert") == 0){
                                    //*vert2 = true;
                                    //couleurPion2(vert2);
                                }
                                ///TROISIEME
                                if (sourisSurTexteCC3)
                                {
                                    SetMouseCursor(MOUSE_CURSOR_IBEAM);
                                    int key = GetCharPressed();
                                    while (key > 0){
                                        if ((key >= 32) && (key <= 125) && (compteurLettreTroisiemeCouleur < CHAR_CHOIX_COULEUR_PION))
                                        {
                                            troisiemeCouleur[compteurLettreTroisiemeCouleur] = (char)key;
                                            troisiemeCouleur[compteurLettreTroisiemeCouleur+1] = '\0';
                                            compteurLettreTroisiemeCouleur++;
                                        }
                                        key = GetCharPressed();
                                    }
                                    if (IsKeyPressed(KEY_BACKSPACE))
                                    {
                                        compteurLettreTroisiemeCouleur--;
                                        if (compteurLettreTroisiemeCouleur < 0) compteurLettreTroisiemeCouleur = 0;
                                        troisiemeCouleur[compteurLettreTroisiemeCouleur] = '\0';
                                    }
                                }
                                else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

                                if (sourisSurTexteCC3) compteurFPS++;
                                else compteurFPS = 0;
                                if (strcmp(troisiemeCouleur,"jaune") == 0){
                                    //*jaune3 = true;
                                    //couleurPion3(jaune3);
                                }
                                if (strcmp(troisiemeCouleur,"bleu") == 0){
                                    //*bleu3 = true;
                                    //couleurPion3(bleu3);
                                }
                                if (strcmp(troisiemeCouleur,"rouge") == 0){
                                    //*rouge3 = true;
                                    //couleurPion3(rouge3);
                                }
                                if (strcmp(troisiemeCouleur,"vert") == 0){
                                    //*vert3 = true;
                                    //couleurPion3(vert3);
                                }
                            }break;
                            case 3:{
                                if (sourisSurTexteCC1){
                                    DrawRectangle(TexteBoutonCC1.x,TexteBoutonCC1.y,TexteBoutonCC1.width,TexteBoutonCC1.height,WHITE);
                                }
                                else DrawRectangle(TexteBoutonCC1.x,TexteBoutonCC1.y,TexteBoutonCC1.width,TexteBoutonCC1.height,BROWN);
                                if (sourisSurTexteCC2){
                                    DrawRectangle(TexteBoutonCC2.x,TexteBoutonCC2.y,TexteBoutonCC2.width,TexteBoutonCC2.height,WHITE);
                                }
                                else DrawRectangle(TexteBoutonCC2.x,TexteBoutonCC2.y,TexteBoutonCC2.width,TexteBoutonCC2.height,BROWN);
                                if (sourisSurTexteCC3){
                                    DrawRectangle(TexteBoutonCC3.x,TexteBoutonCC3.y,TexteBoutonCC3.width,TexteBoutonCC3.height,WHITE);
                                }
                                else DrawRectangle(TexteBoutonCC3.x,TexteBoutonCC3.y,TexteBoutonCC3.width,TexteBoutonCC3.height,BROWN);
                                if (sourisSurTexteCC4){
                                    DrawRectangle(TexteBoutonCC4.x,TexteBoutonCC4.y,TexteBoutonCC4.width,TexteBoutonCC4.height,WHITE);
                                }
                                else DrawRectangle(TexteBoutonCC4.x,TexteBoutonCC4.y,TexteBoutonCC4.width,TexteBoutonCC4.height,BROWN);
                            }
                                if (sourisSurTexteCC1)
                                {
                                    SetMouseCursor(MOUSE_CURSOR_IBEAM);
                                    int key = GetCharPressed();
                                    while (key > 0){
                                        if ((key >= 32) && (key <= 125) && (compteurLettrePremiereCouleur < CHAR_CHOIX_COULEUR_PION))
                                        {
                                            premiereCouleur[compteurLettrePremiereCouleur] = (char)key;
                                            premiereCouleur[compteurLettrePremiereCouleur+1] = '\0';
                                            compteurLettrePremiereCouleur++;
                                        }
                                        key = GetCharPressed();
                                    }
                                    if (IsKeyPressed(KEY_BACKSPACE))
                                    {
                                        compteurLettrePremiereCouleur--;
                                        if (compteurLettrePremiereCouleur < 0) compteurLettrePremiereCouleur = 0;
                                        premiereCouleur[compteurLettrePremiereCouleur] = '\0';
                                    }
                                }
                                else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
                                if (sourisSurTexteCC1) compteurFPS++;
                                else compteurFPS = 0;
                                if (strcmp(premiereCouleur,"jaune") == 0){
                                    //*jaune1 = true;
                                    //couleurPion1(jaune1);
                                }
                                if (strcmp(premiereCouleur,"bleu") == 0){
                                    //*bleu1 = true;
                                    //couleurPion1(bleu1);
                                }
                                if (strcmp(premiereCouleur,"rouge") == 0){
                                    //*rouge1 = true;
                                    //couleurPion1(rouge1);
                                }
                                if (strcmp(premiereCouleur,"vert") == 0){
                                    //*vert1 = true;
                                    //couleurPion1(vert1);
                                }
                                ///DEUXIEME
                                if (sourisSurTexteCC2)
                                {
                                    SetMouseCursor(MOUSE_CURSOR_IBEAM);
                                    int key = GetCharPressed();
                                    while (key > 0){
                                        if ((key >= 32) && (key <= 125) && (compteurLettreDeuxiemeCouleur < CHAR_CHOIX_COULEUR_PION))
                                        {
                                            deuxiemeCouleur[compteurLettreDeuxiemeCouleur] = (char)key;
                                            deuxiemeCouleur[compteurLettreDeuxiemeCouleur+1] = '\0';
                                            compteurLettreDeuxiemeCouleur++;
                                        }
                                        key = GetCharPressed();
                                    }
                                    if (IsKeyPressed(KEY_BACKSPACE))
                                    {
                                        compteurLettreDeuxiemeCouleur--;
                                        if (compteurLettreDeuxiemeCouleur < 0) compteurLettreDeuxiemeCouleur = 0;
                                        deuxiemeCouleur[compteurLettreDeuxiemeCouleur] = '\0';
                                    }
                                }
                                else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

                                if (sourisSurTexteCC2) compteurFPS++;
                                else compteurFPS = 0;
                                if (strcmp(deuxiemeCouleur,"jaune") == 0){
                                    //*jaune2 = true;
                                    //couleurPion2(jaune2);
                                }
                                if (strcmp(deuxiemeCouleur,"bleu") == 0){
                                    //*bleu2 = true;
                                    //couleurPion2(bleu2);
                                }
                                if (strcmp(deuxiemeCouleur,"rouge") == 0){
                                    //*rouge2 = true;
                                    //couleurPion2(rouge2);
                                }
                                if (strcmp(deuxiemeCouleur,"vert") == 0){
                                    //*vert2 = true;
                                    //couleurPion2(vert2);
                                }
                                ///TROISIEME
                                if (sourisSurTexteCC3)
                                {
                                    SetMouseCursor(MOUSE_CURSOR_IBEAM);
                                    int key = GetCharPressed();
                                    while (key > 0){
                                        if ((key >= 32) && (key <= 125) && (compteurLettreTroisiemeCouleur < CHAR_CHOIX_COULEUR_PION))
                                        {
                                            troisiemeCouleur[compteurLettreTroisiemeCouleur] = (char)key;
                                            troisiemeCouleur[compteurLettreTroisiemeCouleur+1] = '\0';
                                            compteurLettreTroisiemeCouleur++;
                                        }
                                        key = GetCharPressed();
                                    }
                                    if (IsKeyPressed(KEY_BACKSPACE))
                                    {
                                        compteurLettreTroisiemeCouleur--;
                                        if (compteurLettreTroisiemeCouleur < 0) compteurLettreTroisiemeCouleur = 0;
                                        troisiemeCouleur[compteurLettreTroisiemeCouleur] = '\0';
                                    }
                                }
                                else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

                                if (sourisSurTexteCC3) compteurFPS++;
                                else compteurFPS = 0;
                                if (strcmp(troisiemeCouleur,"jaune") == 0){
                                    //*jaune3 = true;
                                    //couleurPion3(jaune3);
                                }
                                if (strcmp(troisiemeCouleur,"bleu") == 0){
                                    //*bleu3 = true;
                                    //couleurPion3(bleu3);
                                }
                                if (strcmp(troisiemeCouleur,"rouge") == 0){
                                    //*rouge3 = true;
                                    //couleurPion3(rouge3);
                                }
                                if (strcmp(troisiemeCouleur,"vert") == 0){
                                    //*vert3 = true;
                                    //couleurPion3(vert3);
                                }
                                ///QUATRIEME
                                if (sourisSurTexteCC4)
                                {
                                    SetMouseCursor(MOUSE_CURSOR_IBEAM);
                                    int key = GetCharPressed();
                                    while (key > 0){
                                        if ((key >= 32) && (key <= 125) && (compteurLettreQuatriemeCouleur < CHAR_CHOIX_COULEUR_PION))
                                        {
                                            quatriemeCouleur[compteurLettreQuatriemeCouleur] = (char)key;
                                            quatriemeCouleur[compteurLettreQuatriemeCouleur+1] = '\0';
                                            compteurLettreQuatriemeCouleur++;
                                        }
                                        key = GetCharPressed();
                                    }
                                    if (IsKeyPressed(KEY_BACKSPACE))
                                    {
                                        compteurLettreQuatriemeCouleur--;
                                        if (compteurLettreQuatriemeCouleur < 0) compteurLettreQuatriemeCouleur = 0;
                                        quatriemeCouleur[compteurLettreQuatriemeCouleur] = '\0';
                                    }
                                }
                                else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

                                if (sourisSurTexteCC4) compteurFPS++;
                                else compteurFPS = 0;
                                if (strcmp(quatriemeCouleur,"jaune") == 0){
                                    //*jaune4 = true;
                                    //couleurPion4(jaune4);
                                }
                                if (strcmp(quatriemeCouleur,"bleu") == 0){
                                    //*bleu4 = true;
                                    //couleurPion4(bleu4);
                                }
                                if (strcmp(quatriemeCouleur,"rouge") == 0){
                                    //*rouge4 = true;
                                    //couleurPion4(rouge4);
                                }
                                if (strcmp(quatriemeCouleur,"vert") == 0){
                                    //*vert4 = true;
                                    //couleurPion4(vert4);
                                }
                            default:break;
                        }
                        DrawTextEx(font,"Choisir la couleur de votre pion (Jaune,Bleu,Rouge,Vert)",(Vector2){GetScreenWidth()/6+GetScreenWidth()/40,GetScreenHeight()/6+16*GetScreenHeight()/40},30,2,BLACK);
                        DrawTextureEx(suivant,(Vector2){GetScreenWidth()-GetScreenWidth()/16,GetScreenHeight()-GetScreenHeight()/12},0.0f,1.0f,WHITE);
                        DrawRectangle(GetScreenWidth()-1.375*GetScreenWidth()/16,GetScreenHeight()-GetScreenHeight()/8,GetScreenWidth()/12,GetScreenHeight()/32,BEIGE);
                        DrawTextEx(font,"Suivant",(Vector2){GetScreenWidth()-1.25*GetScreenWidth()/16,GetScreenHeight()-GetScreenHeight()/8},30,2,BLACK);
                        DrawText(premiereCouleur, (int)TexteBoutonCC1.x + 5, (int)TexteBoutonCC1.y + 8, 40, MAROON);
                        DrawText(deuxiemeCouleur, (int)TexteBoutonCC2.x + 5, (int)TexteBoutonCC2.y + 8, 40, MAROON);
                        DrawText(troisiemeCouleur, (int)TexteBoutonCC3.x + 5, (int)TexteBoutonCC3.y + 8, 40, MAROON);
                        DrawText(quatriemeCouleur, (int)TexteBoutonCC4.x + 5, (int)TexteBoutonCC4.y + 8, 40, MAROON);
                        if ((positionSouris.x >= GetScreenWidth()-GetScreenWidth()/16) && (positionSouris.x <= GetScreenWidth()-GetScreenWidth()/16 + quitterImage.width) && (positionSouris.y >= GetScreenHeight()-GetScreenHeight()/12) && (positionSouris.y <= GetScreenHeight()-GetScreenHeight()/12 +suivantImage.height) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
                        {
                            FenetreActuelle = NOUVELLE_PARTIE_SUITE;
                        }
                    }
                    default:break;
                }

                if (IsKeyPressed(KEY_ESCAPE) ||  (positionSouris.x >= GetScreenWidth()-GetScreenWidth()/16) && (positionSouris.x <= GetScreenWidth()-GetScreenWidth()/16 + quitterImage.width) && (positionSouris.y >= GetScreenHeight()/32) && (positionSouris.y <= GetScreenHeight()/32 +quitterImage.height) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
                {
                    FenetreActuelle = MENU;
                    PlaySound(sonBoutton);
                }
            }break;
            case NOUVELLE_PARTIE_SUITE:{
                switch (nbJ) {
                    case 1:{
                        Joueur j1;
                        Joueur j2;
                        DrawTextureEx(fond,(Vector2){0,0},0.0f,1.0f,WHITE);
                        DrawTextureEx(retourMenu,(Vector2){GetScreenWidth()-GetScreenWidth()/16,GetScreenHeight()/32},0.0f,1.0f,WHITE);
                        DrawRectangle(GetScreenWidth()/6,GetScreenHeight()/6,GetScreenWidth()-2*GetScreenWidth()/6,GetScreenHeight()-2*GetScreenHeight()/6,BEIGE);
                        if (sourisSurZT1){
                            DrawRectangle(ZoneTexte1.x,ZoneTexte1.y,ZoneTexte1.width,ZoneTexte1.height,WHITE);
                        }
                        else DrawRectangle(ZoneTexte1.x,ZoneTexte1.y,ZoneTexte1.width,ZoneTexte1.height,BROWN);
                        DrawText(zt1, (int)ZoneTexte1.x + 5, (int)ZoneTexte1.y + 8, 40, MAROON);
                        strcpy(j1.pseudo,zt1);
                        if (sourisSurZT2){
                            DrawRectangle(ZoneTexte2.x,ZoneTexte2.y,ZoneTexte2.width,ZoneTexte2.height,WHITE);
                        }
                        else DrawRectangle(ZoneTexte2.x,ZoneTexte2.y,ZoneTexte2.width,ZoneTexte2.height,BROWN);
                        DrawText(zt2, (int)ZoneTexte2.x + 5, (int)ZoneTexte2.y + 8, 40, MAROON);
                        strcpy(j2.pseudo,zt2);
                        DrawTextEx(font,"Pseudo 1",(Vector2){GetScreenWidth()/6+GetScreenWidth()/40,GetScreenHeight()/6+2.5*GetScreenHeight()/40},40,2,BLACK);
                        DrawTextEx(font,"Pseudo 2",(Vector2){GetScreenWidth()/6+GetScreenWidth()/40,GetScreenHeight()/6+7.5*GetScreenHeight()/40},40,2,BLACK);
                    }break;
                    case 2:{
                        Joueur j1;
                        Joueur j2;
                        Joueur j3;
                        DrawTextureEx(fond,(Vector2){0,0},0.0f,1.0f,WHITE);
                        DrawTextureEx(retourMenu,(Vector2){GetScreenWidth()-GetScreenWidth()/16,GetScreenHeight()/32},0.0f,1.0f,WHITE);
                        DrawRectangle(GetScreenWidth()/6,GetScreenHeight()/6,GetScreenWidth()-2*GetScreenWidth()/6,GetScreenHeight()-2*GetScreenHeight()/6,BEIGE);
                        if (sourisSurZT1){
                            DrawRectangle(ZoneTexte1.x,ZoneTexte1.y,ZoneTexte1.width,ZoneTexte1.height,WHITE);
                        }
                        else DrawRectangle(ZoneTexte1.x,ZoneTexte1.y,ZoneTexte1.width,ZoneTexte1.height,BROWN);
                        DrawText(zt1, (int)ZoneTexte1.x + 5, (int)ZoneTexte1.y + 8, 40, MAROON);
                        strcpy(j1.pseudo,zt1);
                        if (sourisSurZT2){
                            DrawRectangle(ZoneTexte2.x,ZoneTexte2.y,ZoneTexte2.width,ZoneTexte2.height,WHITE);
                        }
                        else DrawRectangle(ZoneTexte2.x,ZoneTexte2.y,ZoneTexte2.width,ZoneTexte2.height,BROWN);
                        DrawText(zt2, (int)ZoneTexte2.x + 5, (int)ZoneTexte2.y + 8, 40, MAROON);
                        strcpy(j2.pseudo,zt2);
                        if (sourisSurZT3){
                            DrawRectangle(ZoneTexte3.x,ZoneTexte3.y,ZoneTexte3.width,ZoneTexte3.height,WHITE);
                        }
                        else DrawRectangle(ZoneTexte3.x,ZoneTexte3.y,ZoneTexte3.width,ZoneTexte3.height,BROWN);
                        DrawText(zt3, (int)ZoneTexte3.x + 5, (int)ZoneTexte3.y + 8, 40, MAROON);
                        strcpy(j3.pseudo,zt3);
                        DrawTextEx(font,"Pseudo 1",(Vector2){GetScreenWidth()/6+GetScreenWidth()/40,GetScreenHeight()/6+2.5*GetScreenHeight()/40},40,2,BLACK);
                        DrawTextEx(font,"Pseudo 2",(Vector2){GetScreenWidth()/6+GetScreenWidth()/40,GetScreenHeight()/6+7.5*GetScreenHeight()/40},40,2,BLACK);
                        DrawTextEx(font,"Pseudo 3",(Vector2){GetScreenWidth()/6+GetScreenWidth()/40,GetScreenHeight()/6+12.5*GetScreenHeight()/40},40,2,BLACK);
                    }break;
                    case 3:{
                        Joueur j1;
                        Joueur j2;
                        Joueur j3;
                        Joueur j4;
                        DrawTextureEx(fond,(Vector2){0,0},0.0f,1.0f,WHITE);
                        DrawTextureEx(retourMenu,(Vector2){GetScreenWidth()-GetScreenWidth()/16,GetScreenHeight()/32},0.0f,1.0f,WHITE);
                        DrawRectangle(GetScreenWidth()/6,GetScreenHeight()/6,GetScreenWidth()-2*GetScreenWidth()/6,GetScreenHeight()-2*GetScreenHeight()/6,BEIGE);
                        if (sourisSurZT1){
                            DrawRectangle(ZoneTexte1.x,ZoneTexte1.y,ZoneTexte1.width,ZoneTexte1.height,WHITE); // rectangle blanc si pas sur zone de texte
                        }
                        else DrawRectangle(ZoneTexte1.x,ZoneTexte1.y,ZoneTexte1.width,ZoneTexte1.height,BROWN); // rectangle marron si pas sur zone de texte
                        DrawText(zt1, (int)ZoneTexte1.x + 5, (int)ZoneTexte1.y + 8, 40, MAROON);
                        strcpy(j1.pseudo,zt1); // passage de la donnee en console
                        if (sourisSurZT2){
                            DrawRectangle(ZoneTexte2.x,ZoneTexte2.y,ZoneTexte2.width,ZoneTexte2.height,WHITE); // rectangle blanc si pas sur zone de texte
                        }
                        else DrawRectangle(ZoneTexte2.x,ZoneTexte2.y,ZoneTexte2.width,ZoneTexte2.height,BROWN); // rectangle marron si pas sur zone de texte
                        DrawText(zt2, (int)ZoneTexte2.x + 5, (int)ZoneTexte2.y + 8, 40, MAROON);
                        strcpy(j2.pseudo,zt2); // passage de la donnee en console
                        if (sourisSurZT3){
                            DrawRectangle(ZoneTexte3.x,ZoneTexte3.y,ZoneTexte3.width,ZoneTexte3.height,WHITE); // rectangle blanc si pas sur zone de texte
                        }
                        else DrawRectangle(ZoneTexte3.x,ZoneTexte3.y,ZoneTexte3.width,ZoneTexte3.height,BROWN); // rectangle marron si pas sur zone de texte
                        DrawText(zt3, (int)ZoneTexte3.x + 5, (int)ZoneTexte3.y + 8, 40, MAROON);
                        strcpy(j3.pseudo,zt3); // passage de la donnee en console
                        if (sourisSurZT4){
                            DrawRectangle(ZoneTexte4.x,ZoneTexte4.y,ZoneTexte4.width,ZoneTexte4.height,WHITE); // rectangle blanc si pas sur zone de texte
                        }
                        else DrawRectangle(ZoneTexte4.x,ZoneTexte4.y,ZoneTexte4.width,ZoneTexte4.height,BROWN); // rectangle marron si pas sur zone de texte
                        DrawText(zt4, (int)ZoneTexte4.x + 5, (int)ZoneTexte4.y + 8, 40, MAROON); // dessine l'input du clavier
                        strcpy(j4.pseudo,zt4); // passage de la donnee en console
                        DrawTextEx(font,"Pseudo 1",(Vector2){GetScreenWidth()/6+GetScreenWidth()/40,GetScreenHeight()/6+2.5*GetScreenHeight()/40},40,2,BLACK);  // affichage pseudo "x"
                        DrawTextEx(font,"Pseudo 2",(Vector2){GetScreenWidth()/6+GetScreenWidth()/40,GetScreenHeight()/6+7.5*GetScreenHeight()/40},40,2,BLACK);  // affichage pseudo "x"
                        DrawTextEx(font,"Pseudo 3",(Vector2){GetScreenWidth()/6+GetScreenWidth()/40,GetScreenHeight()/6+12.5*GetScreenHeight()/40},40,2,BLACK); // affichage pseudo "x"
                        DrawTextEx(font,"Pseudo 4",(Vector2){GetScreenWidth()/6+GetScreenWidth()/40,GetScreenHeight()/6+17.5*GetScreenHeight()/40},40,2,BLACK); // affichage pseudo "x"
                    }break;
                    default:break;
                }
                DrawTextureEx(suivant,(Vector2){GetScreenWidth()-1.75*GetScreenWidth()/16,GetScreenHeight()-GetScreenHeight()/12},0.0f,1.0f,WHITE); // dessin bouton suivant
                DrawRectangle(GetScreenWidth()-2.5*GetScreenWidth()/16,GetScreenHeight()-GetScreenHeight()/8,GetScreenWidth()/8,GetScreenHeight()/32,BEIGE); // dessin pour afficher texte bas droite ecran
                DrawTextEx(font,"Lancer partie",(Vector2){GetScreenWidth()-2.5*GetScreenWidth()/16,GetScreenHeight()-GetScreenHeight()/8},30,2,BLACK); // texte "suivant"
                if (IsKeyPressed(KEY_ESCAPE) ||  (positionSouris.x >= GetScreenWidth()-GetScreenWidth()/16) && (positionSouris.x <= GetScreenWidth()-GetScreenWidth()/16 + quitterImage.width) && (positionSouris.y >= GetScreenHeight()/32) && (positionSouris.y <= GetScreenHeight()/32 +quitterImage.height) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))) // hitbox pour le boutton retour menu
                {
                    FenetreActuelle = NOUVELLE_PARTIE; // affichage fenetre nouvelle partie
                    PlaySound(sonBoutton); // son boutton
                    sleepf(0.316); // bug son correction (duree du son 0.315 secondes)
                    StopSound(sonBoutton); // arret du son boutton
                }
                if ((positionSouris.x >= GetScreenWidth()-1.75*GetScreenWidth()/16) && (positionSouris.x <= GetScreenWidth()-1.75*GetScreenWidth()/16 + quitterImage.width) && (positionSouris.y >= GetScreenHeight()-GetScreenHeight()/12) && (positionSouris.y <= GetScreenHeight()-GetScreenHeight()/12 +suivantImage.height) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))) // hitbox pour le boutton creer nouvelle partie
                {
                    FenetreActuelle = PLATEAU; // affichage fenetre plateau
                    PlaySound(sonBoutton); // son boutton
                    sleepf(0.316); // bug son correction (duree du son 0.315 secondes)
                    StopSound(sonBoutton); // arret du son boutton
                }
            }break;
            case CHARGER_PARTIE:{ // affichage fenetre charger partie
                DrawTextureEx(fond,(Vector2){0,0},0.0f,1.0f,WHITE); // chargement fond
                DrawTextureEx(retourMenu,(Vector2){GetScreenWidth()-GetScreenWidth()/16,GetScreenHeight()/32},0.0f,1.0f,WHITE); // chargement boutton retour
                DrawRectangle(GetScreenWidth()/6,GetScreenHeight()/6,GetScreenWidth()-2*GetScreenWidth()/6,GetScreenHeight()-2*GetScreenHeight()/6,BEIGE); // dessin rectangle par dessus le fond
                DrawTextEx(font,"Choisir sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/4.5,GetScreenHeight()/6+GetScreenHeight()/40},40,2,BLACK); // dessin d'un texte par dessus le rectangle
                DrawRectangle(GetScreenWidth()/6+GetScreenWidth()/24,GetScreenHeight()/6+GetScreenHeight()/15,GetScreenWidth()-2.5*GetScreenWidth()/6,GetScreenHeight()-2.5*GetScreenHeight()/6,WHITE); // dessin d'un rectangle par dessus l'autre rectangle qui servira de hitbox
                if (IsKeyPressed(KEY_ESCAPE) ||  (positionSouris.x >= GetScreenWidth()-GetScreenWidth()/16) && (positionSouris.x <= GetScreenWidth()-GetScreenWidth()/16 + quitterImage.width) && (positionSouris.y >= GetScreenHeight()/32) && (positionSouris.y <= GetScreenHeight()/32 +quitterImage.height) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))) // hitbox pour le boutton retour menu
                {
                    FenetreActuelle = MENU; // retour au menu
                    PlaySound(sonBoutton); // son boutton
                }
            }break;
            case REGLES:{ // affichage fenetre regles
                DrawTextureEx(fond,(Vector2){0,0},0.0f,1.0f,WHITE); // dessin fond
                DrawTextureEx(retourMenu,(Vector2){GetScreenWidth()-GetScreenWidth()/16,GetScreenHeight()/32},0.0f,1.0f,WHITE); // dessin bouton retour
                DrawTextureEx(regles,(Vector2){0+GetScreenWidth()*0.1,0},0.0f,1.0f,WHITE); // dessin des regles
                if (IsKeyPressed(KEY_ESCAPE) ||  (positionSouris.x >= GetScreenWidth()-GetScreenWidth()/16) && (positionSouris.x <= GetScreenWidth()-GetScreenWidth()/16 + quitterImage.width) && (positionSouris.y >= GetScreenHeight()/32) && (positionSouris.y <= GetScreenHeight()/32 +quitterImage.height) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))) // hitbox pour le boutton retour menu
                {
                    FenetreActuelle = MENU; // affichage fenetre menu
                    PlaySound(sonBoutton); // son bouton
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

                if (IsKeyPressed(KEY_ESCAPE) ||  (positionSouris.x >= GetScreenWidth()-GetScreenWidth()/16) && (positionSouris.x <= GetScreenWidth()-GetScreenWidth()/16 + quitterImage.width) && (positionSouris.y >= GetScreenHeight()/32) && (positionSouris.y <= GetScreenHeight()/32 +quitterImage.height) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))) // hitbox pour le boutton retour menu
                {
                    FenetreActuelle = MENU; // retour au menu
                    PlaySound(sonBoutton); // son boutton
                }
            }break;
            default:break; // fin du switch
        }
        EndDrawing(); // terminer le dessin
    }
    CloseAudioDevice(); // fermer les peripheriques audio
    CloseWindow(); // fermer la fenetre
}


void sleepf(float seconds)
{
    int secs = floor(seconds);    // secondes
    int usecs = round((seconds - secs) * 1000000); // microsecondes
    usleep(secs * 1000000 + usecs); // secondes et microsecondes pour le sleepf
}

