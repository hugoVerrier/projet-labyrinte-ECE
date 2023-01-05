//
// Created by hugov on 03/01/2023.
//

#include "plateau.h"

void affichageConsol(){
    Joueur* j;
    Cases* C1,C2,C3,C4,C5,C6,C7,C8,C9,C10,C11,C12,C13,C14,C15,C16,C17,C18,C19,C20,C21,C22,C23,C24,C25,C26,C27,C28,C29,C30,C31,C32,C33,C34;
    int plateau[NBCASE];
    int PlateauAfficher[LIGNE][COLONNE]={0};
    for (int i = 0; i < NBCASE; ++i) {
        plateau[i]= rand()%3;
    }
    for (int i = 0; i < LIGNE; ++i) {
        for (int k = 0; k < COLONNE; ++k) {
            PlateauAfficher[i][k]=plateau[i+k];
            printf(" %d",PlateauAfficher[i][k]);
        }
        printf("\n");
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

void RemplirPlateauCasesAleatoire(Cases PlateauAfficher[LIGNE][COLONNE]){
    for (int i = 0; i < LIGNE; ++i) {
        for (int j = 0; j < COLONNE; ++j) {
            PlateauAfficher[i][j].type = rand()%3;
            PlateauAfficher[i][j].rotation = rand()%4;
        }
    }
}

void AffichageRaylib(){
    InitWindow(GetScreenWidth(),GetScreenHeight(),"Plateau");
    ToggleFullscreen();
    Fenetre FenetreActuelle = PLATEAU;
}