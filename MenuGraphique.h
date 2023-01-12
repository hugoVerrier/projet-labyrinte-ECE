
#ifndef PROJET_LABYRINTE_ECE_MENU_H
#define PROJET_LABYRINTE_ECE_MENU_H


#include ".h de gestion /Bibliotheques.h" // include les bibliotheques utilisees
#include ".h de gestion /Structures.h" // inlude les structures utilisees
#include ".h de gestion /Macro.h" // include les macros utilisees
#include ".h de gestion /Enum.h" // include les enum utilisees




void fenetreMenu(); // creation de la fonction menu regroupant toutes les fenetres
void sleepf(float seconds); // creation d'un sleep floatant pour corriger un bug de son
void creerSauvegardeStructJoueur(char* sauvegarde, Joueur* j);
void creerSauvegardeStructPlateau(FILE * fichier,char* sauvegarde, char** p);
void lireSauvegardeStructJoueur(FILE* fichier,char* sauvegarde, Joueur* j);
void lireSauvegardeStructPlateau(FILE* fichier,char* sauvegarde, char** p);


#endif

