
#ifndef PROJET_LABYRINTE_ECE_MENU_H
#define PROJET_LABYRINTE_ECE_MENU_H


#include "Bibliotheques.h" // include les bibliotheques utilisees
#include "Structures.h" // inlude les structures utilisees
#include "Macro.h" // include les macros utilisees
#include "Enum.h" // include les enum utilisees




void fenetreMenu(); // creation de la fonction menu regroupant toutes les fenetres
void sleepf(float seconds); // creation d'un sleep floatant pour corriger un bug de son
void creerSauvegardePartie(DonneesPartie* dp, Joueur* joueur[dp->nbJoueur], tableau* tb,FILE* fichierNom);
void lireSauvegardePartie(DonneesPartie* dp, Joueur* joueur[dp->nbJoueur], tableau* tb,FILE* fichierNom);

#endif

