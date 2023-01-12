#ifndef PROJET_LABYRINTE_ECE_STRUCTURES_H
#define PROJET_LABYRINTE_ECE_STRUCTURES_H


typedef struct {
    int x,y;
    char pseudo[20],couleur[5];
    int TresorDeck[8],TresorRecup[8];
    int nbJoueur;
}Joueur;

typedef struct{
    int Tab[3][3];
    int IRXYFJDHBGTS[12];
    int rotation,type;
}Cases;

typedef struct{
    Cases Matrice[7][7];
    Cases restante;
}tableau;

#endif
