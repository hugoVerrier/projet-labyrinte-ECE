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
tableau Deplacement_Case_X(int sens, int CoorY, tableau T);
tableau Deplacement_Case_Y(int sens, int CoorX, tableau T);
tableau Deplacement_Case(tableau T);
Cases DeplacerligneXPlateau(Cases PlateauAttend[2],Cases PlateauAfficher[LIGNE][COLONNE],int x,int a);
Texture2D ChoixPoins(Joueur J, char Jaune[6], char Bleu[6],char Rouge[6], char Vert[6],Texture2D PionsJaune,Texture2D PionsVert,Texture2D PionsRouge, Texture2D PionsBleu);
Texture2D ChoixTresor(Cases PlateauAfficher[LIGNE][COLONNE],int x ,int y,Texture2D AileHarpie,Texture2D ArcArtemis,Texture2D BoitePandore,Texture2D BotteHermes,Texture2D Casqueachille,Texture2D Centaure, Texture2D Cerbere, Texture2D ChevalDeTroie, Texture2D ChouetteAthena,Texture2D CorneMinotaure, Texture2D CoupeDyonisos,Texture2D EpeeAres, Texture2D FilArianne, Texture2D FlammeHades, Texture2D FleurAphrodite, Texture2D FoudreZeus, Texture2D HarpeApollon, Texture2D MarteauEphaistos, Texture2D OeilCyclope, Texture2D OeilMoires, Texture2D Pegase, Texture2D TeteGorgonne, Texture2D ToisonOr, Texture2D TridentPoseidon, Texture2D FondVide);
Texture2D ChoixTresorDehors(Cases PlateauAttend[2],int x ,Texture2D AileHarpie,Texture2D ArcArtemis,Texture2D BoitePandore,Texture2D BotteHermes,Texture2D Casqueachille,Texture2D Centaure, Texture2D Cerbere, Texture2D ChevalDeTroie, Texture2D ChouetteAthena,Texture2D CorneMinotaure, Texture2D CoupeDyonisos,Texture2D EpeeAres, Texture2D FilArianne, Texture2D FlammeHades, Texture2D FleurAphrodite, Texture2D FoudreZeus, Texture2D HarpeApollon, Texture2D MarteauEphaistos, Texture2D OeilCyclope, Texture2D OeilMoires, Texture2D Pegase, Texture2D TeteGorgonne, Texture2D ToisonOr, Texture2D TridentPoseidon, Texture2D FondVide);
Texture2D PlateauTresor(Cases PlateauAfficher[LIGNE][COLONNE]);

void AffichageRaylib(int nbJ);

#endif
