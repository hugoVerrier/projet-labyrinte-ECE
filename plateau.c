#include "plateau.h"


void affichageConsol(Cases plateau[NBCASE],Cases PlateauAfficher[LIGNE][COLONNE],Cases PlateauAttend[2]){
    RemplirPlateauLFixe(PlateauAfficher);
    RemplirPlateauTFixe(PlateauAfficher);
    RemplirTabCase(plateau);
    RemplirTabCaseAfficher(plateau,PlateauAfficher,PlateauAttend);
    AfficchageConsolPlateau(PlateauAfficher,PlateauAttend);
}

void RemplirTabCaseAfficher(Cases plateau[NBCASE],Cases PlateauAfficher[LIGNE][COLONNE],Cases PlateauAttend[2]){
    for (int i = 0; i < LIGNE; ++i) {
        for (int j = 0; j < COLONNE; ++j) {
            for (int k = 0; k < NBCASE; ++k) {
                if(PlateauAfficher[i][j].type ==0){
                    PlateauAfficher[i][j].type=plateau[k].type;
                    PlateauAfficher[i][j].rotation=plateau[k].rotation;
                    plateau[k].type=0;
                }
            }
        }
    }
    PlateauAttend[0].type=plateau[33].type;
    PlateauAttend[0].rotation=plateau[33].rotation;
    plateau[33].type=0;
}

void RemplirTabCase(Cases* plateau){
    //remplis les 12 I
    for (int i = 0; i < 12; ++i) {
        plateau[i].type=1;
        plateau[i].rotation=rand()%2;
    }
    //Remplis de case L
    for (int i = 12; i < 28; ++i) {
        plateau[i].type=2;
        plateau[i].rotation=rand()%4;
    }
    // Remplis de case T
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
    PlateauAfficher[0][6]=L4;
    PlateauAfficher[6][0]=L2;
    PlateauAfficher[6][6]=L3;
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
    PlateauAfficher[2][0]=T2;
    PlateauAfficher[4][0]=T2;
    PlateauAfficher[4][2]=T2;
    PlateauAfficher[0][2]=T1;
    PlateauAfficher[0][4]=T1;
    PlateauAfficher[2][2]=T1;
    PlateauAfficher[2][6]=T4;
    PlateauAfficher[4][6]=T4;
    PlateauAfficher[2][4]=T4;
    PlateauAfficher[6][2]=T3;
    PlateauAfficher[6][4]=T3;
    PlateauAfficher[4][4]=T3;
}

void AfficchageConsolPlateau(Cases PlateauAfficher[LIGNE][COLONNE],Cases PlateauAttend[2]){
    for (int i = 0; i < LIGNE; ++i) {
        for (int j = 0; j < COLONNE; ++j) {
            printf(" %d.%d\t",PlateauAfficher[i][j].type,PlateauAfficher[i][j].rotation);
        }
        printf("\n");
    }
    printf("\n\n %d.%d",PlateauAttend[0].type,PlateauAttend[0].rotation);
}

Texture2D ChoixDeCases(Cases PlateauAfficher[LIGNE][COLONNE],int x,int y,Texture2D I1,Texture2D I2,Texture2D L1,Texture2D L2,Texture2D L3,Texture2D L4,Texture2D T1,Texture2D T2,Texture2D T3,Texture2D T4){
    switch (PlateauAfficher[x][y].type) {
        case 1 :
            switch (PlateauAfficher[x][y].rotation) {
                case 0 : return I1;

                case 1 : return I2;
            }

        case 2 :
            switch (PlateauAfficher[x][y].rotation) {
                case 0 : return L1;

                case 1 : return L2;

                case 2 : return L3;

                case 3 : return L4;
            }

        case 3 :
            switch (PlateauAfficher[x][y].rotation) {
                case 0 : return T1;

                case 1 : return T2;

                case 2 : return T3;

                case 3 : return T4;
            }
    }
}

