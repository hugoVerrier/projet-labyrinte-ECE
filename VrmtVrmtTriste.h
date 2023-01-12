//
// Created by Pas un taille crayon on 14/12/2022.
//

#ifndef CA_ME_REND_TRISTE_VRMTVRMTTRISTE_H
#define CA_ME_REND_TRISTE_VRMTVRMTTRISTE_H

#include ".h de gestion /Bibliotheques.h" // include les bibliotheques utilisees
#include ".h de gestion /Structures.h" // inlude les structures utilisees
#include ".h de gestion /Macro.h" // include les macros utilisees
#include ".h de gestion /Enum.h" // include les enum utilisees


Cases Menu_Case();
Cases Creation_Case(Cases K);
Cases Creation_Auto(int TypeK, int CoorX, int CoorY, Cases K);
Cases Init_Case(Cases K, int ID_Case);
void affiche_Case(Cases K);
Cases direction_Possible(Cases K);
Cases Cases_Completion(Cases K);
int ID_Creation(int Auto,int TypeK, int RotaK);
int Mvt_Possible(Cases K1, Cases K2);
void Mvt_Impossible();
void affiche_Tableau(tableau T);
tableau init_Tableau();
tableau Init_Tableau_Fixe();


#endif //CA_ME_REND_TRISTE_VRMTVRMTTRISTE_H
