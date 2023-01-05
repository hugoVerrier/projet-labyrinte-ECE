#ifndef PROJET_LABYRINTE_ECE_MENU_H
#define PROJET_LABYRINTE_ECE_MENU_H

#include "stdio.h" // fonction basique
#include "string.h" // pour les chaines de caracters utilisees pour les zones de textes en graphique
#include "unistd.h" // pour la gestion du temps
#include "raylib.h" // pour utiliser l'interface graphique
#include "plateau.h" // pour utiliser la structure joueur (passer l'instruction graphique et la rattacher avec la console, strcpy)
#include "math.h" // pour le sleepf (flottant)

#define CHAR_OUI_NON 3 // pour la reponse oui ou non pour regle enfant
#define CHAR_CHOIXNBJOUEURS 1 // pour le choix du nombre de joueur (passage du char en int avec strcmp)
#define CHAR_CHOIX_COULEUR_PION 5 // choix de la couleur du pion
#define CHAR_PSEUDO 9 // taille acceptee pour le pseudo
#define JAUNE YELLOW
typedef enum Fenetre{MENU,NOUVELLE_PARTIE,NOUVELLE_PARTIE_SUITE,CHARGER_PARTIE,REGLES,CREDITS,QUITTER,PLATEAU}
Fenetre; // creation d'un enum pour actualiser la fenetre affichee


void fenetreMenu(); // creation de la fonction menu regroupant toutes les fenetres
void sleepf(float seconds); // creation d'un sleep floatant pour corriger un bug de son

#endif