Texture2D ChoixDeCasesDehors(Cases PlateauAttend[2],int x,Texture2D I1,Texture2D I2,Texture2D L1,Texture2D L2,Texture2D L3,Texture2D L4,Texture2D T1,Texture2D T2,Texture2D T3,Texture2D T4){
    if(PlateauAttend[0].type==1){
        PlateauAttend[0].rotation = PlateauAttend[0].rotation%2;
    }
    else if(PlateauAttend[0].type==2 || PlateauAttend[0].type==3){
        PlateauAttend[0].rotation = PlateauAttend[0].rotation%4;
    }
    switch (PlateauAttend[x].type) {
        case 1 :
            switch (PlateauAttend[x].rotation) {
                case 0 : return I1;

                case 1 : return I2;
            }

        case 2 :
            switch (PlateauAttend[x].rotation) {
                case 0 : return L1;

                case 1 : return L2;

                case 2 : return L3;

                case 3 : return L4;
            }

        case 3 :
            switch (PlateauAttend[x].rotation) {
                case 0 : return T1;

                case 1 : return T2;

                case 2 : return T3;

                case 3 : return T4;
            }
    }
}



void AffichageRaylib(int nbJ){
    Cases plateau[NBCASE];
    Cases PlateauAfficher[LIGNE][COLONNE]={0};
    Cases PlateauAttend[2]={0};
    affichageConsol(plateau,PlateauAfficher,PlateauAttend);
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

    Image flecheimage = LoadImage("../Image Plateau/fleche.png");
    ImageResize(&flecheimage,GetScreenHeight()/DIMENSION,GetScreenHeight()/DIMENSION);
    Texture2D fleche = LoadTextureFromImage(flecheimage);
    UnloadImage(flecheimage);


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
        DrawTextureEx(ChoixDeCases(PlateauAfficher,0,0,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3,GetScreenHeight()/8},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,0,1,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+I1.width,GetScreenHeight()/8},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,0,2,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+2*I1.width,GetScreenHeight()/8},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,0,3,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+3*I1.width,GetScreenHeight()/8},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,0,4,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+4*I1.width,GetScreenHeight()/8},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,0,5,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+5*I1.width,GetScreenHeight()/8},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,0,6,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+6*I1.width,GetScreenHeight()/8},0.0f,1.0f,WHITE);

//       dessins deuxième ligne platteau

        DrawTextureEx(ChoixDeCases(PlateauAfficher,1,0,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3,GetScreenHeight()/8+I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,1,1,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+I1.width,GetScreenHeight()/8+I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,1,2,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+2*I1.width,GetScreenHeight()/8+I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,1,3,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+3*I1.width,GetScreenHeight()/8+I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,1,4,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+4*I1.width,GetScreenHeight()/8+I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,1,5,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+5*I1.width,GetScreenHeight()/8+I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,1,6,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+6*I1.width,GetScreenHeight()/8+I1.height},0.0f,1.0f,WHITE);

//       dessins troisième ligne platteau

        DrawTextureEx(ChoixDeCases(PlateauAfficher,2,0,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3,GetScreenHeight()/8+2*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,2,1,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+I1.width,GetScreenHeight()/8+2*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,2,2,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+2*I1.width,GetScreenHeight()/8+2*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,2,3,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+3*I1.width,GetScreenHeight()/8+2*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,2,4,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+4*I1.width,GetScreenHeight()/8+2*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,2,5,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+5*I1.width,GetScreenHeight()/8+2*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,2,6,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+6*I1.width,GetScreenHeight()/8+2*I1.height},0.0f,1.0f,WHITE);

//       dessins quatrième ligne platteau

        DrawTextureEx(ChoixDeCases(PlateauAfficher,3,0,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3,GetScreenHeight()/8+3*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,3,1,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+I1.width,GetScreenHeight()/8+3*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,3,2,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+2*I1.width,GetScreenHeight()/8+3*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,3,3,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+3*I1.width,GetScreenHeight()/8+3*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,3,4,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+4*I1.width,GetScreenHeight()/8+3*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,3,5,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+5*I1.width,GetScreenHeight()/8+3*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,3,6,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+6*I1.width,GetScreenHeight()/8+3*I1.height},0.0f,1.0f,WHITE);

