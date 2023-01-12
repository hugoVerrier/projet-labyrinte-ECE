//
// Created by hugov on 03/01/2023.
//

#ifndef PROJET_LABYRINTE_ECE_PLATEAU_H
#define PROJET_LABYRINTE_ECE_PLATEAU_H

#include "raylib.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "MenuGraphique.h"
#include "VrmtVrmtTriste.h"

#define COLONNE 7
#define LIGNE 7
#define NBCASE 34
#define DIMENSION 10

typedef struct {
    int x,y;
    char pseudo[20],couleur[5];
    int TresorDeck[8],TresorRecup[8];
}Joueur;



void affichageConsol();
void AfficchageConsolPlateau(Cases PlateauAfficher[LIGNE][COLONNE]);
void MelangeTab(Cases* plateau);
void RemplirTabCase(Cases* plateau);
void RemplirPlateauLFixe(Cases PlateauAfficher[LIGNE][COLONNE]);
void RemplirPlateauTFixe(Cases PlateauAfficher[LIGNE][COLONNE]);
void RemplirTabCaseAfficher(Cases plateau[NBCASE],Cases PlateauAfficher[LIGNE][COLONNE]);

void AffichageRaylib();

#endif //PROJET_LABYRINTE_ECE_PLATEAU_H
