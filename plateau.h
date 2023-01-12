//
// Created by hugov on 03/01/2023.
//

#ifndef PROJET_LABYRINTE_ECE_PLATEAU_H
#define PROJET_LABYRINTE_ECE_PLATEAU_H



#include ".h de gestion /Bibliotheques.h" // include les bibliotheques utilisees
#include ".h de gestion /Structures.h" // inlude les structures utilisees
#include ".h de gestion /Macro.h" // include les macros utilisees
#include ".h de gestion /Enum.h" // include les enum utilisees




void affichageConsol();
void AfficchageConsolPlateau(Cases PlateauAfficher[LIGNE][COLONNE]);
void MelangeTab(Cases* plateau);
void RemplirTabCase(Cases* plateau);
void RemplirPlateauLFixe(Cases PlateauAfficher[LIGNE][COLONNE]);
void RemplirPlateauTFixe(Cases PlateauAfficher[LIGNE][COLONNE]);
void RemplirTabCaseAfficher(Cases plateau[NBCASE],Cases PlateauAfficher[LIGNE][COLONNE]);

void AffichageRaylib();

#endif //PROJET_LABYRINTE_ECE_PLATEAU_H
