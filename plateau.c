//
// Created by hugov on 03/01/2023.
//

#include "plateau.h"

void affichagePrincipal(){
    Joueur* j;
    Cases* c;
    int plateau[NBCASE];
    int PlateauAfficher[LIGNE][COLONNE];
    for (int i = 0; i < NBCASE; ++i) {
        plateau[i]= rand(time)%3;
    }
    for (int i = 0; i < LIGNE; ++i) {
        for (int k = 0; k < COLONNE; ++k) {
            PlateauAfficher[i][j]=plateau[i];
            printf(" %d",PlateauAfficher[i][j]);
        }
        printf("\n");
    }
}