//
// Created by hugov on 03/01/2023.
//

#ifndef PROJET_LABYRINTE_ECE_PLATEAU_H
#define PROJET_LABYRINTE_ECE_PLATEAU_H

#include "raylib.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"


#define COLONNE 7
#define LIGNE 7
#define NBCASE 50

typedef struct {
    int x,y;
    char pseudo[20];
    int TresorDeck[8],TresorRecup[8];
}Joueur;

typedef struct {
    int rotation,type;
}Cases;


void affichagePrincipal();

#endif //PROJET_LABYRINTE_ECE_PLATEAU_H
