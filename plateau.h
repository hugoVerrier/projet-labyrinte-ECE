//
// Created by hugov on 03/01/2023.
//

#ifndef PROJET_LABYRINTE_ECE_PLATEAU_H
#define PROJET_LABYRINTE_ECE_PLATEAU_H



#include "Bibliotheques.h" // include les bibliotheques utilisees
#include "Structures.h" // inlude les structures utilisees
#include "Macro.h" // include les macros utilisees
#include "Enum.h" // include les enum utilisees




void affichageConsol(Cases plateau[NBCASE],Cases PlateauAfficher[LIGNE][COLONNE],Cases PlateauAttend[2]);
void AfficchageConsolPlateau(Cases PlateauAfficher[LIGNE][COLONNE],Cases PlateauAttend[2]);
void MelangeTab(Cases* plateau);
void RemplirTabCase(Cases* plateau);
void RemplirPlateauLFixe(Cases PlateauAfficher[LIGNE][COLONNE]);
void RemplirPlateauTFixe(Cases PlateauAfficher[LIGNE][COLONNE]);
void RemplirTabCaseAfficher(Cases plateau[NBCASE],Cases PlateauAfficher[LIGNE][COLONNE],Cases PlateauAttend[2]);
Texture2D ChoixDeCases(Cases PlateauAfficher[LIGNE][COLONNE],int x,int y,Texture2D I1,Texture2D I2,Texture2D L1,Texture2D L2,Texture2D L3,Texture2D L4,Texture2D T1,Texture2D T2,Texture2D T3,Texture2D T4);
Texture2D ChoixDeCasesDehors(Cases PlateauAttend[2],int x,Texture2D I1,Texture2D I2,Texture2D L1,Texture2D L2,Texture2D L3,Texture2D L4,Texture2D T1,Texture2D T2,Texture2D T3,Texture2D T4);
void AffichageRaylib();

#endif //PROJET_LABYRINTE_ECE_PLATEAU_H