//       dessins cinquième ligne platteau

        DrawTextureEx(ChoixDeCases(PlateauAfficher,4,0,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3,GetScreenHeight()/8+4*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,4,1,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+I1.width,GetScreenHeight()/8+4*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,4,2,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+2*I1.width,GetScreenHeight()/8+4*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,4,3,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+3*I1.width,GetScreenHeight()/8+4*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,4,4,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+4*I1.width,GetScreenHeight()/8+4*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,4,5,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+5*I1.width,GetScreenHeight()/8+4*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,4,6,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+6*I1.width,GetScreenHeight()/8+4*I1.height},0.0f,1.0f,WHITE);

//       dessins sixième ligne platteau

        DrawTextureEx(ChoixDeCases(PlateauAfficher,5,0,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3,GetScreenHeight()/8+5*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,5,1,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+I1.width,GetScreenHeight()/8+5*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,5,2,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+2*I1.width,GetScreenHeight()/8+5*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,5,3,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+3*I1.width,GetScreenHeight()/8+5*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,5,4,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+4*I1.width,GetScreenHeight()/8+5*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,5,5,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+5*I1.width,GetScreenHeight()/8+5*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,5,6,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+6*I1.width,GetScreenHeight()/8+5*I1.height},0.0f,1.0f,WHITE);

//       dessins sepième ligne platteau

        DrawTextureEx(ChoixDeCases(PlateauAfficher,6,0,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3,GetScreenHeight()/8+6*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,6,1,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+I1.width,GetScreenHeight()/8+6*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,6,2,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+2*I1.width,GetScreenHeight()/8+6*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,6,3,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+3*I1.width,GetScreenHeight()/8+6*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,6,4,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+4*I1.width,GetScreenHeight()/8+6*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,6,5,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+5*I1.width,GetScreenHeight()/8+6*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,6,6,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+6*I1.width,GetScreenHeight()/8+6*I1.height},0.0f,1.0f,WHITE);

//      dessins des tuiles de cartes
//        DrawRectangle(0,800,200,300,YELLOW);
//        DrawRectangle(0,0,200,300,YELLOW);

//      Tuile supplémentaire
        DrawTextureEx(ChoixDeCasesDehors(PlateauAttend,0,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/7,GetScreenHeight()/8+3*I1.height},0.0f,2.0f,WHITE);
        DrawTextureEx(fleche,(Vector2){GetScreenWidth()/12,GetScreenHeight()/8+3.5*I1.height},0.0f,1.0f,YELLOW);
//        Rectangle Test = {GetScreenWidth()/12,GetScreenHeight()/8+3.5*I1.height,GetScreenHeight()/DIMENSION,GetScreenHeight()/DIMENSION};
//        DrawRectangle(GetScreenWidth()/12,GetScreenHeight()/8+3.5*I1.height,GetScreenHeight()/DIMENSION,GetScreenHeight()/DIMENSION,WHITE);

        if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && (((positionSouris.x>=GetScreenHeight()/8+3.5*I1.height) || (positionSouris.x<=GetScreenHeight()/8+3.5*I1.height+I1.height)) &&((positionSouris.y>=GetScreenHeight()/8+3.5*I1.height)||(positionSouris.y<=GetScreenHeight()/8+3.5*I1.height+I1.height))))){
           BeginDrawing();
           DrawRectangle(GetScreenWidth()/12,GetScreenHeight()/8+3.5*I1.height,GetScreenHeight()/DIMENSION,GetScreenHeight()/DIMENSION,WHITE);
           PlateauAttend[0].rotation = PlateauAttend[0].rotation +1;
           EndDrawing();
        }

        if (IsKeyPressed(KEY_ESCAPE) || ((positionSouris.x >= GetScreenWidth()-GetScreenWidth()/16) && (positionSouris.x <= GetScreenWidth()-GetScreenWidth()/16 + quitterImage.width) && (positionSouris.y >= GetScreenHeight()/32) && (positionSouris.y <= GetScreenHeight()/32 +quitterImage.height) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))) {
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