#ifndef PROJET_LABYRINTE_ECE_MENU_H
#define PROJET_LABYRINTE_ECE_MENU_H

#include "stdio.h"
#include "raylib.h"
#include "unistd.h"

typedef enum Fenetre{MENU,NOUVELLE_PARTIE,NOUVELLE_PARTIE_ENFANT_OUI,NOUVELLE_PARTIE_ENFANT_NON,CHARGER_PARTIE,REGLES,CREDITS,QUITTER,RETOUR}
Fenetre;
void fenetreMenu();


#endif
