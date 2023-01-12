//
// Created by hugov on 03/01/2023.
//

#include "plateau.h"

void affichageConsol(){
    Joueur* j;
    Cases* C1,C2,C3,C4,C5,C6,C7,C8,C9,C10,C11,C12,C13,C14,C15,C16,C17,C18,C19,C20,C21,C22,C23,C24,C25,C26,C27,C28,C29,C30,C31,C32,C33,C34;
    Cases plateau[NBCASE];
    int PlateauAfficher[LIGNE][COLONNE]={0};
    //RemplirPlateauLFixe();
    RemplirTabCase(plateau);
    for (int i = 0; i < NBCASE; ++i) {
        printf(" %d et %d\n",plateau[i].type,plateau[i].rotation);
    }


}

void RemplirTabCase(Cases* plateau){
    //remplis les 12 I
    for (int i = 0; i < 12; ++i) {
        plateau[i].type=1;
        plateau[i].rotation=rand()%2;
    }
    for (int i = 12; i < 28; ++i) {
        plateau[i].type=2;
        plateau[i].rotation=rand()%4;
    }
    for (int i = 28; i < 34; ++i) {
        plateau[i].type=3;
        plateau[i].rotation=rand()%4;
    }
    MelangeTab(plateau);
}

void MelangeTab(Cases* plateau) {
    for (int i = NBCASE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Cases temp = plateau[i];
        plateau[i] = plateau[j];
        plateau[j] = temp;
    }
}

void RemplirPlateauLFixe(Cases PlateauAfficher[LIGNE][COLONNE]){
    Cases L1,L2,L3,L4;
    L1.rotation=0;
    L1.type=2;
    L2.rotation=1;
    L2.type=2;
    L3.rotation=2;
    L3.type=2;
    L4.rotation=3;
    L4.type=2;
    PlateauAfficher[0][0]=L1;
    PlateauAfficher[0][6]=L2;
    PlateauAfficher[6][0]=L3;
    PlateauAfficher[6][6]=L4;
}

void RemplirPlateauTFixe(Cases PlateauAfficher[LIGNE][COLONNE]){
    Cases T1,T2,T3,T4;
    T1.rotation=0;
    T1.type=3;
    T2.rotation=1;
    T2.type=3;
    T3.rotation=2;
    T3.type=3;
    T4.rotation=3;
    T4.type=3;
    PlateauAfficher[2][0]=T1;
    PlateauAfficher[4][0]=T1;
    PlateauAfficher[4][2]=T1;
    PlateauAfficher[0][2]=T2;
    PlateauAfficher[0][4]=T2;
    PlateauAfficher[2][2]=T2;
    PlateauAfficher[2][6]=T3;
    PlateauAfficher[4][6]=T3;
    PlateauAfficher[2][4]=T3;
    PlateauAfficher[6][2]=T4;
    PlateauAfficher[6][4]=T4;
    PlateauAfficher[4][4]=T4;
}





