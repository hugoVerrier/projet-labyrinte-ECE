#ifndef PROJET_LABYRINTE_ECE_MENU_H
#define PROJET_LABYRINTE_ECE_MENU_H

#include "stdio.h"
#include "raylib.h"
#include "unistd.h"

#define CHAR_OUI_NON 3
#define CHAR_CHOIXNBJOUEURS 1
#define CHAR_CHOIX_COULEUR_PION 5

typedef enum Fenetre{MENU,NOUVELLE_PARTIE,CHARGER_PARTIE,REGLES,CREDITS,QUITTER}
Fenetre;

void fenetreMenu();


#endif
