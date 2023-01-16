//
// Created by Pas un taille crayon on 14/12/2022.
//

#ifndef CA_ME_REND_TRISTE_VRMTVRMTTRISTE_H
#define CA_ME_REND_TRISTE_VRMTVRMTTRISTE_H
// Structure des Cases
typedef struct{
    int Tab[3][3];
    // ID - Rotation - X - Y - Fixe - Joueur - Droite - Haut - Bas - Gauche - Tresor - Spawn
    int IRXYFJDHBGTS[12];
}Cases;
// Structure Joueur avec pseudo + coordonnées + Num Joueur + Tresor ( A recuperer / recuperés)
typedef struct {
    int x,y;
    char pseudo[20],couleur[5];
    int TresorDeck[8],TresorRecup[8];
    int nbJoueur;
}Joueur;
// Structure tableau pour le plateau
typedef struct{
    Cases Matrice[7][7];
    Cases restante;
}tableau;

// Fonctions Cases ( Initialisation )
Cases Menu_Case();
Cases Creation_Case(Cases K);
Cases Creation_Auto(int TypeK, int CoorX, int CoorY, Cases K);
Cases Init_Case(Cases K, int ID_Case);
void affiche_Case(Cases K);
Cases direction_Possible(Cases K);
Cases Cases_Completion(Cases K);
int ID_Creation(int Auto,int TypeK, int RotaK);

// Fonctions de tableau (Initialisation + Modifications ( Cases + Tresor )
int nb_Mvt_Possible(tableau T, Joueur J);
int Dir_Actu_Poss(tableau T, Joueur J, int input);
tableau Deplacement_joueur(tableau T, Joueur J) ;
void affiche_Tableau(tableau T);
tableau init_Tableau();
tableau Init_Tableau_Fixe();
tableau Deplacement_Case_X(int sens, int CoorY, tableau T);
tableau Deplacement_Case_Y(int sens, int CoorX, tableau T);
tableau Deplacement_Case(tableau T);
tableau Plateau_RandTresor(tableau T);
Joueur Recuperation_Trez(tableau T, Joueur Jul);

// Fonction d'actualisation
Joueur Actu_Joueur(tableau T, Joueur J);
tableau Actu_Trez_Tableau(tableau T, Joueur J);
#endif //CA_ME_REND_TRISTE_VRMTVRMTTRISTE_H
