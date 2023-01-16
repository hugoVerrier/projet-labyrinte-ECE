//
// Created by hugov on 03/01/2023.
//

#include <raylib/src/raylib.h>
#include "plateau.h"
#include "MenuGraphique.h"


void affichageConsol(Cases plateau[NBCASE],Cases PlateauAfficher[LIGNE][COLONNE],Cases PlateauAttend[2]){
    RemplirPlateauLFixe(PlateauAfficher);
    RemplirPlateauTFixe(PlateauAfficher);
    RemplirTabCase(plateau);
    RemplirTabCaseAfficher(plateau,PlateauAfficher,PlateauAttend);
    PlateauTresor(PlateauAfficher);
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
            printf(" %d.%d.%d\t",PlateauAfficher[i][j].type,PlateauAfficher[i][j].rotation,PlateauAfficher[i][j].tresor);
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

Texture2D ChoixPoins(Joueur J, char Jaune[6], char Bleu[6],char Rouge[6], char Vert[6],Texture2D PionsJaune,Texture2D PionsVert,Texture2D PionsRouge, Texture2D PionsBleu){
    if(strcmp(J.couleur,Jaune)){
        J.pions=PionsJaune;
        J.couleurT=0;
    }
    else if(strcmp(J.couleur,Vert)){
        J.pions=PionsVert;
        J.couleurT=3;
    }
    else if(strcmp(J.couleur,Bleu)){
        J.pions=PionsBleu;
        J.couleurT=0;
    }
    else if(strcmp(J.couleur,Rouge)){
        J.pions=PionsRouge;
        J.couleurT=2;
    }
}

Texture2D PlateauTresor(Cases PlateauAfficher[LIGNE][COLONNE]){
    int nbtresor=24,a,b,veriftresor=0;
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            PlateauAfficher[i][j].tresor=0;
        }
    }
    while(nbtresor>0){
        a = rand()%7;
        b = rand()%7;
        if( (a%2!=0)||(b%2!=0)){
            if(PlateauAfficher[a][b].tresor==0){
                PlateauAfficher[a][b].tresor=nbtresor;
                nbtresor--;
            }
        }
        else if((a%7!=0)&&(b%7!=0)){
            if(PlateauAfficher[a][b].tresor==0){
                PlateauAfficher[a][b].tresor=nbtresor;
                nbtresor--;
            }
        }
    }
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            if(PlateauAfficher[i][j].tresor>0){
                veriftresor++;
            }
        }
    }
}

Texture2D ChoixTresor(Cases PlateauAfficher[LIGNE][COLONNE],int x ,int y,Texture2D AileHarpie,Texture2D ArcArtemis,Texture2D BoitePandore,Texture2D BotteHermes,Texture2D Casqueachille,Texture2D Centaure, Texture2D Cerbere, Texture2D ChevalDeTroie, Texture2D ChouetteAthena,Texture2D CorneMinotaure, Texture2D CoupeDyonisos,Texture2D EpeeAres, Texture2D FilArianne, Texture2D FlammeHades, Texture2D FleurAphrodite, Texture2D FoudreZeus, Texture2D HarpeApollon, Texture2D MarteauEphaistos, Texture2D OeilCyclope, Texture2D OeilMoires, Texture2D Pegase, Texture2D TeteGorgonne, Texture2D ToisonOr, Texture2D TridentPoseidon, Texture2D FondVide){
    switch (PlateauAfficher[x][y].tresor) {
        case 0 : {return FondVide;
                break;}
        case 1 : {return AileHarpie;
            break;}
        case 2 : {return ArcArtemis;
            break;}
        case 3 : {return BoitePandore;
            break;}
        case 4 : {return BotteHermes;
            break;}
        case 5 : {return Casqueachille;
            break;}
        case 6 : {return Centaure;
            break;}
        case 7 : {return Cerbere;
            break;}
        case 8 : {return ChevalDeTroie;
            break;}
        case 9 : {return ChouetteAthena;
            break;}
        case 10 : {return CorneMinotaure;
            break;}
        case 11 : {return CoupeDyonisos;
            break;}
        case 12 : {return EpeeAres;
            break;}
        case 13 : {return FilArianne;
            break;}
        case 14 : {return FlammeHades;
            break;}
        case 15 : {return FleurAphrodite;
            break;}
        case 16 : {return FoudreZeus;
            break;}
        case 17 : {return HarpeApollon;
            break;}
        case 18 : {return MarteauEphaistos;
            break;}
        case 19 : {return OeilCyclope;
            break;}
        case 20 : {return OeilMoires;
            break;}
        case 21 : {return Pegase;
            break;}
        case 22 : {return TeteGorgonne;
            break;}
        case 23 : {return ToisonOr;
            break;}
        case 24: {return TridentPoseidon;
            break;}
        default: {return FondVide;
            break;}
    }
}

Texture2D ChoixTresorDehors(Cases PlateauAttend[2],int x ,Texture2D AileHarpie,Texture2D ArcArtemis,Texture2D BoitePandore,Texture2D BotteHermes,Texture2D Casqueachille,Texture2D Centaure, Texture2D Cerbere, Texture2D ChevalDeTroie, Texture2D ChouetteAthena,Texture2D CorneMinotaure, Texture2D CoupeDyonisos,Texture2D EpeeAres, Texture2D FilArianne, Texture2D FlammeHades, Texture2D FleurAphrodite, Texture2D FoudreZeus, Texture2D HarpeApollon, Texture2D MarteauEphaistos, Texture2D OeilCyclope, Texture2D OeilMoires, Texture2D Pegase, Texture2D TeteGorgonne, Texture2D ToisonOr, Texture2D TridentPoseidon, Texture2D FondVide){
    switch (PlateauAttend[x].tresor) {
        case 0 : {return FondVide;
            break;}
        case 1 : {return AileHarpie;
            break;}
        case 2 : {return ArcArtemis;
            break;}
        case 3 : {return BoitePandore;
            break;}
        case 4 : {return BotteHermes;
            break;}
        case 5 : {return Casqueachille;
            break;}
        case 6 : {return Centaure;
            break;}
        case 7 : {return Cerbere;
            break;}
        case 8 : {return ChevalDeTroie;
            break;}
        case 9 : {return ChouetteAthena;
            break;}
        case 10 : {return CorneMinotaure;
            break;}
        case 11 : {return CoupeDyonisos;
            break;}
        case 12 : {return EpeeAres;
            break;}
        case 13 : {return FilArianne;
            break;}
        case 14 : {return FlammeHades;
            break;}
        case 15 : {return FleurAphrodite;
            break;}
        case 16 : {return FoudreZeus;
            break;}
        case 17 : {return HarpeApollon;
            break;}
        case 18 : {return MarteauEphaistos;
            break;}
        case 19 : {return OeilCyclope;
            break;}
        case 20 : {return OeilMoires;
            break;}
        case 21 : {return Pegase;
            break;}
        case 22 : {return TeteGorgonne;
            break;}
        case 23 : {return ToisonOr;
            break;}
        case 24: {return TridentPoseidon;
            break;}
        default: {return FondVide;
            break;}
    }
}