void AffichageRaylib(int nbJ){
    InitWindow(GetScreenWidth(),GetScreenHeight(),"Plateau");
    ToggleFullscreen();
    Fenetre FenetreActuelle = PLATEAU;

    Image fondImage = LoadImage("../ImagesMenu/fond.png");
    ImageResize(&fondImage,GetScreenWidth(),GetScreenHeight());
    Texture2D fond = LoadTextureFromImage(fondImage);
    UnloadImage(fondImage);

    Image quitterImage = LoadImage("../ImagesMenu/boutonQuitter.png");
    ImageResize(&quitterImage,GetScreenWidth()/22,GetScreenHeight()/18);
    Texture2D quitter = LoadTextureFromImage(quitterImage);
    UnloadImage(quitterImage);

    Image I1image = LoadImage("../Image Plateau/I1.png");
    ImageResize(&I1image,GetScreenHeight()/DIMENSION,GetScreenHeight()/DIMENSION);
    Texture2D I1 = LoadTextureFromImage(I1image);
    UnloadImage(I1image);

    Image I2image = LoadImage("../Image Plateau/I2.png");
    ImageResize(&I2image,GetScreenHeight()/DIMENSION,GetScreenHeight()/DIMENSION);
    Texture2D I2 = LoadTextureFromImage(I2image);
    UnloadImage(I2image);

    Image L1image = LoadImage("../Image Plateau/L1.png");
    ImageResize(&L1image,GetScreenHeight()/DIMENSION,GetScreenHeight()/DIMENSION);
    Texture2D L1 = LoadTextureFromImage(L1image);
    UnloadImage(L1image);

    Image L2image = LoadImage("../Image Plateau/L2.png");
    ImageResize(&L2image,GetScreenHeight()/DIMENSION,GetScreenHeight()/DIMENSION);
    Texture2D L2 = LoadTextureFromImage(L2image);
    UnloadImage(L2image);

    Image L3image = LoadImage("../Image Plateau/L3.png");
    ImageResize(&L3image,GetScreenHeight()/DIMENSION,GetScreenHeight()/DIMENSION);
    Texture2D L3 = LoadTextureFromImage(L3image);
    UnloadImage(L3image);

    Image L4image = LoadImage("../Image Plateau/L4.png");
    ImageResize(&L4image,GetScreenHeight()/DIMENSION,GetScreenHeight()/DIMENSION);
    Texture2D L4 = LoadTextureFromImage(L4image);
    UnloadImage(L4image);

    Image T1image = LoadImage("../Image Plateau/T1.png");
    ImageResize(&T1image,GetScreenHeight()/DIMENSION,GetScreenHeight()/DIMENSION);
    Texture2D T1 = LoadTextureFromImage(T1image);
    UnloadImage(T1image);

    Image T2image = LoadImage("../Image Plateau/T2.png");
    ImageResize(&T2image,GetScreenHeight()/DIMENSION,GetScreenHeight()/DIMENSION);
    Texture2D T2 = LoadTextureFromImage(T2image);
    UnloadImage(T2image);

    Image T3image = LoadImage("../Image Plateau/T3.png");
    ImageResize(&T3image,GetScreenHeight()/DIMENSION,GetScreenHeight()/DIMENSION);
    Texture2D T3 = LoadTextureFromImage(T3image);
    UnloadImage(T3image);

    Image T4image = LoadImage("../Image Plateau/T4.png");
    ImageResize(&T4image,GetScreenHeight()/DIMENSION,GetScreenHeight()/DIMENSION);
    Texture2D T4 = LoadTextureFromImage(T4image);
    UnloadImage(T4image);


    int fin = 0; // fin inutile juste histoire de pas fermer la fenetre

    Vector2 positionSouris = GetMousePosition();

    while(!fin) {
        BeginDrawing();
        ClearBackground(WHITE);

        DrawTextureEx(fond,(Vector2){0,0},0.0f,1.0f,WHITE);
        DrawTextureEx(quitter,(Vector2){GetScreenWidth()-GetScreenWidth()/16,GetScreenHeight()/32},0.0f,1.0f,WHITE);


        //      Afichage cases des joueur
        switch (nbJ) {
            case 2 :
                DrawRectangle(1750,900,200,150,YELLOW);
                DrawRectangle(1750,200,200,150,YELLOW);
                break;

            case 3 :
                DrawRectangle(1750,200,200,150,YELLOW);
                DrawRectangle(1750,550,200,150,YELLOW);
                DrawRectangle(1750,900,200,150,YELLOW);
                break;

            case 4 :
                DrawRectangle(1750,200,200,150,YELLOW);
                DrawRectangle(1750,400,200,150,YELLOW);
                DrawRectangle(1750,600,200,150,YELLOW);
                DrawRectangle(1750,800,200,150,YELLOW);

            default:
                DrawRectangle(1750,900,200,150,YELLOW);
                DrawRectangle(1750,200,200,150,YELLOW);
                break;
        }

        if(nbJ==2){
            Joueur J,J2;
            J.x = 0;
            J.y=0;
            J2.x = 6;
            J2.y=6;
        }
        else if(nbJ==3){
            Joueur J,J2,J3;
            J.x = 0;
            J.y=0;
            J2.x = 6;
            J2.y=6;
            J3.x=6;
            J3.y=0;
        }
        else if(nbJ==4){
            Joueur J,J2,J3,J4;
            J.x = 0;
            J.y=0;
            J2.x = 6;
            J2.y=6;
            J3.x=6;
            J3.y=0;
            J4.x=0;
            J4.y=6;
        }


//       dessins première ligne platteau
        DrawTextureEx(I1,(Vector2){GetScreenWidth()/3,GetScreenHeight()/8},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+I1.width,GetScreenHeight()/8},0.0f,1.0f,WHITE);
        DrawTextureEx(L1,(Vector2){GetScreenWidth()/3+2*I1.width,GetScreenHeight()/8},0.0f,1.0f,WHITE);
        DrawTextureEx(L2,(Vector2){GetScreenWidth()/3+3*I1.width,GetScreenHeight()/8},0.0f,1.0f,WHITE);
        DrawTextureEx(L3,(Vector2){GetScreenWidth()/3+4*I1.width,GetScreenHeight()/8},0.0f,1.0f,WHITE);
        DrawTextureEx(L4,(Vector2){GetScreenWidth()/3+5*I1.width,GetScreenHeight()/8},0.0f,1.0f,WHITE);
        DrawTextureEx(T1,(Vector2){GetScreenWidth()/3+6*I1.width,GetScreenHeight()/8},0.0f,1.0f,WHITE);

//       dessins deuxième ligne platteau

        DrawTextureEx(T2,(Vector2){GetScreenWidth()/3,GetScreenHeight()/8+I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(T3,(Vector2){GetScreenWidth()/3+I1.width,GetScreenHeight()/8+I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(T4,(Vector2){GetScreenWidth()/3+2*I1.width,GetScreenHeight()/8+I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+3*I1.width,GetScreenHeight()/8+I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+4*I1.width,GetScreenHeight()/8+I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+5*I1.width,GetScreenHeight()/8+I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+6*I1.width,GetScreenHeight()/8+I1.height},0.0f,1.0f,WHITE);

//       dessins troisième ligne platteau

        DrawTextureEx(I1,(Vector2){GetScreenWidth()/3,GetScreenHeight()/8+2*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+I1.width,GetScreenHeight()/8+2*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+2*I1.width,GetScreenHeight()/8+2*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+3*I1.width,GetScreenHeight()/8+2*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+4*I1.width,GetScreenHeight()/8+2*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+5*I1.width,GetScreenHeight()/8+2*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+6*I1.width,GetScreenHeight()/8+2*I1.height},0.0f,1.0f,WHITE);

//       dessins quatrième ligne platteau

        DrawTextureEx(I1,(Vector2){GetScreenWidth()/3,GetScreenHeight()/8+3*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+I1.width,GetScreenHeight()/8+3*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+2*I1.width,GetScreenHeight()/8+3*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+3*I1.width,GetScreenHeight()/8+3*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+4*I1.width,GetScreenHeight()/8+3*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+5*I1.width,GetScreenHeight()/8+3*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+6*I1.width,GetScreenHeight()/8+3*I1.height},0.0f,1.0f,WHITE);

//       dessins cinquième ligne platteau

        DrawTextureEx(I1,(Vector2){GetScreenWidth()/3,GetScreenHeight()/8+4*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+I1.width,GetScreenHeight()/8+4*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+2*I1.width,GetScreenHeight()/8+4*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+3*I1.width,GetScreenHeight()/8+4*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+4*I1.width,GetScreenHeight()/8+4*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+5*I1.width,GetScreenHeight()/8+4*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+6*I1.width,GetScreenHeight()/8+4*I1.height},0.0f,1.0f,WHITE);

//       dessins sixième ligne platteau

        DrawTextureEx(I1,(Vector2){GetScreenWidth()/3,GetScreenHeight()/8+5*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+I1.width,GetScreenHeight()/8+5*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+2*I1.width,GetScreenHeight()/8+5*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+3*I1.width,GetScreenHeight()/8+5*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+4*I1.width,GetScreenHeight()/8+5*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+5*I1.width,GetScreenHeight()/8+5*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+6*I1.width,GetScreenHeight()/8+5*I1.height},0.0f,1.0f,WHITE);

//       dessins sepième ligne platteau

        DrawTextureEx(I1,(Vector2){GetScreenWidth()/3,GetScreenHeight()/8+6*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+I1.width,GetScreenHeight()/8+6*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+2*I1.width,GetScreenHeight()/8+6*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+3*I1.width,GetScreenHeight()/8+6*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+4*I1.width,GetScreenHeight()/8+6*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+5*I1.width,GetScreenHeight()/8+6*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(I2,(Vector2){GetScreenWidth()/3+6*I1.width,GetScreenHeight()/8+6*I1.height},0.0f,1.0f,WHITE);

//      dessins des tuiles de cartes
        DrawRectangle(0,800,200,300,YELLOW);
        DrawRectangle(0,0,200,300,YELLOW);

//      Tuile supplémentaire
        DrawTextureEx(I1,(Vector2){GetScreenWidth()/7,GetScreenHeight()/8+3*I1.height},0.0f,2.0f,WHITE);




        if (IsKeyPressed(KEY_ESCAPE) || (positionSouris.x >= GetScreenWidth() - GetScreenWidth() / 16) &&
                                        (positionSouris.x <=
                                         GetScreenWidth() - GetScreenWidth() / 16 + quitterImage.width) &&
                                        (positionSouris.y >= GetScreenHeight() / 32) &&
                                        (positionSouris.y <= GetScreenHeight() / 32 + quitterImage.height) &&
                                        (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))) {
            fin = true;
            //PlaySound(sonBoutton);


        }
        EndDrawing();

    }
}



//void AfficherJoueur(Joueur* J){
//    switch(J->x){
//        case 1 : switch (J->y){
//            case 1 :
//        }
//    }
//
//}