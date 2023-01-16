
#include "MenuGraphique.h"

void fenetreMenu(int* menu){

    // initialisation de la fenetre
    InitWindow(GetScreenWidth(),GetScreenHeight(),"Menu"); // nom de la fenetre
    ToggleFullscreen(); // plein ecran
    Fenetre FenetreActuelle = MENU; // fenetre par defaut sur le menu
    Joueur j; // structure joueur
    int compteurFPS=0; // compteur fps actualisation
    int re = 0; // regle enfant variable pour le switch
    int nbS = 0; // nombre sauvegarde variable pour le switch
    // initialisation variable zone de texte
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
    // initialisation chaine de caractere
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
    Image fondImage = LoadImage("../ImagesMenu/fond.png");// Chargement image de fond
    ImageResize(&fondImage,GetScreenWidth(),GetScreenHeight());//Redimension image
    Texture2D fond = LoadTextureFromImage(fondImage);// Passage en texture

    Image boutonImage = LoadImage("../ImagesMenu/parcheminhorizontal.png");//Chargement image bouton
    ImageResize(&boutonImage,GetScreenWidth()/4,GetScreenHeight()/12);//Redimension image bouton
    Texture2D bouton = LoadTextureFromImage(boutonImage);//Passage en texture image bouton

    Image quitterImage = LoadImage("../ImagesMenu/boutonQuitter.png");//Chargement image bouton quitter
    ImageResize(&quitterImage,GetScreenWidth()/22,GetScreenHeight()/18);//Redimension image bouton quitter
    Texture2D quitter = LoadTextureFromImage(quitterImage);;//Passage en texture image bouton quitter

    Image suivantImage = LoadImage("../ImagesMenu/boutonSuivant.png");//Chargement image bouton suivant
    ImageResize(&suivantImage,GetScreenWidth()/22,GetScreenHeight()/18);;//Redimension image bouton suivant
    Texture2D suivant = LoadTextureFromImage(suivantImage);;//Passage en texture image suivant

    Font font = LoadFont("../Font/Terserah.ttf");// Chargement police de carac


    // chargement et redimension des textures REGLES
    Image reglesImage = LoadImage("../ImagesRegles/regles.png");;//Chargement image regle
    ImageResize(&reglesImage,GetScreenWidth()*0.8,GetScreenWidth()*0.6);//Redimension image regle
    Texture2D regles = LoadTextureFromImage(reglesImage);;//passage en texture image regle
    UnloadImage(reglesImage);//suppression image regle

    // chargement et redimension des textures CREDITS
    Image boutonCreditsImage = LoadImage("../ImagesMenu/parcheminhorizontal.png");;//chargement image bouton credits
    ImageResize(&boutonCreditsImage,GetScreenWidth()/2.5,GetScreenHeight()/11);;//Redimension image bouton credits
    Texture2D boutonCredits = LoadTextureFromImage(boutonCreditsImage);;//passage en texture image bouton credits
    UnloadImage(boutonCreditsImage);;//Redimension image bouton quitter

    Image retourMenuImage = LoadImage("../ImagesMenu/boutonQuitter.png");//Redimension image bouton retour menu
    ImageResize(&retourMenuImage,GetScreenWidth()/22,GetScreenHeight()/18);//Redimension image bouton retour menu
    Texture2D retourMenu = LoadTextureFromImage(retourMenuImage);//Redimension image bouton retour menu

    Image EliotImage = LoadImage("../ImagesCredits/Eliot.png");//chargement image credit
    ImageResize(&EliotImage,GetScreenWidth()/4,GetScreenHeight()/3);//redimension image credit
    Texture2D Eliot = LoadTextureFromImage(EliotImage);//passage en texture image credit
    UnloadImage(EliotImage);//suppression image crédit

    Image HugoImage = LoadImage("../ImagesCredits/Hugo.png");//chargement image credit
    ImageResize(&HugoImage,GetScreenWidth()/4,GetScreenHeight()/3);//redimension image credit
    Texture2D Hugo = LoadTextureFromImage(HugoImage);//passage en texture image credit
    UnloadImage(HugoImage);//suppression image crédit

    Image HeninImage = LoadImage("../ImagesCredits/Henin.png");//chargement image credit
    ImageResize(&HeninImage,GetScreenWidth()/4,GetScreenHeight()/3);//redimension image credit
    Texture2D Henin = LoadTextureFromImage(HeninImage);//passage en texture image credit
    UnloadImage(HeninImage);//suppression image crédit

    Image XavierImage = LoadImage("../ImagesCredits/Xavier.png");//chargement image credit
    ImageResize(&XavierImage,GetScreenWidth()/4,GetScreenHeight()/3);//redimension image credit
    Texture2D Xavier = LoadTextureFromImage(XavierImage);//passage en texture image credit
    UnloadImage(XavierImage);//suppression image crédit

    InitAudioDevice(); // initialisation peripherique audio
    Music music = LoadMusicStream("../SonMenu/son menu.mp3"); // chargement musique


    Sound sonBoutton = LoadSound("../SonMenu/CliqueBoutton.wav"); // chargement son bouton

    int fin = 0; // fin inutile juste histoire de pas fermer la fenetre


    SetTargetFPS(60);
    while (!fin ){
        UpdateMusicStream(music); //mettre a jour la musique
        Vector2 positionSouris; // vecteur(x,y) position souris
        positionSouris = GetMousePosition(); // attribution de la structure 2D avec l'input de la souris
        Rectangle TexteBoutonRE = { GetScreenWidth()/6+GetScreenWidth()/40, GetScreenHeight()/6+2.5*GetScreenHeight()/40, GetScreenHeight()/8, GetScreenHeight()/8 }; //dimension zone texte regle enfant
        Rectangle TexteBoutonNJ = { GetScreenWidth()/6+GetScreenWidth()/40, GetScreenHeight()/6+10*GetScreenHeight()/40, GetScreenHeight()/8, GetScreenHeight()/8 }; //dimension zone texte nombre joueur
        Rectangle TexteBoutonCC1 = { GetScreenWidth()/6+GetScreenWidth()/40, GetScreenHeight()/6+18*GetScreenHeight()/40, GetScreenHeight()/7, GetScreenHeight()/8 }; //dimension zone texte couleur choix 1
        Rectangle TexteBoutonCC2 = { GetScreenWidth()/6+GetScreenWidth()/40+GetScreenWidth()/8, GetScreenHeight()/6+18*GetScreenHeight()/40, GetScreenHeight()/7, GetScreenHeight()/8 }; //dimension zone texte couleur choix 2
        Rectangle TexteBoutonCC3 = { GetScreenWidth()/6+GetScreenWidth()/40+2*GetScreenWidth()/8, GetScreenHeight()/6+18*GetScreenHeight()/40, GetScreenHeight()/7, GetScreenHeight()/8 }; //dimension zone texte couleur choix 3
        Rectangle TexteBoutonCC4 = { GetScreenWidth()/6+GetScreenWidth()/40+3*GetScreenWidth()/8, GetScreenHeight()/6+18*GetScreenHeight()/40, GetScreenHeight()/7, GetScreenHeight()/8 }; //dimension zone texte couleur choix 4
        Rectangle ZoneTexte1 = {GetScreenWidth()-2*GetScreenWidth()/6-GetScreenWidth()/40,GetScreenHeight()/6+2.5*GetScreenHeight()/40,GetScreenWidth()/6,GetScreenHeight()/16}; //dimension zone texte pseudo 1
        Rectangle ZoneTexte2 = {GetScreenWidth()-2*GetScreenWidth()/6-GetScreenWidth()/40,GetScreenHeight()/6+7.5*GetScreenHeight()/40,GetScreenWidth()/6,GetScreenHeight()/16}; //dimension zone texte pseudo 2
        Rectangle ZoneTexte3 = {GetScreenWidth()-2*GetScreenWidth()/6-GetScreenWidth()/40,GetScreenHeight()/6+12.5*GetScreenHeight()/40,GetScreenWidth()/6,GetScreenHeight()/16}; //dimension zone texte pseudo 3
        Rectangle ZoneTexte4 = {GetScreenWidth()-2*GetScreenWidth()/6-GetScreenWidth()/40,GetScreenHeight()/6+17.5*GetScreenHeight()/40,GetScreenWidth()/6,GetScreenHeight()/16}; //dimension zone texte seudo 4
        // initialisation variable des zones de texte
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
        //bool* jaune1 = false;
        //bool* bleu1 = false;
        //bool* rouge1 = false;
        //bool* vert1 = false;
        //bool* jaune2 = false;
        //bool* bleu2 = false;
        //bool* rouge2 = false;
        //bool* vert2 = false;
        //bool* jaune3 = false;
        //bool* bleu3 = false;
        //bool* rouge3 = false;
        //bool* vert3 = false;
        //bool* jaune4 = false;
        //bool* bleu4 = false;
        //bool* rouge4 = false;
        //bool* vert4 = false;


        // verification souris en zone de texte
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













        /// zone de texte pour pseudo
        if (sourisSurZT1) // si souris sur zone de texte alors :
        {
            SetMouseCursor(MOUSE_CURSOR_IBEAM); // si dans zone de texte curseur en mode ecriture de texte
            int key = GetCharPressed(); // initialisation variable prenant l'input du clavier
            while (key > 0){ // tant que variable clavier superieur a 0 alors
                if ((key >= 32) && (key <= 125) && (compteurLettreZT1 < CHAR_PSEUDO)) // et que variable clavier borne sur table ascii + plus petite que limite autorisee alors
                {
                    zt1[compteurLettreZT1] = (char)key; // enregistrement des input dans chaine de caractere
                    zt1[compteurLettreZT1+1] = '\0'; // valeur limite de la chaine de caractere definie par \0
                    compteurLettreZT1++; // ajout avec increment de 1 dans la chaine de caractere pour le compteur
                }
                key = GetCharPressed(); // variable pour l'input
            }
            if (IsKeyPressed(KEY_BACKSPACE)) // si touche effacer alors :
            {
                compteurLettreZT1--; // compteur retire par increment de 1 dans la chaine de caractere pour le compteur
                if (compteurLettreZT1 < 0) compteurLettreZT1 = 0; // si chaine de caractere plus petit que zero dans le compteur alors compteur est nul
                zt1[compteurLettreZT1] = '\0'; // si compteur nul alors chaine de caractere definie par \0 : vide
            }
        }
        else SetMouseCursor(MOUSE_CURSOR_DEFAULT); // si pas dans zone de texte curseur par default

        if (sourisSurZT1) compteurFPS++; // actualisation de la zone de texte si curseur dans la zone de texte
        else compteurFPS = 0; // si pas dans zone de texte elle n'est pas actualisee

        /// zone de texte pour pseudo
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

        /// zone de texte pour pseudo
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

        /// zone de texte pour pseudo
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
            j.nbJoueur = 1;
        }
        if (strcmp(deuxiemeParam,"3") == 0){
            j.nbJoueur = 2;
        }
        if (strcmp(deuxiemeParam,"4") == 0){
            j.nbJoueur= 3;
        }

        if (strcmp(premierParam,"\0") == 0){
            re = 1;
        }
        if (strcmp(premierParam,"oui") == 0 || strcmp(premierParam,"non") == 0){
            re = 2;
        }


        if (FenetreActuelle == MENU){ // si jeu se lance alors musique menu (le jeu se lance sur le menu par defaut)
            PlayMusicStream(music); // musique du menu
        }

        BeginDrawing(); // debut du dessin
        ClearBackground(RAYWHITE); // fond blanc

        switch (FenetreActuelle) { // switch du enum du menu

            case MENU:{ // si menu
                DrawTextureEx(fond,(Vector2){0,0},0.0f,1.0f,WHITE); // dessin fond
                DrawTextureEx(quitter,(Vector2){GetScreenWidth()-GetScreenWidth()/16,GetScreenHeight()/32},0.0f,1.0f,WHITE); // dessin bouton quitter
                DrawTextureEx(bouton,(Vector2){(GetScreenWidth()/2)-GetScreenWidth()/8,GetScreenHeight()/8},0.0f,1.25f,WHITE);  // dessin bouton du menu
                DrawTextureEx(bouton,(Vector2){(GetScreenWidth()/2)-GetScreenWidth()/8,GetScreenHeight()/8+GetScreenWidth()/8},0.0f,1.25f,WHITE); // dessin bouton du menu
                DrawTextureEx(bouton,(Vector2){(GetScreenWidth()/2)-GetScreenWidth()/8,GetScreenHeight()/8+2*GetScreenWidth()/8},0.0f,1.25f,WHITE); // dessin bouton du menu
                DrawTextureEx(bouton,(Vector2){(GetScreenWidth()/2)-GetScreenWidth()/8,GetScreenHeight()/8+3*GetScreenWidth()/8},0.0f,1.25f,WHITE); // dessin bouton du menu
                DrawTextureEx(bouton,(Vector2){(GetScreenWidth()/2)-GetScreenWidth()/6.5,0+GetScreenHeight()/40},0.0f,1.5f,WHITE); // dessin rectangle du menu texte
                DrawTextEx(font,"KNOSSOS",(Vector2){GetScreenWidth()/2-GetScreenWidth()/30,0+GetScreenHeight()/20},60,0,BLACK); // dessin du texte nom du jeu
                DrawTextEx(font,"Nouvelle partie",(Vector2){(GetScreenWidth()/2-GetScreenWidth()/20),GetScreenHeight()/8+GetScreenHeight()/32},40,0,BLACK); // dessin du texte
                DrawTextEx(font,"Charger partie",(Vector2){(GetScreenWidth()/2-GetScreenWidth()/20),GetScreenHeight()/8+GetScreenWidth()/8+GetScreenHeight()/32},40,0,BLACK); // dessin du texte
                DrawTextEx(font,"Afficher regle",(Vector2){(GetScreenWidth()/2-GetScreenWidth()/20),GetScreenHeight()/8+2*GetScreenWidth()/8+GetScreenHeight()/32},40,0,BLACK); // dessin du texte
                DrawTextEx(font,"Credits",(Vector2){(GetScreenWidth()/2-GetScreenWidth()/50),GetScreenHeight()/8+3*GetScreenWidth()/8+GetScreenHeight()/32},40,0,BLACK); // dessin du texte
                if (IsKeyPressed(KEY_ESCAPE) ||  (positionSouris.x >= GetScreenWidth()-GetScreenWidth()/16) && (positionSouris.x <= GetScreenWidth()-GetScreenWidth()/16 + quitterImage.width) && (positionSouris.y >= GetScreenHeight()/32) && (positionSouris.y <= GetScreenHeight()/32 +quitterImage.height) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
                {
                    FenetreActuelle = QUITTER; // si bouton quitter
                    PlaySound(sonBoutton); // jouer son bouton
                }
                else if ( (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) && (positionSouris.x >= (GetScreenWidth()/2)-GetScreenWidth()/8) && (positionSouris.x <= (GetScreenWidth()/2)-GetScreenWidth()/8+boutonImage.width) && (positionSouris.y >= GetScreenHeight()/8) && (positionSouris.y <= GetScreenHeight()/8+boutonImage.height) ){
                    FenetreActuelle = NOUVELLE_PARTIE; // si bouton nouvelle partie
                    PlaySound(sonBoutton); // jouer son bouton
                    sleepf(0.216); // pause duree son pour actualiser affichage
                    StopSound(sonBoutton); // son d'arrêt bouton
                }
                else if ( (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) && (positionSouris.x >= (GetScreenWidth()/2)-GetScreenWidth()/8) && (positionSouris.x <= (GetScreenWidth()/2)-GetScreenWidth()/8+boutonImage.width) && (positionSouris.y >= GetScreenHeight()/8+GetScreenWidth()/8) && (positionSouris.y <= GetScreenHeight()/8+GetScreenWidth()/8+boutonImage.height) ){
                    FenetreActuelle = CHARGER_PARTIE; // si bouton charger partie
                    PlaySound(sonBoutton); // jouer son bouton
                    sleepf(0.216); // pause duree son pour actualiser affichage
                    StopSound(sonBoutton); // son d'arrêt bouton
                }
                else if ( (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) && (positionSouris.x >= (GetScreenWidth()/2)-GetScreenWidth()/8) && (positionSouris.x <= (GetScreenWidth()/2)-GetScreenWidth()/8+boutonImage.width) && (positionSouris.y >= GetScreenHeight()/8+2*GetScreenWidth()/8) && (positionSouris.y <= GetScreenHeight()/8+2*GetScreenWidth()/8+boutonImage.height) ){
                    FenetreActuelle = REGLES; // si bouton regle
                    PlaySound(sonBoutton); // jouer son bouton
                }
                else if ( (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) && (positionSouris.x >= (GetScreenWidth()/2)-GetScreenWidth()/8) && (positionSouris.x <= (GetScreenWidth()/2)-GetScreenWidth()/8+boutonImage.width) && (positionSouris.y >= GetScreenHeight()/8+3*GetScreenWidth()/8) && (positionSouris.y <= GetScreenHeight()/8+3*GetScreenWidth()/8+boutonImage.height) ){
                    FenetreActuelle = CREDITS; // si bouton credits
                    PlaySound(sonBoutton); // jouer son bouton
                }
            }break;
            case QUITTER:{ // si bouton quitter menu
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
            case NOUVELLE_PARTIE:{ // si bouton nouvelle partie
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



                        switch (j.nbJoueur) { // switch nombre de joueur
                            case 1:{ // si 2 joueurs
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
                                ///PREMIERE ZONE DE TEXTE COULEUR
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
                            case 2:{ // si 3 joueurs
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
                                ///DEUXIEME ZONE DE TEXTE COULEUR
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
                                ///TROISIEME ZONE DE TEXTE COULEUR
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
                            case 3:{ // si 4 joueurs
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
                                ///PREMIERE ZONE DE TEXTE COULEUR
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
                                ///DEUXIEME ZONE DE TEXTE COULEUR
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
                                ///TROISIEME ZONE DE TEXTE COULEUR
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
                                ///QUATRIEME ZONE DE TEXTE COULEUR
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
                                    //*jaune4;
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
                        DrawTextureEx(suivant,(Vector2){GetScreenWidth()-GetScreenWidth()/16,GetScreenHeight()-GetScreenHeight()/12},0.0f,1.0f,WHITE); // dessine le bouton suivant
                        DrawRectangle(GetScreenWidth()-1.375*GetScreenWidth()/16,GetScreenHeight()-GetScreenHeight()/8,GetScreenWidth()/12,GetScreenHeight()/32,BEIGE); // dessine un rectangle pour le texte
                        DrawTextEx(font,"Suivant",(Vector2){GetScreenWidth()-1.25*GetScreenWidth()/16,GetScreenHeight()-GetScreenHeight()/8},30,2,BLACK); // dessine le texte "suivant"
                        DrawText(premiereCouleur, (int)TexteBoutonCC1.x + 5, (int)TexteBoutonCC1.y + 8, 40, MAROON);  // dessine l'input du clavier
                        DrawText(deuxiemeCouleur, (int)TexteBoutonCC2.x + 5, (int)TexteBoutonCC2.y + 8, 40, MAROON);  // dessine l'input du clavier
                        DrawText(troisiemeCouleur, (int)TexteBoutonCC3.x + 5, (int)TexteBoutonCC3.y + 8, 40, MAROON); // dessine l'input du clavier
                        DrawText(quatriemeCouleur, (int)TexteBoutonCC4.x + 5, (int)TexteBoutonCC4.y + 8, 40, MAROON); // dessine l'input du clavier
                        if ((positionSouris.x >= GetScreenWidth()-GetScreenWidth()/16) && (positionSouris.x <= GetScreenWidth()-GetScreenWidth()/16 + quitterImage.width) && (positionSouris.y >= GetScreenHeight()-GetScreenHeight()/12) && (positionSouris.y <= GetScreenHeight()-GetScreenHeight()/12 +suivantImage.height) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))) // hitbox pour le boutton retour menu
                        {
                            FenetreActuelle = NOUVELLE_PARTIE_SUITE; // affichage fenetre nouvelle partie suite
                            PlaySound(sonBoutton); // son bouton
                        }
                    }
                    default:break; // fin du switch regle enfant
                }

                if (IsKeyPressed(KEY_ESCAPE) ||  (positionSouris.x >= GetScreenWidth()-GetScreenWidth()/16) && (positionSouris.x <= GetScreenWidth()-GetScreenWidth()/16 + quitterImage.width) && (positionSouris.y >= GetScreenHeight()/32) && (positionSouris.y <= GetScreenHeight()/32 +quitterImage.height) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))) // hitbox pour le boutton retour menu
                {
                    FenetreActuelle = MENU; // affichage fenetre menu
                    PlaySound(sonBoutton); // son bouton
                }
            }break;
            case NOUVELLE_PARTIE_SUITE:{ // affichage fenetre nouvelle partie suite
                switch (j.nbJoueur) { // switch en fonction du nombre de joueur
                    case 1:{ // cas ou il y a 2 joueurs
                        Joueur j1; // creation de deux structures pour 2 joueurs
                        Joueur j2; // creation de deux structures pour 2 joueurs
                        DrawTextureEx(fond,(Vector2){0,0},0.0f,1.0f,WHITE); // dessine le fond
                        DrawTextureEx(retourMenu,(Vector2){GetScreenWidth()-GetScreenWidth()/16,GetScreenHeight()/32},0.0f,1.0f,WHITE); // dessine le bouton retour menu
                        DrawRectangle(GetScreenWidth()/6,GetScreenHeight()/6,GetScreenWidth()-2*GetScreenWidth()/6,GetScreenHeight()-2*GetScreenHeight()/6,BEIGE); // dessine un rectangle par dessus le fond
                        if (sourisSurZT1){
                            DrawRectangle(ZoneTexte1.x,ZoneTexte1.y,ZoneTexte1.width,ZoneTexte1.height,WHITE); // rectangle blanc si pas sur zone de texte
                        }
                        else DrawRectangle(ZoneTexte1.x,ZoneTexte1.y,ZoneTexte1.width,ZoneTexte1.height,BROWN); // rectangle marron si pas sur zone de texte
                        DrawText(zt1, (int)ZoneTexte1.x + 5, (int)ZoneTexte1.y + 8, 40, MAROON); // dessine l'input du clavier
                        strcpy(j1.pseudo,zt1); // passage de la donnee en console
                        if (sourisSurZT2){
                            DrawRectangle(ZoneTexte2.x,ZoneTexte2.y,ZoneTexte2.width,ZoneTexte2.height,WHITE); // rectangle blanc si pas sur zone de texte
                        }
                        else DrawRectangle(ZoneTexte2.x,ZoneTexte2.y,ZoneTexte2.width,ZoneTexte2.height,BROWN); // rectangle marron si pas sur zone de texte
                        DrawText(zt2, (int)ZoneTexte2.x + 5, (int)ZoneTexte2.y + 8, 40, MAROON); // dessine l'input du clavier
                        strcpy(j2.pseudo,zt2); // passage de la donnee en console
                        DrawTextEx(font,"Pseudo 1",(Vector2){GetScreenWidth()/6+GetScreenWidth()/40,GetScreenHeight()/6+2.5*GetScreenHeight()/40},40,2,BLACK); // affichage pseudo "x"
                        DrawTextEx(font,"Pseudo 2",(Vector2){GetScreenWidth()/6+GetScreenWidth()/40,GetScreenHeight()/6+7.5*GetScreenHeight()/40},40,2,BLACK); // affichage pseudo "x"
                    }break;
                    case 2:{ // cas ou il y a 3 joueurs
                        Joueur j1; // creation de 3 structures pour 3 joueurs
                        Joueur j2; // creation de 3 structures pour 3 joueurs
                        Joueur j3; // creation de 3 structures pour 3 joueurs
                        DrawTextureEx(fond,(Vector2){0,0},0.0f,1.0f,WHITE); // dessin du fond
                        DrawTextureEx(retourMenu,(Vector2){GetScreenWidth()-GetScreenWidth()/16,GetScreenHeight()/32},0.0f,1.0f,WHITE); // dessin du bouton retour menu
                        DrawRectangle(GetScreenWidth()/6,GetScreenHeight()/6,GetScreenWidth()-2*GetScreenWidth()/6,GetScreenHeight()-2*GetScreenHeight()/6,BEIGE); // dessin du rectangle par dessus le fond
                        if (sourisSurZT1){
                            DrawRectangle(ZoneTexte1.x,ZoneTexte1.y,ZoneTexte1.width,ZoneTexte1.height,WHITE); // rectangle blanc si pas sur zone de texte
                        }
                        else DrawRectangle(ZoneTexte1.x,ZoneTexte1.y,ZoneTexte1.width,ZoneTexte1.height,BROWN); // rectangle marron si pas sur zone de texte
                        DrawText(zt1, (int)ZoneTexte1.x + 5, (int)ZoneTexte1.y + 8, 40, MAROON); // dessine l'input du clavier
                        strcpy(j1.pseudo,zt1); // passage de la donnee en console
                        if (sourisSurZT2){
                            DrawRectangle(ZoneTexte2.x,ZoneTexte2.y,ZoneTexte2.width,ZoneTexte2.height,WHITE); // rectangle blanc si pas sur zone de texte
                        }
                        else DrawRectangle(ZoneTexte2.x,ZoneTexte2.y,ZoneTexte2.width,ZoneTexte2.height,BROWN); // rectangle marron si pas sur zone de texte
                        DrawText(zt2, (int)ZoneTexte2.x + 5, (int)ZoneTexte2.y + 8, 40, MAROON); // dessine l'input du clavier
                        strcpy(j2.pseudo,zt2); // passage de la donnee en console
                        if (sourisSurZT3){
                            DrawRectangle(ZoneTexte3.x,ZoneTexte3.y,ZoneTexte3.width,ZoneTexte3.height,WHITE); // rectangle blanc si pas sur zone de texte
                        }
                        else DrawRectangle(ZoneTexte3.x,ZoneTexte3.y,ZoneTexte3.width,ZoneTexte3.height,BROWN); // rectangle marron si pas sur zone de texte
                        DrawText(zt3, (int)ZoneTexte3.x + 5, (int)ZoneTexte3.y + 8, 40, MAROON); // dessine l'input du clavier
                        strcpy(j3.pseudo,zt3); // passage de la donnee en console
                        DrawTextEx(font,"Pseudo 1",(Vector2){GetScreenWidth()/6+GetScreenWidth()/40,GetScreenHeight()/6+2.5*GetScreenHeight()/40},40,2,BLACK);  // affichage pseudo "x"
                        DrawTextEx(font,"Pseudo 2",(Vector2){GetScreenWidth()/6+GetScreenWidth()/40,GetScreenHeight()/6+7.5*GetScreenHeight()/40},40,2,BLACK);  // affichage pseudo "x"
                        DrawTextEx(font,"Pseudo 3",(Vector2){GetScreenWidth()/6+GetScreenWidth()/40,GetScreenHeight()/6+12.5*GetScreenHeight()/40},40,2,BLACK); // affichage pseudo "x"
                    }break;
                    case 3:{ // cas ou il y a 4 joueurs
                        Joueur j1; //creation de 4 structures pour les 4 joueurs
                        Joueur j2; //creation de 4 structures pour les 4 joueurs
                        Joueur j3; //creation de 4 structures pour les 4 joueurs
                        Joueur j4; //creation de 4 structures pour les 4 joueurs
                        DrawTextureEx(fond,(Vector2){0,0},0.0f,1.0f,WHITE); // dessin du fond
                        DrawTextureEx(retourMenu,(Vector2){GetScreenWidth()-GetScreenWidth()/16,GetScreenHeight()/32},0.0f,1.0f,WHITE); // dessin du bouton retour
                        DrawRectangle(GetScreenWidth()/6,GetScreenHeight()/6,GetScreenWidth()-2*GetScreenWidth()/6,GetScreenHeight()-2*GetScreenHeight()/6,BEIGE); // dessin du rectangle par dessus le fond
                        if (sourisSurZT1){
                            DrawRectangle(ZoneTexte1.x,ZoneTexte1.y,ZoneTexte1.width,ZoneTexte1.height,WHITE); // rectangle blanc si pas sur zone de texte
                        }
                        else DrawRectangle(ZoneTexte1.x,ZoneTexte1.y,ZoneTexte1.width,ZoneTexte1.height,BROWN); // rectangle marron si pas sur zone de texte
                        DrawText(zt1, (int)ZoneTexte1.x + 5, (int)ZoneTexte1.y + 8, 40, MAROON); // dessine l'input du clavier
                        strcpy(j1.pseudo,zt1); // passage de la donnee en console
                        if (sourisSurZT2){
                            DrawRectangle(ZoneTexte2.x,ZoneTexte2.y,ZoneTexte2.width,ZoneTexte2.height,WHITE); // rectangle blanc si pas sur zone de texte
                        }
                        else DrawRectangle(ZoneTexte2.x,ZoneTexte2.y,ZoneTexte2.width,ZoneTexte2.height,BROWN); // rectangle marron si pas sur zone de texte
                        DrawText(zt2, (int)ZoneTexte2.x + 5, (int)ZoneTexte2.y + 8, 40, MAROON); // dessine l'input du clavier
                        strcpy(j2.pseudo,zt2); // passage de la donnee en console
                        if (sourisSurZT3){
                            DrawRectangle(ZoneTexte3.x,ZoneTexte3.y,ZoneTexte3.width,ZoneTexte3.height,WHITE); // rectangle blanc si pas sur zone de texte
                        }
                        else DrawRectangle(ZoneTexte3.x,ZoneTexte3.y,ZoneTexte3.width,ZoneTexte3.height,BROWN); // rectangle marron si pas sur zone de texte
                        DrawText(zt3, (int)ZoneTexte3.x + 5, (int)ZoneTexte3.y + 8, 40, MAROON); // dessine l'input du clavier
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
                    default:break; // fin du switch
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
                nbS = 7;
                switch (nbS) { // switch nombre de sauvegarde
                    case 1:{
                        // initialisation variable
                        Joueur* j1 =NULL;
                        tableau* t1 =NULL;
                        // dessin sauvegarde
                        DrawLine(GetScreenWidth()/6+GetScreenWidth()/24,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/12,GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/12,BLACK);
                        DrawTextEx(font,"Sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/40},30.0,2.0,BLACK);
                        if ((positionSouris.x >= GetScreenWidth()/6+GetScreenWidth()/24) &&(positionSouris.x <= GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6) && (positionSouris.y >= GetScreenHeight()/6+GetScreenHeight()/15) && (positionSouris.y <= GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/12) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
                            lireSauvegarderJoueurPlateau(j1,t1);
                            FenetreActuelle = PLATEAU;
                        }
                    }break;
                    case 2:{
                        // initialisation variable
                        Joueur* j1 =NULL;
                        tableau* t1 =NULL;
                        Joueur* j2 =NULL;
                        tableau* t2 =NULL;
                        // dessin sauvegarde
                        DrawLine(GetScreenWidth()/6+GetScreenWidth()/24,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/12,GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/12,BLACK);
                        DrawTextEx(font,"Sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/40},30.0,2.0,BLACK);
                        DrawLine(GetScreenWidth()/6+GetScreenWidth()/24,GetScreenHeight()/6+GetScreenHeight()/15+2*GetScreenHeight()/12,GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6,GetScreenHeight()/6+GetScreenHeight()/15+2*GetScreenHeight()/12,BLACK);
                        DrawTextEx(font,"Sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/40+GetScreenHeight()/12},30.0,2.0,BLACK);
                        if ((positionSouris.x >= GetScreenWidth()/6+GetScreenWidth()/24) &&(positionSouris.x <= GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6) && (positionSouris.y >= GetScreenHeight()/6+GetScreenHeight()/15) && (positionSouris.y <= GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/12) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
                            lireSauvegarderJoueurPlateau(j1,t1);
                            FenetreActuelle = PLATEAU;
                        }
                        if ((positionSouris.x >= GetScreenWidth()/6+GetScreenWidth()/24) &&(positionSouris.x <= GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6) && (positionSouris.y >= GetScreenHeight()/6+GetScreenHeight()/15) && (positionSouris.y <= GetScreenHeight()/6+GetScreenHeight()/15+2*GetScreenHeight()/12) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
                            lireSauvegarderJoueurPlateau(j2,t2);
                            FenetreActuelle = PLATEAU;
                        }
                    }break;
                    case 3:{
                        // initialisation variable
                        Joueur* j1 =NULL;
                        tableau* t1 =NULL;
                        Joueur* j2 =NULL;
                        tableau* t2 =NULL;
                        Joueur* j3 =NULL;
                        tableau* t3 =NULL;
                        // dessin sauvegarde
                        DrawLine(GetScreenWidth()/6+GetScreenWidth()/24,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/12,GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/12,BLACK);
                        DrawTextEx(font,"Sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/40},30.0,2.0,BLACK);
                        DrawLine(GetScreenWidth()/6+GetScreenWidth()/24,GetScreenHeight()/6+GetScreenHeight()/15+2*GetScreenHeight()/12,GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6,GetScreenHeight()/6+GetScreenHeight()/15+2*GetScreenHeight()/12,BLACK);
                        DrawTextEx(font,"Sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/40+GetScreenHeight()/12},30.0,2.0,BLACK);
                        DrawLine(GetScreenWidth()/6+GetScreenWidth()/24,GetScreenHeight()/6+GetScreenHeight()/15+3*GetScreenHeight()/12,GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6,GetScreenHeight()/6+GetScreenHeight()/15+3*GetScreenHeight()/12,BLACK);
                        DrawTextEx(font,"Sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/40+2*GetScreenHeight()/12},30.0,2.0,BLACK);
                        if ((positionSouris.x >= GetScreenWidth()/6+GetScreenWidth()/24) &&(positionSouris.x <= GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6) && (positionSouris.y >= GetScreenHeight()/6+GetScreenHeight()/15) && (positionSouris.y <= GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/12) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
                            lireSauvegarderJoueurPlateau(j1,t1);
                            FenetreActuelle = PLATEAU;
                        }
                        if ((positionSouris.x >= GetScreenWidth()/6+GetScreenWidth()/24) &&(positionSouris.x <= GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6) && (positionSouris.y >= GetScreenHeight()/6+GetScreenHeight()/15) && (positionSouris.y <= GetScreenHeight()/6+GetScreenHeight()/15+2*GetScreenHeight()/12) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
                            lireSauvegarderJoueurPlateau(j2,t2);
                            FenetreActuelle = PLATEAU;
                        }
                        if ((positionSouris.x >= GetScreenWidth()/6+GetScreenWidth()/24) &&(positionSouris.x <= GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6) && (positionSouris.y >= GetScreenHeight()/6+GetScreenHeight()/15+2*GetScreenHeight()/12) && (positionSouris.y <= GetScreenHeight()/6+GetScreenHeight()/15+3*GetScreenHeight()/12) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
                            lireSauvegarderJoueurPlateau(j3,t3);
                            FenetreActuelle = PLATEAU;
                        }
                    }break;
                    case 4:{
                        // initialisation variable
                        Joueur* j1 =NULL;
                        tableau* t1 =NULL;
                        Joueur* j2 =NULL;
                        tableau* t2 =NULL;
                        Joueur* j3 =NULL;
                        tableau* t3 =NULL;
                        Joueur* j4 =NULL;
                        tableau* t4 =NULL;
                        // dessin sauvegarde
                        DrawLine(GetScreenWidth()/6+GetScreenWidth()/24,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/12,GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/12,BLACK);
                        DrawTextEx(font,"Sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/40},30.0,2.0,BLACK);
                        DrawLine(GetScreenWidth()/6+GetScreenWidth()/24,GetScreenHeight()/6+GetScreenHeight()/15+2*GetScreenHeight()/12,GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6,GetScreenHeight()/6+GetScreenHeight()/15+2*GetScreenHeight()/12,BLACK);
                        DrawTextEx(font,"Sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/40+GetScreenHeight()/12},30.0,2.0,BLACK);
                        DrawLine(GetScreenWidth()/6+GetScreenWidth()/24,GetScreenHeight()/6+GetScreenHeight()/15+3*GetScreenHeight()/12,GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6,GetScreenHeight()/6+GetScreenHeight()/15+3*GetScreenHeight()/12,BLACK);
                        DrawTextEx(font,"Sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/40+2*GetScreenHeight()/12},30.0,2.0,BLACK);
                        DrawLine(GetScreenWidth()/6+GetScreenWidth()/24,GetScreenHeight()/6+GetScreenHeight()/15+4*GetScreenHeight()/12,GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6,GetScreenHeight()/6+GetScreenHeight()/15+4*GetScreenHeight()/12,BLACK);
                        DrawTextEx(font,"Sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/40+3*GetScreenHeight()/12},30.0,2.0,BLACK);
                        if ((positionSouris.x >= GetScreenWidth()/6+GetScreenWidth()/24) &&(positionSouris.x <= GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6) && (positionSouris.y >= GetScreenHeight()/6+GetScreenHeight()/15) && (positionSouris.y <= GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/12) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
                            lireSauvegarderJoueurPlateau(j1,t1);
                            FenetreActuelle = PLATEAU;
                        }
                        if ((positionSouris.x >= GetScreenWidth()/6+GetScreenWidth()/24) &&(positionSouris.x <= GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6) && (positionSouris.y >= GetScreenHeight()/6+GetScreenHeight()/15) && (positionSouris.y <= GetScreenHeight()/6+GetScreenHeight()/15+2*GetScreenHeight()/12) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
                            lireSauvegarderJoueurPlateau(j2,t2);
                            FenetreActuelle = PLATEAU;
                        }
                        if ((positionSouris.x >= GetScreenWidth()/6+GetScreenWidth()/24) &&(positionSouris.x <= GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6) && (positionSouris.y >= GetScreenHeight()/6+GetScreenHeight()/15+2*GetScreenHeight()/12) && (positionSouris.y <= GetScreenHeight()/6+GetScreenHeight()/15+3*GetScreenHeight()/12) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
                            lireSauvegarderJoueurPlateau(j3,t3);
                            FenetreActuelle = PLATEAU;
                        }
                        if ((positionSouris.x >= GetScreenWidth()/6+GetScreenWidth()/24) &&(positionSouris.x <= GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6) && (positionSouris.y >= GetScreenHeight()/6+GetScreenHeight()/15+3*GetScreenHeight()/12) && (positionSouris.y <= GetScreenHeight()/6+GetScreenHeight()/15+4*GetScreenHeight()/12) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
                            lireSauvegarderJoueurPlateau(j4,t4);
                            FenetreActuelle = PLATEAU;
                        }
                    }break;
                    case 5:{
                        // initialisation variable
                        Joueur* j1 =NULL;
                        tableau* t1 =NULL;
                        Joueur* j2 =NULL;
                        tableau* t2 =NULL;
                        Joueur* j3 =NULL;
                        tableau* t3 =NULL;
                        Joueur* j4 =NULL;
                        tableau* t4 =NULL;
                        Joueur* j5 =NULL;
                        tableau* t5 =NULL;
                        // dessin sauvegarde
                        DrawLine(GetScreenWidth()/6+GetScreenWidth()/24,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/12,GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/12,BLACK);
                        DrawTextEx(font,"Sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/40},30.0,2.0,BLACK);
                        DrawLine(GetScreenWidth()/6+GetScreenWidth()/24,GetScreenHeight()/6+GetScreenHeight()/15+2*GetScreenHeight()/12,GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6,GetScreenHeight()/6+GetScreenHeight()/15+2*GetScreenHeight()/12,BLACK);
                        DrawTextEx(font,"Sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/40+GetScreenHeight()/12},30.0,2.0,BLACK);
                        DrawLine(GetScreenWidth()/6+GetScreenWidth()/24,GetScreenHeight()/6+GetScreenHeight()/15+3*GetScreenHeight()/12,GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6,GetScreenHeight()/6+GetScreenHeight()/15+3*GetScreenHeight()/12,BLACK);
                        DrawTextEx(font,"Sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/40+2*GetScreenHeight()/12},30.0,2.0,BLACK);
                        DrawLine(GetScreenWidth()/6+GetScreenWidth()/24,GetScreenHeight()/6+GetScreenHeight()/15+4*GetScreenHeight()/12,GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6,GetScreenHeight()/6+GetScreenHeight()/15+4*GetScreenHeight()/12,BLACK);
                        DrawTextEx(font,"Sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/40+3*GetScreenHeight()/12},30.0,2.0,BLACK);
                        DrawLine(GetScreenWidth()/6+GetScreenWidth()/24,GetScreenHeight()/6+GetScreenHeight()/15+5*GetScreenHeight()/12,GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6,GetScreenHeight()/6+GetScreenHeight()/15+5*GetScreenHeight()/12,BLACK);
                        DrawTextEx(font,"Sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/40+4*GetScreenHeight()/12},30.0,2.0,BLACK);
                        if ((positionSouris.x >= GetScreenWidth()/6+GetScreenWidth()/24) &&(positionSouris.x <= GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6) && (positionSouris.y >= GetScreenHeight()/6+GetScreenHeight()/15) && (positionSouris.y <= GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/12) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
                            lireSauvegarderJoueurPlateau(j1,t1);
                            FenetreActuelle = PLATEAU;
                        }
                        if ((positionSouris.x >= GetScreenWidth()/6+GetScreenWidth()/24) &&(positionSouris.x <= GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6) && (positionSouris.y >= GetScreenHeight()/6+GetScreenHeight()/15) && (positionSouris.y <= GetScreenHeight()/6+GetScreenHeight()/15+2*GetScreenHeight()/12) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
                            lireSauvegarderJoueurPlateau(j2,t2);
                            FenetreActuelle = PLATEAU;
                        }
                        if ((positionSouris.x >= GetScreenWidth()/6+GetScreenWidth()/24) &&(positionSouris.x <= GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6) && (positionSouris.y >= GetScreenHeight()/6+GetScreenHeight()/15+2*GetScreenHeight()/12) && (positionSouris.y <= GetScreenHeight()/6+GetScreenHeight()/15+3*GetScreenHeight()/12) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
                            lireSauvegarderJoueurPlateau(j3,t3);
                            FenetreActuelle = PLATEAU;
                        }
                        if ((positionSouris.x >= GetScreenWidth()/6+GetScreenWidth()/24) &&(positionSouris.x <= GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6) && (positionSouris.y >= GetScreenHeight()/6+GetScreenHeight()/15+3*GetScreenHeight()/12) && (positionSouris.y <= GetScreenHeight()/6+GetScreenHeight()/15+4*GetScreenHeight()/12) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
                            lireSauvegarderJoueurPlateau(j4,t4);
                            FenetreActuelle = PLATEAU;
                        }
                        if ((positionSouris.x >= GetScreenWidth()/6+GetScreenWidth()/24) &&(positionSouris.x <= GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6) && (positionSouris.y >= GetScreenHeight()/6+GetScreenHeight()/15+4*GetScreenHeight()/12) && (positionSouris.y <= GetScreenHeight()/6+GetScreenHeight()/15+5*GetScreenHeight()/12) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
                            lireSauvegarderJoueurPlateau(j5,t5);
                            FenetreActuelle = PLATEAU;
                        }
                    }break;
                    case 6:{
                        // initialisation variable
                        Joueur* j1 =NULL;
                        tableau* t1 =NULL;
                        Joueur* j2 =NULL;
                        tableau* t2 =NULL;
                        Joueur* j3 =NULL;
                        tableau* t3 =NULL;
                        Joueur* j4 =NULL;
                        tableau* t4 =NULL;
                        Joueur* j5 =NULL;
                        tableau* t5 =NULL;
                        Joueur* j6 =NULL;
                        tableau* t6 =NULL;
                        // dessin sauvegarde
                        DrawLine(GetScreenWidth()/6+GetScreenWidth()/24,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/12,GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/12,BLACK);
                        DrawTextEx(font,"Sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/40},30.0,2.0,BLACK);
                        DrawLine(GetScreenWidth()/6+GetScreenWidth()/24,GetScreenHeight()/6+GetScreenHeight()/15+2*GetScreenHeight()/12,GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6,GetScreenHeight()/6+GetScreenHeight()/15+2*GetScreenHeight()/12,BLACK);
                        DrawTextEx(font,"Sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/40+GetScreenHeight()/12},30.0,2.0,BLACK);
                        DrawLine(GetScreenWidth()/6+GetScreenWidth()/24,GetScreenHeight()/6+GetScreenHeight()/15+3*GetScreenHeight()/12,GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6,GetScreenHeight()/6+GetScreenHeight()/15+3*GetScreenHeight()/12,BLACK);
                        DrawTextEx(font,"Sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/40+2*GetScreenHeight()/12},30.0,2.0,BLACK);
                        DrawLine(GetScreenWidth()/6+GetScreenWidth()/24,GetScreenHeight()/6+GetScreenHeight()/15+4*GetScreenHeight()/12,GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6,GetScreenHeight()/6+GetScreenHeight()/15+4*GetScreenHeight()/12,BLACK);
                        DrawTextEx(font,"Sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/40+3*GetScreenHeight()/12},30.0,2.0,BLACK);
                        DrawLine(GetScreenWidth()/6+GetScreenWidth()/24,GetScreenHeight()/6+GetScreenHeight()/15+5*GetScreenHeight()/12,GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6,GetScreenHeight()/6+GetScreenHeight()/15+5*GetScreenHeight()/12,BLACK);
                        DrawTextEx(font,"Sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/40+4*GetScreenHeight()/12},30.0,2.0,BLACK);
                        DrawLine(GetScreenWidth()/6+GetScreenWidth()/24,GetScreenHeight()/6+GetScreenHeight()/15+6*GetScreenHeight()/12,GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6,GetScreenHeight()/6+GetScreenHeight()/15+6*GetScreenHeight()/12,BLACK);
                        DrawTextEx(font,"Sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/40+5*GetScreenHeight()/12},30.0,2.0,BLACK);
                        if ((positionSouris.x >= GetScreenWidth()/6+GetScreenWidth()/24) &&(positionSouris.x <= GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6) && (positionSouris.y >= GetScreenHeight()/6+GetScreenHeight()/15) && (positionSouris.y <= GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/12) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
                            lireSauvegarderJoueurPlateau(j1,t1);
                            FenetreActuelle = PLATEAU;
                        }
                        if ((positionSouris.x >= GetScreenWidth()/6+GetScreenWidth()/24) &&(positionSouris.x <= GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6) && (positionSouris.y >= GetScreenHeight()/6+GetScreenHeight()/15) && (positionSouris.y <= GetScreenHeight()/6+GetScreenHeight()/15+2*GetScreenHeight()/12) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
                            lireSauvegarderJoueurPlateau(j2,t2);
                            FenetreActuelle = PLATEAU;
                        }
                        if ((positionSouris.x >= GetScreenWidth()/6+GetScreenWidth()/24) &&(positionSouris.x <= GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6) && (positionSouris.y >= GetScreenHeight()/6+GetScreenHeight()/15+2*GetScreenHeight()/12) && (positionSouris.y <= GetScreenHeight()/6+GetScreenHeight()/15+3*GetScreenHeight()/12) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
                            lireSauvegarderJoueurPlateau(j3,t3);
                            FenetreActuelle = PLATEAU;
                        }
                        if ((positionSouris.x >= GetScreenWidth()/6+GetScreenWidth()/24) &&(positionSouris.x <= GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6) && (positionSouris.y >= GetScreenHeight()/6+GetScreenHeight()/15+3*GetScreenHeight()/12) && (positionSouris.y <= GetScreenHeight()/6+GetScreenHeight()/15+4*GetScreenHeight()/12) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
                            lireSauvegarderJoueurPlateau(j4,t4);
                            FenetreActuelle = PLATEAU;
                        }
                        if ((positionSouris.x >= GetScreenWidth()/6+GetScreenWidth()/24) &&(positionSouris.x <= GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6) && (positionSouris.y >= GetScreenHeight()/6+GetScreenHeight()/15+4*GetScreenHeight()/12) && (positionSouris.y <= GetScreenHeight()/6+GetScreenHeight()/15+5*GetScreenHeight()/12) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
                            lireSauvegarderJoueurPlateau(j5,t5);
                            FenetreActuelle = PLATEAU;
                        }
                        if ((positionSouris.x >= GetScreenWidth()/6+GetScreenWidth()/24) &&(positionSouris.x <= GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6) && (positionSouris.y >= GetScreenHeight()/6+GetScreenHeight()/15+5*GetScreenHeight()/12) && (positionSouris.y <= GetScreenHeight()/6+GetScreenHeight()/15+6*GetScreenHeight()/12) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
                            lireSauvegarderJoueurPlateau(j6,t6);
                            FenetreActuelle = PLATEAU;
                        }
                    }break;
                    case 7:{
                        // initialisation variable
                        Joueur* j1 =NULL;
                        tableau* t1 =NULL;
                        Joueur* j2 =NULL;
                        tableau* t2 =NULL;
                        Joueur* j3 =NULL;
                        tableau* t3 =NULL;
                        Joueur* j4 =NULL;
                        tableau* t4 =NULL;
                        Joueur* j5 =NULL;
                        tableau* t5 =NULL;
                        Joueur* j6 =NULL;
                        tableau* t6 =NULL;
                        Joueur* j7 =NULL;
                        tableau* t7 =NULL;
                        // dessin sauvegarde
                        DrawLine(GetScreenWidth()/6+GetScreenWidth()/24,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/12,GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/12,BLACK);
                        DrawTextEx(font,"Sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/40},30.0,2.0,BLACK);
                        DrawLine(GetScreenWidth()/6+GetScreenWidth()/24,GetScreenHeight()/6+GetScreenHeight()/15+2*GetScreenHeight()/12,GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6,GetScreenHeight()/6+GetScreenHeight()/15+2*GetScreenHeight()/12,BLACK);
                        DrawTextEx(font,"Sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/40+GetScreenHeight()/12},30.0,2.0,BLACK);
                        DrawLine(GetScreenWidth()/6+GetScreenWidth()/24,GetScreenHeight()/6+GetScreenHeight()/15+3*GetScreenHeight()/12,GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6,GetScreenHeight()/6+GetScreenHeight()/15+3*GetScreenHeight()/12,BLACK);
                        DrawTextEx(font,"Sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/40+2*GetScreenHeight()/12},30.0,2.0,BLACK);
                        DrawLine(GetScreenWidth()/6+GetScreenWidth()/24,GetScreenHeight()/6+GetScreenHeight()/15+4*GetScreenHeight()/12,GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6,GetScreenHeight()/6+GetScreenHeight()/15+4*GetScreenHeight()/12,BLACK);
                        DrawTextEx(font,"Sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/40+3*GetScreenHeight()/12},30.0,2.0,BLACK);
                        DrawLine(GetScreenWidth()/6+GetScreenWidth()/24,GetScreenHeight()/6+GetScreenHeight()/15+5*GetScreenHeight()/12,GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6,GetScreenHeight()/6+GetScreenHeight()/15+5*GetScreenHeight()/12,BLACK);
                        DrawTextEx(font,"Sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/40+4*GetScreenHeight()/12},30.0,2.0,BLACK);
                        DrawLine(GetScreenWidth()/6+GetScreenWidth()/24,GetScreenHeight()/6+GetScreenHeight()/15+6*GetScreenHeight()/12,GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6,GetScreenHeight()/6+GetScreenHeight()/15+6*GetScreenHeight()/12,BLACK);
                        DrawTextEx(font,"Sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/40+5*GetScreenHeight()/12},30.0,2.0,BLACK);
                        DrawTextEx(font,"Sauvegarde :",(Vector2){GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()/40,GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/40+6*GetScreenHeight()/12},30.0,2.0,BLACK);
                        if ((positionSouris.x >= GetScreenWidth()/6+GetScreenWidth()/24) &&(positionSouris.x <= GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6) && (positionSouris.y >= GetScreenHeight()/6+GetScreenHeight()/15) && (positionSouris.y <= GetScreenHeight()/6+GetScreenHeight()/15+GetScreenHeight()/12) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
                            lireSauvegarderJoueurPlateau(j1,t1);
                            FenetreActuelle = PLATEAU;
                        }
                        if ((positionSouris.x >= GetScreenWidth()/6+GetScreenWidth()/24) &&(positionSouris.x <= GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6) && (positionSouris.y >= GetScreenHeight()/6+GetScreenHeight()/15) && (positionSouris.y <= GetScreenHeight()/6+GetScreenHeight()/15+2*GetScreenHeight()/12) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
                            lireSauvegarderJoueurPlateau(j2,t2);
                            FenetreActuelle = PLATEAU;
                        }
                        if ((positionSouris.x >= GetScreenWidth()/6+GetScreenWidth()/24) &&(positionSouris.x <= GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6) && (positionSouris.y >= GetScreenHeight()/6+GetScreenHeight()/15+2*GetScreenHeight()/12) && (positionSouris.y <= GetScreenHeight()/6+GetScreenHeight()/15+3*GetScreenHeight()/12) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
                            lireSauvegarderJoueurPlateau(j3,t3);
                            FenetreActuelle = PLATEAU;
                        }
                        if ((positionSouris.x >= GetScreenWidth()/6+GetScreenWidth()/24) &&(positionSouris.x <= GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6) && (positionSouris.y >= GetScreenHeight()/6+GetScreenHeight()/15+3*GetScreenHeight()/12) && (positionSouris.y <= GetScreenHeight()/6+GetScreenHeight()/15+4*GetScreenHeight()/12) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
                            lireSauvegarderJoueurPlateau(j4,t4);
                            FenetreActuelle = PLATEAU;
                        }
                        if ((positionSouris.x >= GetScreenWidth()/6+GetScreenWidth()/24) &&(positionSouris.x <= GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6) && (positionSouris.y >= GetScreenHeight()/6+GetScreenHeight()/15+4*GetScreenHeight()/12) && (positionSouris.y <= GetScreenHeight()/6+GetScreenHeight()/15+5*GetScreenHeight()/12) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
                            lireSauvegarderJoueurPlateau(j5,t5);
                            FenetreActuelle = PLATEAU;
                        }
                        if ((positionSouris.x >= GetScreenWidth()/6+GetScreenWidth()/24) &&(positionSouris.x <= GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6) && (positionSouris.y >= GetScreenHeight()/6+GetScreenHeight()/15+5*GetScreenHeight()/12) && (positionSouris.y <= GetScreenHeight()/6+GetScreenHeight()/15+6*GetScreenHeight()/12) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
                            lireSauvegarderJoueurPlateau(j6,t6);
                            FenetreActuelle = PLATEAU;
                        }
                        if ((positionSouris.x >= GetScreenWidth()/6+GetScreenWidth()/24) &&(positionSouris.x <= GetScreenWidth()/6+GetScreenWidth()/24+GetScreenWidth()-2.5*GetScreenWidth()/6) && (positionSouris.y >= GetScreenHeight()/6+GetScreenHeight()/15+6*GetScreenHeight()/12) && (positionSouris.y <= GetScreenHeight()/6+GetScreenHeight()/15+7*GetScreenHeight()/12) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
                            lireSauvegarderJoueurPlateau(j7,t7);
                            FenetreActuelle = PLATEAU;
                        }
                    }break;
                    default:break; // fin du switch sauvegarde

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
                DrawTextureEx(fond,(Vector2){0,0},0.0f,1.0f,WHITE); // dessin image fond
                DrawTextureEx(retourMenu,(Vector2){GetScreenWidth()-GetScreenWidth()/16,GetScreenHeight()/32},0.0f,1.0f,WHITE); // dessin bouton retour

                DrawTextureEx(Eliot,(Vector2){0+GetScreenWidth()/8,GetScreenHeight()/22+boutonImage.height},0.0f,1.0f,WHITE); // dessin image eliot
                DrawTextureEx(boutonCredits,(Vector2){0+GetScreenWidth()/22,GetScreenHeight()/22},0.0f,1.0f,WHITE); // dessin bouton
                DrawTextEx(font,"Eliot Rineau",(Vector2){0+GetScreenWidth()/6,GetScreenHeight()/14},30,2,WHITE); // dessin texte

                DrawTextureEx(Hugo,(Vector2){0+GetScreenWidth()/8+GetScreenWidth()/2,GetScreenHeight()/22+boutonImage.height},0.0f,1.0f,WHITE); // dessin image hugo
                DrawTextureEx(boutonCredits,(Vector2){0+GetScreenWidth()/22+GetScreenWidth()/2,GetScreenHeight()/22},0.0f,1.0f,WHITE); // dessin bouton
                DrawTextEx(font,"Hugo Verrier",(Vector2){0+GetScreenWidth()/6+GetScreenWidth()/2,0+GetScreenHeight()/14},30,2,WHITE); // dessin texte

                DrawTextureEx(Henin,(Vector2){0+GetScreenWidth()/8,GetScreenHeight()/22+boutonImage.height+GetScreenHeight()/2},0.0f,1.0f,WHITE); // dessin image henin
                DrawTextureEx(boutonCredits,(Vector2){0+GetScreenWidth()/22,GetScreenHeight()/2+GetScreenHeight()/22},0.0f,1.0f,WHITE); // dessin bouton
                DrawTextEx(font,"Henintsoa Ramakavelo",(Vector2){0+GetScreenWidth()/6-GetScreenWidth()/35,0+GetScreenHeight()/14+GetScreenHeight()/2},30,2,WHITE); // dessin texte

                DrawTextureEx(Xavier,(Vector2){0+GetScreenWidth()/8+GetScreenWidth()/2,GetScreenHeight()/22+boutonImage.height+GetScreenHeight()/2},0.0f,1.0f,WHITE); // dessin image xavier
                DrawTextureEx(boutonCredits,(Vector2){0+GetScreenWidth()/22+GetScreenWidth()/2,GetScreenHeight()/2+GetScreenHeight()/22},0.0f,1.0f,WHITE); // dessin bouton
                DrawTextEx(font,"Xavier Ogandaga Wora",(Vector2){0+GetScreenWidth()/6+GetScreenWidth()/2-GetScreenWidth()/35,0+GetScreenHeight()/14+GetScreenHeight()/2},30,2,WHITE); // dessin texte

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


void sleepf(float seconds){ // fonction sleep flottant
    int secs = floor(seconds);    // secondes
    int usecs = round((seconds - secs) * 1000000); // microsecondes
    //usleep(secs * 1000000 + usecs); // secondes et microsecondes pour le sleepf
}




void lireSauvegarderJoueurPlateau(Joueur* j,tableau* t){
    FILE* fichierJoueur = fopen("../Joueur.txt","r"); //ouverture d'un fichier joueur en mode lecture
    FILE* fichierTableau = fopen("../Tableau.txt","r"); //ouverture d'un fichier plateau en mode lecture
    char avancement; // variable pour "materialiser" l'increment du fichier texte
    if (fichierTableau != NULL) { // if amenant à une boucle
        for (int i = 0; i < LIGNE; ++i) {
            for (int j = 0; j < COLONNE; ++j) {
                { // parcourt les données du plateau
                    avancement = t->Matrice[LIGNE][COLONNE].rotation; // charge rotation des cases
                    avancement = t->Matrice[LIGNE][COLONNE].type; // charge type des cases
                    avancement = t->Matrice[LIGNE][COLONNE].IRXYFJDHBGTS; // charge de toutes les donnes d'une case
                    avancement = t->Matrice[LIGNE][COLONNE].Tab;// charge du tableau
                    fputc(avancement, fichierTableau);
                }
                fputc("\n", fichierTableau); // retour a la ligne dans le fichier texte
            }
            fclose(fichierTableau); // fermeture du fichier du plateau
        }
        for (int k = 0; k < j->nbJoueur; ++k) { // parcourt les donnees des joueurs (en fonction de leur nombre)
            fprintf(fichierJoueur, "%d\n", j->x); // charge de la position du joueur selon le vecteur 2D : X
            fprintf(fichierTableau, "%d\n", j->y); // charge de la position du joueur selon le vecteur 2D : Y
            printf(fichierTableau, "%d\n", *j->pseudo); // charge du pseudo du joueur
            fprintf(fichierTableau, "%d\n", *j->TresorDeck); // charge du tresor a recuperer par le joueur
            fprintf(fichierTableau, "%d\n", *j->TresorRecup); // charge des tresors recuperes par le joueur
        }
    }
    fclose(fichierJoueur); // fermeture du fichier de joueur
}


void creerSauvegardeJoueurPlateau(Joueur* j,tableau* t){ // fonction pour creer une sauvegarde
    FILE* fichierJoueur = fopen("../Joueur.txt","w"); // creation d'un fichier texte pour les données des joueurs
    FILE* fichierTableau = fopen("../Tableau.txt","w"); // creation d'un fichier texte pour les données du plateau
    char avancement; // variable pour "materialiser" l'increment du fichier texte
    if (fichierTableau != NULL){ // if amenant à une boucle
        for (int i = 0; i < LIGNE; ++i) {
            for (int j = 0; j < COLONNE; ++j) { // parcourt les données du plateau
                avancement = t->Matrice[LIGNE][COLONNE].rotation; // sauvegarde rotation des cases
                avancement = t->Matrice[LIGNE][COLONNE].type; // sauvegarde type des cases
                avancement = t->Matrice[LIGNE][COLONNE].IRXYFJDHBGTS; // sauvegarde de toutes les donnes d'une case
                avancement = t->Matrice[LIGNE][COLONNE].Tab; // sauvegarde du tableau
                fputc(avancement,fichierTableau); // ecriture sur le fichier texte des données
            }
            fputc("\n",fichierTableau); // retour a la ligne dans le fichier texte
        }
        fclose(fichierTableau); // fermeture du fichier du plateau
    }
    for (int k = 0; k < j->nbJoueur; ++k) { // sauvegarde les donnees des joueurs (en fonction de leur nombre)
        fprintf(fichierJoueur,"%d\n",j->x); // sauvegarde de la position du joueur selon le vecteur 2D : X
        fprintf(fichierJoueur,"%d\n",j->y); // sauvegarde de la position du joueur selon le vecteur 2D : Y
        printf(fichierJoueur,"%d\n",*j->pseudo); // sauvegarde du pseudo du joueur
        fprintf(fichierJoueur,"%d\n",*j->TresorDeck); // sauvegarde du tresor a recuperer par le joueur
        fprintf(fichierJoueur,"%d\n",*j->TresorRecup); // sauvegarde des tresors recuperes par le joueur
    }
    fclose(fichierJoueur); // fermeture du fichier de joueur
}

//     Sound sonPoseTuile = LoadSound("../SonMenu/sonPoseTuiles.wav");
//commit