void AffichageRaylib(int nbJ){
    Cases plateau[NBCASE];
    Cases PlateauAfficher[LIGNE][COLONNE]={0};
    Cases PlateauAttend[2]={0};
    char Jaune[6]={'j','a','u','n','e','\0'},Vert[5]={'v','e','r','t','\0'},Bleu[5]={'b','l','e','u','\0'},Rouge[6]={'r','o','u','g','e','\0'};
    PlateauTresor(PlateauAfficher);
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

    Image flechedroiteimage = LoadImage("../Image Plateau/109617.png");
    ImageResize(&flechedroiteimage,GetScreenHeight()/DIMENSION,GetScreenHeight()/DIMENSION);
    Texture2D flecheD = LoadTextureFromImage(flechedroiteimage);
    UnloadImage(flechedroiteimage);

    Image AileHarpieImage = LoadImage("../Image Plateau/Aile Harpie.png");
    ImageResize(&AileHarpieImage,GetScreenHeight()/DIMENSIONP,GetScreenHeight()/DIMENSIONP);
    Texture2D AileHarpie = LoadTextureFromImage(AileHarpieImage);
    UnloadImage(AileHarpieImage);

    Image  ArcArtemisImage= LoadImage("../Image Plateau/Arc Artemis.png");
    ImageResize(&ArcArtemisImage,GetScreenHeight()/DIMENSIONP,GetScreenHeight()/DIMENSIONP);
    Texture2D ArcArtemis = LoadTextureFromImage(ArcArtemisImage);
    UnloadImage(ArcArtemisImage);

    Image BoitePandoreImage = LoadImage("../Image Plateau/Boite Pandore.png");
    ImageResize(&BoitePandoreImage,GetScreenHeight()/DIMENSIONP,GetScreenHeight()/DIMENSIONP);
    Texture2D BoitePandore = LoadTextureFromImage(BoitePandoreImage);
    UnloadImage(BoitePandoreImage);

    Image BotteHermesImage = LoadImage("../Image Plateau/Botte Hermes.png");
    ImageResize(&BotteHermesImage,GetScreenHeight()/DIMENSIONP,GetScreenHeight()/DIMENSIONP);
    Texture2D BotteHermes= LoadTextureFromImage(BotteHermesImage);
    UnloadImage(BotteHermesImage);

    Image CasqueAchilleImage = LoadImage("../Image Plateau/Casque Achille.png");
    ImageResize(&CasqueAchilleImage,GetScreenHeight()/DIMENSIONP,GetScreenHeight()/DIMENSIONP);
    Texture2D CasqueAchille = LoadTextureFromImage(CasqueAchilleImage);
    UnloadImage(CasqueAchilleImage);

    Image CentaureImage = LoadImage("../Image Plateau/Centaure.png");
    ImageResize(&CentaureImage,GetScreenHeight()/DIMENSIONP,GetScreenHeight()/DIMENSIONP);
    Texture2D Centaure = LoadTextureFromImage(CentaureImage);
    UnloadImage(CentaureImage);

    Image CerbereImage = LoadImage("../Image Plateau/Cerbere.png");
    ImageResize(&CerbereImage,GetScreenHeight()/DIMENSIONP,GetScreenHeight()/DIMENSIONP);
    Texture2D Cerbere = LoadTextureFromImage(CerbereImage);
    UnloadImage(CerbereImage);

    Image ChevalTroieImage = LoadImage("../Image Plateau/Cheval Troie.png");
    ImageResize(&ChevalTroieImage,GetScreenHeight()/DIMENSIONP,GetScreenHeight()/DIMENSIONP);
    Texture2D ChevalTroie = LoadTextureFromImage(ChevalTroieImage);
    UnloadImage(ChevalTroieImage);

    Image ChouetteAthenaImage = LoadImage("../Image Plateau/Chouette Athena.png");
    ImageResize(&ChouetteAthenaImage,GetScreenHeight()/DIMENSIONP,GetScreenHeight()/DIMENSIONP);
    Texture2D ChouetteAthena = LoadTextureFromImage(ChouetteAthenaImage);
    UnloadImage(ChouetteAthenaImage);

    Image CorneMinotaureImage = LoadImage("../Image Plateau/Corne Minotaure.png");
    ImageResize(&CorneMinotaureImage,GetScreenHeight()/DIMENSIONP,GetScreenHeight()/DIMENSIONP);
    Texture2D CorneMinotaure = LoadTextureFromImage(CorneMinotaureImage);
    UnloadImage(CorneMinotaureImage);

    Image CoupeDyonisosImage = LoadImage("../Image Plateau/Coupe Dyonisos.png");
    ImageResize(&CoupeDyonisosImage,GetScreenHeight()/DIMENSIONP,GetScreenHeight()/DIMENSIONP);
    Texture2D CoupeDyonisos = LoadTextureFromImage(CoupeDyonisosImage);
    UnloadImage(CoupeDyonisosImage);

    Image EpeeAresImage = LoadImage("../Image Plateau/Epee Ares.png");
    ImageResize(&EpeeAresImage,GetScreenHeight()/DIMENSIONP,GetScreenHeight()/DIMENSIONP);
    Texture2D EpeeAres = LoadTextureFromImage(EpeeAresImage);
    UnloadImage(EpeeAresImage);

    Image FilArianneImage = LoadImage("../Image Plateau/Fil Arianne.png");
    ImageResize(&FilArianneImage,GetScreenHeight()/DIMENSIONP,GetScreenHeight()/DIMENSIONP);
    Texture2D FilArianne = LoadTextureFromImage(FilArianneImage);
    UnloadImage(FilArianneImage);

    Image FlammeHadesImage = LoadImage("../Image Plateau/Flamme Hades.png");
    ImageResize(&FlammeHadesImage,GetScreenHeight()/DIMENSIONP,GetScreenHeight()/DIMENSIONP);
    Texture2D FlammeHades = LoadTextureFromImage(FlammeHadesImage);
    UnloadImage(FlammeHadesImage);

    Image FleurAphroditeImage = LoadImage("../Image Plateau/Fleur Aphrodite.png");
    ImageResize(&FleurAphroditeImage,GetScreenHeight()/DIMENSIONP,GetScreenHeight()/DIMENSIONP);
    Texture2D FleurAphrodite = LoadTextureFromImage(FleurAphroditeImage);
    UnloadImage(FleurAphroditeImage);

    Image FoudreZeusImage = LoadImage("../Image Plateau/Foudre Zeus.png");
    ImageResize(&FoudreZeusImage,GetScreenHeight()/DIMENSIONP,GetScreenHeight()/DIMENSIONP);
    Texture2D FoudreZeus = LoadTextureFromImage(FoudreZeusImage);
    UnloadImage(FoudreZeusImage);

    Image HarpeApollonImage = LoadImage("../Image Plateau/Harpe Apollon.png");
    ImageResize(&HarpeApollonImage,GetScreenHeight()/DIMENSIONP,GetScreenHeight()/DIMENSIONP);
    Texture2D HarpeApollon = LoadTextureFromImage(HarpeApollonImage);
    UnloadImage(HarpeApollonImage);

    Image MarteauEphaistosImage = LoadImage("../Image Plateau/Marteau Ephaistos.png");
    ImageResize(&MarteauEphaistosImage,GetScreenHeight()/DIMENSIONP,GetScreenHeight()/DIMENSIONP);
    Texture2D MarteauEpahistos = LoadTextureFromImage(MarteauEphaistosImage);
    UnloadImage(MarteauEphaistosImage);

    Image OeilCyclopeImage = LoadImage("../Image Plateau/Oeil Cyclope4.png");
    ImageResize(&OeilCyclopeImage,GetScreenHeight()/DIMENSIONP,GetScreenHeight()/DIMENSIONP);
    Texture2D OeilCyclope = LoadTextureFromImage(OeilCyclopeImage);
    UnloadImage(OeilCyclopeImage);

    Image OeilMoiresImage = LoadImage("../Image Plateau/Oeil Moires.png");
    ImageResize(&OeilMoiresImage,GetScreenHeight()/DIMENSIONP,GetScreenHeight()/DIMENSIONP);
    Texture2D OeilMoires = LoadTextureFromImage(OeilMoiresImage);
    UnloadImage(OeilMoiresImage);

    Image PegaseImage = LoadImage("../Image Plateau/Pegase.png");
    ImageResize(&PegaseImage,GetScreenHeight()/DIMENSIONP,GetScreenHeight()/DIMENSIONP);
    Texture2D Pegase = LoadTextureFromImage(PegaseImage);
    UnloadImage(PegaseImage);

    Image TeteGorgonneImage = LoadImage("../Image Plateau/Tete Gorgonne.png");
    ImageResize(&TeteGorgonneImage,GetScreenHeight()/DIMENSIONP,GetScreenHeight()/DIMENSIONP);
    Texture2D TeteGorgonne = LoadTextureFromImage(TeteGorgonneImage);
    UnloadImage(TeteGorgonneImage);

    Image ToisonOrImage = LoadImage("../Image Plateau/Toison or.png");
    ImageResize(&ToisonOrImage,GetScreenHeight()/DIMENSIONP,GetScreenHeight()/DIMENSIONP);
    Texture2D ToisonOr = LoadTextureFromImage(ToisonOrImage);
    UnloadImage(ToisonOrImage);

    Image TridentPoseidonImage = LoadImage("../Image Plateau/Trident poseidon.png");
    ImageResize(&TridentPoseidonImage,GetScreenHeight()/DIMENSIONP,GetScreenHeight()/DIMENSIONP);
    Texture2D TridentPoseidon = LoadTextureFromImage(TridentPoseidonImage);
    UnloadImage(TridentPoseidonImage);

    Image Psg_BleuImage = LoadImage("../Image Plateau/Psg_Bleu.png");
    ImageResize(&Psg_BleuImage,GetScreenHeight()/DIMENSIONP,GetScreenHeight()/DIMENSIONP);
    Texture2D PionsBleu = LoadTextureFromImage(Psg_BleuImage);
    UnloadImage(Psg_BleuImage);

    Image Psg_RougeImage = LoadImage("../Image Plateau/Psg_Rouge.png");
    ImageResize(&Psg_RougeImage,GetScreenHeight()/DIMENSIONP,GetScreenHeight()/DIMENSIONP);
    Texture2D PionsRouge = LoadTextureFromImage(Psg_RougeImage);
    UnloadImage(Psg_RougeImage);

    Image Psg_JauneImage = LoadImage("../Image Plateau/Psg_Jaune.png");
    ImageResize(&Psg_JauneImage,GetScreenHeight()/DIMENSIONP,GetScreenHeight()/DIMENSIONP);
    Texture2D PionsJaune = LoadTextureFromImage(Psg_JauneImage);
    UnloadImage(Psg_JauneImage);

    Image Psg_VertImage = LoadImage("../Image Plateau/Psg_Vert.png");
    ImageResize(&Psg_VertImage,GetScreenHeight()/DIMENSIONP,GetScreenHeight()/DIMENSIONP);
    Texture2D PionsVert = LoadTextureFromImage(Psg_VertImage);
    UnloadImage(Psg_VertImage);

    Image FondVideImage = LoadImage("../Image Plateau/fondVid.png");
    ImageResize(&FondVideImage,GetScreenHeight()/DIMENSIONP,GetScreenHeight()/DIMENSIONP);
    Texture2D FondVide = LoadTextureFromImage(FondVideImage);
    UnloadImage(FondVideImage);

    int fin = 0; // fin inutile juste histoire de pas fermer la fenetre



    while(!fin) {
        BeginDrawing();
        ClearBackground(WHITE);
        Vector2 positionSouris = GetMousePosition();
        DrawTextureEx(fond,(Vector2){0,0},0.0f,1.0f,WHITE);
        DrawTextureEx(quitter,(Vector2){GetScreenWidth()-GetScreenWidth()/16,GetScreenHeight()/32},0.0f,1.0f,WHITE);
        Joueur J,J2,J3,J4;



        if(nbJ==2){
            J.x = 0;
            J.y=0;
            J2.x = 6;
            J2.y=6;
            ChoixPoins(J,Jaune,Bleu,Rouge,Vert,PionsJaune,PionsVert,PionsRouge,PionsBleu);
            ChoixPoins(J2,Jaune,Bleu,Rouge,Vert,PionsJaune,PionsVert,PionsRouge,PionsBleu);
        }
        else if(nbJ==3){
            J.x = 0;
            J.y=0;
            J2.x = 6;
            J2.y=6;
            J3.x=6;
            J3.y=0;
            ChoixPoins(J,Jaune,Bleu,Rouge,Vert,PionsJaune,PionsVert,PionsRouge,PionsBleu);
            ChoixPoins(J2,Jaune,Bleu,Rouge,Vert,PionsJaune,PionsVert,PionsRouge,PionsBleu);
            ChoixPoins(J3,Jaune,Bleu,Rouge,Vert,PionsJaune,PionsVert,PionsRouge,PionsBleu);
        }
        else if(nbJ==4){

            J.x = 0;
            J.y=0;
            J2.x = 6;
            J2.y=6;
            J3.x=6;
            J3.y=0;
            J4.x=0;
            J4.y=6;
            ChoixPoins(J,Jaune,Bleu,Rouge,Vert,PionsJaune,PionsVert,PionsRouge,PionsBleu);
            ChoixPoins(J2,Jaune,Bleu,Rouge,Vert,PionsJaune,PionsVert,PionsRouge,PionsBleu);
            ChoixPoins(J3,Jaune,Bleu,Rouge,Vert,PionsJaune,PionsVert,PionsRouge,PionsBleu);
            ChoixPoins(J4,Jaune,Bleu,Rouge,Vert,PionsJaune,PionsVert,PionsRouge,PionsBleu);
        }

        //      Afichage cases des joueur
        switch (nbJ) {
            case 2 :
//                if(J.couleurT==0){
//                    DrawRectangle(1750,900,200,150,YELLOW);
//                    DrawTextureEx(J.pions,(Vector2){1750,200},0.0f,1.0f,YELLOW);
//                }else if(J.couleurT==1){
//                    DrawRectangle(1750,900,200,150,BLUE);
//                    DrawTextureEx(J.pions,(Vector2){1750,200},0.0f,1.0f,BLUE);
//                }else if(J.couleurT==2){
//                    DrawRectangle(1750,900,200,150,RED);
//                    DrawTextureEx(J.pions,(Vector2){1750,200},0.0f,1.0f,RED);
//                }else if(J.couleurT==3){
//                    DrawRectangle(1750,900,200,150,GREEN);
//                    DrawTextureEx(J.pions,(Vector2){1750,200},0.0f,1.0f,GREEN);
//                }
//                else{DrawRectangle(1750,900,200,150,WHITE);
//                    DrawTextureEx(J.pions,(Vector2){1750,200},0.0f,1.0f,WHITE);}
//
//                if(J2.couleurT==0){
//                    DrawRectangle(1750,900,200,150,YELLOW);
//                    DrawTextureEx(J2.pions,(Vector2){1750,200},0.0f,1.0f,YELLOW);
//                }else if(J2.couleurT==1){
//                    DrawRectangle(1750,900,200,150,BLUE);
//                    DrawTextureEx(J2.pions,(Vector2){1750,200},0.0f,1.0f,BLUE);
//                }else if(J2.couleurT==2){
//                    DrawRectangle(1750,900,200,150,RED);
//                    DrawTextureEx(J2.pions,(Vector2){1750,200},0.0f,1.0f,RED);
//                }else if(J2.couleurT==3){
//                    DrawRectangle(1750,900,200,150,GREEN);
//                    DrawTextureEx(J2.pions,(Vector2){1750,200},0.0f,1.0f,GREEN);
//                }
//                else{DrawRectangle(1750,900,200,150,WHITE);
//                    DrawTextureEx(J2.pions,(Vector2){1750,200},0.0f,1.0f,WHITE);}
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

        if(((   (positionSouris.x>=GetScreenHeight()/7) &&
                (positionSouris.x<=GetScreenHeight()/7+GetScreenWidth()/16)) &&
            ((positionSouris.y>=GetScreenWidth()/8+2.5*I1.height) &&
             (positionSouris.y<=GetScreenWidth()/8+2.5*I1.height+GetScreenHeight()/DIMENSION))) &&
           IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){

            BeginDrawing();
            PlateauAttend[0].rotation = PlateauAttend[0].rotation +1;
            EndDrawing();
        }


        //fleche de droite première ligne
        if( ((((positionSouris.x>=GetScreenWidth()/3+7*I1.width) &&
               (positionSouris.x<=GetScreenWidth()/3+7*I1.width+flecheD.width)) &&
              ((positionSouris.y>=GetScreenHeight()/8+I1.width) &&
               (positionSouris.y<=GetScreenHeight()/8+I1.width+flecheD.width))) &&
             IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){

            PlateauAttend[1].type=PlateauAfficher[1][0].type;
            PlateauAttend[1].tresor=PlateauAfficher[1][0].tresor;
            PlateauAttend[1].rotation=PlateauAfficher[1][0].rotation;
            for (int i = 0; i < 7; ++i) {
                PlateauAfficher[1][i].type=PlateauAfficher[1][i+1].type;
                PlateauAfficher[1][i].tresor=PlateauAfficher[1][i+1].tresor;
                PlateauAfficher[1][i].rotation=PlateauAfficher[1][i+1].rotation;
            }
            PlateauAfficher[1][6].type=PlateauAttend[0].type;
            PlateauAfficher[1][6].tresor=PlateauAttend[0].tresor;
            PlateauAfficher[1][6].rotation=PlateauAttend[0].rotation;
            PlateauAttend[0].type=PlateauAttend[1].type;
            PlateauAttend[0].tresor=PlateauAttend[1].tresor;
            PlateauAttend[0].rotation=PlateauAttend[1].rotation;
            EndDrawing();
        }

        //fleche de droite deuxieme ligne
        if( ((((positionSouris.x>=GetScreenWidth()/3+7*I1.width) &&
               (positionSouris.x<=GetScreenWidth()/3+7*I1.width+flecheD.width)) &&
              ((positionSouris.y>=GetScreenHeight()/8+3*I1.width) &&
               (positionSouris.y<=GetScreenHeight()/8+3*I1.width+flecheD.width))) &&
             IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){

            PlateauAttend[1].type=PlateauAfficher[3][0].type;
            PlateauAttend[1].tresor=PlateauAfficher[3][0].tresor;
            PlateauAttend[1].rotation=PlateauAfficher[3][0].rotation;
            for (int i = 0; i < 7; ++i) {
                PlateauAfficher[3][i].type=PlateauAfficher[3][i+1].type;
                PlateauAfficher[3][i].tresor=PlateauAfficher[3][i+1].tresor;
                PlateauAfficher[3][i].rotation=PlateauAfficher[3][i+1].rotation;
            }
            PlateauAfficher[3][6].type=PlateauAttend[0].type;
            PlateauAfficher[3][6].tresor=PlateauAttend[0].tresor;
            PlateauAfficher[3][6].rotation=PlateauAttend[0].rotation;
            PlateauAttend[0].type=PlateauAttend[1].type;
            PlateauAttend[0].tresor=PlateauAttend[1].tresor;
            PlateauAttend[0].rotation=PlateauAttend[1].rotation;
            EndDrawing();
        }

        //fleche de droite troisieme ligne
        if( ((((positionSouris.x>=GetScreenWidth()/3+7*I1.width) &&
               (positionSouris.x<=GetScreenWidth()/3+7*I1.width+flecheD.width)) &&
              ((positionSouris.y>=GetScreenHeight()/8+5*I1.width) &&
               (positionSouris.y<=GetScreenHeight()/8+5*I1.width+flecheD.width))) &&
             IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){

            PlateauAttend[1].type=PlateauAfficher[5][0].type;
            PlateauAttend[1].tresor=PlateauAfficher[5][0].tresor;
            PlateauAttend[1].rotation=PlateauAfficher[5][0].rotation;
            for (int i = 0; i < 7; ++i) {
                PlateauAfficher[5][i].type=PlateauAfficher[5][i+1].type;
                PlateauAfficher[5][i].tresor=PlateauAfficher[5][i+1].tresor;
                PlateauAfficher[5][i].rotation=PlateauAfficher[5][i+1].rotation;
            }
            PlateauAfficher[5][6].type=PlateauAttend[0].type;
            PlateauAfficher[5][6].tresor=PlateauAttend[0].tresor;
            PlateauAfficher[5][6].rotation=PlateauAttend[0].rotation;
            PlateauAttend[0].type=PlateauAttend[1].type;
            PlateauAttend[0].tresor=PlateauAttend[1].tresor;
            PlateauAttend[0].rotation=PlateauAttend[1].rotation;
            EndDrawing();
        }

        //fleche de gauche première ligne
        if( ((((positionSouris.x>=GetScreenWidth()/3-I1.width) &&
               (positionSouris.x<=GetScreenWidth()/3-I1.width+flecheD.width)) &&
              ((positionSouris.y>=GetScreenHeight()/8+I1.width) &&
               (positionSouris.y<=GetScreenHeight()/8+I1.width+flecheD.width))) &&
             IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){

            PlateauAttend[1].type=PlateauAfficher[1][6].type;
            PlateauAttend[1].tresor=PlateauAfficher[1][6].tresor;
            PlateauAttend[1].rotation=PlateauAfficher[1][6].rotation;
            for (int i = 6; i > -1; --i) {
                PlateauAfficher[1][i].type=PlateauAfficher[1][i-1].type;
                PlateauAfficher[1][i].tresor=PlateauAfficher[1][i-1].tresor;
                PlateauAfficher[1][i].rotation=PlateauAfficher[1][i-1].rotation;
            }
            PlateauAfficher[1][0].type=PlateauAttend[0].type;
            PlateauAfficher[1][0].tresor=PlateauAttend[0].tresor;
            PlateauAfficher[1][0].rotation=PlateauAttend[0].rotation;
            PlateauAttend[0].type=PlateauAttend[1].type;
            PlateauAttend[0].tresor=PlateauAttend[1].tresor;
            PlateauAttend[0].rotation=PlateauAttend[1].rotation;
            EndDrawing();
        }

        //fleche de gauche deuxieme ligne
        if( ((((positionSouris.x>=GetScreenWidth()/3-I1.width) &&
               (positionSouris.x<=GetScreenWidth()/3-I1.width+flecheD.width)) &&
              ((positionSouris.y>=GetScreenHeight()/8+3*I1.width) &&
               (positionSouris.y<=GetScreenHeight()/8+3*I1.width+flecheD.width))) &&
             IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){

            PlateauAttend[1].type=PlateauAfficher[3][6].type;
            PlateauAttend[1].tresor=PlateauAfficher[3][6].tresor;
            PlateauAttend[1].rotation=PlateauAfficher[3][6].rotation;
            for (int i = 6; i > -1; --i) {
                PlateauAfficher[3][i].type=PlateauAfficher[3][i-1].type;
                PlateauAfficher[3][i].tresor=PlateauAfficher[3][i-1].tresor;
                PlateauAfficher[3][i].rotation=PlateauAfficher[3][i-1].rotation;
            }
            PlateauAfficher[3][0].type=PlateauAttend[0].type;
            PlateauAfficher[3][0].tresor=PlateauAttend[0].tresor;
            PlateauAfficher[3][0].rotation=PlateauAttend[0].rotation;
            PlateauAttend[0].type=PlateauAttend[1].type;
            PlateauAttend[0].tresor=PlateauAttend[1].tresor;
            PlateauAttend[0].rotation=PlateauAttend[1].rotation;
            EndDrawing();
        }

        //fleche de gauche troisieme ligne
        if( ((((positionSouris.x>=GetScreenWidth()/3-I1.width) &&
               (positionSouris.x<=GetScreenWidth()/3-I1.width+flecheD.width)) &&
              ((positionSouris.y>=GetScreenHeight()/8+5*I1.width) &&
               (positionSouris.y<=GetScreenHeight()/8+5*I1.width+flecheD.width))) &&
             IsMouseButtonPressed(MOUSE_LEFT_BUTTON))) {

            PlateauAttend[1].type = PlateauAfficher[5][6].type;
            PlateauAttend[1].tresor = PlateauAfficher[5][6].tresor;
            PlateauAttend[1].rotation = PlateauAfficher[5][6].rotation;
            for (int i = 6; i > -1; --i) {
                PlateauAfficher[5][i].type = PlateauAfficher[5][i - 1].type;
                PlateauAfficher[5][i].tresor = PlateauAfficher[5][i - 1].tresor;
                PlateauAfficher[5][i].rotation = PlateauAfficher[5][i - 1].rotation;
            }
            PlateauAfficher[5][0].type = PlateauAttend[0].type;
            PlateauAfficher[5][0].tresor = PlateauAttend[0].tresor;
            PlateauAfficher[5][0].rotation = PlateauAttend[0].rotation;
            PlateauAttend[0].type = PlateauAttend[1].type;
            PlateauAttend[0].tresor = PlateauAttend[1].tresor;
            PlateauAttend[0].rotation = PlateauAttend[1].rotation;
            EndDrawing();
        }

        //fleche du bas premire colone
        if( ((((positionSouris.x>=GetScreenWidth()/3+I1.width) &&
               (positionSouris.x<=GetScreenWidth()/3+I1.width+flecheD.width)) &&
              ((positionSouris.y>=GetScreenHeight()/8-I1.width) &&
               (positionSouris.y<=GetScreenHeight()/8-I1.width+flecheD.width))) &&
             IsMouseButtonPressed(MOUSE_LEFT_BUTTON))) {


            PlateauAttend[1].type = PlateauAfficher[6][1].type;
            PlateauAttend[1].tresor = PlateauAfficher[6][1].tresor;
            PlateauAttend[1].rotation = PlateauAfficher[6][1].rotation;
            for (int i = 6; i > -1; --i) {
                PlateauAfficher[i][1].type = PlateauAfficher[i-1][1].type;
                PlateauAfficher[i][1].tresor = PlateauAfficher[i-1][1].tresor;
                PlateauAfficher[i][1].rotation = PlateauAfficher[i-1][1].rotation;
            }
            PlateauAfficher[0][1].type = PlateauAttend[0].type;
            PlateauAfficher[0][1].tresor = PlateauAttend[0].tresor;
            PlateauAfficher[0][1].rotation = PlateauAttend[0].rotation;
            PlateauAttend[0].type = PlateauAttend[1].type;
            PlateauAttend[0].tresor = PlateauAttend[1].tresor;
            PlateauAttend[0].rotation = PlateauAttend[1].rotation;
            EndDrawing();
        }

        //fleche du bas deuxieme colonne
        if( ((((positionSouris.x>=GetScreenWidth()/3+3*I1.width) &&
               (positionSouris.x<=GetScreenWidth()/3+3*I1.width+flecheD.width)) &&
              ((positionSouris.y>=GetScreenHeight()/8-I1.width) &&
               (positionSouris.y<=GetScreenHeight()/8-I1.width+flecheD.width))) &&
             IsMouseButtonPressed(MOUSE_LEFT_BUTTON))) {


            PlateauAttend[1].type = PlateauAfficher[6][3].type;
            PlateauAttend[1].tresor = PlateauAfficher[6][3].tresor;
            PlateauAttend[1].rotation = PlateauAfficher[6][3].rotation;
            for (int i = 6; i > -1; --i) {
                PlateauAfficher[i][3].type = PlateauAfficher[i-1][3].type;
                PlateauAfficher[i][3].tresor = PlateauAfficher[i-1][3].tresor;
                PlateauAfficher[i][3].rotation = PlateauAfficher[i-1][3].rotation;
            }
            PlateauAfficher[0][3].type = PlateauAttend[0].type;
            PlateauAfficher[0][3].tresor = PlateauAttend[0].tresor;
            PlateauAfficher[0][3].rotation = PlateauAttend[0].rotation;
            PlateauAttend[0].type = PlateauAttend[1].type;
            PlateauAttend[0].tresor = PlateauAttend[1].tresor;
            PlateauAttend[0].rotation = PlateauAttend[1].rotation;
            EndDrawing();
        }

        //fleche du bas troisieme colonne
        if( ((((positionSouris.x>=GetScreenWidth()/3+5*I1.width) &&
               (positionSouris.x<=GetScreenWidth()/3+5*I1.width+flecheD.width)) &&
              ((positionSouris.y>=GetScreenHeight()/8-I1.width) &&
               (positionSouris.y<=GetScreenHeight()/8-I1.width+flecheD.width))) &&
             IsMouseButtonPressed(MOUSE_LEFT_BUTTON))) {


            PlateauAttend[1].type = PlateauAfficher[6][5].type;
            PlateauAttend[1].tresor = PlateauAfficher[6][5].tresor;
            PlateauAttend[1].rotation = PlateauAfficher[6][5].rotation;
            for (int i = 6; i > -1; --i) {
                PlateauAfficher[i][5].type = PlateauAfficher[i-1][5].type;
                PlateauAfficher[i][5].tresor = PlateauAfficher[i-1][5].tresor;
                PlateauAfficher[i][5].rotation = PlateauAfficher[i-1][5].rotation;
            }
            PlateauAfficher[0][5].type = PlateauAttend[0].type;
            PlateauAfficher[0][5].tresor = PlateauAttend[0].tresor;
            PlateauAfficher[0][5].rotation = PlateauAttend[0].rotation;
            PlateauAttend[0].type = PlateauAttend[1].type;
            PlateauAttend[0].tresor = PlateauAttend[1].tresor;
            PlateauAttend[0].rotation = PlateauAttend[1].rotation;
            EndDrawing();
        }

        //fleche du haut premiere colonne
        if( ((((positionSouris.x>=GetScreenWidth()/3+I1.width) &&
               (positionSouris.x<=GetScreenWidth()/3+I1.width+flecheD.width)) &&
              ((positionSouris.y>=GetScreenHeight()/8+7*I1.width) &&
               (positionSouris.y<=GetScreenHeight()/8+7*I1.width+flecheD.width))) &&
             IsMouseButtonPressed(MOUSE_LEFT_BUTTON))) {


            PlateauAttend[1].type = PlateauAfficher[0][1].type;
            PlateauAttend[1].tresor = PlateauAfficher[0][1].tresor;
            PlateauAttend[1].rotation = PlateauAfficher[0][1].rotation;
            for (int i = 0; i < 7; ++i) {
                PlateauAfficher[i][1].type = PlateauAfficher[i+1][1].type;
                PlateauAfficher[i][1].tresor = PlateauAfficher[i+1][1].tresor;
                PlateauAfficher[i][1].rotation = PlateauAfficher[i+1][1].rotation;
            }
            PlateauAfficher[6][1].type = PlateauAttend[0].type;
            PlateauAfficher[6][1].tresor = PlateauAttend[0].tresor;
            PlateauAfficher[6][1].rotation = PlateauAttend[0].rotation;
            PlateauAttend[0].type = PlateauAttend[1].type;
            PlateauAttend[0].tresor = PlateauAttend[1].tresor;
            PlateauAttend[0].rotation = PlateauAttend[1].rotation;
            EndDrawing();
        }

        //fleche du haut deuxieme colonne
        if( ((((positionSouris.x>=GetScreenWidth()/3+3*I1.width) &&
               (positionSouris.x<=GetScreenWidth()/3+3*I1.width+flecheD.width)) &&
              ((positionSouris.y>=GetScreenHeight()/8+7*I1.width) &&
               (positionSouris.y<=GetScreenHeight()/8+7*I1.width+flecheD.width))) &&
             IsMouseButtonPressed(MOUSE_LEFT_BUTTON))) {


            PlateauAttend[1].type = PlateauAfficher[0][3].type;
            PlateauAttend[1].tresor = PlateauAfficher[0][3].tresor;
            PlateauAttend[1].rotation = PlateauAfficher[0][3].rotation;
            for (int i = 0; i < 7; ++i) {
                PlateauAfficher[i][3].type = PlateauAfficher[i+1][3].type;
                PlateauAfficher[i][3].tresor = PlateauAfficher[i+1][3].tresor;
                PlateauAfficher[i][3].rotation = PlateauAfficher[i+1][3].rotation;
            }
            PlateauAfficher[6][3].type = PlateauAttend[0].type;
            PlateauAfficher[6][3].tresor = PlateauAttend[0].tresor;
            PlateauAfficher[6][3].rotation = PlateauAttend[0].rotation;
            PlateauAttend[0].type = PlateauAttend[1].type;
            PlateauAttend[0].tresor = PlateauAttend[1].tresor;
            PlateauAttend[0].rotation = PlateauAttend[1].rotation;
            EndDrawing();
        }

        //fleche du haut troisieme colonne
        if( ((((positionSouris.x>=GetScreenWidth()/3+5*I1.width) &&
               (positionSouris.x<=GetScreenWidth()/3+5*I1.width+flecheD.width)) &&
              ((positionSouris.y>=GetScreenHeight()/8+7*I1.width) &&
               (positionSouris.y<=GetScreenHeight()/8+7*I1.width+flecheD.width))) &&
             IsMouseButtonPressed(MOUSE_LEFT_BUTTON))) {


            PlateauAttend[1].type = PlateauAfficher[0][5].type;
            PlateauAttend[1].tresor = PlateauAfficher[0][5].tresor;
            PlateauAttend[1].rotation = PlateauAfficher[0][5].rotation;
            for (int i = 0; i < 7; ++i) {
                PlateauAfficher[i][5].type = PlateauAfficher[i+1][5].type;
                PlateauAfficher[i][5].tresor = PlateauAfficher[i+1][5].tresor;
                PlateauAfficher[i][5].rotation = PlateauAfficher[i+1][5].rotation;
            }
            PlateauAfficher[6][5].type = PlateauAttend[0].type;
            PlateauAfficher[6][5].tresor = PlateauAttend[0].tresor;
            PlateauAfficher[6][5].rotation = PlateauAttend[0].rotation;
            PlateauAttend[0].type = PlateauAttend[1].type;
            PlateauAttend[0].tresor = PlateauAttend[1].tresor;
            PlateauAttend[0].rotation = PlateauAttend[1].rotation;
            EndDrawing();
        }


//       dessins première ligne platteau
        DrawTextureEx(ChoixDeCases(PlateauAfficher,0,0,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3,GetScreenHeight()/8},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,0,1,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+I1.width,GetScreenHeight()/8},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,0,1,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+1.25*I1.width,GetScreenHeight()/8+0.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,0,2,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+2*I1.width,GetScreenHeight()/8},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,0,2,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+2.25*I1.width,GetScreenHeight()/8+0.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,0,3,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+3*I1.width,GetScreenHeight()/8},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,0,3,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+3.25*I1.width,GetScreenHeight()/8+0.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,0,4,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+4*I1.width,GetScreenHeight()/8},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,0,4,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+4.25*I1.width,GetScreenHeight()/8+0.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,0,5,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+5*I1.width,GetScreenHeight()/8},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,0,5,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+5.25*I1.width,GetScreenHeight()/8+0.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,0,6,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+6*I1.width,GetScreenHeight()/8},0.0f,1.0f,WHITE);

//       dessins deuxième ligne platteau

        DrawTextureEx(ChoixDeCases(PlateauAfficher,1,0,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3,GetScreenHeight()/8+I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,1,0,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+0.25*I1.width,GetScreenHeight()/8+1.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,1,1,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+I1.width,GetScreenHeight()/8+I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,1,1,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+1.25*I1.width,GetScreenHeight()/8+1.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,1,2,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+2*I1.width,GetScreenHeight()/8+I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,1,2,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+2.25*I1.width,GetScreenHeight()/8+1.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,1,3,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+3*I1.width,GetScreenHeight()/8+I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,1,3,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+3.25*I1.width,GetScreenHeight()/8+1.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,1,4,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+4*I1.width,GetScreenHeight()/8+I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,1,4,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+4.25*I1.width,GetScreenHeight()/8+1.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,1,5,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+5*I1.width,GetScreenHeight()/8+I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,1,5,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+5.25*I1.width,GetScreenHeight()/8+1.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,1,6,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+6*I1.width,GetScreenHeight()/8+I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,1,6,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+6.25*I1.width,GetScreenHeight()/8+1.25*I1.width},0.0f,0.5f,WHITE);

//       dessins troisième ligne platteau

        DrawTextureEx(ChoixDeCases(PlateauAfficher,2,0,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3,GetScreenHeight()/8+2*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,2,0,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+0.25*I1.width,GetScreenHeight()/8+2.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,2,1,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+I1.width,GetScreenHeight()/8+2*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,2,1,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+1.25*I1.width,GetScreenHeight()/8+2.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,2,2,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+2*I1.width,GetScreenHeight()/8+2*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,2,2,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+2.25*I1.width,GetScreenHeight()/8+2.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,2,3,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+3*I1.width,GetScreenHeight()/8+2*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,2,3,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+3.25*I1.width,GetScreenHeight()/8+2.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,2,4,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+4*I1.width,GetScreenHeight()/8+2*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,2,4,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+4.25*I1.width,GetScreenHeight()/8+2.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,2,5,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+5*I1.width,GetScreenHeight()/8+2*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,2,5,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+5.25*I1.width,GetScreenHeight()/8+2.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,2,6,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+6*I1.width,GetScreenHeight()/8+2*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,2,6,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+6.25*I1.width,GetScreenHeight()/8+2.25*I1.width},0.0f,0.5f,WHITE);

//       dessins quatrième ligne platteau

        DrawTextureEx(ChoixDeCases(PlateauAfficher,3,0,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3,GetScreenHeight()/8+3*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,3,0,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+0.25*I1.width,GetScreenHeight()/8+3.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,3,1,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+I1.width,GetScreenHeight()/8+3*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,3,1,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+1.25*I1.width,GetScreenHeight()/8+3.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,3,2,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+2*I1.width,GetScreenHeight()/8+3*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,3,2,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+2.25*I1.width,GetScreenHeight()/8+3.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,3,3,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+3*I1.width,GetScreenHeight()/8+3*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,3,3,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+3.25*I1.width,GetScreenHeight()/8+3.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,3,4,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+4*I1.width,GetScreenHeight()/8+3*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,3,4,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+4.25*I1.width,GetScreenHeight()/8+3.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,3,5,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+5*I1.width,GetScreenHeight()/8+3*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,3,5,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+5.25*I1.width,GetScreenHeight()/8+3.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,3,6,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+6*I1.width,GetScreenHeight()/8+3*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,3,6,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+6.25*I1.width,GetScreenHeight()/8+3.25*I1.width},0.0f,0.5f,WHITE);

//       dessins cinquième ligne platteau

        DrawTextureEx(ChoixDeCases(PlateauAfficher,4,0,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3,GetScreenHeight()/8+4*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,4,0,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+0.25*I1.width,GetScreenHeight()/8+4.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,4,1,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+I1.width,GetScreenHeight()/8+4*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,4,1,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+1.25*I1.width,GetScreenHeight()/8+4.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,4,2,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+2*I1.width,GetScreenHeight()/8+4*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,4,2,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+2.25*I1.width,GetScreenHeight()/8+4.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,4,3,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+3*I1.width,GetScreenHeight()/8+4*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,4,3,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+3.25*I1.width,GetScreenHeight()/8+4.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,4,4,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+4*I1.width,GetScreenHeight()/8+4*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,4,4,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+4.25*I1.width,GetScreenHeight()/8+4.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,4,5,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+5*I1.width,GetScreenHeight()/8+4*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,4,5,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+5.25*I1.width,GetScreenHeight()/8+4.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,4,6,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+6*I1.width,GetScreenHeight()/8+4*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,4,6,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+6.25*I1.width,GetScreenHeight()/8+4.25*I1.width},0.0f,0.5f,WHITE);

//       dessins sixième ligne platteau

        DrawTextureEx(ChoixDeCases(PlateauAfficher,5,0,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3,GetScreenHeight()/8+5*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,5,0,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+0.25*I1.width,GetScreenHeight()/8+5.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,5,1,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+I1.width,GetScreenHeight()/8+5*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,5,1,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+1.25*I1.width,GetScreenHeight()/8+5.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,5,2,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+2*I1.width,GetScreenHeight()/8+5*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,5,2,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+2.25*I1.width,GetScreenHeight()/8+5.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,5,3,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+3*I1.width,GetScreenHeight()/8+5*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,5,3,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+3.25*I1.width,GetScreenHeight()/8+5.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,5,4,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+4*I1.width,GetScreenHeight()/8+5*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,5,4,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+4.25*I1.width,GetScreenHeight()/8+5.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,5,5,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+5*I1.width,GetScreenHeight()/8+5*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,5,5,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+5.25*I1.width,GetScreenHeight()/8+5.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,5,6,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+6*I1.width,GetScreenHeight()/8+5*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,5,6,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+6.25*I1.width,GetScreenHeight()/8+5.25*I1.width},0.0f,0.5f,WHITE);

//       dessins sepième ligne platteau

        DrawTextureEx(ChoixDeCases(PlateauAfficher,6,0,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3,GetScreenHeight()/8+6*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,6,1,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+I1.width,GetScreenHeight()/8+6*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,6,1,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+1.25*I1.width,GetScreenHeight()/8+6.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,6,2,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+2*I1.width,GetScreenHeight()/8+6*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,6,2,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+2.25*I1.width,GetScreenHeight()/8+6.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,6,3,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+3*I1.width,GetScreenHeight()/8+6*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,6,3,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+3.25*I1.width,GetScreenHeight()/8+6.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,6,4,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+4*I1.width,GetScreenHeight()/8+6*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,6,4,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+4.25*I1.width,GetScreenHeight()/8+6.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,6,5,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+5*I1.width,GetScreenHeight()/8+6*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(ChoixTresor(PlateauAfficher,6,5,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/3+5.25*I1.width,GetScreenHeight()/8+6.25*I1.width},0.0f,0.5f,WHITE);
        DrawTextureEx(ChoixDeCases(PlateauAfficher,6,6,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/3+6*I1.width,GetScreenHeight()/8+6*I1.height},0.0f,1.0f,WHITE);


//      Tuile supplémentaire
        DrawTextureEx(ChoixDeCasesDehors(PlateauAttend,0,I1,I2,L1,L2,L3,L4,T1,T2,T3,T4),(Vector2){GetScreenWidth()/7,GetScreenHeight()/8+3*I1.height},0.0f,2.0f,WHITE);
        DrawTextureEx(ChoixTresorDehors(PlateauAttend,0,AileHarpie,ArcArtemis,BoitePandore,BotteHermes,CasqueAchille,Centaure,Cerbere,ChevalTroie,ChouetteAthena,CorneMinotaure,CoupeDyonisos,EpeeAres,FilArianne,FlammeHades,FleurAphrodite,FoudreZeus,HarpeApollon,MarteauEpahistos,OeilCyclope,OeilMoires,Pegase,TeteGorgonne,ToisonOr,TridentPoseidon,FondVide),(Vector2){GetScreenWidth()/7+0.75*I1.width,GetScreenHeight()/8+3.75*I1.height},0.0f,1.0f,WHITE);
        DrawTextureEx(fleche,(Vector2){GetScreenWidth()/12,GetScreenHeight()/8+3.5*I1.height},0.0f,1.0f,YELLOW);
        DrawTextureEx(flecheD,(Vector2){GetScreenWidth()/3+2*I1.width,GetScreenHeight()/8-I1.width},90.0f,1.0f,WHITE); //fleche du haut première colonne
        DrawTextureEx(flecheD,(Vector2){GetScreenWidth()/3+4*I1.width,GetScreenHeight()/8-I1.width},90.0f,1.0f,WHITE); // fleche du haut deuxieme colonne
        DrawTextureEx(flecheD,(Vector2){GetScreenWidth()/3+6*I1.width,GetScreenHeight()/8-I1.width},90.0f,1.0f,WHITE); // fleche du haut troisieme colonne
        DrawTextureEx(flecheD,(Vector2){GetScreenWidth()/3+I1.width,GetScreenHeight()/8+8*I1.width},270.0f,1.0f,WHITE); // fleche du bas première colonne
        DrawTextureEx(flecheD,(Vector2){GetScreenWidth()/3+3*I1.width,GetScreenHeight()/8+8*I1.width},270.0f,1.0f,WHITE); // fleche du bas deuxieme colonne
        DrawTextureEx(flecheD,(Vector2){GetScreenWidth()/3+5*I1.width,GetScreenHeight()/8+8*I1.width},270.0f,1.0f,WHITE);// fleche du bas troisieme colonne
        DrawTextureEx(flecheD,(Vector2){GetScreenWidth()/3-I1.width,GetScreenHeight()/8+I1.width},0.0f,1.0f,WHITE); // fleche de gacuhe première ligne
        DrawTextureEx(flecheD,(Vector2){GetScreenWidth()/3-I1.width,GetScreenHeight()/8+3*I1.width},0.0f,1.0f,WHITE); // fleche de gauche deuxieme ligne
        DrawTextureEx(flecheD,(Vector2){GetScreenWidth()/3-I1.width,GetScreenHeight()/8+5*I1.width},0.0f,1.0f,WHITE); // fleche de gauche troisieme ligne
        DrawTextureEx(flecheD,(Vector2){GetScreenWidth()/3+8*I1.width,GetScreenHeight()/8+2*I1.width},180.0f,1.0f,WHITE); // fleche de droite premiere ligne
        DrawTextureEx(flecheD,(Vector2){GetScreenWidth()/3+8*I1.width,GetScreenHeight()/8+4*I1.width},180.0f,1.0f,WHITE); // fleche de droite deuxieme ligne
        DrawTextureEx(flecheD,(Vector2){GetScreenWidth()/3+8*I1.width,GetScreenHeight()/8+6*I1.width},180.0f,1.0f,WHITE); // fleche de droite troisième ligne


        if (IsKeyPressed(KEY_ESCAPE) || ((positionSouris.x >= GetScreenWidth()-GetScreenWidth()/16) && (positionSouris.x <= GetScreenWidth()-GetScreenWidth()/16 + quitterImage.width) && (positionSouris.y >= GetScreenHeight()/32) && (positionSouris.y <= GetScreenHeight()/32 +quitterImage.height) && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))) {
            fin = true;
            //PlaySound(sonBoutton);
            printf("%f.2 et %f.2",positionSouris.x,positionSouris.y);

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